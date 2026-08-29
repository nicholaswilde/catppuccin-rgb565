/**
 * @file CatppuccinRGB565.h
 * @brief Catppuccin color palette for RGB565 display devices.
 *
 * Provides all 26 official Catppuccin colors across the four flavors —
 * Mocha, Macchiato, Frappé, and Latte — pre-converted to the RGB565
 * format used by TFT and OLED displays.
 *
 * All RGB565 values are stored in big-endian (host) byte order. If your
 * display driver requires byte-swapped values (e.g., TFT_eSPI with
 * DMA), use the helper macros:
 *   CATP_SWAP(color)   — byte-swap a single value at compile time
 *   CATP_SWAP16(color) — alias of CATP_SWAP
 *
 * Usage:
 *   #include "CatppuccinRGB565.h"
 *   uint16_t bg = Catppuccin::Mocha::base;
 *   uint16_t fg = Catppuccin::Mocha::text;
 *
 * Official palette spec: https://github.com/catppuccin/palette
 * RGB565 formula: r5g6b5 = (r & 0xF8)<<8 | (g & 0xFC)<<3 | b>>3
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef CATPPUCCIN_RGB565_H
#define CATPPUCCIN_RGB565_H

#include <stdint.h>

// ---------------------------------------------------------------------------
// Utility macros
// ---------------------------------------------------------------------------

/** Byte-swap a compile-time RGB565 constant (for byte-order-swapped drivers). */
#define CATP_SWAP(c)   ((uint16_t)(((c) >> 8) | ((c) << 8)))
#define CATP_SWAP16(c) CATP_SWAP(c)

