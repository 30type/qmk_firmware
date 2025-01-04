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

enum layers{
  _BASE,
  _SYM,
  _NAV,
  _NUM
};

#define LT_TAB LT(_NUM, KC_TAB)
#define LT_SPC LT(_SYM, KC_SPC)
#define MT_LSFT LSFT_T(KC_ESC)
#define FN_NAV MO(_NAV)
#define LT_CN LCTL_T(KC_N)
#define LT_AS LOPT_T(KC_S)
#define LT_GT LCMD_T(KC_T)
#define LT_SD LSFT_T(KC_D)
#define LT_SR RSFT_T(KC_R)
#define LT_GA RCMD_T(KC_A)
#define LT_AE ROPT_T(KC_E)
#define LT_CI RCTL_T(KC_I)

enum combo_events {
  COMBO_TAB,
  COMBO_ESC,
  COMBO_ENT,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_33_split_space(
    KC_V,    KC_F,    KC_M,    KC_W,    KC_G,    KC_X,    KC_J,    KC_O,    KC_U,    KC_COMM,
    LT_CN,   LT_AS,   LT_GT,   LT_SD,   KC_Y,    KC_H,    LT_SR,   LT_GA,   LT_AE,   LT_CI,
    KC_B,    KC_Z,    KC_K,    KC_C,    KC_P,    KC_Q,    KC_L,    KC_QUOT, KC_SLSH, KC_DOT,
                      KC_NO,   FN_NAV,  MT_LSFT, LT_SPC,  LT_TAB,  KC_NO
  ),

  [_SYM] = LAYOUT_33_split_space(
    KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_EQL,  KC_GRV,  KC_COLN, KC_SCLN, KC_PLUS,
    KC_LCTL, KC_LOPT, KC_LCMD, KC_LSFT, KC_CIRC, KC_ASTR, KC_LPRN, KC_LCBR, KC_LBRC, KC_MINS,
    KC_NO,   KC_NO,   KC_BSLS, KC_PIPE, KC_AMPR, KC_TILD, KC_RPRN, KC_RCBR, KC_RBRC, KC_UNDS,
                      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  ),

  [_NAV] = LAYOUT_33_split_space(
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
    KC_LCTL, KC_LOPT, KC_LCMD, KC_LSFT, KC_NO,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_DEL,
    QK_BOOT, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_BSPC, KC_TAB,  KC_NO,   KC_NO,
                      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  ),

  [_NUM] = LAYOUT_33_split_space(
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  ),
};


#ifdef COMBO_ENABLE
const uint16_t PROGMEM combo_tab[] = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM combo_esc[] = {KC_E, KC_W, COMBO_END};
const uint16_t PROGMEM combo_ent[] = {FN_NAV, LT_TAB, COMBO_END};

combo_t key_combos[] = {
  [COMBO_TAB] = COMBO(combo_tab,KC_TAB),
  [COMBO_ESC] = COMBO(combo_esc,KC_ESC),
  [COMBO_ENT] = COMBO(combo_ent,KC_ENT),

};
#endif
