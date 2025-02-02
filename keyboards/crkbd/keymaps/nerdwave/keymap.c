/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "./nerdwave.h"
// Left-hand home row mods
#define HOME_A LGUI_T(KC_A)
#define HOME_O LALT_T(KC_O)
#define HOME_E LCTL_T(KC_E)
#define HOME_U LSFT_T(KC_U)

// Right-hand home row mods
#define HOME_H RSFT_T(KC_H)
#define HOME_T RCTL_T(KC_T)
#define HOME_N LALT_T(KC_N)
#define HOME_S RGUI_T(KC_S)

#define MED_ESC LT(LMEDIA, KC_ESC)
#define NAV_SPC LT(LNAV, KC_SPC)
#define MOUSE_TAB LT(LMOUSE, KC_TAB)
#define SYM_ENT LT(LSYM, KC_ENT)
#define NUM_BSP LT(LNUM, KC_BSPC)
#define FN_DEL LT(LFN, KC_DEL)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [LBASE] = LAYOUT_split_3x6_3(
       //,--------------------------------------------.                    ,--------------------------------------------.
XXXXXXX,   KC_QUOT, KC_COMM,  KC_DOT,    KC_P,    KC_Y,                         KC_F,    KC_G,    KC_C,    KC_R,    KC_L, XXXXXXX,
       //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
XXXXXXX,    HOME_A,  HOME_O,  HOME_E,   HOME_U,   KC_I,     /*#####*/           KC_D,  HOME_H,  HOME_T,  HOME_N,  HOME_S, XXXXXXX,
       //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
