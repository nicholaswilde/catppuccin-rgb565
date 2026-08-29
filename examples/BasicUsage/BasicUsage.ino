/**
 * @file BasicUsage.ino
 * @brief Demonstrates basic usage of CatppuccinRGB565 with TFT_eSPI.
 *
 * Wire up your RGB565 TFT display, set your User_Setup.h in TFT_eSPI,
 * and this sketch will paint the screen with the Mocha base color and
 * write a greeting in Mocha text color.
 */

#include <TFT_eSPI.h>
#include <CatppuccinRGB565.h>

TFT_eSPI tft;

void setup() {
    tft.init();
    tft.setRotation(1);

    // Fill background with Mocha base
    tft.fillScreen(Catppuccin::Mocha::base);

    // Draw text in Mocha text color
    tft.setTextColor(Catppuccin::Mocha::text, Catppuccin::Mocha::base);
    tft.setTextSize(2);
    tft.setCursor(10, 10);
    tft.print("Catppuccin Mocha");

    // Show a palette strip
    const uint16_t colors[] = {
        Catppuccin::Mocha::rosewater,
        Catppuccin::Mocha::flamingo,
        Catppuccin::Mocha::pink,
        Catppuccin::Mocha::mauve,
        Catppuccin::Mocha::red,
        Catppuccin::Mocha::peach,
        Catppuccin::Mocha::yellow,
        Catppuccin::Mocha::green,
        Catppuccin::Mocha::teal,
        Catppuccin::Mocha::sky,
        Catppuccin::Mocha::sapphire,
        Catppuccin::Mocha::blue,
        Catppuccin::Mocha::lavender,
    };
    const int count = sizeof(colors) / sizeof(colors[0]);
    const int sw = tft.width() / count;
    for (int i = 0; i < count; i++) {
        tft.fillRect(i * sw, 40, sw, 30, colors[i]);
    }
}

void loop() {}
