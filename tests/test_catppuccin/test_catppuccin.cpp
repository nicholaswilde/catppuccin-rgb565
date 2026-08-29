#include <unity.h>
#include "CatppuccinRGB565.h"
// Include the implementation directly so the linker resolves getPalette()
// in the native test environment (mirrors the mocks.cpp include pattern).
#include "../../src/CatppuccinRGB565.cpp"

using namespace Catppuccin;

// ---------------------------------------------------------------------------
// Helpers
// ---------------------------------------------------------------------------
static uint16_t rgb888_to_rgb565(uint32_t rgb888) {
    uint8_t r = (rgb888 >> 16) & 0xFF;
    uint8_t g = (rgb888 >> 8)  & 0xFF;
    uint8_t b =  rgb888        & 0xFF;
    return (uint16_t)(((r & 0xF8) << 8) | ((g & 0xFC) << 3) | (b >> 3));
}

void setUp(void) {}
void tearDown(void) {}

// ---------------------------------------------------------------------------
// Mocha
// ---------------------------------------------------------------------------
void test_mocha_base(void) {
    TEST_ASSERT_EQUAL_HEX16(rgb888_to_rgb565(0x1e1e2e), Mocha::base);
}
void test_mocha_mantle(void) {
    TEST_ASSERT_EQUAL_HEX16(rgb888_to_rgb565(0x181825), Mocha::mantle);
}
void test_mocha_crust(void) {
    TEST_ASSERT_EQUAL_HEX16(rgb888_to_rgb565(0x11111b), Mocha::crust);
}
void test_mocha_text(void) {
    TEST_ASSERT_EQUAL_HEX16(rgb888_to_rgb565(0xcdd6f4), Mocha::text);
}
void test_mocha_rosewater(void) {
    TEST_ASSERT_EQUAL_HEX16(rgb888_to_rgb565(0xf5e0dc), Mocha::rosewater);
}
void test_mocha_flamingo(void) {
    TEST_ASSERT_EQUAL_HEX16(rgb888_to_rgb565(0xf2cdcd), Mocha::flamingo);
}
void test_mocha_pink(void) {
    TEST_ASSERT_EQUAL_HEX16(rgb888_to_rgb565(0xf5c2e7), Mocha::pink);
}
void test_mocha_mauve(void) {
    TEST_ASSERT_EQUAL_HEX16(rgb888_to_rgb565(0xcba6f7), Mocha::mauve);
}
void test_mocha_red(void) {
    TEST_ASSERT_EQUAL_HEX16(rgb888_to_rgb565(0xf38ba8), Mocha::red);
}
void test_mocha_maroon(void) {
    TEST_ASSERT_EQUAL_HEX16(rgb888_to_rgb565(0xeba0ac), Mocha::maroon);
}
void test_mocha_peach(void) {
    TEST_ASSERT_EQUAL_HEX16(rgb888_to_rgb565(0xfab387), Mocha::peach);
}
void test_mocha_yellow(void) {
    TEST_ASSERT_EQUAL_HEX16(rgb888_to_rgb565(0xf9e2af), Mocha::yellow);
}
void test_mocha_green(void) {
    TEST_ASSERT_EQUAL_HEX16(rgb888_to_rgb565(0xa6e3a1), Mocha::green);
}
void test_mocha_teal(void) {
    TEST_ASSERT_EQUAL_HEX16(rgb888_to_rgb565(0x94e2d5), Mocha::teal);
}
void test_mocha_sky(void) {
    TEST_ASSERT_EQUAL_HEX16(rgb888_to_rgb565(0x89dceb), Mocha::sky);
}
void test_mocha_sapphire(void) {
    TEST_ASSERT_EQUAL_HEX16(rgb888_to_rgb565(0x74c7ec), Mocha::sapphire);
}
void test_mocha_blue(void) {
    TEST_ASSERT_EQUAL_HEX16(rgb888_to_rgb565(0x89b4fa), Mocha::blue);
}
void test_mocha_lavender(void) {
    TEST_ASSERT_EQUAL_HEX16(rgb888_to_rgb565(0xb4befe), Mocha::lavender);
}

// ---------------------------------------------------------------------------
// Macchiato
// ---------------------------------------------------------------------------
void test_macchiato_base(void) {
    TEST_ASSERT_EQUAL_HEX16(rgb888_to_rgb565(0x24273a), Macchiato::base);
}
void test_macchiato_text(void) {
    TEST_ASSERT_EQUAL_HEX16(rgb888_to_rgb565(0xcad3f5), Macchiato::text);
}
void test_macchiato_blue(void) {
    TEST_ASSERT_EQUAL_HEX16(rgb888_to_rgb565(0x8aadf4), Macchiato::blue);
}
void test_macchiato_green(void) {
    TEST_ASSERT_EQUAL_HEX16(rgb888_to_rgb565(0xa6da95), Macchiato::green);
}
void test_macchiato_red(void) {
    TEST_ASSERT_EQUAL_HEX16(rgb888_to_rgb565(0xed8796), Macchiato::red);
}
void test_macchiato_mauve(void) {
    TEST_ASSERT_EQUAL_HEX16(rgb888_to_rgb565(0xc6a0f6), Macchiato::mauve);
}

