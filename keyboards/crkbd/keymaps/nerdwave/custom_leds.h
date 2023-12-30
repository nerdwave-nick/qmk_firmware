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

#define HALF_OFFSET 27
#define HOFF(i, lowerInclusive, upperExclusive) (((i) >= lowerInclusive && (i) < upperExclusive) || (((i) >= (lowerInclusive + HALF_OFFSET)) && ((i)< (upperExclusive+HALF_OFFSET)) ))
#define isBacklight(i) HOFF(i, 0, 6)

int get_breath_v(uint8_t time, uint8_t pulseDepthModifier, uint8_t preScaledV) {
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

    return scale8(abs8(sin8(time) - 128) * pulse_mult / pulse_div + pulse_add, preScaledV);
}
#define BOTTOM_HUE_COUNT 6
#define BOTTOM_HUE_TIME 100
#define BOTTOM_HUE_MIN 179
#define BOTTOM_HUE_MAX 221
#define BOTTOM_HUE_DIFF ((BOTTOM_HUE_MAX - BOTTOM_HUE_MIN)/BOTTOM_HUE_COUNT)
int8_t bottom_hue_direction[BOTTOM_HUE_COUNT] = { 1, 1, 1, -1, -1, -1 };
uint8_t bottom_hue_list[BOTTOM_HUE_COUNT] = {
    BOTTOM_HUE_MIN,
    BOTTOM_HUE_MIN + 2*BOTTOM_HUE_DIFF,
    BOTTOM_HUE_MIN + 4*BOTTOM_HUE_DIFF,
    BOTTOM_HUE_MAX,
    BOTTOM_HUE_MAX - 2*BOTTOM_HUE_DIFF,
    BOTTOM_HUE_MAX - 4*BOTTOM_HUE_DIFF };
static uint8_t counter = 0;
void update_timer_and_hues(void) {
    uint8_t new_counter = (g_rgb_timer / BOTTOM_HUE_TIME);
    if (new_counter != counter) {
        counter = new_counter;
        for (uint8_t i = 0; i < BOTTOM_HUE_COUNT; i++) {
            bottom_hue_list[i]+=bottom_hue_direction[i];// = BOTTOM_HUE_OFFSET + (BOTTOM_HUE_MULT * (i + counter));
            if (bottom_hue_list[i] >= BOTTOM_HUE_MAX) {
                bottom_hue_direction[i]=-1;
            } else if (bottom_hue_list[i] <= BOTTOM_HUE_MIN) {
                bottom_hue_direction[i]=1;
            }
        }
    }
}
uint8_t get_bottom_hue(uint8_t index) {
    return bottom_hue_list[index];
}

static bool yae_miko_breathe(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);
    update_timer_and_hues();
    uint16_t time = scale16by8(g_rgb_timer, rgb_matrix_config.speed / 8);
    uint8_t pulseDepthModifier = rgb_matrix_config.hsv.s;
    uint8_t v = rgb_matrix_config.hsv.v;
    uint8_t breath_v = get_breath_v(time, pulseDepthModifier, v);

    RGB color;
    uint8_t index;
    for (uint8_t i = led_min; i < led_max; i++) {
        RGB_MATRIX_TEST_LED_FLAGS();
        index = i >= HALF_OFFSET ? i : i + HALF_OFFSET;
        if (isBacklight(i)) {
            color = rgb_matrix_hsv_to_rgb((HSV){get_bottom_hue(index-HALF_OFFSET), 255, breath_v});
        } else {
            color = rgb_matrix_hsv_to_rgb((HSV){5*index, 255, breath_v});
        }
        rgb_matrix_set_color(i, color.r, color.g, color.b);
    }
    return rgb_matrix_check_finished_leds(led_max);
}


#endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
