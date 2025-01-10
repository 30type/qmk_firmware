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
#include "features/achordion.h"
#include "features/orbital_mouse.h"

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
  if (!process_achordion(keycode, record)) { return false; }

  if (!process_orbital_mouse(keycode, record)) { return false; }
  // Your macros ...


  return true;
}

void matrix_scan_user(void) {
  achordion_task();
  orbital_mouse_task();

}

enum layers{
  _BASE,
  _SYM,
  _NAV,
  _MSE,
  _EEP,
};

#define LT_MSE MO(_MSE)
#define LT_SPC LT(_SYM, KC_SPC)
#define MT_LSFT OSM(MOD_LSFT)
#define FN_NAV LT(_NAV, KC_ESC)
#define LT_CN LCTL_T(KC_N)
#define LT_AS LOPT_T(KC_S)
#define LT_GT LCMD_T(KC_T)
#define LT_SY LSFT_T(KC_Y)
#define LT_SR RSFT_T(KC_R)
#define LT_GA RCMD_T(KC_A)
#define LT_AE ROPT_T(KC_E)
#define LT_CI RCTL_T(KC_I)

enum combo_events {
  COMBO_ENT,
  COMBO_EEP,
  COMBO_CAP,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_33_split_space(
    KC_Z,    KC_C,    KC_M,    KC_W,    KC_K,    KC_J,    KC_V,    KC_O,    KC_U,    KC_NO  ,
    LT_CN,   LT_AS,   LT_GT,   LT_SY,   KC_F,    KC_H,    LT_SR,   LT_GA,   LT_AE,   LT_CI  ,
    KC_B,    KC_NO,   KC_D,    KC_G,    KC_P,    KC_Q,    KC_L,    KC_X,    KC_NO,   LT_MSE ,
                      _______, MT_LSFT, FN_NAV , LT_SPC , LT_MSE , _______
  ),

  [_SYM] = LAYOUT_33_split_space(
    KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_EQL,  KC_GRV,  KC_COLN, KC_TILD, KC_PLUS,
    KC_COMM, KC_DOT,  KC_SLSH, KC_ASTR, KC_CIRC, KC_LBRC, KC_LPRN, KC_LCBR, KC_DQUO, KC_MINS,
    KC_LT,   KC_GT,   KC_BSLS, KC_PIPE, KC_AMPR, KC_RBRC, KC_RPRN, KC_RCBR, KC_QUOT, KC_UNDS,
                      _______, KC_TRNS, KC_SCLN, KC_TRNS, KC_TRNS, _______
  ),

  [_NAV] = LAYOUT_33_split_space(
    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
    KC_LCTL, KC_LOPT, KC_LCMD, KC_LSFT, KC_NO,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_DEL,
    QK_BOOT, _______, _______, _______, _______, _______, KC_BSPC, KC_TAB,  _______, _______,
                      _______, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, _______
  ),

  [_MSE] = LAYOUT_33_split_space(
    _______, OM_DBLS, OM_SEL1, OM_SEL2, OM_SEL3, _______, _______, _______, _______, _______,
    OM_SLOW, OM_L   , OM_U   , OM_R   , OM_W_U , _______, _______, _______, _______, _______,
    OM_RELS, OM_HLDS, OM_D   , OM_BTNS, OM_W_D , _______, _______, _______, _______, _______,
                      _______, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, _______
  ),

  [_EEP] = LAYOUT_33_split_space(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                      _______, _______, _______, _______, _______, _______
  ),
};


#ifdef COMBO_ENABLE
const uint16_t PROGMEM combo_ent[] = {FN_NAV, LT_SPC, COMBO_END};
const uint16_t PROGMEM combo_eep[] = {KC_Z, KC_C, KC_M, KC_W, COMBO_END};
const uint16_t PROGMEM combo_cap[] = {KC_G, KC_L, COMBO_END};

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
    case LT_AS: return KC_C;
    case KC_P: return KC_K;
    case KC_C: return KC_D;
    case LT_SPC: return KC_ENT;
  }
  if ((mods & MOD_MASK_CTRL)) {
    switch (keycode) {
      case KC_C: return C(KC_V);
    }
  }
  return KC_TRNS;
}
