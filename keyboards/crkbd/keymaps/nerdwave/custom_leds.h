// !!! DO NOT ADD #pragma once !!! //
// Step 1.
// Declare custom effects using the RGB_MATRIX_EFFECT macro
// (note the lack of semicolon after the macro!)
RGB_MATRIX_EFFECT(yae_miko_breathe)

// Step 2.
// Define effects inside the `RGB_MATRIX_CUSTOM_EFFECT_IMPLS` ifdef block
#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

#include "os_detection.h"
#include "rgb_matrix_types.h"

// #define ROW0_H 253
// #define ROW1_H 253
// #define ROW2_H 255
// #define ROW3_H 255
// #define ROW4_H 255
// #define ROW5_H 255

// #define ROW0_H_OSX 220
// #define ROW1_H_OSX 223
// #define ROW2_H_OSX 225
// #define ROW3_H_OSX 225
// #define ROW4_H_OSX 225
// #define ROW5_H_OSX 225

// #define ROW0_S 255
// #define ROW1_S 230
// #define ROW2_S 150
// #define ROW3_S 90
// #define ROW4_S 50
// #define ROW5_S 20


// static uint8_t changeHueBasedOnValue(uint8_t hue, uint8_t v) {
//     if ( v > 230) {
//         return hue;
//     } else if ( v < 25 ) {
//         return hue - 14;
//     } else if ( v < 30 ) {
//         return hue - 12;
//     } else if ( v < 50 ) {
//         return hue - 10;
//     } else if ( v < 70 ) {
//         return hue - 9;
//     } else if ( v < 90 ) {
//         return hue - 8;
//     } else if ( v < 110 ) {
//         return hue - 7;
//     } else if ( v < 130 ) {
//         return hue - 6;
//     } else if ( v < 150 ) {
//         return hue - 5;
//     } else if ( v < 170 ) {
//         return hue - 4;
//     } else if ( v < 190 ) {
//         return hue - 3;
//     } else if ( v < 210 ) {
//         return hue - 2;
//     } else {
//         return hue - 1;
//     }
// }

// static void put_yae_miko_schema(uint8_t i, RGB Row0, RGB Row1, RGB Row2, RGB Row3, RGB Row4, RGB Row5) {
//     if (!rgb_matrix_is_enabled()) {
//         rgb_matrix_set_color(i, 0, 0, 0);
//         return;
//     }
//     if (i < 1) {
//         rgb_matrix_set_color(i, Row0.r, Row0.g, Row0.b);
//     }
//     else if (i<14) {
//         rgb_matrix_set_color(i, Row5.r, Row5.g, Row5.b);
//     } else if (i<29) {
//         rgb_matrix_set_color(i, Row4.r, Row4.g, Row4.b);
//     }
//     else if (i<44) {
//         rgb_matrix_set_color(i, Row3.r, Row3.g, Row3.b);
//     }
//     else if (i<59) {
//         rgb_matrix_set_color(i, Row2.r, Row2.g, Row2.b);
//     }
//     else if (i<74) {
//         rgb_matrix_set_color(i, Row1.r, Row1.g, Row1.b);
//     }
//     else {
//         rgb_matrix_set_color(i, Row0.r, Row0.g, Row0.b);
//     }
// }
// static bool yae_miko_breathe(effect_params_t* params) {
//     RGB_MATRIX_USE_LIMITS(led_min, led_max);

//     uint16_t time = scale16by8(g_rgb_timer, rgb_matrix_config.speed / 8);
//     uint8_t pulseDepthModifier = rgb_matrix_config.hsv.s;
//     uint8_t pulse_mult, pulse_div, pulse_add;

//     if (pulseDepthModifier > 225) {
//         pulse_mult = 2;
//         pulse_div = 1;
//         pulse_add = 0;
//     } else if (pulseDepthModifier > 200) {
//         pulse_add = 32;
//         pulse_mult = 7;
//         pulse_div = 4;
//     } else if (pulseDepthModifier > 175) {
//         pulse_add = 64;
//         pulse_mult = 3;
//         pulse_div = 2;
//     } else if (pulseDepthModifier > 150) {
//         pulse_add = 96;
//         pulse_mult = 5;
//         pulse_div = 4;
//     } else if (pulseDepthModifier > 125) {
//         pulse_add = 128;
//         pulse_mult = 1;
//         pulse_div = 1;
//     } else if (pulseDepthModifier > 100) {
//         pulse_add = 160;
//         pulse_mult = 3;
//         pulse_div = 4;
//     } else if (pulseDepthModifier > 75) {
//         pulse_add = 192;
//         pulse_mult = 1;
//         pulse_div = 2;
//     } else if (pulseDepthModifier > 50) {
//         pulse_add = 224;
//         pulse_mult = 1;
//         pulse_div = 4;
//     } else {
//         pulse_mult = 0;
//         pulse_div = 0;
//         pulse_add = 255;
//     }

