/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

#define KC_CAD	LALT(LCTL(KC_DEL))
// Tap Dance declarations
enum {
    TD_1_EXCLAIM,
    TD_2_AT,
    TD_3_HASH,
    TD_4_DOLLAR,
    TD_5_PERCENT,
    TD_6_CIRCUMFLEX,
    TD_7_AMPERSAND,
    TD_8_ASTERISK,
    TD_GRAVE_TILDE,
    TD_LEFT_PAREN_CURLY,
    TD_RIGHT_PAREN_CURLY,
    TD_LEFT_ANGLE_BRACKET,
    TD_RIGHT_ANGLE_BRACKET,
    TD_SEMICOLON_COLON,
    TD_EQUAL_PLUS,
    TD_MINUS_UNDERSCORE,
    TD_SLASH_BACKSLASH,
    TD_QUOTE_DOUBLE_QUOTE,
    TD_TAB_TOGGLE2,
    TD_COPY_CUT,
};

// Tap Dance definitions
tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Escape, twice for Caps Lock
    [TD_1_EXCLAIM] = ACTION_TAP_DANCE_DOUBLE(KC_KP_1, KC_EXCLAIM),
    [TD_2_AT] = ACTION_TAP_DANCE_DOUBLE(KC_KP_2, KC_AT),
    [TD_3_HASH] = ACTION_TAP_DANCE_DOUBLE(KC_KP_3, KC_HASH),
    [TD_4_DOLLAR] = ACTION_TAP_DANCE_DOUBLE(KC_KP_4, KC_DOLLAR),
    [TD_5_PERCENT] = ACTION_TAP_DANCE_DOUBLE(KC_KP_5, KC_PERCENT),
    [TD_6_CIRCUMFLEX] = ACTION_TAP_DANCE_DOUBLE(KC_KP_6, KC_CIRCUMFLEX),
    [TD_7_AMPERSAND] = ACTION_TAP_DANCE_DOUBLE(KC_KP_7, KC_AMPERSAND),
    [TD_8_ASTERISK] = ACTION_TAP_DANCE_DOUBLE(KC_KP_8, KC_ASTERISK),
    [TD_GRAVE_TILDE] = ACTION_TAP_DANCE_DOUBLE(KC_GRAVE, KC_TILDE),
    [TD_LEFT_PAREN_CURLY] = ACTION_TAP_DANCE_DOUBLE(KC_LEFT_PAREN, KC_LEFT_CURLY_BRACE),
    [TD_RIGHT_PAREN_CURLY] = ACTION_TAP_DANCE_DOUBLE(KC_RIGHT_PAREN, KC_RIGHT_CURLY_BRACE),
    [TD_LEFT_ANGLE_BRACKET] = ACTION_TAP_DANCE_DOUBLE(KC_LEFT_BRACKET, KC_LEFT_ANGLE_BRACKET),
    [TD_RIGHT_ANGLE_BRACKET] = ACTION_TAP_DANCE_DOUBLE(KC_RIGHT_BRACKET, KC_RIGHT_ANGLE_BRACKET),
    [TD_SEMICOLON_COLON] = ACTION_TAP_DANCE_DOUBLE(KC_SEMICOLON, KC_COLN),
    [TD_EQUAL_PLUS] = ACTION_TAP_DANCE_DOUBLE(KC_EQUAL, KC_KP_PLUS),
    [TD_MINUS_UNDERSCORE] = ACTION_TAP_DANCE_DOUBLE(KC_KP_MINUS, KC_UNDERSCORE),
    [TD_SLASH_BACKSLASH] = ACTION_TAP_DANCE_DOUBLE(KC_KP_SLASH, KC_BACKSLASH),
    [TD_QUOTE_DOUBLE_QUOTE] = ACTION_TAP_DANCE_DOUBLE(KC_QUOTE, KC_DOUBLE_QUOTE),
    [TD_TAB_TOGGLE2] = ACTION_TAP_DANCE_LAYER_TOGGLE(KC_TAB, 2),
    [TD_COPY_CUT] = ACTION_TAP_DANCE_DOUBLE(KC_COPY, KC_CUT),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       TD(TD_TAB_TOGGLE2),    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_ESCAPE,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      LCTL(KC_S),    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, TD(TD_QUOTE_DOUBLE_QUOTE), KC_ENTER,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LEFT_CTRL,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_KP_DOT, KC_QUESTION,  XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, KC_LEFT_SHIFT,  KC_SPACE,     KC_BACKSPACE,   MO(1), XXXXXXX
                                      //`--------------------------'  `--------------------------'

  ),

    [1] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       TD(TD_GRAVE_TILDE), TD(TD_1_EXCLAIM), TD(TD_2_AT), TD(TD_3_HASH), TD(TD_4_DOLLAR), TD(TD_5_PERCENT),                         TD(TD_6_CIRCUMFLEX), TD(TD_7_AMPERSAND), TD(TD_8_ASTERISK), KC_KP_9, KC_KP_0, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, TD(TD_SLASH_BACKSLASH), TD(TD_MINUS_UNDERSCORE), TD(TD_EQUAL_PLUS), TD(TD_LEFT_PAREN_CURLY), TD(TD_RIGHT_PAREN_CURLY),                      TD(TD_LEFT_ANGLE_BRACKET), TD(TD_RIGHT_ANGLE_BRACKET), TD(TD_SEMICOLON_COLON), KC_PIPE, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LEFT_GUI, _______,  _______,     KC_DELETE,   _______, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  ),

    [2] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       TD(TD_TAB_TOGGLE2), XXXXXXX, TD(TD_COPY_CUT), KC_UP, KC_PASTE, XXXXXXX,                      XXXXXXX, KC_MS_WH_UP, KC_MS_UP, KC_MS_WH_DOWN, XXXXXXX, KC_AUDIO_VOL_UP,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN, KC_RIGHT, XXXXXXX,                      XXXXXXX, KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT, XXXXXXX, KC_AUDIO_VOL_DOWN,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_CAD, XXXXXXX, XXXXXXX, LCTL_T(KC_Y), LCTL_T(KC_U), XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_AUDIO_MUTE,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX,   KC_LEFT_SHIFT,  KC_LEFT_ALT,     KC_MS_BTN1, KC_MS_BTN2, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  )
};