// ---------------------------------------------------------------------------
// Frappé
// ---------------------------------------------------------------------------
void test_frappe_base(void) {
    TEST_ASSERT_EQUAL_HEX16(rgb888_to_rgb565(0x303446), Frappe::base);
}
void test_frappe_text(void) {
    TEST_ASSERT_EQUAL_HEX16(rgb888_to_rgb565(0xc6d0f5), Frappe::text);
}
void test_frappe_blue(void) {
    TEST_ASSERT_EQUAL_HEX16(rgb888_to_rgb565(0x8caaee), Frappe::blue);
}
void test_frappe_green(void) {
    TEST_ASSERT_EQUAL_HEX16(rgb888_to_rgb565(0xa6d189), Frappe::green);
}
void test_frappe_red(void) {
    TEST_ASSERT_EQUAL_HEX16(rgb888_to_rgb565(0xe78284), Frappe::red);
}
void test_frappe_mauve(void) {
    TEST_ASSERT_EQUAL_HEX16(rgb888_to_rgb565(0xca9ee6), Frappe::mauve);
}

// ---------------------------------------------------------------------------
// Latte
// ---------------------------------------------------------------------------
void test_latte_base(void) {
    TEST_ASSERT_EQUAL_HEX16(rgb888_to_rgb565(0xeff1f5), Latte::base);
}
void test_latte_text(void) {
    TEST_ASSERT_EQUAL_HEX16(rgb888_to_rgb565(0x4c4f69), Latte::text);
}
void test_latte_blue(void) {
    TEST_ASSERT_EQUAL_HEX16(rgb888_to_rgb565(0x1e66f5), Latte::blue);
}
void test_latte_green(void) {
    TEST_ASSERT_EQUAL_HEX16(rgb888_to_rgb565(0x40a02b), Latte::green);
}
void test_latte_red(void) {
    TEST_ASSERT_EQUAL_HEX16(rgb888_to_rgb565(0xd20f39), Latte::red);
}
void test_latte_mauve(void) {
    TEST_ASSERT_EQUAL_HEX16(rgb888_to_rgb565(0x8839ef), Latte::mauve);
}

// ---------------------------------------------------------------------------
// Runtime getPalette()
// ---------------------------------------------------------------------------
void test_get_palette_mocha(void) {
    const Palette& p = getPalette(Flavor::Mocha);
    TEST_ASSERT_EQUAL_HEX16(Mocha::base,  p.base);
    TEST_ASSERT_EQUAL_HEX16(Mocha::text,  p.text);
    TEST_ASSERT_EQUAL_HEX16(Mocha::blue,  p.blue);
    TEST_ASSERT_EQUAL_HEX16(Mocha::green, p.green);
    TEST_ASSERT_EQUAL_HEX16(Mocha::red,   p.red);
    TEST_ASSERT_EQUAL_HEX16(Mocha::crust, p.crust);
}
void test_get_palette_macchiato(void) {
    const Palette& p = getPalette(Flavor::Macchiato);
    TEST_ASSERT_EQUAL_HEX16(Macchiato::base,  p.base);
    TEST_ASSERT_EQUAL_HEX16(Macchiato::text,  p.text);
    TEST_ASSERT_EQUAL_HEX16(Macchiato::blue,  p.blue);
}
void test_get_palette_frappe(void) {
    const Palette& p = getPalette(Flavor::Frappe);
    TEST_ASSERT_EQUAL_HEX16(Frappe::base,  p.base);
    TEST_ASSERT_EQUAL_HEX16(Frappe::text,  p.text);
    TEST_ASSERT_EQUAL_HEX16(Frappe::blue,  p.blue);
}
void test_get_palette_latte(void) {
    const Palette& p = getPalette(Flavor::Latte);
    TEST_ASSERT_EQUAL_HEX16(Latte::base,  p.base);
    TEST_ASSERT_EQUAL_HEX16(Latte::text,  p.text);
    TEST_ASSERT_EQUAL_HEX16(Latte::blue,  p.blue);
}

// ---------------------------------------------------------------------------
// CATP_SWAP macro
// ---------------------------------------------------------------------------
void test_swap_macro(void) {
    uint16_t original = 0xABCD;
    uint16_t swapped  = CATP_SWAP(original);
    TEST_ASSERT_EQUAL_HEX16(0xCDAB, swapped);
}
void test_swap_roundtrip(void) {
    uint16_t val = Mocha::base;
    TEST_ASSERT_EQUAL_HEX16(val, CATP_SWAP(CATP_SWAP(val)));
}

