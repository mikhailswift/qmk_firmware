#include QMK_KEYBOARD_H

enum tap_dances {
  TD_LBRC_COMBO,
  TD_RBRC_COMBO,
  TD_PRN,
  TD_BRC,
  TD_BKT,
};

void dance_lbrc_combo_fin(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        register_code(KC_RSFT);
        register_code(KC_9);
    } else if (state->count == 2) {
        register_code(KC_RSFT);
        register_code(KC_LBRC);
    } else {
        register_code(KC_LBRC);
    }
}

void dance_lbrc_combo_reset(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        unregister_code(KC_RSFT);
        unregister_code(KC_9);
    } else if (state->count == 2) {
        unregister_code(KC_RSFT);
        unregister_code(KC_LBRC);
    } else {
        unregister_code(KC_LBRC);
    }
}

void dance_rbrc_combo_fin(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        register_code(KC_RSFT);
        register_code(KC_0);
    } else if (state->count == 2) {
        register_code(KC_RSFT);
        register_code(KC_RBRC);
    } else {
        register_code(KC_RBRC);
    }

}

void dance_rbrc_combo_reset(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        unregister_code(KC_RSFT);
        unregister_code(KC_0);
    } else if (state->count == 2) {
        unregister_code(KC_RSFT);
        unregister_code(KC_RBRC);
    } else {
        unregister_code(KC_RBRC);
    }
}

qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_LBRC_COMBO] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_lbrc_combo_fin, dance_lbrc_combo_reset),
    [TD_RBRC_COMBO] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_rbrc_combo_fin, dance_rbrc_combo_reset),
};
