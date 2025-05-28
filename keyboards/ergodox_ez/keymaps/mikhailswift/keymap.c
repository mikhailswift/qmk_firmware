#include QMK_KEYBOARD_H
#include "version.h"

#include "tapdances.h"

#define KC_PAUSE KC_MEDIA_PLAY_PAUSE
#define KC_NEXT KC_MEDIA_NEXT_TRACK
#define KC_PREV KC_MEDIA_PREV_TRACK
#define KC_VOL_DOWN KC_AUDIO_VOL_DOWN
#define KC_VOL_UP  KC_AUDIO_VOL_UP
#define KC_MUTE KC_AUDIO_MUTE
#define KC_SFT_SPACE LSFT_T(KC_SPACE)
#define KC_CTL_BSPACE LCTL_T(KC_BSPC)
#define KC_ALT_TAB LALT_T(KC_TAB)
#define KC_SFT_ENTER LSFT_T(KC_ENTER)
#define KC_TDLBRC TD(TD_LBRC_COMBO)
#define KC_TDRBRC TD(TD_RBRC_COMBO)
#define KC_TGL_COLOR  TOGGLE_LAYER_COLOR

#define RGBLIGHT_DEFAULT_COLOR  51, 170, 255
#define RGBLIGHT_GAMING_COLOR  255,   0,   0
#define RGBLIGHT_SYMBOLS_COLOR  25, 191,  27
#define RGBLIGHT_ADJUST_COLOR  227, 240,  40

enum layers {
  QWERTY,
  GAMING,
  SYMBOLS,
  ADJUST,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [QWERTY] = LAYOUT_ergodox_pretty(
    KC_TRANSPARENT, KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_TRANSPARENT,
    LGUI(KC_TAB),   KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           KC_TDLBRC,                                      KC_TDRBRC,      KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_TRANSPARENT,
    LGUI_T(KC_ESC), KC_A,           KC_S,           KC_D,           KC_F,           KC_G,                                                                           KC_H,           KC_J,           KC_K,           KC_L,           KC_SCLN,        KC_QUOTE,
    OSL(SYMBOLS),   KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,           KC_MINUS,                                       KC_EQUAL,       KC_N,           KC_M,           KC_COMMA,       KC_DOT,         KC_SLASH,       OSL(ADJUST),
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_CAPS,        KC_F5,                                                                                                          KC_DEL,         KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                    LCTL(KC_LALT),  KC_SCRL,        KC_PAUSE,       KC_PSCR,
                                                                                                                    KC_HOME,        KC_PGUP,
                                                                                    KC_SFT_SPACE,   KC_CTL_BSPACE,  KC_END,         KC_PGDN,        KC_ALT_TAB, KC_SFT_ENTER
  ),
  [GAMING] = LAYOUT_ergodox_pretty(
    KC_ESC,         KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TAB,         KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_LSFT,        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_LCTL,        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                          KC_SPACE, KC_BSPC,        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [SYMBOLS] = LAYOUT_ergodox_pretty(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TILD,        KC_PERC,        KC_AMPR,        KC_PIPE,        KC_AT,          KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_SLASH,       KC_KP_7,        KC_KP_8,        KC_KP_9,        KC_KP_PLUS,     KC_TRANSPARENT,
    KC_TRANSPARENT, KC_HASH,        KC_EXLM,        KC_CIRC,        KC_DLR,         KC_QUES,                                                                        KC_ASTR,        KC_KP_4,        KC_KP_5,        KC_KP_6,        KC_MINUS,       KC_GRAVE,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_BSLS,        KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_KP_1,        KC_KP_2,        KC_KP_3,        KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_KP_0,        KC_KP_DOT,      KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [ADJUST] = LAYOUT_ergodox_pretty(
    KC_TRANSPARENT, KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          RGB_TOG,                                        KC_TRANSPARENT, KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_UP,       KC_TRANSPARENT, KC_MS_WH_UP,    RGB_VAI,                                        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_F12,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_RIGHT,    KC_MS_WH_DOWN,                                                                  KC_LEFT,        KC_DOWN,        KC_UP,          KC_RIGHT,       KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, RGB_VAD,                                        KC_NUM,         KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    QK_BOOT,        KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_BTN1,     KC_MS_BTN2,                                                                                                     KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, TG(GAMING),
                                                                                                    KC_TRANSPARENT, KC_MUTE,        KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                    KC_VOL_UP,      KC_NEXT,
                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_VOL_DOWN,    KC_PREV,        KC_TRANSPARENT, KC_TRANSPARENT
  ),
};

// Runs just one time when the keyboard initializes.
void keyboard_post_init_user(void) {
  rgblight_setrgb(RGBLIGHT_DEFAULT_COLOR);
};

// Runs whenever there is a layer state change.
layer_state_t layer_state_set_user(layer_state_t state) {
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();

  uint8_t layer = get_highest_layer(state);
  switch (layer) {
    case 0:
      rgblight_setrgb(RGBLIGHT_DEFAULT_COLOR);
      break;
    case GAMING:
      rgblight_setrgb(RGBLIGHT_GAMING_COLOR);
      break;
    case SYMBOLS:
      rgblight_setrgb(RGBLIGHT_SYMBOLS_COLOR);
      ergodox_right_led_1_on();
      break;
    case ADJUST:
      rgblight_setrgb(RGBLIGHT_ADJUST_COLOR);
      ergodox_right_led_2_on();
      break;
    default:
      break;
  }

  return state;
};
