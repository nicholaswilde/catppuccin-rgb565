# Catppuccin RGB565

[![PlatformIO CI](https://github.com/nicholaswilde/catppuccin-rgb565/actions/workflows/ci.yml/badge.svg)](https://github.com/nicholaswilde/catppuccin-rgb565/actions/workflows/ci.yml)

A PlatformIO / Arduino library providing the full [Catppuccin](https://github.com/catppuccin/catppuccin) color palette — all **4 flavors × 26 colors** — pre-converted to **RGB565** for use with RGB565 TFT and OLED display drivers (TFT_eSPI, Adafruit GFX, LVGL, etc.).

## Flavors

| Flavor | Base | Variant |
|--------|------|---------|
| 🌙 Mocha | `#1E1E2E` | Dark |
| 🪐 Macchiato | `#24273A` | Dark |
| 🌸 Frappé | `#303446` | Dark |
| 🌻 Latte | `#EFF1F5` | Light |

## Installation

### PlatformIO (recommended)

Add to your `platformio.ini`:

```ini
lib_deps =
    https://github.com/nicholaswilde/catppuccin-rgb565.git
```

### Arduino Library Manager

Search for **CatppuccinRGB565** in the Arduino IDE Library Manager.

## Usage

### Static (compile-time) constants

```cpp
#include "CatppuccinRGB565.h"

// Mocha colors
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

## All 26 Colors

Each flavor exposes these members in the `Catppuccin::<Flavor>` namespace:

`rosewater` · `flamingo` · `pink` · `mauve` · `red` · `maroon` · `peach` · `yellow` · `green` · `teal` · `sky` · `sapphire` · `blue` · `lavender` · `text` · `subtext1` · `subtext0` · `overlay2` · `overlay1` · `overlay0` · `surface2` · `surface1` · `surface0` · `base` · `mantle` · `crust`

## RGB565 Conversion

All values are converted using the standard formula:

```
rgb565 = (r & 0xF8) << 8 | (g & 0xFC) << 3 | b >> 3
```

This matches the convention used by TFT_eSPI, Adafruit GFX, and LVGL.

## Running Tests

```bash
pio test -e native
```

## Examples

- [`BasicUsage`](examples/BasicUsage/BasicUsage.ino) — fill background and text with Mocha
- [`RuntimeFlavor`](examples/RuntimeFlavor/RuntimeFlavor.ino) — cycle through all 4 flavors at runtime

## :balance_scale: License

[Apache License 2.0](LICENSE)

## :writing_hand: Author

This project was started in 2026 by [Nicholas Wilde](https://github.com/nicholaswilde/).
