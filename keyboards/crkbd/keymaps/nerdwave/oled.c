
#ifdef OLED_ENABLE

#include "./nerdwave.h"
#include "./bongocat.h"

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master())
    return OLED_ROTATION_270;
    else return OLED_ROTATION_180;
}

// uint32_t anim_timer         = 0;
// uint32_t anim_sleep         = 0;
// uint8_t  current_idle_frame = 0;

// bool tap_anim        = false;
// bool tap_anim_toggle = false;

// void render_crkbd_logo(void) {
//     static const char PROGMEM crkbd_logo[] = {
//         0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
//         0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
//         0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
//         0};
//     oled_write_P(crkbd_logo, false);
// }

char     keylog_str[KEYLOG_LEN+1] = "     ";
uint8_t  keylogs_str_idx        = 0;
uint16_t log_timer              = 0;

const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

void add_keylog(uint16_t keycode) {
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) || (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) {
        keycode = keycode & 0xFF;
    }

    for (uint8_t i = KEYLOG_LEN ; i > 0; i--) {
        keylog_str[i] = keylog_str[i - 1];
    }
    if (keycode < 60) {
        keylog_str[0] = code_to_name[keycode];
    }
    keylog_str[KEYLOG_LEN ] = 0;

    log_timer = timer_read();
}

void update_log(void) {
    if (timer_elapsed(log_timer) > 750) {
        add_keylog(0);
    }
}
void render_keylogger_status(void) {
    oled_write_P(PSTR("klogr"), false);
    oled_write(keylog_str, false);
    oled_write_char('\n', false);
}

void render_default_layer_state(void) {
    oled_write_P(PSTR("blyr "), false);
    if (!layer_state_is(LGAMING)) {
        oled_write_P(PSTR(" BASE\n"), false);
    } else {
        oled_write_P(PSTR(" GMNG\n"), true);
    }
}

void render_mod_status(uint8_t modifiers) {
    oled_write_P(PSTR("mods "), false);
    oled_write_P(PSTR(" "), false);
    oled_write_P(PSTR("S"), (modifiers & MOD_MASK_SHIFT));
    oled_write_P(PSTR("C"), (modifiers & MOD_MASK_CTRL));
    oled_write_P(PSTR("A"), (modifiers & MOD_MASK_ALT));
    oled_write_P(PSTR("G"), (modifiers & MOD_MASK_GUI));
    oled_write_char('\n', false);
}

static void render_layer_state(void) {
    oled_write_P(PSTR("lyr  "), false);
    if (layer_state_is(LNAV)) {
        oled_write_P(PSTR("  NAV"), true);
    }
    else if (layer_state_is(LMOUSE)) {
        oled_write_P(PSTR("MOUSE"), true);
    }
    else if (layer_state_is(LMEDIA)) {
        oled_write_P(PSTR("MEDIA"), true);
    }
    else if (layer_state_is(LNUM)) {
        oled_write_P(PSTR("  NUM"), true);
    }
    else if (layer_state_is(LSYM)) {
        oled_write_P(PSTR("  SYM"), true);
    }
    else if (layer_state_is(LFN)) {
        oled_write_P(PSTR("   FN"), true);
    }else {
        oled_write_P(PSTR("     "), false);
    }
}

void render_status_main(void) {
    /* Show Keyboard Layout  */
    render_default_layer_state();
    // render_layer_state();
    // render_keylock_status(host_keyboard_led_state());
    render_mod_status(get_mods());

    render_keylogger_status();

    render_layer_state();


}

// // Idle animation
// void animation_phase(void) {
//     if (!tap_anim) {
//         current_idle_frame = (current_idle_frame + 1) % NUM_IDLE_FRAMES;
//         uint8_t idx = abs((NUM_IDLE_FRAMES - 1) - current_idle_frame);
//         oled_write_compressed_P(idle_block_map[idx], idle_frames[idx]);
//     }
// }

static const char numbers[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
static void print_wpm(uint16_t wpm) {
    uint8_t digit = 0;
    char   buf[5] = {'0', '0', '0', '0', '\0'};
    uint8_t index = 4;
    oled_write_P(PSTR(" "), false);
    while (wpm != 0 && index != 0) {

        // Extract the last digit of N
        digit = wpm % 10;
        buf[--index] = numbers[digit];
        // Update N to N/10 to extract
        // next last digit
        wpm = wpm / 10;
    }
    oled_write(buf, false);
    oled_set_cursor(0,0);
}

// static void render_anim(void) {
//     uint16_t wpm = get_current_wpm();
//     if (wpm > 10) {
//         oled_on();
//         if (timer_elapsed32(anim_timer) > (IDLE_FRAME_DURATION + 4000/wpm * 2)) {
//                 anim_timer = timer_read32();
//                 tap_anim_toggle = !tap_anim_toggle;
//                 oled_write_compressed_P(tap_block_map[tap_anim_toggle], tap_frames[tap_anim_toggle]);
//         }
//     } else if (wpm > 000) {  // prevent sleep
//     // Idle behaviour
//         oled_on();
//         if (timer_elapsed32(anim_timer) > IDLE_FRAME_DURATION) {
//             anim_timer = timer_read32();
//             animation_phase();
//         }
//         anim_sleep = timer_read32();
//     } else {  // Turn off screen when timer threshold elapsed or reset time since last input
//         if (timer_elapsed32(anim_sleep) > OLED_TIMEOUT) {
//             oled_off();
//         } else {
//             if (timer_elapsed32(anim_timer) > IDLE_FRAME_DURATION) {
//                 anim_timer = timer_read32();
//                 animation_phase();
//             }
//         }
//     }
// }

bool oled_task_user(void) {
    update_log();
    if (is_keyboard_master()) {
        render_status_main();  // Renders the current keyboard state (layer, lock, caps, scroll, etc)
    }
    else {
        print_wpm(get_current_wpm());
        draw_bongo_table();
        draw_bongocat();
//     uint16_t wpm = get_current_wpm();
    }
    return false;
}

void oled_process_record_user_oled(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        add_keylog(keycode);
    }
    // #ifdef OLED_ENABLE
    //     // Check if non-mod
    //     if ((keycode >= KC_A && keycode <= KC_0) || (keycode >= KC_TAB && keycode <= KC_SLASH)) {
    //         if (record->event.pressed) {
    //             // Display tap frames
    //         }
    //     }eseseseseseseseseseseseesesessesesessesesesesesesesesesseseesesesesesesesesesese
    // #endif
}
#endif
