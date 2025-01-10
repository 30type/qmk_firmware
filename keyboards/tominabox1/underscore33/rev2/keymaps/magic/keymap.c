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
  _EEP,
};

#define QK_MAGI QK_AREP
#define LT_SPC LT(_SYM, KC_SPC)
#define MT_LSFT OSM(MOD_LSFT)
#define FN_NAV LT(_NAV, KC_ESC)
#define LT_L LCTL_T(KC_L)
#define LT_A LOPT_T(KC_A)
#define LT_T LCMD_T(KC_T)
#define LT_C LSFT_T(KC_C)
#define LT_I RCMD_T(KC_I)
#define LT_E ROPT_T(KC_E)
#define LT_O RCTL_T(KC_O)

enum combo_events {
  COMBO_ENT,
  COMBO_EEP,
  COMBO_CAP,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_33_split_space(
    KC_D,    KC_N,    KC_S,    KC_Y,    KC_DOT,  KC_COMM, KC_P,    KC_R,    KC_H,    KC_U,
    LT_L,    LT_A,    LT_T,    LT_C,    KC_G,    KC_V,    QK_MAGI, LT_I,    LT_E,    LT_O,
    KC_NO,   KC_Z,    KC_F,    KC_B,    KC_M,    KC_K,    KC_W,    KC_J,    KC_Q,    KC_X,
                      KC_NO,   MT_LSFT, FN_NAV,  LT_SPC,  KC_TAB,  KC_NO
  ),

  [_SYM] = LAYOUT_33_split_space(
    KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_EQL,  KC_GRV,  KC_COLN, KC_TILD, KC_PLUS,
    KC_COMM, KC_DOT,  KC_SLSH, KC_ASTR, KC_CIRC, KC_LBRC, KC_LPRN, KC_LCBR, KC_DQUO, KC_MINS,
    KC_LT,   KC_GT,   KC_BSLS, KC_PIPE, KC_AMPR, KC_RBRC, KC_RPRN, KC_RCBR, KC_QUOT, KC_UNDS,
                      KC_TRNS, KC_TRNS, KC_SCLN, KC_TRNS, KC_TRNS, KC_TRNS
  ),

  [_NAV] = LAYOUT_33_split_space(
    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
    KC_LCTL, KC_LOPT, KC_LCMD, KC_LSFT, KC_NO,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_DEL,
    QK_BOOT, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_BSPC, KC_TAB,  KC_NO,   KC_NO,
                      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  ),

  [_EEP] = LAYOUT_33_split_space(
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO
  ),
};


#ifdef COMBO_ENABLE
const uint16_t PROGMEM combo_ent[] = {FN_NAV, LT_SPC, COMBO_END};
const uint16_t PROGMEM combo_eep[] = {KC_D, KC_N, KC_S, KC_W, COMBO_END};
const uint16_t PROGMEM combo_cap[] = {KC_B, KC_W, COMBO_END};

combo_t key_combos[] = {
  [COMBO_ENT] = COMBO(combo_ent,KC_ENTER),
  [COMBO_EEP] = COMBO(combo_eep,TG(_EEP)),
  [COMBO_CAP] = COMBO(combo_cap,CW_TOGG),
};
#endif

#ifdef COMBO_TERM_PER_COMBO
uint16_t get_combo_term(uint16_t combo_index, combo_t *combo) {
    // or with combo index, i.e. its name from enum.
    switch (combo_index) {
        case COMBO_ENT:
            return 1000;
    }
    return COMBO_TERM;
}
#endif

uint16_t get_alt_repeat_key_keycode_user(uint16_t keycode, uint8_t mods) {
  switch (keycode) {
    case KC_A: return KC_N;
    case KC_B: return KC_Y;
    case KC_C: return KC_K;
    case KC_D: return KC_L;
    case KC_E: return KC_H;
    case KC_F: return KC_T;
    case KC_G: return KC_NO;
    case KC_H: return KC_E;
    case KC_I: return KC_R;
    case KC_J: return KC_NO;
    case KC_K: return KC_NO;
    case KC_L: return KC_D;
    case KC_M: return KC_Y;
    case KC_N: return KC_A;
    case KC_O: return KC_U;
    case KC_P: return KC_NO;
    case KC_Q: return KC_U;
    case KC_R: return KC_I;
    case KC_S: return KC_T;
    case KC_T: return KC_S;
    case KC_U: return KC_NO;
    case KC_V: return KC_NO;
    case KC_W: return KC_NO;
    case KC_X: return KC_NO;
    case KC_Y: return KC_NO;
    case KC_Z: return KC_NO;
  }
  return KC_TRNS;
}
