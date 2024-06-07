/* Copyright 2022 @ Keychron (https://www.keychron.com)
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
#include <stdint.h>
#include "os_detection.h"
#include "print.h"

#define L(COLOR) { RGB_ ## COLOR}

enum layers{
    MAC_BASE,
    MAC_FN_1,
    MAC_FN_2,
    WIN_BASE,
    WIN_FN_1,
    WIN_FN_2
};

const uint16_t PROGMEM rgbMapping[][MATRIX_ROWS][MATRIX_COLS][3] = {
    [MAC_FN_1] = {
        {
            //  KC_ESC,     KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,      KC_F6,      KC_F7,      KC_F8,      KC_F9,      KC_F10,     KC_F11,     KC_F12,     KNOB,       KC_PSCR,    KC_MIC,
                L(OFF),     L(OFF),     L(OFF),     L(OFF),     L(OFF),     L(OFF),     L(OFF),     L(OFF),     L(OFF),     L(OFF),     L(OFF),     L(OFF),     L(OFF),     L(OFF),     L(WHITE),     L(WHITE)
        },{
            //  KC_GRV,     KC_1,       KC_2,       KC_3,       KC_4,       KC_5,       KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       KC_MINS,    KC_EQL,     KC_BSPC,    KC_INS,     KC_HOME,
                L(OFF),     L(OFF),     L(OFF),     L(OFF),     L(OFF),     L(OFF),     L(OFF),     L(OFF),     L(OFF),     L(OFF),     L(OFF),     L(OFF),     L(OFF),     L(OFF),     L(WHITE),     L(WHITE)
        },{
            //  KC_TAB,     KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,       KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,       KC_LBRC,    KC_RBRC,    KC_BSLS,    KC_DEL,     KC_END,
                L(OFF),     L(OFF),     L(OFF),     L(OFF),     L(OFF),     L(OFF),     L(OFF),     L(OFF),     L(OFF),     L(OFF),     L(OFF),     L(OFF),     L(OFF),     L(OFF),     L(WHITE),     L(WHITE)
        }, {
            //  KC_CAPS,    KC_A,       KC_S,       KC_D,       KC_F,       KC_G,       KC_H,       KC_J,       KC_K,       KC_L,       KC_SCLN,    KC_QUOT,    KC_PGDN,    KC_ENT,     KC_RGB,     KC_PGUP,
                L(OFF),     L(OFF),     L(WHITE),   L(WHITE),   L(WHITE),   L(OFF),     L(GREEN),   L(GREEN),   L(GREEN),   L(GREEN),   L(OFF),     L(OFF),     L(WHITE),     L(OFF),     L(WHITE),     L(WHITE)
        }, {
            //  KC_LSFT,                KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,       KC_N,       KC_M,       KC_COMM,    KC_DOT,     KC_SLSH,                KC_RSFT,    KC_RGHT,    KC_UP,
                L(OFF),     L(OFF),     L(OFF),     L(OFF),     L(OFF),     L(OFF),     L(OFF),     L(OFF),     L(OFF),     L(OFF),     L(OFF),     L(OFF),     L(OFF),     L(OFF),     L(OFF),     L(WHITE)
        }, {
            //  KC_LCTL,    KC_LOPT,    KC_LCMD,                                        KC_SPC,                                         KC_RCMD,    KC_ROPT,    MO(MAC_FN), KC_RCTL,    KC_LEFT,    KC_DOWN,
                L(OFF),     L(OFF),     L(OFF),     L(OFF),     L(OFF),     L(OFF),     L(WHITE),   L(OFF),     L(OFF),     L(OFF),     L(OFF),     L(OFF),     L(OFF),     L(OFF),     L(OFF),     L(OFF)
        }
    },
    [WIN_FN_1] = {
        {
            //  KC_ESC,     KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,      KC_F6,      KC_F7,      KC_F8,      KC_F9,      KC_F10,     KC_F11,     KC_F12,     KNOB,       KC_PSCR,    KC_MIC,
                L(OFF),     L(OFF),     L(OFF),     L(OFF),     L(OFF),     L(OFF),     L(OFF),     L(OFF),     L(OFF),     L(OFF),     L(OFF),     L(OFF),     L(OFF),     L(OFF),     L(WHITE),     L(WHITE)
        },{
            //  KC_GRV,     KC_1,       KC_2,       KC_3,       KC_4,       KC_5,       KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       KC_MINS,    KC_EQL,     KC_BSPC,    KC_INS,     KC_HOME,
                L(OFF),     L(OFF),     L(OFF),     L(OFF),     L(OFF),     L(OFF),     L(OFF),     L(OFF),     L(OFF),     L(OFF),     L(OFF),     L(OFF),     L(OFF),     L(OFF),     L(WHITE),     L(WHITE)
        },{
            //  KC_TAB,     KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,       KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,       KC_LBRC,    KC_RBRC,    KC_BSLS,    KC_DEL,     KC_END,
                L(OFF),     L(OFF),     L(OFF),     L(OFF),     L(OFF),     L(OFF),     L(OFF),     L(OFF),     L(OFF),     L(OFF),     L(OFF),     L(OFF),     L(OFF),     L(OFF),     L(WHITE),     L(WHITE)
        }, {
            //  KC_CAPS,    KC_A,       KC_S,       KC_D,       KC_F,       KC_G,       KC_H,       KC_J,       KC_K,       KC_L,       KC_SCLN,    KC_QUOT,    KC_PGDN,    KC_ENT,     KC_RGB,     KC_PGUP,
                L(OFF),     L(OFF),     L(WHITE),   L(WHITE),   L(WHITE),   L(OFF),     L(GREEN),   L(GREEN),   L(GREEN),   L(GREEN),   L(OFF),     L(OFF),     L(WHITE),     L(OFF),     L(WHITE),     L(WHITE)
        }, {
            //  KC_LSFT,                KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,       KC_N,       KC_M,       KC_COMM,    KC_DOT,     KC_SLSH,                KC_RSFT,    KC_RGHT,    KC_UP,
                L(OFF),     L(OFF),     L(OFF),     L(OFF),     L(OFF),     L(OFF),     L(OFF),     L(OFF),     L(OFF),     L(OFF),     L(OFF),     L(OFF),     L(OFF),     L(OFF),     L(OFF),     L(WHITE)
        }, {
            //  KC_LCTL,    KC_LOPT,    KC_LCMD,                                        KC_SPC,                                         KC_RCMD,    KC_ROPT,    MO(MAC_FN), KC_RCTL,    KC_LEFT,    KC_DOWN,
                L(OFF),     L(OFF),     L(OFF),     L(OFF),     L(OFF),     L(OFF),     L(WHITE),   L(OFF),     L(OFF),     L(OFF),     L(OFF),     L(OFF),     L(OFF),     L(OFF),     L(OFF),     L(OFF)
        }
    }
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [MAC_BASE] = LAYOUT_tkl_f13_ansi(
        KC_ESC,         KC_F1,      KC_F2,      KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,       KC_F12,    KC_MUTE,    KC_NO,      KC_NO,      RGB_TOG,
        KC_GRV,         KC_1,       KC_2,       KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,      KC_EQL,    KC_BSPC,    KC_INS,     KC_HOME,    KC_PGUP,
        KC_TAB,         KC_Q,       KC_W,       KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,      KC_RBRC,   KC_BSLS,    KC_DEL,     KC_END,     KC_PGDN,
        MO(MAC_FN_1),   KC_A,       KC_S,       KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,                 KC_ENT,
        KC_LSFT,                    KC_Z,       KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,                 KC_RSFT,                KC_UP,
        KC_LCTL,        KC_LOPT,    KC_LCMD,                        KC_SPC,                                 KC_RCMD,  KC_ROPT,  MO(MAC_FN_2),            KC_RCTL,    KC_LEFT,    KC_DOWN,    KC_RGHT),

    [MAC_FN_1] = LAYOUT_tkl_f13_ansi(
        _______,        _______,    _______,    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,     _______,   _______,    KC_7,       KC_8,       KC_9,
        _______,        _______,    _______,    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,     _______,   _______,    KC_4,       KC_5,       KC_6,
        _______,        _______,    _______,    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,     _______,   _______,    KC_1,       KC_2,       KC_3,
        _______,        _______,    KC_LCTL,    KC_LOPT,  KC_LCMD,  _______,  KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  _______,  _______,                _______,
        _______,                    _______,    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,                _______,                KC_0,
        _______,        _______,    _______,                        LSFT_T(KC_SPC),                         _______,  _______,  _______,                _______,    _______,    _______,    _______),
    [MAC_FN_2] = LAYOUT_tkl_f13_ansi(
        _______,        KC_BRID,    KC_BRIU,    KC_MCTL,  KC_LPAD,  RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,     KC_VOLU,   RGB_MOD,    KC_7,       KC_8,       KC_9,
        _______,        _______,    _______,    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,     _______,   _______,    KC_4,       KC_5,       KC_6,
        _______,        _______,    _______,    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,     _______,   _______,    KC_1,       KC_2,       KC_3,
        _______,        _______,    KC_LCTL,    KC_LOPT,  KC_LCMD,  _______,  KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  _______,  _______,                _______,
        _______,                    _______,    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,                _______,                KC_0,
        QK_COMBO_TOGGLE,_______,    _______,                        KC_LSFT,                                _______,  _______,  _______,                _______,    _______,    _______,    _______),

    [WIN_BASE] = LAYOUT_tkl_f13_ansi(
        KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,     KC_MUTE,  KC_PSCR,  KC_NO,    RGB_MOD,
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,     KC_BSPC,  KC_INS,   KC_HOME,  KC_PGUP,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,    KC_BSLS,  KC_DEL,   KC_END,   KC_PGDN,
        MO(WIN_FN_1),  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,              KC_ENT,
        KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,              KC_RSFT,            KC_UP,
        KC_LCTL,  KC_LWIN,  KC_LALT,
                                    KC_SPC,                                 KC_RALT,  KC_RWIN,  MO(WIN_FN_2), KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT),
    [WIN_FN_1] = LAYOUT_tkl_f13_ansi(
        _______,        _______,    _______,    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,     _______,   _______,    KC_7,       KC_8,       KC_9,
        _______,        _______,    _______,    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,     _______,   _______,    KC_4,       KC_5,       KC_6,
        _______,        _______,    _______,    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,     _______,   _______,    KC_1,       KC_2,       KC_3,
        _______,        _______,    KC_LCTL,    KC_LOPT,  KC_LCMD,  _______,  KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  _______,  _______,                _______,
        _______,                    _______,    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,                _______,                KC_0,
        _______,        _______,    _______,                        LSFT_T(KC_SPC),                         _______,  _______,  _______,                _______,    _______,    _______,    _______),

    [WIN_FN_2] = LAYOUT_tkl_f13_ansi(
        _______,            KC_BRID,  KC_BRIU,  _______,  _______,  RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,    RGB_TOG,  _______,  _______,  RGB_TOG,
        KC_CAPS,            _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,  _______,  _______,
        RGB_TOG,            RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,  _______,  _______,
        RGB_TOG,            RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,  _______,  _______,  _______,  _______,  _______,  _______,              _______,
        _______,            _______,  _______,  _______,  _______,  _______,  NK_TOGG,  _______,  _______,  _______,  _______,              _______,            _______,
        QK_COMBO_TOGGLE,    _______,  _______,                                _______,                                _______,  _______,  _______,    _______,  _______,  _______,  _______),
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [MAC_BASE] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [MAC_FN_1]   = {ENCODER_CCW_CW(RGB_VAD, RGB_VAI) },
    [MAC_FN_2]   = {ENCODER_CCW_CW(RGB_VAD, RGB_VAI) },
    [WIN_BASE] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [WIN_FN_1]   = {ENCODER_CCW_CW(RGB_VAD, RGB_VAI) },
    [WIN_FN_2]   = {ENCODER_CCW_CW(RGB_VAD, RGB_VAI) }
};
#endif // ENCODER_MAP_ENABLE

void rgb_set_with_mapping(int index, const uint16_t color[]) {
    rgb_matrix_set_color(index, color[0], color[1], color[2]);
};

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max){
    if (get_highest_layer(layer_state) > 0) {
        uint8_t layer = get_highest_layer(layer_state);

        for (uint8_t row = 0; row < MATRIX_ROWS; ++row) {
            for (uint8_t col = 0; col < MATRIX_COLS; ++col) {
                uint8_t index = g_led_config.matrix_co[row][col];

                if (index >= led_min && index < led_max && index != NO_LED) {
                    rgb_set_with_mapping(index, rgbMapping[layer][row][col]);
                }
            }
        }
    }
    return false;
};

// Combos
const uint16_t PROGMEM esc[] = {KC_F, KC_J, COMBO_END};
const uint16_t PROGMEM lcmd[] = {KC_J, KC_SPC, COMBO_END};

const uint16_t PROGMEM ctrl_c[] = {KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM ctrl_v[] = {KC_S, KC_D, COMBO_END};
const uint16_t PROGMEM ctrl_x[] = {KC_A, KC_S, COMBO_END};
const uint16_t PROGMEM ctrl_z[] = {KC_S, KC_D, KC_F, COMBO_END};

const uint16_t PROGMEM delete_letter[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM delete_letter_del[] = {KC_J, KC_L, COMBO_END};
const uint16_t PROGMEM delete_word[] = {KC_K, KC_L, COMBO_END};
const uint16_t PROGMEM delete_line[] = {KC_J, KC_K, KC_L, COMBO_END};

combo_t key_combos[] = {
    COMBO(esc, KC_ESC),
    COMBO(lcmd, OSM(MOD_LGUI)),

    COMBO(delete_letter, KC_BSPC),
    COMBO(delete_letter_del, KC_DEL),
    COMBO(delete_word, LOPT(KC_BSPC)),
    COMBO(delete_line, LCMD(KC_BSPC)),

    COMBO(ctrl_c, LCMD(KC_C)),
    COMBO(ctrl_v, LCMD(KC_V)),
    COMBO(ctrl_x, LCMD(KC_X)),
    COMBO(ctrl_z, LCMD(KC_Z))
};

bool combo_should_trigger(uint16_t combo_index, combo_t *combo, uint16_t keycode, keyrecord_t *record) {
    return layer_state_is(MAC_FN_1) || layer_state_is(MAC_FN_2) || layer_state_is(MAC_BASE);
}

bool dip_switch_update_user(uint8_t index, bool active) {
    if (index == 0) {
        default_layer_set(1UL << (active ? WIN_BASE : MAC_BASE));
        return false;
    }
    return true;
}

void keyboard_post_init_user(void) {
    combo_disable();
}
