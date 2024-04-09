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
#define _ZERO 0
#define _ONE 1
#define _TWO 2
#define _THREE 3

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

/* ZERO (qwerty)
* ,-----------------------------------------------------------------------------------.
* |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |   -  |  =   |
* |------+------+------+------+------+------+------+------+------+------+------+------|
* | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
* |------+------+------+------+------+------+------+------+------+------+------+------|
* | CAPS |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
* |------+------+------+------+------+------+------+------+------+------+------+------|
* | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter | (Hold for shift / tap for enter)
* |------+------+------+------+------+------+------+------+------+------+------+------|
* | THREE| Ctrl | Alt  | GUI  |TWO   |    Space    |ONE   | Left | Down |  Up  |Right |
* `-----------------------------------------------------------------------------------'
*/
[_ZERO] = LAYOUT(                                                                                                   \
  KC_GRV, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,       \
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_BSPC,        \
  KC_EQL,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,      \
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, SFT_T(KC_ENT), \
  TG(_THREE), KC_LCTL, KC_LALT, KC_LGUI, MO(_TWO),KC_SPC,KC_SPC,MO(_ONE),KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT         \
),

/* ONE
* ,-----------------------------------------------------------------------------------.
* |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
* |------+------+------+------+------+------+------+------+------+------+------+------|
* |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Del  |
* |------+------+------+------+------+------+------+------+------+------+------+------|
* |      |      |      |      |      |      |      |      |      |   [  |   ]  |  \   |
* |------+------+------+------+------+------+------+------+------+------+------+------|
* |      |      |      |      |      | ENTER       |ISO # |ISO / |  PUP |  PDN |      |
* |------+------+------+------+------+------+------+------+------+------+------+------|
* |      |      |      |  OS  |      | BACKSPACE   |      | Next | Vol- | Vol+ | Play |
* `-----------------------------------------------------------------------------------'
*/

[_ONE] = LAYOUT(                                                                                              \
  KC_ESC, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  \
  KC_F12,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,  \
  RESET,   BL_INC, RGB_SAI, _______, _______, _______, _______, _______, _______, KC_LBRC, KC_RBRC, KC_BSLS,  \
  KC_CAPS , BL_DEC, _______, _______, _______, KC_ENT, KC_ENT, KC_NUHS, KC_NUBS, KC_PGUP, KC_PGDN, _______,    \
  RGB_TOG, _______, _______, KC_LGUI, _______, KC_BSPC, KC_BSPC, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY  \
),

/* TWO
* ,-----------------------------------------------------------------------------------.
* |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
* |------+------+------+------+------+------+------+------+------+------+------+------|
* |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Del  |
* |------+------+------+------+------+------+------+------+------+------+------+------|
* |      |      |      |      |      |      |      |      |      |   {  |   }  |  |   |
* |------+------+------+------+------+------+------+------+------+------+------+------|
* |  ESC |      |      |      |      |   ENTER     |ISO ~ |ISO | |  HOM |  END |      |
* |------+------+------+------+------+------+------+------+------+------+------+------|
* |      |      |      |  OS  |      | BACKSPACE   |      | Next | Vol- | Vol+ | Play |
* `-----------------------------------------------------------------------------------'
*/

[_TWO] = LAYOUT(                                                                                                \
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,    \
  KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL,    \
  RESET, _______, _______, _______, _______, _______, _______, _______, _______, KC_LCBR, KC_RCBR, KC_PIPE,     \
  KC_ESC, _______, _______, _______, _______, KC_ENT, KC_ENT,S(KC_NUHS),S(KC_NUBS),KC_HOME, KC_END, _______,    \
  BL_STEP, _______, _______, KC_LGUI, _______, KC_BSPC, KC_BSPC, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY    \
),

/* THREE
* ,-----------------------------------------------------------------------------------.
* |      |      |  £   |      |      |      |      |      |      |      |      |      |
* |------+------+------+------+------+------+------+------+------+------+------+------|
* |      |      |      |      |      |      |      |      |      |      |      |      |
* |------+------+------+------+------+------+------+------+------+------+------+------|
* |      |      |      |      |      |      |      |      |      |      |      |      |
* |------+------+------+------+------+------+------+------+------+------+------+------|
* |      |      |      |      |      |      |      |      |      |      |      |      |
* |------+------+------+------+------+------+------+------+------+------+------+------|
* |      |      |      |      |      |      |      |      |BL_OFF|BL_DEC|BL_INC|BL_ON |
* `-----------------------------------------------------------------------------------'
*/
[_THREE] = LAYOUT(                                                                                             \
  RGB_TOG, RGB_RMOD, RGB_MOD, RGB_M_P, RGB_M_B, _______, _______, _______, _______, KC_PSLS, KC_PAST, KC_PMNS, \
  RGB_HUD, RGB_HUI, RGB_SAD, RGB_SAI, _______, _______, _______, _______, KC_P7, KC_P8, KC_P9, KC_PPLS,        \
  RGB_SPD, RGB_SPI, RGB_VAD, RGB_VAI, _______, _______, _______, _______, KC_P4, KC_P5, KC_P6, KC_PCMM,        \
  _______, _______, _______, _______, _______, _______, _______, _______, KC_P1, KC_P2, KC_P3, KC_PEQL,        \
  _______, _______, _______, _______, _______, _______, _______, _______, KC_P0, KC_P0, KC_PDOT, KC_PENT       \
)
};
