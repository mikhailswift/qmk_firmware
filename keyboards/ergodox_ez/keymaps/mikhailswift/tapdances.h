#include QMK_KEYBOARD_H

enum tap_dances {
  TD_LBRC_COMBO,
  TD_RBRC_COMBO,
};

void dance_brc_combo_fin(qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    if (state->keycode == TD(TD_LBRC_COMBO)) {
      register_code16(KC_LPRN);
    } else if (state->keycode == TD(TD_RBRC_COMBO)) {
      register_code16(KC_RPRN);
    }
  } else if (state->count == 2) {
    if (state->keycode == TD(TD_LBRC_COMBO)) {
      register_code16(KC_LCBR);
    } else if (state->keycode == TD(TD_RBRC_COMBO)) {
      register_code16(KC_RCBR);
    }
  } else {
    if (state->keycode == TD(TD_LBRC_COMBO)) {
      register_code(KC_LBRC);
    } else if (state->keycode == TD(TD_RBRC_COMBO)) {
      register_code(KC_RBRC);
    }
  }
}

void dance_brc_combo_reset(qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    if (state->keycode == TD(TD_LBRC_COMBO)) {
      unregister_code16(KC_LPRN);
    } else if (state->keycode == TD(TD_RBRC_COMBO)) {
      unregister_code16(KC_RPRN);
    }
  } else if (state->count == 2) {
    if (state->keycode == TD(TD_LBRC_COMBO)) {
      unregister_code16(KC_LCBR);
    } else if (state->keycode == TD(TD_RBRC_COMBO)) {
      unregister_code16(KC_RCBR);
    }
  } else if (state->count > 2) {
    if (state->keycode == TD(TD_LBRC_COMBO)) {
      unregister_code(KC_LBRC);
    } else if (state->keycode == TD(TD_RBRC_COMBO)) {
      unregister_code(KC_RBRC);
    }
  }
}

qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_LBRC_COMBO] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_brc_combo_fin, dance_brc_combo_reset),
  [TD_RBRC_COMBO] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_brc_combo_fin, dance_brc_combo_reset),
};
