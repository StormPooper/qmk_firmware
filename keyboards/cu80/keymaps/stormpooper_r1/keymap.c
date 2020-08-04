#include QMK_KEYBOARD_H

void tapdance_dynamicmacro(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count > 2) return;
    keyrecord_t kr;
    kr.event.pressed = false;
    uint16_t action  = DYN_REC_STOP;
    if (state->count == 1) {
        action = DYN_MACRO_PLAY1;
    } else if (state->count == 2) {
        action = DYN_REC_START1;
    }
    process_dynamic_macro(action, &kr);
}

enum { TD_DYNMACRO };

qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_DYNMACRO] = ACTION_TAP_DANCE_FN(tapdance_dynamicmacro),
};

#define _DEFAULT 0
#define _FNCTION 1

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_DEFAULT] = LAYOUT_all(KC_ESC, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_PSCR, KC_SLCK, KC_PAUS,

                            KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC, KC_INS, KC_HOME, KC_PGUP,

                            KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_DEL, KC_END, KC_PGDN,

                            KC_LOCK, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_NUHS, KC_ENT,

                            KC_LSFT, KC_NUBS, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_UP,

                            KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, KC_RALT, LT(_FNCTION, KC_RGUI), KC_APP, KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT),

    [_FNCTION] = LAYOUT_all(_______, KC_F13, KC_F14, KC_F15, KC_F16, KC_F17, KC_F18, KC_F19, KC_F20, KC_F21, KC_F22, KC_F23, KC_F24, KC_MUTE, TD(TD_DYNMACRO), _______,

                            _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_VOLD, KC_MPLY, KC_VOLU,
                            // TEMP: Increase Auto Shift speed
                            KC_ASUP, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MPRV, KC_MSTP, KC_MNXT,

                            KC_ASTG, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                            // TEMP: Decrease Auto Shift speed
                            KC_ASDN, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                            // TEMP: Report Auto Shift speed
                            KC_ASRP, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______),
};
