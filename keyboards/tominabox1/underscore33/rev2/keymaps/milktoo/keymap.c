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
#include "features/repeat_key.h"
#include "./keycodes.h"



enum layers {
    _BASE,
    _GAME,
    _SYM,
    _NAV,
    _NUM,
    _WM,
    _FUN,
    _CO1,
    _CO2,
    _EEP
};
// keymap
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_BASE] = LAYOUT_33_custom(
        KC_B   , KC_L   , KC_F   , KC_D   , KC_M   , KC_P   , KC_Y   , KC_O   , KC_U   , C_BSPC,
        MT_CH  , MT_AN  , MT_GS  , MT_ST  , KC_G   , KC_W   , MT_SC  , MT_GE  , MT_AI  , MT_CA  ,
        XXXXXXX, XXXXXXX, XXXXXXX, LT_R   , XXXXXXX, WM     , SPC    , NUM    , XXXXXXX, XXXXXXX,
                          XXXXXXX, XXXXXXX, LT_R   , KC_NO  , SPC   , MO(_FUN), XXXXXXX
    ),

    [_GAME] = LAYOUT_33_custom(
        _______, _______, _______, _______, _______, KC_Q   , KC_G   , KC_O   , KC_U   , KC_J   ,
        _______, _______, _______, _______, _______, KC_Y   , KC_C   , KC_A   , KC_E   , KC_I   ,
        _______, _______, _______, _______, _______, KC_P   , KC_W   , KC_X   , XXXXXXX, KC_LSFT,
                          _______, _______, _______, _______, KC_SPC , _______, XXXXXXX
    ),

    [_SYM] = LAYOUT_33_custom(
        KC_EXLM, KC_HASH, KC_AT  , KC_DLR , KC_PERC, KC_TILD, KC_GRV , KC_COLN, KC_ASTR, KC_PLUS,
        KC_COMM, KC_LBRC, KC_LCBR, KC_LPRN, KC_CIRC, KC_SLSH, KC_EQL , KC_DQUO, KC_LT  , KC_MINS,
        KC_DOT , KC_RBRC, KC_RCBR, KC_RPRN, KC_AMPR, KC_BSLS, KC_PIPE, KC_QUOT, KC_GT  , KC_UNDS,
                          _______, _______, KC_SCLN, _______, _______, _______, XXXXXXX
    ),

    [_NAV] = LAYOUT_33_custom(
        KC_PSCR, _______, _______, _______, _______, KC_PGUP, KC_HOME, KC_UP  , KC_END , KC_BSPC,
        KC_LCTL, KC_LOPT, KC_LCMD, KC_LSFT, _______, KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_DEL ,
        XXXXXXX, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                          _______, _______, _______, _______, _______, TTY1   , TTY2
    ),

     [_NUM] = LAYOUT_33_custom(
        KC_EXLM, KC_5   , KC_6   , KC_7   , _______, _______, _______, _______, _______, KC_PLUS,
        KC_4   , KC_3   , KC_2   , KC_1   , _______, _______, _______, KC_LCMD, _______, KC_MINS,
        KC_DOT , _______, KC_8   , KC_9   , _______, _______, KC_BSPC, _______, _______, KC_UNDS,
                          _______, _______, KC_0   , _______, _______, QK_BOOT, XXXXXXX
    ),

     [_WM] = LAYOUT_33_custom(
        KC_EXLM, WM_5   , WM_6   , WM_7   , _______, _______, _______, _______, _______, _______,
        WM_4   , WM_3   , WM_2   , WM_1   , _______, _______, _______, _______, _______, _______,
        KC_DOT , _______, WM_8   , WM_9   , _______, _______, _______, _______, _______, _______,
                          _______, _______, KC_R   , _______, _______, _______, XXXXXXX
    ),

    [_FUN] = LAYOUT_33_custom(
        KC_F1  , KC_F2  , KC_F3  , KC_F4  , _______, _______, _______, _______, _______, _______,
        KC_F5  , KC_F6  , KC_F7  , KC_F8  , KC_F9  , _______, _______, _______, _______, _______,
        _______, _______, KC_F10 , KC_F11 , KC_F12 , _______, _______, _______, _______, _______,
                          _______, _______, _______, _______, _______, _______, XXXXXXX
    ),

    // abstraction laye for letter-combos
    [_CO1] = LAYOUT_33_custom(
        G_00   , G_01   , G_02   , G_03   , G_04   , G_05   , G_06   , G_07   , G_08   , G_09   ,
        G_10   , G_11   , G_12   , G_13   , G_14   , G_15   , G_16   , G_17   , G_18   , G_19   ,
        G_20   , G_21   , G_22   , G_23   , G_24   , G_25   , G_26   , G_27   , G_28   , G_29   ,
                          G_32   , G_33   , G_34   , G_35   , G_36   , G_37   , XXXXXXX
    ),

    // abstraction laye for symbol-combos
    [_CO2] = LAYOUT_33_custom(
        H_00   , H_01   , H_02   , H_03   , H_04   , H_05   , H_06   , H_07   , H_08   , H_09   ,
        H_10   , H_11   , H_12   , H_13   , H_14   , H_15   , H_16   , H_17   , H_18   , H_19   ,
        H_20   , H_21   , H_22   , H_23   , H_24   , H_25   , H_26   , H_27   , H_28   , H_29   ,
                          H_32   , H_33   , H_34   , H_35   , H_36   , H_37   , XXXXXXX
    ),

    // afk layer
    [_EEP] = LAYOUT_33_custom(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, TG(_EEP)
    ),
};