//     uint8_t v = scale8(abs8(sin8(time) - 128) * pulse_mult / pulse_div + pulse_add, rgb_matrix_config.hsv.v);

//     os_variant_t os = detected_host_os();
//     RGB Row0, Row1, Row2, Row3, Row4, Row5;
//     if (os != OS_MACOS) {
//         Row0 = rgb_matrix_hsv_to_rgb((HSV){changeHueBasedOnValue(ROW0_H, v), ROW0_S, v});
//         Row1 = rgb_matrix_hsv_to_rgb((HSV){changeHueBasedOnValue(ROW1_H, v), ROW1_S, v});
//         Row2 = rgb_matrix_hsv_to_rgb((HSV){changeHueBasedOnValue(ROW2_H, v), ROW2_S, v});
//         Row3 = rgb_matrix_hsv_to_rgb((HSV){changeHueBasedOnValue(ROW3_H, v), ROW3_S, v});
//         Row4 = rgb_matrix_hsv_to_rgb((HSV){changeHueBasedOnValue(ROW4_H, v), ROW4_S, v});
//         Row5 = rgb_matrix_hsv_to_rgb((HSV){changeHueBasedOnValue(ROW5_H, v), ROW5_S, v});
//     } else {
//         Row0 = rgb_matrix_hsv_to_rgb((HSV){changeHueBasedOnValue(ROW0_H_OSX, v), ROW0_S, v});
//         Row1 = rgb_matrix_hsv_to_rgb((HSV){changeHueBasedOnValue(ROW1_H_OSX, v), ROW1_S, v});
//         Row2 = rgb_matrix_hsv_to_rgb((HSV){changeHueBasedOnValue(ROW2_H_OSX, v), ROW2_S, v});
//         Row3 = rgb_matrix_hsv_to_rgb((HSV){changeHueBasedOnValue(ROW3_H_OSX, v), ROW3_S, v});
//         Row4 = rgb_matrix_hsv_to_rgb((HSV){changeHueBasedOnValue(ROW4_H_OSX, v), ROW4_S, v});
//         Row5 = rgb_matrix_hsv_to_rgb((HSV){changeHueBasedOnValue(ROW5_H_OSX, v), ROW5_S, v});
//     }

//     for (uint8_t i = led_min; i < led_max; i++) {
//         RGB_MATRIX_TEST_LED_FLAGS();
//         put_yae_miko_schema(i, Row0, Row1, Row2, Row3, Row4, Row5);
//     }
//     return rgb_matrix_check_finished_leds(led_max);
// }

