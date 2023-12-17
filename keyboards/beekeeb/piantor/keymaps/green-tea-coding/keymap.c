// Copyright 2022 beekeeb
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

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
     /*
      * ┌───┬───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┬───┐
      * │Tab│ Q │ W │ F │ P │ B │       │ J │ L │ U │ Y │ ; │ \ │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │Ctl│ A │ R │ S │ T │ G │       │ M │ N │ E │ I │ O │ ' │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │Sft│ Z │ X │ C │ D │ V │       │ K │ H │ , │ . │ / │Sft│
      * └───┴───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┴───┘
      *               ┌───┐                   ┌───┐
      *               │Alt├───┐           ┌───┤Gui│
      *               └───┤Low├───┐   ┌───┤Rai├───┘
      *                   └───┤Bsp│   │Spc├───┘
      *                       └───┘   └───┘
      */
    [_COLEMAK] = LAYOUT_split_3x6_3(
        KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                               KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSLS,
        KC_LCTL, KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                               KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    QUOT_SPC,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,                               KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                                            KC_LALT, LOWER,   KC_BSPC,           KC_SPC,  RAISE,   KC_LGUI
    ),

     /*
      * ┌───┬───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┬───┐
      * │Esc│PgU│C+L│Up │C+R│Hom│       │ ^ │ ( │ ) │ = │ + │Del│
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │Ctl│PgD│Lft│Dwn│Rgt│End│       │ ~ │ [ │ ] │ - │ _ │Ent│
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │Sft│ ! │ @ │ # │ $ │ % │       │ ^ │ { │ } │ & │ * │Sft│
      * └───┴───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┴───┘
      *               ┌───┐                   ┌───┐
      *               │Alt├───┐           ┌───┤Gui│
      *               └───┤Low├───┐   ┌───┤Adj├───┘
      *                   └───┤Bsp│   │Spc├───┘
      *                       └───┘   └───┘
      */
    [_LOWER] = LAYOUT_split_3x6_3(
        KC_ESC,  KC_PGUP, LCTL(KC_LEFT),KC_UP,LCTL(KC_RGHT),KC_HOME,                      GRAV_SPC,KC_LPRN, KC_RPRN, KC_EQL , KC_PLUS, KC_DEL,
        KC_LCTL, KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_END,                              TILD_SPC,KC_LBRC, KC_RBRC, KC_MINS, KC_UNDS, KC_ENT,
        _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                             KC_CIRC, KC_LCBR, KC_RCBR, KC_AMPR, KC_ASTR, _______,
                                            _______, _______,   _______,           _______, TG(ADJUST), _______
    ),

     /*
      * ┌───┬───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┬───┐
      * │Esc│G+1│G+2│G+3│G+4│G+5│       │F12│F7 │F8 │F9 │ Ä │Del│
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │Ctl│Pla│Nxt│ ß │Vl+│   │       │F11│F4 │F5 │F6 │ Ö │Ent│
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │Sft│Stp│Pre│Mut│Vl-│   │       │F10│F1 │F2 │F3 │ Ü │Sft│
      * └───┴───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┴───┘
      *               ┌───┐                   ┌───┐
      *               │Alt├───┐           ┌───┤Gui│
      *               └───┤Adj├───┐   ┌───┤Rai├───┘
      *                   └───┤Bsp│   │Spc├───┘
      *                       └───┘   └───┘
      */
    [_RAISE] = LAYOUT_split_3x6_3(
        _______, LGUI(KC_1), LGUI(KC_2), LGUI(KC_3), LGUI(KC_4), LGUI(KC_5),              KC_F12,  KC_F7,   KC_F8,   KC_F9,   RALT(KC_Q), KC_DEL,
        _______, KC_MPLY, KC_MNXT, RALT(KC_S),KC_VOLU, _______,                           KC_F11,  KC_F4,   KC_F5,   KC_F6,   RALT(KC_P), KC_ENT,
        _______, KC_MSTP, KC_MPRV, KC_MUTE, KC_VOLD, _______,                             KC_F10,  KC_F1,   KC_F2,   KC_F3,   RALT(KC_Y), _______,
                                            _______, TG(ADJUST), _______,          _______, _______, _______
    ),

     /*
      * ┌───┬───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┬───┐
      * │RBT│ ! │ @ │ # │ $ │ % │       │ ^ │ & │ * │ ( │ ) │ \ │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │PSc│ 1 │ 2 │ 3 │ 4 │ 5 │       │ 6 │ 7 │ 8 │ 9 │ 0 │ ' │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │Sft│   │   │   │   │   │       │   │   │   │   │   │Sft│
      * └───┴───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┴───┘
      *               ┌───┐                   ┌───┐
      *               │Alt├───┐           ┌───┤Gui│
      *               └───┤Low├───┐   ┌───┤Cmk├───┘
      *                   └───┤Bsp│   │Spc├───┘
      *                       └───┘   └───┘
      */
    [_ADJUST] = LAYOUT_split_3x6_3(
        QK_RBT,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,              KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
        KC_PSCR, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                 KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
        _______, _______, _______, _______, _______, _______,                     _______,  _______,   _______,   _______,   _______, _______,
                                            _______, LOWER, _______,          _______, TO(COLEMAK), _______
    ),
};

bool was_in_adjust = false;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case LOWER:
      if (record->event.pressed) {
        // Allow to use the LOWER layer by holding the key down while
        // in ADJUST. When releasing LOWER, return to ADJUST rather than
        // the default layer.
        if (layer_state_is(_ADJUST)) {
          was_in_adjust = true;
          layer_off(_ADJUST);
        }
        else {
          was_in_adjust = false;
        }
        layer_on(_LOWER);
      } else {
        layer_off(_LOWER);
        if (was_in_adjust) {
          layer_on(_ADJUST);
        }
      }
      return false;
      break;

    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
      } else {
        layer_off(_RAISE);
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
    // If you are on Linux, use the normal keycodes instead of these functions.
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
