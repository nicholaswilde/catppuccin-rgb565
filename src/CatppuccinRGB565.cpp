/**
 * @file CatppuccinRGB565.cpp
 * @brief Runtime palette lookup implementation.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include "CatppuccinRGB565.h"

namespace Catppuccin {

static const Palette mocha_palette = {
    Mocha::rosewater, Mocha::flamingo,  Mocha::pink,      Mocha::mauve,
    Mocha::red,       Mocha::maroon,    Mocha::peach,     Mocha::yellow,
    Mocha::green,     Mocha::teal,      Mocha::sky,       Mocha::sapphire,
    Mocha::blue,      Mocha::lavender,  Mocha::text,      Mocha::subtext1,
    Mocha::subtext0,  Mocha::overlay2,  Mocha::overlay1,  Mocha::overlay0,
    Mocha::surface2,  Mocha::surface1,  Mocha::surface0,  Mocha::base,
    Mocha::mantle,    Mocha::crust,
};

static const Palette macchiato_palette = {
    Macchiato::rosewater, Macchiato::flamingo,  Macchiato::pink,      Macchiato::mauve,
    Macchiato::red,       Macchiato::maroon,    Macchiato::peach,     Macchiato::yellow,
    Macchiato::green,     Macchiato::teal,      Macchiato::sky,       Macchiato::sapphire,
    Macchiato::blue,      Macchiato::lavender,  Macchiato::text,      Macchiato::subtext1,
    Macchiato::subtext0,  Macchiato::overlay2,  Macchiato::overlay1,  Macchiato::overlay0,
    Macchiato::surface2,  Macchiato::surface1,  Macchiato::surface0,  Macchiato::base,
    Macchiato::mantle,    Macchiato::crust,
};

static const Palette frappe_palette = {
    Frappe::rosewater, Frappe::flamingo,  Frappe::pink,      Frappe::mauve,
    Frappe::red,       Frappe::maroon,    Frappe::peach,     Frappe::yellow,
    Frappe::green,     Frappe::teal,      Frappe::sky,       Frappe::sapphire,
    Frappe::blue,      Frappe::lavender,  Frappe::text,      Frappe::subtext1,
    Frappe::subtext0,  Frappe::overlay2,  Frappe::overlay1,  Frappe::overlay0,
    Frappe::surface2,  Frappe::surface1,  Frappe::surface0,  Frappe::base,
    Frappe::mantle,    Frappe::crust,
};

static const Palette latte_palette = {
    Latte::rosewater, Latte::flamingo,  Latte::pink,      Latte::mauve,
    Latte::red,       Latte::maroon,    Latte::peach,     Latte::yellow,
    Latte::green,     Latte::teal,      Latte::sky,       Latte::sapphire,
    Latte::blue,      Latte::lavender,  Latte::text,      Latte::subtext1,
    Latte::subtext0,  Latte::overlay2,  Latte::overlay1,  Latte::overlay0,
    Latte::surface2,  Latte::surface1,  Latte::surface0,  Latte::base,
    Latte::mantle,    Latte::crust,
};

const Palette& getPalette(Flavor flavor) {
    switch (flavor) {
        case Flavor::Macchiato: return macchiato_palette;
        case Flavor::Frappe:    return frappe_palette;
        case Flavor::Latte:     return latte_palette;
        case Flavor::Mocha:
        default:                return mocha_palette;
    }
}

} // namespace Catppuccin
