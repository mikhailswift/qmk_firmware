#include QMK_KEYBOARD_H

enum tap_dances {
  TD_LBRC_COMBO,
  TD_RBRC_COMBO,
};

tap_dance_action_t tap_dance_actions[] = {
    [TD_LBRC_COMBO] = ACTION_TAP_DANCE_DOUBLE(KC_LBRC, KC_LPRN),
    [TD_RBRC_COMBO] = ACTION_TAP_DANCE_DOUBLE(KC_RBRC, KC_RPRN),
};

/*
void dance_brc_combo_fin(tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    if (state->keycode == TD(TD_LBRC_COMBO)) {
      register_code16(KC_LBRC);
    } else if (state->keycode == TD(TD_RBRC_COMBO)) {
      register_code16(KC_RBRC);
    }
  } else if (state->count == 2) {
    if (state->keycode == TD(TD_LBRC_COMBO)) {
      register_code16(KC_LPRN);
    } else if (state->keycode == TD(TD_RBRC_COMBO)) {
      register_code16(KC_RPRN);
    }
  }
}

void dance_brc_combo_reset(tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    if (state->keycode == TD(TD_LBRC_COMBO)) {
      unregister_code16(KC_LBRC);
    } else if (state->keycode == TD(TD_RBRC_COMBO)) {
      unregister_code16(KC_RBRC);
    }
  } else if (state->count == 2) {
    if (state->keycode == TD(TD_LBRC_COMBO)) {
      unregister_code16(KC_LPRN);
    } else if (state->keycode == TD(TD_RBRC_COMBO)) {
      unregister_code16(KC_RPRN);
    }
  }
}

tap_dance_action_t tap_dance_actions[] = {
  [TD_LBRC_COMBO] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_brc_combo_fin, dance_brc_combo_reset),
  [TD_RBRC_COMBO] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_brc_combo_fin, dance_brc_combo_reset),
};
*/
