/* --------------------------------------------------------------------------------------------
    __    __     __  __        __  __     ______     __  __     __    __     ______     ______
   /\ "-./  \   /\ \_\ \      /\ \/ /    /\  ___\   /\ \_\ \   /\ "-./  \   /\  __ \   /\  == \
   \ \ \-./\ \  \ \____ \     \ \  _"-.  \ \  __\   \ \____ \  \ \ \-./\ \  \ \  __ \  \ \  _-/
    \ \_\ \ \_\  \/\_____\     \ \_\ \_\  \ \_____\  \/\_____\  \ \_\ \ \_\  \ \_\ \_\  \ \_\
     \/_/  \/_/   \/_____/      \/_/\/_/   \/_____/   \/_____/   \/_/  \/_/   \/_/\/_/   \/_/

-----------------------------------------------------------------------------------------------
*/



#include QMK_KEYBOARD_H
#include "features/achordion.h"
#include "features/orbital_mouse.h"
#include "features/repeat_key.h"

enum custom_keycodes {
    M_THE = SAFE_RANGE,
    ALTREP = SAFE_RANGE,
    REPEAT = SAFE_RANGE,
    // Other custom keys...
    // combo keycodes
    G_00,
    G_01,
    G_02,
    G_03,
    G_04,
    G_05,
    G_06,
    G_07,
    G_08,
    G_09,

    G_10,
    G_11,
    G_12,
    G_13,
    G_14,
    G_15,
    G_16,
    G_17,
    G_18,
    G_19,

    G_20,
    G_21,
    G_22,
    G_23,
    G_24,
    G_25,
    G_26,
    G_27,
    G_28,
    G_29,

    G_32,
    G_33,
    G_34,
    G_35,
    G_36,
    G_37,




    H_00,
    H_01,
    H_02,
    H_03,
    H_04,
    H_05,
    H_06,
    H_07,
    H_08,
    H_09,

    H_10,
    H_11,
    H_12,
    H_13,
    H_14,
    H_15,
    H_16,
    H_17,
    H_18,
    H_19,

    H_20,
    H_21,
    H_22,
    H_23,
    H_24,
    H_25,
    H_26,
    H_27,
    H_28,
    H_29,

    H_32,
    H_33,
    H_34,
    H_35,
    H_36,
    H_37
};

enum layers{
    _BASE,
    _GAME,
    _SYM,
    _NAV,
    _NUM,
    _FUN,
    _MSE,
    _COMBO1,
    _COMBO2,
    _EEP,
};


#define FN_K    LT(_MSE, KC_K)
#define FN_SPC  LT(_SYM, KC_SPC)
#define FN_NUM  LT(_NUM, KC_NO)

#define FN_GAME DF(_GAME)
#define FN_BASE DF(_BASE)

#define LT_CE LCTL_T(KC_E)
#define LT_AI LOPT_T(KC_I)
#define LT_GA LCMD_T(KC_A)
#define LT_SH LSFT_T(KC_H)
#define LT_SN RSFT_T(KC_N)
#define LT_GT RCMD_T(KC_T)
#define LT_AR ROPT_T(KC_R)
#define LT_CD RCTL_T(KC_D)

#define MAGI LT(_NAV,KC_F22)

#define CAPS KC_F23 // caps word or capslock