// combo shit
enum combo_events {
    COMBO_ESC,
    COMBO_TAB,
    COMBO_ENT,
    COMBO_QUE,
    COMBO_CAP,
    COMBO_JJJ,
    COMBO_QQQ,
    COMBO_ZZZ,
    COMBO_XXX,
    COMBO_VVV,
    COMBO_KKK,
    COMBO_EEP,
};

#ifdef COMBO_ENABLE
const uint16_t PROGMEM combo_esc[] = {G_01 , G_13 ,        COMBO_END};
const uint16_t PROGMEM combo_tab[] = {G_08 , G_16 ,        COMBO_END};
const uint16_t PROGMEM combo_ent[] = {G_03 , G_14 ,        COMBO_END};
const uint16_t PROGMEM combo_que[] = {G_13 , G_14 ,        COMBO_END};
const uint16_t PROGMEM combo_cap[] = {G_14 , G_15 ,        COMBO_END};
const uint16_t PROGMEM combo_jjj[] = {G_05 , G_15 ,        COMBO_END};
const uint16_t PROGMEM combo_qqq[] = {G_06 , G_16 ,        COMBO_END};
const uint16_t PROGMEM combo_zzz[] = {G_01 , G_03 ,        COMBO_END};
const uint16_t PROGMEM combo_xxx[] = {G_01 , G_11 ,        COMBO_END};
const uint16_t PROGMEM combo_vvv[] = {G_02 , G_12 ,        COMBO_END};
const uint16_t PROGMEM combo_kkk[] = {G_03 , G_13 ,        COMBO_END};
const uint16_t PROGMEM combo_eep[] = {G_03 , G_05 , G_08 , COMBO_END};

combo_t key_combos[] = {
    [COMBO_ESC] = COMBO(combo_esc,KC_ESC),
    [COMBO_TAB] = COMBO(combo_tab,KC_TAB),
    [COMBO_ENT] = COMBO(combo_ent,KC_ENT),
    [COMBO_QUE] = COMBO(combo_que,KC_QUES),
    [COMBO_CAP] = COMBO(combo_cap,KC_CAPS),
    [COMBO_JJJ] = COMBO(combo_jjj,KC_J),
    [COMBO_QQQ] = COMBO(combo_qqq,KC_Q),
    [COMBO_ZZZ] = COMBO(combo_zzz,KC_Z),
    [COMBO_XXX] = COMBO(combo_xxx,KC_X),
    [COMBO_VVV] = COMBO(combo_vvv,KC_V),
    [COMBO_KKK] = COMBO(combo_kkk,KC_K),
    [COMBO_EEP] = COMBO(combo_eep,TG(_EEP)),
};
#endif

uint8_t combo_ref_from_layer(uint8_t layer){
    switch (get_highest_layer(layer_state)){
        case _NAV :
        case _SYM :
        case _NUM :
          return _CO2;

        case _EEP : return _EEP;
        default   : return _CO1;
    }
    return layer;  // important if default is not in case.
}




// user shit
bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    if (!process_achordion(keycode, record)) { return false; }
    // Your macros ...
    return true;
}
void matrix_scan_user(void) {
    achordion_task();
}



// achordion shit
uint16_t achordion_timeout(uint16_t tap_hold_keycode) {
    switch (tap_hold_keycode) {
        // left thumb keys
        case NUM:
        case LT_R:
        // right thumb keys
        case SPC:
        return 0;  // Bypass Achordion for these keys.
    }
    return 500;
};


// caps shit
bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        // Keycodes that continue Caps Word, with shift applied.
        case KC_A ... KC_Z:
            add_weak_mods(MOD_BIT(KC_LSFT));  // Apply shift to next key.
            return true;

        // Keycodes that continue Caps Word, without shifting.
        case KC_1 ... KC_0:
        case KC_BSPC:
        case KC_DEL:
        case KC_MINS:
        case KC_UNDS:
            return true;

        default: return false;  // Deactivate Caps Word.
    }
}

