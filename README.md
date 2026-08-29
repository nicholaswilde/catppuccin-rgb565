# :art: Catppuccin RGB565 :cat:

[![PlatformIO CI](https://github.com/nicholaswilde/catppuccin-rgb565/actions/workflows/ci.yml/badge.svg)](https://github.com/nicholaswilde/catppuccin-rgb565/actions/workflows/ci.yml)

A PlatformIO / Arduino library providing the full [Catppuccin](https://github.com/catppuccin/catppuccin) color palette — all **4 flavors × 26 colors** — pre-converted to **RGB565** for use with TFT and OLED display drivers (TFT_eSPI, Adafruit GFX, LVGL, etc.).

## :art: Flavors

| Flavor | Base | Variant |
|--------|------|---------|
| :crescent_moon: Mocha | `#1E1E2E` | Dark |
| :ringed_planet: Macchiato | `#24273A` | Dark |
| :cherry_blossom: Frappé | `#303446` | Dark |
| :sunflower: Latte | `#EFF1F5` | Light |

## :inbox_tray: Installation

### PlatformIO (recommended)

Add to your `platformio.ini`:

```ini
lib_deps =
    https://github.com/nicholaswilde/catppuccin-rgb565.git
```

### Arduino Library Manager

Search for **CatppuccinRGB565** in the Arduino IDE Library Manager.

## :wrench: Usage

### Static (compile-time) constants

```cpp
#include "CatppuccinRGB565.h"

// Fill screen with Mocha base, draw text in Mocha text color
tft.fillScreen(Catppuccin::Mocha::base);
tft.setTextColor(Catppuccin::Mocha::text, Catppuccin::Mocha::base);
tft.drawRect(0, 0, 100, 50, Catppuccin::Mocha::blue);
```

### Runtime flavor selection

```cpp
#include "CatppuccinRGB565.h"

const Catppuccin::Palette& p = Catppuccin::getPalette(Catppuccin::Flavor::Macchiato);
tft.fillScreen(p.base);
tft.setTextColor(p.text, p.base);
```

### Byte-swapped values (for DMA drivers)

```cpp
uint16_t bg = CATP_SWAP(Catppuccin::Mocha::base);
```

## :rainbow: All 26 Colors

Each flavor exposes these members in the `Catppuccin::<Flavor>` namespace:

`rosewater` · `flamingo` · `pink` · `mauve` · `red` · `maroon` · `peach` · `yellow` · `green` · `teal` · `sky` · `sapphire` · `blue` · `lavender` · `text` · `subtext1` · `subtext0` · `overlay2` · `overlay1` · `overlay0` · `surface2` · `surface1` · `surface0` · `base` · `mantle` · `crust`

## :abacus: RGB565 Conversion

All values are converted using the standard formula:

```
rgb565 = (r & 0xF8) << 8 | (g & 0xFC) << 3 | b >> 3
```

This matches the convention used by TFT_eSPI, Adafruit GFX, and LVGL.

## :white_check_mark: Tasks

This project uses [Task](https://taskfile.dev) to simplify common operations.

| Task | Description |
|------|-------------|
| `task build` | Compile the CydColorPalette example |
| `task upload` | Build and flash to a connected CYD device |
| `task monitor` | Open serial monitor |
| `task flash` | Upload then open monitor in one step |
| `task test` | Run host-native unit tests |

## :bulb: Examples

### [`BasicUsage`](examples/BasicUsage/BasicUsage.ino)

Fills a TFT_eSPI display with the Mocha base color, draws text in the Mocha
text color, and renders an accent color strip across the screen.

### [`RuntimeFlavor`](examples/RuntimeFlavor/RuntimeFlavor.ino)

Demonstrates `getPalette()` by cycling through all four flavors every 3
seconds at runtime — no recompile needed to switch themes.

### [`CydColorPalette`](examples/CydColorPalette/CydColorPalette.ino) :sparkles:

A full palette viewer for the **ESP32-2432S028R** (CYD — Cheap Yellow
Display). Shows all 26 colors as labeled circles arranged in a two-column
grid. Touch the screen to advance to the next flavor; auto-advances every
8 seconds if idle.

```
┌─────────────────── Mocha ───────────────────┐
│ ● rosewater    │ ● lavender                 │
│ ● flamingo     │ ● text                     │
│ ● pink         │ ● subtext1                 │
│   ...          │   ...                      │
│ ● blue         │ ● crust                    │
│         ● ○ ○ ○                             │
└─────────────────────────────────────────────┘
```

**Build and flash:**

```bash
cd examples/CydColorPalette
pio run -e cyd_28r -t upload
```

Or from the project root using Task:

```bash
task upload
```

## :test_tube: Tests

45 Unity tests cover color accuracy (verified against the runtime RGB888→RGB565
formula), runtime palette lookup, byte-swap macro, and structural integrity.

```bash
task test
# or
pio test -e native
```

## :balance_scale: License

[Apache License 2.0](LICENSE)

## :writing_hand: Author

This project was started in 2026 by [Nicholas Wilde](https://github.com/nicholaswilde/).
