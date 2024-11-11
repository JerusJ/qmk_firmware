/* Copyright 2024 @ Keychron (https://www.keychron.com)
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

#include <stdint.h>
#include "action.h"
#include "keycodes.h"
#include QMK_KEYBOARD_H
#include "keychron_common.h"

enum layers {
    BASE,
    FN,
    L2,
    L3,
};

enum custom_keycodes {
    SEQ_RALT_UP = SAFE_RANGE,
    SEQ_RALT_DOWN,
    SEQ_MONA_1,
    SEQ_MONA_2,
    SEQ_MONA_3,
    SEQ_MONA_4,
    SEQ_MONB_1,
    SEQ_MONB_2,
    SEQ_MONB_3,
    SEQ_MONB_4,
    SEQ_MONC_1,
    SEQ_MONC_2,
    SEQ_MONC_3,
    SEQ_MONC_4,
};

enum MONITOR_TYPE {
    MONITOR_ALL,
    MONITOR_A,
    MONITOR_B,
    MONITOR_C
};

void tessmart_swap_monitor(enum MONITOR_TYPE monitor, uint16_t monitor_num) {
    tap_code(KC_RIGHT_CTRL);
    wait_ms(100);
    tap_code(KC_RIGHT_CTRL);

    wait_ms(100);
    switch (monitor) {
        case MONITOR_ALL:
            tap_code(KC_UP);
            break;
        case MONITOR_A:
            tap_code(KC_LEFT);
            break;
        case MONITOR_B:
            tap_code(KC_DOWN);
            break;
        case MONITOR_C: // NOTE(jesse): this is a complete and utter guess, their docs are not accurate.
            tap_code(KC_RIGHT);
            break;
    }

    wait_ms(100);
    switch (monitor_num) {
        case 1:
            tap_code(KC_1);
            break;
        case 2:
            tap_code(KC_2);
            break;
        case 3:
            tap_code(KC_3);
            break;
        case 4:
            tap_code(KC_4);
            break;
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case SEQ_RALT_UP:
            if (record->event.pressed) {
                // Press RIGHT ALT, release, press again, release, then press UP
                tap_code(KC_RALT);
                wait_ms(100);
                tap_code(KC_RALT);
                wait_ms(100);
                tap_code(KC_UP);
            }
            return false;

        case SEQ_RALT_DOWN:
            if (record->event.pressed) {
                // Press RIGHT ALT, release, press again, release, then press DOWN
                tap_code(KC_RALT);
                wait_ms(100);
                tap_code(KC_RALT);
                wait_ms(100);
                tap_code(KC_DOWN);
            }
            return false;

        // Monitor A
        case SEQ_MONA_1:
            if (record->event.pressed) {
                tessmart_swap_monitor(MONITOR_A, 1);
            }
            return false;
        case SEQ_MONA_2:
            if (record->event.pressed) {
                tessmart_swap_monitor(MONITOR_A, 2);
            }
            return false;
        case SEQ_MONA_3:
            if (record->event.pressed) {
                tessmart_swap_monitor(MONITOR_A, 3);
            }
            return false;
        case SEQ_MONA_4:
            if (record->event.pressed) {
                tessmart_swap_monitor(MONITOR_A, 4);
            }
            return false;

        // Monitor B
        case SEQ_MONB_1:
            if (record->event.pressed) {
                tessmart_swap_monitor(MONITOR_B, 1);
            }
            return false;
        case SEQ_MONB_2:
            if (record->event.pressed) {
                tessmart_swap_monitor(MONITOR_B, 2);
            }
            return false;
        case SEQ_MONB_3:
            if (record->event.pressed) {
                tessmart_swap_monitor(MONITOR_B, 3);
            }
            return false;
        case SEQ_MONB_4:
            if (record->event.pressed) {
                tessmart_swap_monitor(MONITOR_B, 4);
            }
            return false;

        // Monitor C
        case SEQ_MONC_1:
            if (record->event.pressed) {
                tessmart_swap_monitor(MONITOR_C, 1);
            }
            return false;
        case SEQ_MONC_2:
            if (record->event.pressed) {
                tessmart_swap_monitor(MONITOR_C, 2);
            }
            return false;
        case SEQ_MONC_3:
            if (record->event.pressed) {
                tessmart_swap_monitor(MONITOR_C, 3);
            }
            return false;
        case SEQ_MONC_4:
            if (record->event.pressed) {
                tessmart_swap_monitor(MONITOR_C, 4);
            }
            return false;
    }
    return true;
}


// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT_tenkey_27(
        KC_MUTE, KC_ESC,         KC_DEL,         KC_TAB,         KC_BSPC,
        MC_1,	 SEQ_MONA_4,     SEQ_MONB_4,     SEQ_MONC_4,     KC_PMNS,
        MC_2,	 SEQ_MONA_3,	 SEQ_MONB_3,	 SEQ_MONC_3,	 SEQ_RALT_UP,
        MC_3,	 SEQ_MONA_2,	 SEQ_MONB_2,	 SEQ_MONC_2,
        MC_4,	 SEQ_MONA_1,	 SEQ_MONB_1,	 SEQ_MONC_1,	 SEQ_RALT_DOWN,
        MO(FN),  KC_P0,          KC_PDOT         ),

    [FN] = LAYOUT_tenkey_27(
        RGB_TOG, BT_HST1, BT_HST2, BT_HST3, P2P4G,
        _______, RGB_MOD, RGB_VAI, RGB_HUI, _______,
        _______, RGB_RMOD,RGB_VAD, RGB_HUD, _______,
        _______, RGB_SAI, RGB_SPI, KC_MPRV,
        _______, RGB_SAD, RGB_SPD, KC_MPLY, _______,
        _______, RGB_TOG,          KC_MNXT          ),

    [L2] = LAYOUT_tenkey_27(
        _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,
        _______, _______, _______, _______,
        _______, _______, _______, _______, _______,
        _______, _______,          _______          ),

    [L3] = LAYOUT_tenkey_27(
        _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,
        _______, _______, _______, _______,
        _______, _______, _______, _______, _______,
        _______, _______,          _______          )
};

// clang-format on
#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [BASE] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [FN]   = {ENCODER_CCW_CW(RGB_VAD, RGB_VAI)},
    [L2]   = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [L3]   = {ENCODER_CCW_CW(RGB_VAD, RGB_VAI)},
};
#endif // ENCODER_MAP_ENABLE

// bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//     if (!process_record_keychron_common(keycode, record)) {
//         return false;
//     }
//     return true;
// }
//

