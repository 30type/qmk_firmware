#pragma once

// hrm
#define MT_CN LCTL_T(KC_N)
#define MT_CA RCTL_T(KC_A)

#define MT_AS LOPT_T(KC_S)
#define MT_AI ROPT_T(KC_I)

#define MT_GH LCMD_T(KC_H)
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
#define NUM LT(_NUM, KC_X)
#define SPC LT(_SYM, KC_SPC)



// some stuff
#define C_BSPC C(KC_BSPC)

#define LT_W LT(_WM, KC_W)

#define TTY1 C(A(KC_F1))
#define TTY2 C(A(KC_F2))

// #define FN_GAME MO(_GAME)
// #define FN_BASE MO(_BASE)



// custom keycodes for combos
enum custom_keycodes {
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