#define TTY2 C(A(KC_F2))
#define TTY3 C(A(KC_F3))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_BASE] = LAYOUT_33_split_space(
        KC_NO  , KC_L   , KC_S   , KC_K   , KC_NO  , KC_NO  , KC_G   , KC_O   , KC_U   , KC_ESC ,
        LT_CD  , LT_AR  , LT_GT  , LT_SN  , KC_Y   , KC_W   , LT_SH  , LT_GA  , LT_AI  , LT_CE  ,
        KC_M   , XXXXXXX, KC_V   , KC_P   , KC_B   , KC_F   , KC_C   , KC_X   , XXXXXXX, FN_K   ,
                          XXXXXXX, XXXXXXX, MAGI   , FN_SPC , FN_NUM , XXXXXXX
    ),

    [_GAME] = LAYOUT_33_split_space(
        _______, _______, _______, _______, _______, KC_Q   , KC_W   , KC_O   , KC_U   , KC_Z   ,
        _______, _______, _______, _______, _______, KC_G   , KC_H   , KC_A   , KC_I   , KC_E   ,
        _______, _______, _______, _______, _______, KC_F   , KC_C   , KC_X   , XXXXXXX, KC_K   ,
                          _______, _______, _______, KC_SPC , _______, _______
    ),

    [_SYM] = LAYOUT_33_split_space(
        KC_EXLM, KC_HASH, KC_AT  , KC_DLR , KC_PERC, KC_TILD, KC_GRV , KC_COLN, KC_ASTR, KC_PLUS,
        KC_COMM, KC_DOT , KC_SLSH, KC_EQL , KC_CIRC, KC_LBRC, KC_LPRN, KC_LCBR, KC_DQUO, KC_MINS,
        KC_LT  , KC_GT  , KC_BSLS, KC_PIPE, KC_AMPR, KC_RBRC, KC_RPRN, KC_RCBR, KC_QUOT, KC_UNDS,
                          _______, _______, KC_SCLN, _______, _______, _______
    ),

    [_NAV] = LAYOUT_33_split_space(
        _______, _______, _______, _______, _______, _______, _______, KC_UP  , KC_PSCR, _______,
        KC_LCTL, KC_LOPT, KC_LCMD, KC_LSFT, FN_GAME, TTY2   , KC_LEFT, KC_DOWN, KC_RGHT, KC_DEL ,
        XXXXXXX, _______, _______, _______, FN_BASE, TTY3   , KC_BSPC, KC_TAB , _______, _______,
                          _______, _______, _______, _______, _______, _______
    ),

     [_NUM] = LAYOUT_33_split_space(
        KC_NO  , KC_5   , KC_6   , KC_7   , _______, _______, _______, _______, _______, _______,
        KC_4   , KC_3   , KC_2   , KC_1   , _______, _______, _______, KC_LCMD, _______, _______,
        _______, _______, KC_8   , KC_9   , _______, _______, KC_BSPC, _______, _______, _______,
                          _______, _______, KC_0   , _______, _______, QK_BOOT
    ),

    [_MSE] = LAYOUT_33_split_space(
        _______, OM_DBLS, OM_SEL1, OM_SEL2, OM_SEL3, _______, _______, _______, _______, _______,
        OM_SLOW, OM_L   , OM_U   , OM_R   , OM_W_U , _______, _______, _______, _______, _______,
        OM_RELS, OM_HLDS, OM_D   , OM_BTNS, OM_W_D , _______, _______, _______, _______, _______,
                          _______, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, _______
    ),

    [_FUN] = LAYOUT_33_split_space(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    ),

    [_COMBO1] = LAYOUT_33_split_space(
        G_00   , G_01   , G_02   , G_03   , G_04   , G_05   , G_06   , G_07   , G_08   , G_09   ,
        G_10   , G_11   , G_12   , G_13   , G_14   , G_15   , G_16   , G_17   , G_18   , G_19   ,
        G_20   , G_21   , G_22   , G_23   , G_24   , G_25   , G_26   , G_27   , G_28   , G_29   ,
                          G_32   , G_33   , G_34   , G_35   , G_36   , G_37
    ),

    [_COMBO2] = LAYOUT_33_split_space(
        H_00   , H_01   , H_02   , H_03   , H_04   , H_05   , H_06   , H_07   , H_08   , H_09   ,
        H_10   , H_11   , H_12   , H_13   , H_14   , H_15   , H_16   , H_17   , H_18   , H_19   ,
        H_20   , H_21   , H_22   , H_23   , H_24   , H_25   , H_26   , H_27   , H_28   , H_29   ,
                          H_32   , H_33   , H_34   , H_35   , H_36   , H_37
    ),

    [_EEP] = LAYOUT_33_split_space(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    ),
};