static bool yae_miko_breathe(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);

    uint16_t time = scale16by8(g_rgb_timer, rgb_matrix_config.speed / 8);
    uint8_t pulseDepthModifier = rgb_matrix_config.hsv.s;
    uint8_t pulse_mult, pulse_div, pulse_add;

    if (pulseDepthModifier > 225) {
        pulse_mult = 2;
        pulse_div = 1;
        pulse_add = 0;
    } else if (pulseDepthModifier > 200) {
        pulse_add = 32;
        pulse_mult = 7;
        pulse_div = 4;
    } else if (pulseDepthModifier > 175) {
        pulse_add = 64;
        pulse_mult = 3;
        pulse_div = 2;
    } else if (pulseDepthModifier > 150) {
        pulse_add = 96;
        pulse_mult = 5;
        pulse_div = 4;
    } else if (pulseDepthModifier > 125) {
        pulse_add = 128;
        pulse_mult = 1;
        pulse_div = 1;
    } else if (pulseDepthModifier > 100) {
        pulse_add = 160;
        pulse_mult = 3;
        pulse_div = 4;
    } else if (pulseDepthModifier > 75) {
        pulse_add = 192;
        pulse_mult = 1;
        pulse_div = 2;
    } else if (pulseDepthModifier > 50) {
        pulse_add = 224;
        pulse_mult = 1;
        pulse_div = 4;
    } else {
        pulse_mult = 0;
        pulse_div = 0;
        pulse_add = 255;
    }

    uint8_t v = scale8(abs8(sin8(time) - 128) * pulse_mult / pulse_div + pulse_add, rgb_matrix_config.hsv.v);

    // os_variant_t os = detected_host_os();
    // RGB Row0, Row1, Row2, Row3, Row4, Row5;
    // if (os != OS_MACOS) {
    //     Row0 = rgb_matrix_hsv_to_rgb((HSV){changeHueBasedOnValue(ROW0_H, v), ROW0_S, v});
    //     Row1 = rgb_matrix_hsv_to_rgb((HSV){changeHueBasedOnValue(ROW1_H, v), ROW1_S, v});
    //     Row2 = rgb_matrix_hsv_to_rgb((HSV){changeHueBasedOnValue(ROW2_H, v), ROW2_S, v});
    //     Row3 = rgb_matrix_hsv_to_rgb((HSV){changeHueBasedOnValue(ROW3_H, v), ROW3_S, v});
    //     Row4 = rgb_matrix_hsv_to_rgb((HSV){changeHueBasedOnValue(ROW4_H, v), ROW4_S, v});
    //     Row5 = rgb_matrix_hsv_to_rgb((HSV){changeHueBasedOnValue(ROW5_H, v), ROW5_S, v});
    // } else {
    //     Row0 = rgb_matrix_hsv_to_rgb((HSV){changeHueBasedOnValue(ROW0_H_OSX, v), ROW0_S, v});
    //     Row1 = rgb_matrix_hsv_to_rgb((HSV){changeHueBasedOnValue(ROW1_H_OSX, v), ROW1_S, v});
    //     Row2 = rgb_matrix_hsv_to_rgb((HSV){changeHueBasedOnValue(ROW2_H_OSX, v), ROW2_S, v});
    //     Row3 = rgb_matrix_hsv_to_rgb((HSV){changeHueBasedOnValue(ROW3_H_OSX, v), ROW3_S, v});
    //     Row4 = rgb_matrix_hsv_to_rgb((HSV){changeHueBasedOnValue(ROW4_H_OSX, v), ROW4_S, v});
    //     Row5 = rgb_matrix_hsv_to_rgb((HSV){changeHueBasedOnValue(ROW5_H_OSX, v), ROW5_S, v});
    // }
//  unsigned char v = rgb_matrix_config.hsv.v;
#define HALF_OFFSET 27
#define HOFF(i, lowerInclusive, upperExclusive) (((i) >= lowerInclusive && (i) < upperExclusive) || (((i) >= (lowerInclusive + HALF_OFFSET)) && ((i)< (upperExclusive+HALF_OFFSET)) ))
#define isBacklight(i) HOFF(i, 0, 6)
    for (uint8_t i = led_min; i < led_max; i++) {
        RGB_MATRIX_TEST_LED_FLAGS();
        // if (is_keyboard_master()) {
            // put_yae_miko_schema(i, Row0, Row1, Row2, Row3, Row4, Row5);
            if (isBacklight(i)) {
                RGB color  = rgb_matrix_hsv_to_rgb((HSV){180, 255, v});
                rgb_matrix_set_color(i, color.r, color.g, color.b);
            } else {
                uint8_t index = i > HALF_OFFSET ? i : i + HALF_OFFSET;
                RGB color  = rgb_matrix_hsv_to_rgb((HSV){5*index, 255, v});
                rgb_matrix_set_color(i, color.r, color.g, color.b);
            }

        // } else {
            // rgb_matrix_set_color(i, color.r, color.g, color.b);
        // }
        //  else {
        //         if (i < 6) {
        //         rgb_matrix_set_color(i, 255, 0, 0);
        //     } else if (i < 12) {
        //         rgb_matrix_set_color(i, 0, 255, 0);
        //     } else if (i < 15) {
        //         rgb_matrix_set_color(i, 0, 0, 255);
        //     } else if (i < 20) {
        //         rgb_matrix_set_color(i, 255, 0, 255);
        //     }else if (i < 25) {
        //         rgb_matrix_set_color(i, 0, 255, 255);
        //     }else if (i < 30) {
        //         rgb_matrix_set_color(i, 255, 255, 0);
        //     }else {
        //         rgb_matrix_set_color(i, 50, 50, 50);
        //     }
        // }
    }
    return rgb_matrix_check_finished_leds(led_max);
}


#endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
