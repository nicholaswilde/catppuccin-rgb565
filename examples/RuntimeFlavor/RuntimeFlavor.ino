/**
 * @file RuntimeFlavor.ino
 * @brief Demonstrates runtime flavor switching with CatppuccinRGB565.
 */

#include <TFT_eSPI.h>
#include <CatppuccinRGB565.h>

TFT_eSPI tft;

void paintFlavor(Catppuccin::Flavor flavor, const char* label) {
    const Catppuccin::Palette& p = Catppuccin::getPalette(flavor);
    tft.fillScreen(p.base);
    tft.setTextColor(p.text, p.base);
    tft.setTextSize(2);
    tft.setCursor(10, 10);
    tft.print(label);
    delay(3000);
}

void setup() {
    tft.init();
    tft.setRotation(1);
}

void loop() {
    paintFlavor(Catppuccin::Flavor::Mocha,      "Mocha");
    paintFlavor(Catppuccin::Flavor::Macchiato,  "Macchiato");
    paintFlavor(Catppuccin::Flavor::Frappe,     "Frappe");
    paintFlavor(Catppuccin::Flavor::Latte,      "Latte");
}