// ---------------------------------------------------------------------------
// All 4 flavors have distinct bases (sanity check)
// ---------------------------------------------------------------------------
void test_all_flavors_distinct_base(void) {
    TEST_ASSERT_NOT_EQUAL(Mocha::base,      Macchiato::base);
    TEST_ASSERT_NOT_EQUAL(Mocha::base,      Frappe::base);
    TEST_ASSERT_NOT_EQUAL(Mocha::base,      Latte::base);
    TEST_ASSERT_NOT_EQUAL(Macchiato::base,  Frappe::base);
    TEST_ASSERT_NOT_EQUAL(Macchiato::base,  Latte::base);
    TEST_ASSERT_NOT_EQUAL(Frappe::base,     Latte::base);
}

// ---------------------------------------------------------------------------
// Palette struct has exactly 26 members (compile-time size check)
// ---------------------------------------------------------------------------
void test_palette_struct_member_count(void) {
    // If struct changes, this will catch accidental additions/deletions
    TEST_ASSERT_EQUAL(26 * sizeof(uint16_t), sizeof(Palette));
}

// ---------------------------------------------------------------------------
// RGB565 values are within valid 16-bit range (trivial but explicit)
// ---------------------------------------------------------------------------
void test_mocha_colors_are_16bit(void) {
    TEST_ASSERT_EQUAL_HEX16(Mocha::base,   Mocha::base   & 0xFFFF);
    TEST_ASSERT_EQUAL_HEX16(Mocha::text,   Mocha::text   & 0xFFFF);
    TEST_ASSERT_EQUAL_HEX16(Mocha::blue,   Mocha::blue   & 0xFFFF);
    TEST_ASSERT_EQUAL_HEX16(Mocha::red,    Mocha::red    & 0xFFFF);
    TEST_ASSERT_EQUAL_HEX16(Mocha::green,  Mocha::green  & 0xFFFF);
    TEST_ASSERT_EQUAL_HEX16(Mocha::mauve,  Mocha::mauve  & 0xFFFF);
    TEST_ASSERT_EQUAL_HEX16(Mocha::yellow, Mocha::yellow & 0xFFFF);
    TEST_ASSERT_EQUAL_HEX16(Mocha::peach,  Mocha::peach  & 0xFFFF);
}

// ---------------------------------------------------------------------------
// main
// ---------------------------------------------------------------------------
int main(int argc, char **argv) {
    UNITY_BEGIN();

    // Mocha color accuracy
    RUN_TEST(test_mocha_base);
    RUN_TEST(test_mocha_mantle);
    RUN_TEST(test_mocha_crust);
    RUN_TEST(test_mocha_text);
    RUN_TEST(test_mocha_rosewater);
    RUN_TEST(test_mocha_flamingo);
    RUN_TEST(test_mocha_pink);
    RUN_TEST(test_mocha_mauve);
    RUN_TEST(test_mocha_red);
    RUN_TEST(test_mocha_maroon);
    RUN_TEST(test_mocha_peach);
    RUN_TEST(test_mocha_yellow);
    RUN_TEST(test_mocha_green);
    RUN_TEST(test_mocha_teal);
    RUN_TEST(test_mocha_sky);
    RUN_TEST(test_mocha_sapphire);
    RUN_TEST(test_mocha_blue);
    RUN_TEST(test_mocha_lavender);

    // Macchiato color accuracy
    RUN_TEST(test_macchiato_base);
    RUN_TEST(test_macchiato_text);
    RUN_TEST(test_macchiato_blue);
    RUN_TEST(test_macchiato_green);
    RUN_TEST(test_macchiato_red);
    RUN_TEST(test_macchiato_mauve);

    // Frappé color accuracy
    RUN_TEST(test_frappe_base);
    RUN_TEST(test_frappe_text);
    RUN_TEST(test_frappe_blue);
    RUN_TEST(test_frappe_green);
    RUN_TEST(test_frappe_red);
    RUN_TEST(test_frappe_mauve);

    // Latte color accuracy
    RUN_TEST(test_latte_base);
    RUN_TEST(test_latte_text);
    RUN_TEST(test_latte_blue);
    RUN_TEST(test_latte_green);
    RUN_TEST(test_latte_red);
    RUN_TEST(test_latte_mauve);

    // Runtime getPalette()
    RUN_TEST(test_get_palette_mocha);
    RUN_TEST(test_get_palette_macchiato);
    RUN_TEST(test_get_palette_frappe);
    RUN_TEST(test_get_palette_latte);

    // CATP_SWAP macro
    RUN_TEST(test_swap_macro);
    RUN_TEST(test_swap_roundtrip);

    // Structural / sanity
    RUN_TEST(test_all_flavors_distinct_base);
    RUN_TEST(test_palette_struct_member_count);
    RUN_TEST(test_mocha_colors_are_16bit);

    return UNITY_END();
}
