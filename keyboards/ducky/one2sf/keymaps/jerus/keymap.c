/* Copyright 2019 /u/KeepItUnder
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

// LAYERS
enum Layer {
    _QWERTY = 0,        // Standard QWERTY layer
    _FUNCTION,          // Function key layer
    _COLOUR             // RGB key layer
};
#define _QW _QWERTY
#define _FN _FUNCTION
#define _CLR _COLOUR

enum custom_keycodes {
    SEQ_RALT_UP = SAFE_RANGE,
    SEQ_RALT_DOWN,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case SEQ_RALT_UP:
            if (record->event.pressed) {
                // Press RIGHT ALT, release, press again, release, then press UP
                register_code(KC_RALT);
                unregister_code(KC_RALT);
                register_code(KC_RALT);
                unregister_code(KC_RALT);
                register_code(KC_UP);
            } else {
                unregister_code(KC_UP);
            }
            return false;

        case SEQ_RALT_DOWN:
            if (record->event.pressed) {
                // Press RIGHT ALT, release, press again, release, then press DOWN
                register_code(KC_RALT);
                unregister_code(KC_RALT);
                register_code(KC_RALT);
                unregister_code(KC_RALT);
                register_code(KC_DOWN);
            } else {
                unregister_code(KC_DOWN);
            }
            return false;
    }
    return true;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_all(
        QK_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_DEL,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_PGUP,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_NUHS, KC_ENT,  KC_PGDN,
        KC_LSFT, KC_NUBS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, SEQ_RALT_UP,
        KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                    KC_RALT, MO(1),   KC_RCTL, KC_LEFT, SEQ_RALT_DOWN, KC_RGHT
    ),

    [_FUNCTION] = LAYOUT_all(
        KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,    KC_F10,  KC_F11,  KC_F12,  KC_DEL,  _______,
        _______, KC_BTN1, KC_MS_U, KC_BTN2, KC_WH_U, _______, KC_INS,  _______, KC_UP,   KC_PAUSE, KC_PGUP, KC_HOME, KC_PSCR, _______, KC_HOME,
        _______, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D, _______, KC_SCRL, KC_LEFT, KC_DOWN, KC_RIGHT, KC_PGDN, KC_END,  _______, _______, KC_END,
        _______, _______, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, KC_MUTE, KC_VOLD,  KC_VOLU, _______, _______, _______,
        _______, _______, _______,                            _______,                   MO(2),    _______, _______, _______, _______, _______
    ),

    [_COLOUR] = LAYOUT_all(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, _______, _______, _______, _______, _______, _______,
        _______, _______, _______,                            _______,                   _______, _______, _______, _______, _______, _______
    ),

};