// ---------------------------------------------------------------------------
// Flavor identifiers (for runtime selection)
// ---------------------------------------------------------------------------
namespace Catppuccin {

enum class Flavor : uint8_t {
    Mocha      = 0,
    Macchiato  = 1,
    Frappe     = 2,
    Latte      = 3,
};

// ---------------------------------------------------------------------------
// Mocha  (#1E1E2E base)
// ---------------------------------------------------------------------------
namespace Mocha {
    static constexpr uint16_t rosewater = 0xF71B;  // #F5E0DC
    static constexpr uint16_t flamingo  = 0xF679;  // #F2CDCD
    static constexpr uint16_t pink      = 0xF61C;  // #F5C2E7
    static constexpr uint16_t mauve     = 0xCD3E;  // #CBA6F7
    static constexpr uint16_t red       = 0xF455;  // #F38BA8
    static constexpr uint16_t maroon    = 0xED15;  // #EBA0AC
    static constexpr uint16_t peach     = 0xFD90;  // #FAB387
    static constexpr uint16_t yellow    = 0xFF15;  // #F9E2AF
    static constexpr uint16_t green     = 0xA714;  // #A6E3A1
    static constexpr uint16_t teal      = 0x971A;  // #94E2D5
    static constexpr uint16_t sky       = 0x8EFD;  // #89DCEB
    static constexpr uint16_t sapphire  = 0x763D;  // #74C7EC
    static constexpr uint16_t blue      = 0x8DBF;  // #89B4FA
    static constexpr uint16_t lavender  = 0xB5FF;  // #B4BEFE
    static constexpr uint16_t text      = 0xCEBE;  // #CDD6F4
    static constexpr uint16_t subtext1  = 0xBE1B;  // #BAC2DE
    static constexpr uint16_t subtext0  = 0xA579;  // #A6ADC8
    static constexpr uint16_t overlay2  = 0x94D6;  // #9399B2
    static constexpr uint16_t overlay1  = 0x7C33;  // #7F849C
    static constexpr uint16_t overlay0  = 0x6B90;  // #6C7086
    static constexpr uint16_t surface2  = 0x5ACE;  // #585B70
    static constexpr uint16_t surface1  = 0x422B;  // #45475A
    static constexpr uint16_t surface0  = 0x3188;  // #313244
    static constexpr uint16_t base      = 0x18E5;  // #1E1E2E
    static constexpr uint16_t mantle    = 0x18C4;  // #181825
    static constexpr uint16_t crust     = 0x1083;  // #11111B
} // namespace Mocha

// ---------------------------------------------------------------------------
// Macchiato  (#24273A base)
// ---------------------------------------------------------------------------
namespace Macchiato {
    static constexpr uint16_t rosewater = 0xF6DA;  // #F4DBD6
    static constexpr uint16_t flamingo  = 0xF638;  // #F0C6C6
    static constexpr uint16_t pink      = 0xF5FC;  // #F5BDE6
    static constexpr uint16_t mauve     = 0xC51E;  // #C6A0F6
    static constexpr uint16_t red       = 0xEC32;  // #ED8796
    static constexpr uint16_t maroon    = 0xECD4;  // #EE99A0
    static constexpr uint16_t peach     = 0xF54F;  // #F5A97F
    static constexpr uint16_t yellow    = 0xEEB3;  // #EED49F
    static constexpr uint16_t green     = 0xA6D2;  // #A6DA95
    static constexpr uint16_t teal      = 0x8EB9;  // #8BD5CA
    static constexpr uint16_t sky       = 0x96BC;  // #91D7E3
    static constexpr uint16_t sapphire  = 0x7E3C;  // #7DC4E4
    static constexpr uint16_t blue      = 0x8D7E;  // #8AADF4
    static constexpr uint16_t lavender  = 0xB5FF;  // #B7BDF8
    static constexpr uint16_t text      = 0xCE9E;  // #CAD3F5
    static constexpr uint16_t subtext1  = 0xBE1C;  // #B8C0E0
    static constexpr uint16_t subtext0  = 0xA579;  // #A5ADCB
    static constexpr uint16_t overlay2  = 0x94D6;  // #939AB7
    static constexpr uint16_t overlay1  = 0x8434;  // #8087A2
    static constexpr uint16_t overlay0  = 0x6B91;  // #6E738D
    static constexpr uint16_t surface2  = 0x5B0F;  // #5B6078
    static constexpr uint16_t surface1  = 0x4A6C;  // #494D64
    static constexpr uint16_t surface0  = 0x31C9;  // #363A4F
    static constexpr uint16_t base      = 0x2127;  // #24273A
    static constexpr uint16_t mantle    = 0x1906;  // #1E2030
    static constexpr uint16_t crust     = 0x18C4;  // #181926
} // namespace Macchiato

// ---------------------------------------------------------------------------
// Frappé  (#303446 base)
// ---------------------------------------------------------------------------
namespace Frappe {
    static constexpr uint16_t rosewater = 0xF6B9;  // #F2D5CF
    static constexpr uint16_t flamingo  = 0xEDF7;  // #EEBEBE
    static constexpr uint16_t pink      = 0xF5DC;  // #F4B8E4
    static constexpr uint16_t mauve     = 0xCCFC;  // #CA9EE6
    static constexpr uint16_t red       = 0xE410;  // #E78284
    static constexpr uint16_t maroon    = 0xECD3;  // #EA999C
    static constexpr uint16_t peach     = 0xECEE;  // #EF9F76
    static constexpr uint16_t yellow    = 0xE652;  // #E5C890
    static constexpr uint16_t green     = 0xA691;  // #A6D189
    static constexpr uint16_t teal      = 0x8657;  // #81C8BE
    static constexpr uint16_t sky       = 0x9E9B;  // #99D1DB
    static constexpr uint16_t sapphire  = 0x861B;  // #85C1DC
    static constexpr uint16_t blue      = 0x8D5D;  // #8CAAEE
    static constexpr uint16_t lavender  = 0xBDDE;  // #BABBF1
    static constexpr uint16_t text      = 0xC69E;  // #C6D0F5
    static constexpr uint16_t subtext1  = 0xB5FC;  // #B5BFE2
    static constexpr uint16_t subtext0  = 0xA579;  // #A5ADCE
    static constexpr uint16_t overlay2  = 0x94F7;  // #949CBB
    static constexpr uint16_t overlay1  = 0x8454;  // #838BA7
    static constexpr uint16_t overlay0  = 0x73D2;  // #737994
    static constexpr uint16_t surface2  = 0x6350;  // #626880
    static constexpr uint16_t surface1  = 0x52AD;  // #51576D
    static constexpr uint16_t surface0  = 0x422B;  // #414559
    static constexpr uint16_t base      = 0x31A8;  // #303446
    static constexpr uint16_t mantle    = 0x2967;  // #292C3C
    static constexpr uint16_t crust     = 0x2126;  // #232634
} // namespace Frappe

// ---------------------------------------------------------------------------
// Latte  (#EFF1F5 base)
// ---------------------------------------------------------------------------
namespace Latte {
    static constexpr uint16_t rosewater = 0xDC4F;  // #DC8A78
    static constexpr uint16_t flamingo  = 0xDBCF;  // #DD7878
    static constexpr uint16_t pink      = 0xEBB9;  // #EA76CB
    static constexpr uint16_t mauve     = 0x89DD;  // #8839EF
    static constexpr uint16_t red       = 0xD067;  // #D20F39
    static constexpr uint16_t maroon    = 0xE22A;  // #E64553
    static constexpr uint16_t peach     = 0xFB21;  // #FE640B
    static constexpr uint16_t yellow    = 0xDC63;  // #DF8E1D
    static constexpr uint16_t green     = 0x4505;  // #40A02B
    static constexpr uint16_t teal      = 0x1493;  // #179299
    static constexpr uint16_t sky       = 0x053C;  // #04A5E5
    static constexpr uint16_t sapphire  = 0x24F6;  // #209FB5
    static constexpr uint16_t blue      = 0x1B3E;  // #1E66F5
    static constexpr uint16_t lavender  = 0x743F;  // #7287FD
    static constexpr uint16_t text      = 0x4A6D;  // #4C4F69
    static constexpr uint16_t subtext1  = 0x5AEE;  // #5C5F77
    static constexpr uint16_t subtext0  = 0x6B70;  // #6C6F85
    static constexpr uint16_t overlay2  = 0x7BF2;  // #7C7F93
    static constexpr uint16_t overlay1  = 0x8C74;  // #8C8FA1
    static constexpr uint16_t overlay0  = 0x9D16;  // #9CA0B0
    static constexpr uint16_t surface2  = 0xAD97;  // #ACB0BE
    static constexpr uint16_t surface1  = 0xCE9B;  // #CCD0DA
    static constexpr uint16_t surface0  = 0xE75D;  // #E6E9EF
    static constexpr uint16_t base      = 0xEF9E;  // #EFF1F5
    static constexpr uint16_t mantle    = 0xE75D;  // #E6E9EF
    static constexpr uint16_t crust     = 0xDF1D;  // #DCE0E8
} // namespace Latte

// ---------------------------------------------------------------------------
// Runtime palette struct — for flavor selection at run time
// ---------------------------------------------------------------------------
struct Palette {
    uint16_t rosewater;
    uint16_t flamingo;
    uint16_t pink;
    uint16_t mauve;
    uint16_t red;
    uint16_t maroon;
    uint16_t peach;
    uint16_t yellow;
    uint16_t green;
    uint16_t teal;
    uint16_t sky;
    uint16_t sapphire;
    uint16_t blue;
    uint16_t lavender;
    uint16_t text;
    uint16_t subtext1;
    uint16_t subtext0;
    uint16_t overlay2;
    uint16_t overlay1;
    uint16_t overlay0;
    uint16_t surface2;
    uint16_t surface1;
    uint16_t surface0;
    uint16_t base;
    uint16_t mantle;
    uint16_t crust;
};

/**
 * @brief Return a Palette for the requested flavor.
 * @param flavor One of the Catppuccin::Flavor enum values.
 * @return const reference to the static palette.
 */
const Palette& getPalette(Flavor flavor);

} // namespace Catppuccin

#endif // CATPPUCCIN_RGB565_H