enum combo_events {
    COMBO_ENT,
    COMBO_CAP,
    COMBO_EEP,
    COMBO_JJJ,
    COMBO_QQQ,
    COMBO_ZZZ,
};
#ifdef COMBO_ENABLE
const uint16_t PROGMEM combo_ent[] = {G_13   , G_16   , COMBO_END};
const uint16_t PROGMEM combo_cap[] = {G_14   , G_15   , COMBO_END};
const uint16_t PROGMEM combo_eep[] = {G_01   , G_03   , G_06   , G_08   , COMBO_END};
const uint16_t PROGMEM combo_jjj[] = {G_01   , G_02   , COMBO_END};
const uint16_t PROGMEM combo_qqq[] = {G_02   , G_03   , COMBO_END};
const uint16_t PROGMEM combo_zzz[] = {G_01   , G_03   , COMBO_END};

combo_t key_combos[] = {
    [COMBO_ENT] = COMBO(combo_ent,KC_ENTER),
    [COMBO_CAP] = COMBO(combo_cap,CAPS),
    [COMBO_EEP] = COMBO(combo_eep,TG(_EEP)),
    [COMBO_JJJ] = COMBO(combo_jjj,KC_J),
    [COMBO_QQQ] = COMBO(combo_qqq,KC_Q),
    [COMBO_ZZZ] = COMBO(combo_zzz,KC_Z),
};
#endif
#define COMBO_REF_DEFAULT _EEP

uint8_t combo_ref_from_layer(uint8_t layer){
    switch (get_highest_layer(layer_state)){
        case _NAV: return _COMBO2;
        case _SYM: return _COMBO2;
        case _NUM: return _COMBO2;
        case _EEP: return _EEP;
        default: return _COMBO1;
    }
    return layer;  // important if default is not in case.
}





bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    if (!process_achordion(keycode, record)) { return false; }
    if (!process_repeat_key_with_alt(keycode, record, REPEAT, ALTREP)) { return false; }
    if (!process_orbital_mouse(keycode, record)) { return false; }
    // Your macros ...
    switch (keycode) {
        case M_THE: SEND_STRING(/*spc*/"the "); break;
        case MAGI:
            if (record->tap.count && record->event.pressed) {
                alt_repeat_key_tap();
            } break;
        case CAPS: caps_word_toggle(); break; }
    return true;
}

void matrix_scan_user(void) {
    achordion_task();
    orbital_mouse_task();
}
uint16_t achordion_timeout(uint16_t tap_hold_keycode) {
    switch (tap_hold_keycode) {
        // left thumb keys
        case FN_NUM:
        case MAGI:
        // right thumb keys
        case FN_SPC:
        case FN_K  :
        return 0;  // Bypass Achordion for these keys.
    }
    return 500;
};
uint16_t get_alt_repeat_key_keycode_user(uint16_t keycode, uint8_t mods) {
    switch (keycode) {
        case LT_GA: return KC_X;
        case KC_B: return KC_Y;
        case KC_C: return KC_H;
        case LT_CD: return KC_D;
        case LT_CE: return KC_E;
        case KC_F: return KC_T;
        case KC_G: return KC_H;
        case KC_H: return KC_E;
        case LT_AI: return KC_U;
        case FN_K: return KC_E;
        case KC_L: return KC_L;
        case LT_SN: return KC_Y;
        case KC_O: return KC_A;
        case KC_P: return KC_P;
        case LT_AR: return KC_L;
        case KC_S: return KC_T;
        case LT_GT: return KC_S;
        case KC_U: return KC_I;
        case KC_W: return KC_H;
        case KC_X: return KC_A;
        case KC_Y: return KC_P;
        case KC_Z: return KC_Z;
        case FN_SPC: return M_THE;
    }
    return KC_TRNS;
}
bool remember_last_key_user(uint16_t keycode, keyrecord_t* record,
                            uint8_t* remembered_mods) {
    switch (keycode) {
        case MAGI: return false; break;
    }
    return true;
}





bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        // Keycodes that continue Caps Word, with shift applied.
        case KC_A ... KC_Z:
        case KC_F22:
            add_weak_mods(MOD_BIT(KC_LSFT));  // Apply shift to next key.
            return true;

        // Keycodes that continue Caps Word, without shifting.
        case KC_1 ... KC_0:
        case KC_BSPC:
        case KC_DEL:
        case KC_MINS:
        case KC_UNDS:
            return true;

        default:
            return false;  // Deactivate Caps Word.
    }
}

