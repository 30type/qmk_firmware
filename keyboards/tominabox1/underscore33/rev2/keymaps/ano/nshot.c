/* N-SHOT MOD CONFIGURATION.
 * Reminder of the nshot structure:
 * 
 * typedef struct {
 *     uint16_t      trigger;          // Keycode to activate the n-shot mod
 *     uint8_t       modbit;           // Modbit allows for mod combos.
 *     uint8_t       alternate_modbit; // Alternate modbit for Gui-Ctl swapping.
 *     uint8_t       max_count;        // one-shot, two-shot, ..., n-shot.
 *     bool          active_on_rolls;  // Behavior for A down, Mod down, A up = (active_on_rolls == true ? Mod-A : a)
 *     oneshot_state state;            // Direct from users/callum
 *     uint8_t       count;            // N-shot count state
 *     bool          had_keydown;      // keydown state for (active_on_rolls == false)
 * } nshot_state_t;
 *
 * OSR_SFT is a base-layer thumbshift key. It is more stringent about rolls than the other nshots.
 * If you are reading my code for ideas, there is almost certainly no reason why you should want to
 * use a homerolled nshot for thumbshift instead of using QMK's defaults.
 * I am committing crimes against good sense and also reasonable layer state with this guy.
 * It is on purpose, but trust me: you do not have this usecase, and default is better for your usecase.
*/

#define MODBIT_MEH   MOD_BIT(KC_LCTL) | MOD_BIT(KC_LALT) | MOD_BIT(KC_LSFT) 
nshot_state_t  nshot_states[] = {
//| trigger  | modbit            | swap-to          | max | roll into | State         | ## | timer | keydown? | //roll-in action |
//|----------|-------------------|------------------|-----|-----------|---------------|----|-------|----------|------------------|
    {OS_LSFT,  MOD_BIT(KC_LSFT),  MOD_BIT(KC_LSFT),   1,   true,       os_up_unqueued,  0,   0,     true },    // S-a
    // {OS_LCTL,  MOD_BIT(KC_LCTL),  MOD_BIT(KC_LGUI),   1,   true,       os_up_unqueued,  0,   0,     false},    // C-a
    // {OS_LALT,  MOD_BIT(KC_LALT),  MOD_BIT(KC_LALT),   1,   true,       os_up_unqueued,  0,   0,     false},    // A-a
    // {OS_RALT,  MOD_BIT(KC_RALT),  MOD_BIT(KC_RALT),   1,   true,       os_up_unqueued,  0,   0,     false},    // AltGr-a
    // {OS_LGUI,  MOD_BIT(KC_LGUI),  MOD_BIT(KC_LCTL),   1,   true,       os_up_unqueued,  0,   0,     false},    // G-a
    {OS_LMEH,  MODBIT_MEH      ,  MODBIT_MEH      ,   1,   true,       os_up_unqueued,  0,   0,     false},    // C-S-A-x
    // {TS_LCTL,  MOD_BIT(KC_LCTL),  MOD_BIT(KC_LCTL),   2,   true,       os_up_unqueued,  0,   0,     false},    // C-a
    // {OSR_SFT,  MOD_BIT(KC_LSFT),  MOD_BIT(KC_LSFT),   1,   false,      os_up_unqueued,  0,   0,     false}     // a
};
uint8_t        NUM_NSHOT_STATES = sizeof(nshot_states) / sizeof(nshot_state_t);

bool is_nshot_cancel_key(uint16_t keycode) {
    switch (keycode) {
//         case PANIC:
//         case CLEAR:
//         case NAVMODE:
//             return true;
        default:
            return false;
    }
}

bool is_nshot_ignored_key(uint16_t keycode) {
    switch (keycode) {
//         case NAVMODE:
//         case NUM_OSL:
//         case NUMMODE:
//         case FUNMODE:
//         case SYMMODE:
//         case MCRMODE:
//         case OS_LSFT:
//         case OS_LCTL:
//         case OS_LALT:
//         case OS_LGUI:
//             return true;
        default:
            return false;
    }
}
