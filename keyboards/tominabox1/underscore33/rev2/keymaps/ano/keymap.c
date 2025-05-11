/* Copyright 2020 tominabox1
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H

enum custom_keycodes {
  OS_LMEH = SAFE_RANGE,
  OS_LSFT
};

#include "features/nshot_mod.h"
// #include "./nshot.c"

enum layers{
  _BASE,
  _NUM,
  _WIN,
  _SYM,
  _NAV
};

#define SPC LT(_SYM, KC_SPC)
#define R LT(_NAV, KC_R)
#define C_BSPC C(KC_BSPC)
#define M LT(_WIN, KC_M)
#define D LT(_NUM, KC_D)
#define MAGI OS_LSFT

#define MT_CN LCTL_T(KC_N)
#define MT_AS LALT_T(KC_S)
#define MT_GH LGUI_T(KC_H)
#define MT_SC LSFT_T(KC_C)

#define MT_ST RSFT_T(KC_T)
#define MT_GE RGUI_T(KC_E)
#define MT_AA RALT_T(KC_A)
#define MT_CI RCTL_T(KC_I)

#define WM_01 G(KC_1)
#define WM_02 G(KC_2)
#define WM_03 G(KC_3)
#define WM_04 G(KC_4)
#define WM_05 G(KC_5)

enum combo_events {
  COMBO_BSPC,
  COMBO_NUMBAK,
  COMBO_TAB,
  COMBO_ESC,
  COMBO_DEL,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_33_split_space(
        KC_B   , KC_F   , KC_L   , KC_Q   , _______, _______, KC_V   , KC_U   , KC_O   , KC_Y   ,
        MT_CN  , MT_AS  , MT_GH  , MT_SC  , KC_P   , MAGI   , MT_ST  , MT_GE  , MT_AA  , MT_CI  ,
        KC_X   , KC_Z   , KC_K   , KC_W   , KC_G   , M      , D      , _______, _______, _______,
                          _______, _______, R      , SPC    , OS_LSFT, _______
    ),

    [_SYM] = LAYOUT_33_split_space(
        KC_1   , KC_2   , KC_3   , _______, _______, _______, _______, KC_8   , KC_9   , KC_0   ,
        KC_EXLM, KC_AT  , KC_HASH, KC_DLR , KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_EQUAL, KC_MINS,
        _______, _______, _______, KC_LPRN, KC_UNDS, KC_RPRN, KC_RBRC, _______, _______, _______,
                          _______, _______, _______, _______, _______, _______
    ),

    [_NAV] = LAYOUT_33_split_space(
        KC_PSCR, KC_NO  , _______, _______, QK_BOOT, KC_GRV , KC_PGDN, KC_UP  , KC_PGUP, KC_BSPC,
        KC_LCTL, KC_LALT, KC_LCMD, KC_LSFT, KC_NO  , KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_END ,
        _______, _______, _______, _______, KC_NO  , KC_MINS, KC_INT1, KC_COMM, KC_DOT , KC_BSLS,
                          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),

    [_WIN] = LAYOUT_33_split_space(
        _______, _______, _______, _______, KC_NO  , KC_GRV , KC_PGDN, KC_UP  , KC_PGUP, KC_SCLN,
        WM_05  , WM_03  , WM_02  , WM_01  , KC_NO  , KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_END ,
        _______, _______, _______, WM_04  , KC_NO  , _______, KC_INT1, KC_COMM, KC_DOT , KC_BSLS,
                          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),
    
    [_NUM] = LAYOUT_33_split_space(
        _______, KC_6   , KC_5   , _______, _______, KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,
        _______, KC_3   , KC_2   , KC_1   , _______, KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,
        _______, _______, _______, KC_4   , _______, KC_NO  , _______, KC_NO  , KC_NO  , KC_NO  ,
                          KC_TRNS, KC_TRNS, KC_0   , KC_TRNS, KC_TRNS, KC_TRNS
    ),
};


#ifdef COMBO_ENABLE
const uint16_t PROGMEM combo_bspc[] = {KC_O, KC_P, COMBO_END};
const uint16_t PROGMEM combo_numbak[] = {KC_0, KC_9, COMBO_END};
const uint16_t PROGMEM combo_tab[] = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM combo_esc[] = {KC_E, KC_W, COMBO_END};
const uint16_t PROGMEM combo_del[] = {KC_MINS, KC_EQL, COMBO_END};

combo_t key_combos[] = {
    [COMBO_BSPC] = COMBO(combo_bspc,KC_BSPC),
    [COMBO_NUMBAK] = COMBO(combo_numbak,KC_BSPC),
    [COMBO_TAB] = COMBO(combo_tab,KC_TAB),
    [COMBO_ESC] = COMBO(combo_esc,KC_ESC),
    [COMBO_DEL] = COMBO(combo_del,KC_DEL),
  
};
#endif
  
void leader_start_user(void) {
    // Do something when the leader key is pressed
}

void leader_end_user(void) {
    if (leader_sequence_one_key(KC_N)) {
        // Leader, f => Types the below string
        SEND_STRING("x");
    } else if (leader_sequence_one_key(KC_S)) {
        // Leader, f => Types the below string
        SEND_STRING("v");
    } else if (leader_sequence_one_key(KC_H)) {
        // Leader, f => Types the below string
        SEND_STRING("k");
    } 
}
