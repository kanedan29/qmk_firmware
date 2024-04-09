/*
Base Copyright 2017 Luiz Ribeiro <luizribeiro@gmail.com>
Modified 2017 Andrew Novak <ndrw.nvk@gmail.com>
Modified 2018 Wayne Jones (WarmCatUK) <waynekjones@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public LicensezZZ
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

#define ______ KC_TRNS
#define _DEFLT 0
#define _RAISE 1



enum custom_keycodes {
    P_MACRO = SAFE_RANGE
};

// GBP £ Macro (sends alt 156 - windows users only)
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch(keycode) {
            case P_MACRO:
                SEND_STRING(SS_DOWN(X_LALT));
                SEND_STRING(SS_TAP(X_KP_1));
                SEND_STRING(SS_TAP(X_KP_5));
                SEND_STRING(SS_TAP(X_KP_6));
                SEND_STRING(SS_UP(X_LALT));
                return false; break;
        }
    }
    return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* Qwerty
     * ,-----------------------------------------------------------------------------------.
     * |   1  |   2  |   3  |   4  |   5  |   -  |  =   |   6  |   7  |   8  |   9  |   0  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |   Q  |   W  |   E  |   R  |   T  |   [  |   ]  |   Y  |   U  |   I  |   O  |   P  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |   A  |   S  |   D  |   F  |   G  |  Tab | Bksp |   H  |   J  |   K  |   L  |   ;  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |   Z  |   X  |   C  |   V  |   B  |  `   |  "   |   N  |   M  |   ,  |   .  |   /  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Ctrl | Alt  | GUI  | Lower| Sft  |    Enter    | Spc  | Raise| Ctrl | Alt  | GUI  |
     * `-----------------------------------------------------------------------------------'
     */
    [_DEFLT] = LAYOUT( \
        KC_1,    KC_2,    KC_3,    KC_4,    KC_5,   KC_MINS, KC_EQL,   KC_6,    KC_7,    KC_8,    KC_9,    KC_0,      \
        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,   KC_LBRC, KC_RBRC,  KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,      \
        KC_A,    KC_S,    KC_D,    KC_F,    KC_G,   KC_TAB, KC_BSPC,   KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,   \
        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,   KC_GRV , KC_QUOT,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,   \
        KC_LCTL, KC_LALT, KC_LGUI, MO(_LOWER),   KC_LSFT, KC_ENT, KC_ENT,  KC_SPC,  MO(_RAISE),   KC_LCTL, KC_LALT, KC_LGUI   \
    ),

    /* Lower
     * ,-----------------------------------------------------------------------------------.
     * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  | F10  | F11  | F12  |
     * |------+------+------+------+------+-------------+------+------+------+------+------|
     * |      |      | Tab  |      |      |      |      |      |   `  |  up  |      | Bksp |
     * |------+------+------+------+------+-------------+------+------+------+------+------|
     * |  ESC | Ctrl | Alt  | GUI  |      |      |  del | Enter| left | down |right |  "   |
     * |------+------+------+------+------+------|------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |      |      |      |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |             | Sft  |      |      |      |Enter |
     * `-----------------------------------------------------------------------------------'
     */
    [_LOWER] = LAYOUT( \
      KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  \
      _______, _______, KC_TAB,  _______, _______, _______, _______, _______, KC_GRV, KC_UP,   _______, KC_BSPC, \
      KC_ESC,  KC_LCTL, KC_LALT, KC_LGUI, _______, _______, KC_DEL,  KC_ENT,  KC_LEFT, KC_DOWN, KC_RGHT, KC_QUOT, \
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
      _______, _______, _______, _______, _______, _______, _______, KC_LSFT, _______, _______, _______, KC_ENT   \
    ),


    /* Raise
     * ,-----------------------------------------------------------------------------------.
     * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  | F10  | F11  | F12  |
     * |------+------+------+------+------+-------------+------+------+------+------+------|
     * |      |      | Vol+ |      |      |      |      |      |      |      |      | Bksp |
     * |------+------+------+------+------+-------------+------+------+------+------+------|
     * |  Esc | Play | Vol- | Next |      |      |  del | Enter|   -  |   =  |   [  |   ]  |
     * |------+------+------+------+------+------|------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |      |      |      |      |   \  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |             |    Shift    |      |      |      |Enter |
     * `-----------------------------------------------------------------------------------'
     */
    [_RAISE] = LAYOUT( \
      KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F11,  KC_F12,  KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,    \
      _______, _______, KC_VOLU, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
      KC_ESC,  KC_MPLY, KC_VOLD, KC_MNXT, _______, _______, KC_DEL,  KC_ENT,  KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, \
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_BSLS, \
      _______, _______, _______, _______, _______, _______, _______, KC_LSFT, _______, _______, _______, KC_ENT   \
    ),


};
