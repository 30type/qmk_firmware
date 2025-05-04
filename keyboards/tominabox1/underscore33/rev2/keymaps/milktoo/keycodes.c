#pragma once

// hrm
#define MT_CH LCTL_T(KC_H)
#define MT_CA RCTL_T(KC_A)

#define MT_AN LOPT_T(KC_N)
#define MT_AI ROPT_T(KC_I)

#define MT_GS LCMD_T(KC_S)
#define MT_GE RCMD_T(KC_E)

#define MT_ST LSFT_T(KC_T)
#define MT_SC RSFT_T(KC_C)



// window management 
#define WM_1 G(KC_1)
#define WM_2 G(KC_2)
#define WM_3 G(KC_3)
#define WM_4 G(KC_4)
#define WM_5 G(KC_5)
#define WM_6 G(KC_6)
#define WM_7 G(KC_7)
#define WM_8 G(KC_8)
#define WM_9 G(KC_9)



// thumbkeys
#define LT_R LT(_NAV, KC_R)
#define NUM MO(_NUM)
#define SPC LT(_SYM, KC_SPC)



// some stuff
#define C_BSPC C(KC_BSPC)

#define WM MO(_WM)

#define TTY1 C(A(KC_F1))
#define TTY2 C(A(KC_F2))

// #define FN_GAME MO(_GAME)
// #define FN_BASE MO(_BASE)



// custom keycodes for combos
enum custom_keycodes {
    QMK_USER = SAFE_RANGE,
    LP01,
    LR01,
    LM01,
    LI01,
    LI11,

    LP02,
    LR02,
    LM02,
    LI02,
    LI12,

    LT01,
    LT02,

    RP01,
    RR01,
    RM01,
    RI01,
    RI11,

    RP02,
    RR02,
    RM02,
    RI02,
    RI12,

    RT01,
    RT02
};