XXXXXXX,   KC_SLSH,    KC_Q,    KC_J,    KC_K,    KC_X,                         KC_B,    KC_M,    KC_W,    KC_V,    KC_Z, XXXXXXX,
       //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                             MED_ESC, NAV_SPC,MOUSE_TAB,                     SYM_ENT, NUM_BSP,  FN_DEL
                          //|----------------------------------|  |-----------------------------|
  ),

    [LGAMING] = LAYOUT_split_3x6_3(
        //,--------------------------------------------.                    ,--------------------------------------------.
XXXXXXX,     KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,                         KC_I, XXXXXXX, XXXXXXX, XXXXXXX,TO(LBASE),  XXXXXXX,
        //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
XXXXXXX,    KC_LSFT,    KC_A,    KC_S,    KC_D,    KC_F,                         KC_L, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,
        //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
XXXXXXX,    KC_LCTL,    KC_1,    KC_2,    KC_3,    KC_4,                         KC_M, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,
        //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                              KC_LALT,KC_SPACE,    KC_V,                        KC_F4,   KC_F5,  KC_ESC
  //                           |--------------------------------|  |--------------------------'
  ),

    [LNAV] = LAYOUT_split_3x6_3(
  //,--------------------------------------------.                    ,--------------------------------------------.
     XXXXXXX,    C(KC_X), C(KC_C), C(KC_V),XXXXXXX, XXXXXXX,                   C(S(KC_Z)), C(KC_V), C(KC_C), C(KC_X), C(KC_Z),  XXXXXXX,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
  XXXXXXX,       KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,                      KC_CAPS, KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT,  XXXXXXX,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
       XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                    KC_INS,KC_HOME,KC_PAGE_DOWN,KC_PAGE_UP,KC_END,  XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                XXXXXXX, _______,  XXXXXXX,    KC_ENT, KC_BSPC, KC_DEL
  //                           '--------------------------'  '--------------------------'
  ),

    [LMOUSE] = LAYOUT_split_3x6_3(
  //,--------------------------------------------.                    ,--------------------------------------------.
       XXXXXXX,    C(KC_X), C(KC_C), C(KC_V),XXXXXXX, XXXXXXX,                    C(S(KC_Z)), C(KC_V), C(KC_C), C(KC_X), C(KC_Z),  XXXXXXX,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
     XXXXXXX,    KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,                      XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R,  XXXXXXX,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R,  XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                XXXXXXX, XXXXXXX,  _______,     KC_BTN1, KC_BTN2, KC_BTN3
  //                           '--------------------------'  '--------------------------'
  ),

    [LMEDIA] = LAYOUT_split_3x6_3(
  //,--------------------------------------------.                    ,--------------------------------------------.
     XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      RGB_TOG, RGB_SPI, RGB_HUI, RGB_SAI, RGB_VAI,  XXXXXXX,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      XXXXXXX,   KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,                      RGB_MOD, KC_MPRV, KC_MSTP, KC_MPLY, KC_MNXT,  XXXXXXX,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                _______, XXXXXXX,  XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX
  //                           '--------------------------'  '--------------------------'
  ),

    [LNUM] = LAYOUT_split_3x6_3(
  //,--------------------------------------------.                    ,--------------------------------------------.
      XXXXXXX,   KC_LBRC,    KC_7,    KC_8,    KC_9, KC_RBRC,                      QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, TO(LGAMING),  XXXXXXX,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
   XXXXXXX, KC_SEMICOLON,    KC_4,    KC_5,    KC_6,  KC_EQL,                      XXXXXXX, KC_RSFT, KC_RCTL, KC_RALT, KC_LGUI,  XXXXXXX,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
     XXXXXXX,   KC_GRAVE,    KC_1,    KC_2,    KC_3, KC_BSLS,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                  KC_DOT,    KC_0,KC_MINUS,    XXXXXXX, _______, XXXXXXX
  //                           '--------------------------'  '--------------------------'
  ),

    [LSYM] = LAYOUT_split_3x6_3(
  //,--------------------------------------------.                    ,--------------------------------------------.
   XXXXXXX,   S(KC_LBRC), S(KC_7), S(KC_8), S(KC_9),S(KC_RBRC),                    QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, TO(LGAMING),  XXXXXXX,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
      XXXXXXX,   KC_COLN, S(KC_4), S(KC_5), S(KC_6),S(KC_EQL),                     XXXXXXX, KC_RSFT, KC_RCTL, KC_RALT, KC_LGUI,  XXXXXXX,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
    XXXXXXX, S(KC_GRAVE), S(KC_1), S(KC_2), S(KC_3),S(KC_BSLS),                    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                              S(KC_9), S(KC_0),S(KC_MINUS),    _______, XXXXXXX, XXXXXXX
  //                           '--------------------------'  '--------------------------'
  ),

    [LFN] = LAYOUT_split_3x6_3(
  //,--------------------------------------------.                    ,--------------------------------------------.
       XXXXXXX,   KC_F12,   KC_F7,   KC_F8,   KC_F9, KC_PSCR,                      QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, TO(LGAMING),  XXXXXXX,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
        XXXXXXX,  KC_F11,   KC_F4,   KC_F5,   KC_F6, KC_SCRL,                     XXXXXXX, KC_RSFT, KC_RCTL, KC_RALT, KC_LGUI,  XXXXXXX,
  //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
        XXXXXXX,  KC_F10,   KC_F1,   KC_F2,   KC_F3, KC_PAUS,                    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                  KC_APP,KC_SPACE,  KC_TAB,    XXXXXXX, XXXXXXX, _______
  //                           '--------------------------'  '--------------------------'
  )
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    #ifdef OLED_ENABLE
    oled_process_record_user_oled(keycode, record);
    #endif
    return true;
}

uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t *record) {
switch (keycode) {
case LT(LMEDIA, KC_ESC):
case LT(LNAV, KC_SPC):
case LT(LMOUSE,KC_TAB):
case LT(LSYM, KC_ENT):
case LT(LNUM, KC_BSPC):
case LT(LFN,KC_DEL):
return 0;
default:
return QUICK_TAP_TERM;
}
}

#ifdef RGB_MATRIX_ENABLE
void keyboard_post_init_user(void) {
rgblight_enable_noeeprom(); // enables Rgb, without saving settings
rgblight_sethsv_noeeprom(0, 150, 255);
rgblight_set_speed_noeeprom(70); // sets speed to 255
rgblight_mode_noeeprom(2); // sets mode to Fast breathing without saving
}
#endif

bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
switch (keycode) {
case HOME_A:
case HOME_O:
case HOME_E:
case HOME_T:
case HOME_N:
case HOME_S:
return false;
default:
// Do not select the hold action when another key is tapped.
return true;
}
}
