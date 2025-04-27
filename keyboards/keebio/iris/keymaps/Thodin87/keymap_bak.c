#include QMK_KEYBOARD_H

#define EE_HANDS
#define _COLEMAK 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 3


enum custom_keycodes {
  COLEMAK = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
  QUOT_SPC,
  GRAV_SPC,
  TILD_SPC
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  // DHM mod
  [_COLEMAK] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     QK_GRAVE_ESCAPE,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    GRAV_SPC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                               KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSLS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LCTL, LSFT_T(KC_A), LCTL_T(KC_R), LALT_T(KC_S), LGUI_T(KC_T), KC_G,           KC_M,    RGUI_T(KC_N), LALT_T(KC_E), RCTL_T(KC_I), RSFT_T(KC_O), QUOT_SPC,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT, LT(ADJUST, KC_Z), KC_X,    LT(RAISE, KC_C), LT(LOWER,KC_D), KC_V, KC_DEL, KC_ENT,  KC_K,    LT(LOWER, KC_H), LT(RAISE, KC_COMM), KC_DOT,  LT(ADJUST, KC_SLSH), KC_RSFT,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_LALT, LOWER,   KC_BSPC,                   KC_SPC,  RAISE,   KC_LGUI
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_LOWER] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_ESC,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                            KC_CIRC, KC_AMPR, KC_ASTR, KC_MINS, KC_EQL,  RALT(KC_Q),
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_ESC,  KC_PGUP, LCTL(KC_LEFT),KC_UP,LCTL(KC_RGHT),KC_HOME,                     GRAV_SPC,KC_LPRN, KC_RPRN, KC_EQL , KC_PLUS, RALT(KC_P),
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LCTL, KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_END,                             TILD_SPC,KC_LBRC, KC_RBRC, KC_MINS, KC_UNDS, RALT(KC_Y),
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, _______, _______, _______, _______, _______, _______,          _______, _______, KC_LCBR, KC_RCBR, _______, RALT(KC_S), _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_LALT, LOWER,   KC_BSPC,                   KC_SPC,  RAISE,   KC_LGUI
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_RAISE] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_ESC,  _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_ESC,  KC_MPLY, _______, _______, _______, _______,                            KC_COMM, KC_7,    KC_8,    KC_9,    _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     RGB_MOD, KC_LSFT, KC_MNXT, RALT(KC_S), KC_VOLU, KC_UNDS,                         KC_DOT,  KC_4,    KC_5,    KC_6,    KC_RSFT,  _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     RGB_TOG, KC_MSTP, KC_MPRV, KC_MUTE, KC_VOLD, KC_MINS, KC_LPRN,          _______, KC_0,    KC_1,    KC_2,    KC_3,    _______,  _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    KC_LALT, LOWER,   KC_BSPC,                   KC_SPC,  RAISE,   KC_LGUI
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_ADJUST] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     QK_RBT,  DT_PRNT, LGUI(KC_7), LGUI(KC_8), LGUI(KC_9), _______,                   KC_F12,  KC_F7,   KC_F8,   KC_F9,   _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, DT_UP,   LGUI(KC_4), LGUI(KC_5), LGUI(KC_6), _______,                   KC_F11,  KC_F4,   KC_F5,   KC_F6,   _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______, DT_DOWN, LGUI(KC_1), LGUI(KC_2), LGUI(KC_3), _______, _______, _______, KC_F10,  KC_F1,   KC_F2,   KC_F3,   _______, KC_PSCR,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;

    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;

    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;

    // With the windows deadkeys layout, the quotation marks require
    // a subsequent space to appear. So we automatically press it here.
    case QUOT_SPC:
      if (record->event.pressed) {
         SEND_STRING("' ");
      }
      else {

      }
      break;

    case GRAV_SPC:
      if (record->event.pressed) {
        SEND_STRING("` ");
      }
      break;


    case TILD_SPC:
      if (record->event.pressed) {
        SEND_STRING("~ ");
      }
      break;
  }
  return true;
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LSFT_T(KC_A):
            return 150;
        case RSFT_T(KC_O):
            return 150;
        default:
            return TAPPING_TERM;
    }
}

