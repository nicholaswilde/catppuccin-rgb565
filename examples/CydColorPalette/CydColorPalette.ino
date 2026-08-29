/**
 * CydColorPalette — Catppuccin palette viewer for ESP32-2432S028R (CYD)
 *
 * Shows all 26 Catppuccin colors as labeled circles on the ILI9341 320×240
 * display. Touch anywhere to advance to the next flavor. Flavor cycles
 * automatically every AUTO_ADVANCE_MS milliseconds if idle.
 *
 * Board: ESP32-2432S028R (CYD — Cheap Yellow Display)
 * Build: pio run -e cyd_28r  (from this directory)
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <Arduino.h>
#include <SPI.h>
#include <TFT_eSPI.h>
#include <XPT2046_Touchscreen.h>
#include <CatppuccinRGB565.h>

// ---------------------------------------------------------------------------
// Pin definitions (ESP32-2432S028R — resistive touch)
// ---------------------------------------------------------------------------
#define XPT_CS   33
#define XPT_IRQ  36
#define XPT_MOSI 32
#define XPT_MISO 39
#define XPT_CLK  25
#define TFT_BL_PIN 21

// ---------------------------------------------------------------------------
// Layout constants  (display: 320 × 240 landscape)
// ---------------------------------------------------------------------------
static constexpr int DISP_W       = 320;
static constexpr int DISP_H       = 240;
static constexpr int HEADER_H     = 22;
static constexpr int FOOTER_H     = 14;
static constexpr int GRID_Y       = HEADER_H;
static constexpr int GRID_H       = DISP_H - HEADER_H - FOOTER_H;
static constexpr int NUM_COLORS   = 26;
static constexpr int ROWS         = 13;    // NUM_COLORS / 2
static constexpr int COLS         = 2;
static constexpr int COL_W        = DISP_W / COLS;  // 160
static constexpr int ROW_H        = GRID_H / ROWS;  // ~15
static constexpr int CIRCLE_R     = 5;
static constexpr int CIRCLE_X_OFF = CIRCLE_R + 4;   // from col left edge
static constexpr int LABEL_X_OFF  = CIRCLE_R * 2 + 9;
static constexpr int AUTO_ADVANCE_MS = 8000;

// ---------------------------------------------------------------------------
// Globals
// ---------------------------------------------------------------------------
TFT_eSPI tft;
static SPIClass touchSPI(HSPI);
static XPT2046_Touchscreen touch(XPT_CS, XPT_IRQ);

static uint8_t  currentFlavor   = 0;
static uint32_t lastTouchMs     = 0;
static bool     lastTouchState  = false;

// ---------------------------------------------------------------------------
// Palette data — name + member pointer offset within Catppuccin::Palette
// ---------------------------------------------------------------------------
struct ColorEntry {
    const char*  name;
    uint8_t      offset;  // byte offset of the uint16_t member in Palette
};

#define OFFSET(member) ((uint8_t)offsetof(Catppuccin::Palette, member))

static const ColorEntry COLORS[NUM_COLORS] = {
    { "rosewater", OFFSET(rosewater) },
    { "flamingo",  OFFSET(flamingo)  },
    { "pink",      OFFSET(pink)      },
    { "mauve",     OFFSET(mauve)     },
    { "red",       OFFSET(red)       },
    { "maroon",    OFFSET(maroon)    },
    { "peach",     OFFSET(peach)     },
    { "yellow",    OFFSET(yellow)    },
    { "green",     OFFSET(green)     },
    { "teal",      OFFSET(teal)      },
    { "sky",       OFFSET(sky)       },
    { "sapphire",  OFFSET(sapphire)  },
    { "blue",      OFFSET(blue)      },
    { "lavender",  OFFSET(lavender)  },
    { "text",      OFFSET(text)      },
    { "subtext1",  OFFSET(subtext1)  },
    { "subtext0",  OFFSET(subtext0)  },
    { "overlay2",  OFFSET(overlay2)  },
    { "overlay1",  OFFSET(overlay1)  },
    { "overlay0",  OFFSET(overlay0)  },
    { "surface2",  OFFSET(surface2)  },
    { "surface1",  OFFSET(surface1)  },
    { "surface0",  OFFSET(surface0)  },
    { "base",      OFFSET(base)      },
    { "mantle",    OFFSET(mantle)    },
    { "crust",     OFFSET(crust)     },
};

static const char* FLAVOR_NAMES[] = { "Mocha", "Macchiato", "Frappe", "Latte" };
static const char  FLAVOR_ICONS[] = { '*', '+', '~', 'o' };  // ASCII stand-ins

// ---------------------------------------------------------------------------
// Helpers
// ---------------------------------------------------------------------------
static uint16_t getColor(const Catppuccin::Palette& p, uint8_t offset) {
    const uint8_t* base = reinterpret_cast<const uint8_t*>(&p);
    uint16_t val;
    memcpy(&val, base + offset, sizeof(val));
    return val;
}

static bool isTouched() {
    if (!touch.touched()) return false;
    TS_Point p = touch.getPoint();
    return (p.x != 0 || p.y != 0);
}

// ---------------------------------------------------------------------------
// Drawing
// ---------------------------------------------------------------------------
static void drawHeader(const Catppuccin::Palette& p, const char* name) {
    tft.fillRect(0, 0, DISP_W, HEADER_H, p.crust);

    // Centered flavor name
    tft.setTextColor(p.text, p.crust);
    tft.setTextSize(2);
    tft.setTextDatum(MC_DATUM);
    tft.drawString(name, DISP_W / 2, HEADER_H / 2);
    tft.setTextDatum(TL_DATUM);  // reset
}

static void drawFooter(const Catppuccin::Palette& p, uint8_t active) {
    int footerY = DISP_H - FOOTER_H;
    tft.fillRect(0, footerY, DISP_W, FOOTER_H, p.base);

    constexpr int DOT_R   = 5;
    constexpr int DOT_GAP = 6;
    constexpr int N       = 4;
    int totalW = N * (DOT_R * 2) + (N - 1) * DOT_GAP;
    int startX = (DISP_W - totalW) / 2;
    int dotY   = footerY + FOOTER_H / 2;

    for (int i = 0; i < N; i++) {
        int cx = startX + i * (DOT_R * 2 + DOT_GAP) + DOT_R;
        uint16_t fill = (i == active) ? p.blue : p.surface2;
        tft.fillCircle(cx, dotY, DOT_R, fill);
    }
}

static void drawGrid(const Catppuccin::Palette& p) {
    tft.fillRect(0, GRID_Y, DISP_W, GRID_H, p.base);

    for (int i = 0; i < NUM_COLORS; i++) {
        int col = i / ROWS;
        int row = i % ROWS;
        int x   = col * COL_W;
        int y   = GRID_Y + row * ROW_H;

        uint16_t circleColor = getColor(p, COLORS[i].offset);

        // Thin outline ring so dark circles stay visible on dark bg
        int cx = x + CIRCLE_X_OFF;
        int cy = y + ROW_H / 2;
        tft.fillCircle(cx, cy, CIRCLE_R + 1, p.overlay0);
        tft.fillCircle(cx, cy, CIRCLE_R,     circleColor);

        // Label
        tft.setTextColor(p.text, p.base);
        tft.setTextSize(1);
        tft.setCursor(x + LABEL_X_OFF, cy - 4);
        tft.print(COLORS[i].name);
    }
}

static void drawFlavor(uint8_t flavorIdx) {
    Catppuccin::Flavor f;
    switch (flavorIdx) {
        case 1:  f = Catppuccin::Flavor::Macchiato; break;
        case 2:  f = Catppuccin::Flavor::Frappe;    break;
        case 3:  f = Catppuccin::Flavor::Latte;     break;
        default: f = Catppuccin::Flavor::Mocha;     break;
    }
    const Catppuccin::Palette& p = Catppuccin::getPalette(f);

    drawGrid(p);
    drawHeader(p, FLAVOR_NAMES[flavorIdx]);
    drawFooter(p, flavorIdx);
}

// ---------------------------------------------------------------------------
// Arduino entry points
// ---------------------------------------------------------------------------
void setup() {
    // Backlight on
    pinMode(TFT_BL_PIN, OUTPUT);
    digitalWrite(TFT_BL_PIN, HIGH);

    // TFT
    tft.init();
    tft.setRotation(1);  // landscape
    tft.fillScreen(TFT_BLACK);

    // Touch (uses HSPI — separate from TFT VSPI)
    touchSPI.begin(XPT_CLK, XPT_MISO, XPT_MOSI, XPT_CS);
    touch.begin(touchSPI);
    touch.setRotation(1);

    // Draw initial flavor
    drawFlavor(currentFlavor);
    lastTouchMs = millis();
}

void loop() {
    bool touched = isTouched();

    // Rising-edge detect — advance on first contact, not while held
    if (touched && !lastTouchState) {
        currentFlavor = (currentFlavor + 1) % 4;
        drawFlavor(currentFlavor);
        lastTouchMs = millis();
    }
    lastTouchState = touched;

    // Auto-advance if idle
    if (!touched && (millis() - lastTouchMs >= AUTO_ADVANCE_MS)) {
        currentFlavor = (currentFlavor + 1) % 4;
        drawFlavor(currentFlavor);
        lastTouchMs = millis();
    }

    delay(20);
}
