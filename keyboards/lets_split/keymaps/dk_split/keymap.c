#include "flip_keymap.h"
#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _COLEMAK 1
#define _DVORAK 2
#define _LOWER 3
#define _RAISE 4
#define _NUMONE 5
#define _NUMTWO 6
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  DVORAK
};

#define LOWER  MO(_LOWER)
#define RAISE  MO(_RAISE)
#define NUMONE  MO(_NUMONE)
#define NUMTWO  MO(_NUMTWO)
#define ADJUST MO(_ADJUST)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Qwerty
* |------+------+------+------+------+------+------+------+------+------+------+------|
* |   Q  |   W  |   E  |   R  |   T  |   [  |   ]  |   Y  |   U  |   I  |   O  |   P  |
* |------+------+------+------+------+------+------+------+------+------+------+------|
* |   A  |   S  |   D  |   F  |   G  |  Tab | Bksp |   H  |   J  |   K  |   L  |   ;  |
* |------+------+------+------+------+------+------+------+------+------+------+------|
* |   Z  |   X  |   C  |   V  |   B  |   `  |  "   |   N  |   M  |   ,  |   .  |   /  |
* |------+------+------+------+------+------+------+------+------+------+------+------|
* | Ctrl | Alt  | GUI  | Lower|    Shift    |    Space    | Raise| Ctrl | Alt  | GUI  |
* `-----------------------------------------------------------------------------------'
*/
[_QWERTY] = LAYOUT_ortho_4x12( \
  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,   KC_LBRC, KC_RBRC,  KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,      \
  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,   KC_TAB , KC_BSPC,  KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,   \
  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,   KC_GRV , KC_QUOT,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,   \
  KC_LCTL, KC_LALT, KC_LGUI, NUMONE, LOWER,   KC_LSFT, KC_SPC,  RAISE,  NUMTWO,    KC_LCTL, KC_LALT, KC_LGUI   \
),


/* Lower
* |------+------+------+------+------+-------------+------+------+------+------+------|
* |      |      | Tab  |      |      |      |      |      |   `  |  up  |      | Bksp |
* |------+------+------+------+------+-------------+------+------+------+------+------|
* |  ESC | Ctrl | Alt  | GUI  |      |      |  del | Enter| left | down |right |  "   |
* |------+------+------+------+------+------|------+------+------+------+------+------|
* |      |      |      |      |      |      |      |      |      |      |      |      |
* |------+------+------+------+------+------+------+------+------+------+------+------|
* |      |      |      |      |             |    Shift    |      |      |      |Enter |
* `-----------------------------------------------------------------------------------'
*/
[_LOWER] = LAYOUT_ortho_4x12( \
  _______, _______, KC_TAB,  _______, _______, _______, _______, _______, KC_GRV, KC_UP,   _______, KC_BSPC, \
  KC_ESC,  KC_LCTL, KC_LALT, KC_LGUI, _______, _______, KC_DEL,  KC_ENT,  KC_LEFT, KC_DOWN, KC_RGHT, KC_QUOT, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, KC_LSFT, KC_LSFT, _______, _______, _______, KC_ENT   \
),

/* Raise
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
[_RAISE] = LAYOUT_ortho_4x12( \
  _______, _______, KC_VOLU, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  KC_ESC,  KC_MPLY, KC_VOLD, KC_MNXT, _______, _______, KC_DEL,  KC_ENT,  KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_BSLS, \
  _______, _______, _______, _______, _______, _______, KC_LSFT, KC_LSFT, _______, _______, _______, KC_ENT   \
),

/* NUMONE
* ,-----------------------------------------------------------------------------------.
* |   1  |   2  |   3  |   4  |   5  |   -  |  =   |   6  |   7  |   8  |   9  |   0  |
* |------+------+------+------+------+-------------+------+------+------+------+------|
* |  Esc | Play | Vol- | Next |      |      |  del | Enter|   -  |   =  |   [  |   ]  |
* |------+------+------+------+------+------|------+------+------+------+------+------|
* |      |      |      |      |      |      |      |      |      |      |      |   \  |
* |------+------+------+------+------+------+------+------+------+------+------+------|
* |      |      |      |      |             |    Shift    |      |      |      |Enter |
* `-----------------------------------------------------------------------------------'
*/
[_NUMONE] = LAYOUT_ortho_4x12( \
  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,   KC_MINS, KC_EQL,   KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    \
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, KC_LSFT, KC_LSFT, _______, _______, _______, _______   \
),

/* NUMTWO
* ,-----------------------------------------------------------------------------------.
* |   1  |   2  |   3  |   4  |   5  |   -  |  =   |   6  |   7  |   8  |   9  |   0  |
* |------+------+------+------+------+-------------+------+------+------+------+------|
* |  Esc | Play | Vol- | Next |      |      |  del | Enter|   -  |   =  |   [  |   ]  |
* |------+------+------+------+------+------|------+------+------+------+------+------|
* |      |      |      |      |      |      |      |      |      |      |      |   \  |
* |------+------+------+------+------+------+------+------+------+------+------+------|
* |      |      |      |      |             |    Shift    |      |      |      |Enter |
* `-----------------------------------------------------------------------------------'
*/
[_NUMTWO] = LAYOUT_ortho_4x12( \
  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,   KC_MINS, KC_EQL,   KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    \
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, KC_LSFT, KC_LSFT, _______, _______, _______, _______, _______, _______  \
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|      |      |      |      |      |      |      |      |      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |Aud on|Audoff|AGnorm|AGswap|Qwerty|Colemk|Dvorak|      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] =  LAYOUT_ortho_4x12( \
  _______, RESET,   _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_DEL, \
  _______, _______, _______, AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  COLEMAK, DVORAK,  _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
),



/* Colemak
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   F  |   P  |   G  |   J  |   L  |   U  |   Y  |   ;  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   R  |   S  |   T  |   D  |   H  |   N  |   E  |   I  |   O  |  '   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   K  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Adjust| Ctrl | Alt  | GUI  |Lower |Space |Space |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_COLEMAK] = LAYOUT_ortho_4x12( \
  KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC, \
  KC_ESC,  KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT, \
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT , \
  ADJUST,  KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT \
),

/* Dvorak
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   '  |   ,  |   .  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |   S  |  /   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   ;  |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   Z  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Adjust| Ctrl | Alt  | GUI  |Lower |Space |Space |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_DVORAK] = LAYOUT_ortho_4x12( \
  KC_TAB,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_BSPC, \
  KC_ESC,  KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_SLSH, \
  KC_LSFT, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_ENT , \
  ADJUST,  KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT \
)

};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
    case COLEMAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_COLEMAK);
      }
      return false;
    case DVORAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_DVORAK);
      }
      return false;
  }
  return true;
}
