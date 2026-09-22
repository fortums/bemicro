// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
enum layer_names {
    BEAT,
    FUNC
};
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     *                   ┌───-┐ 
     *  ┌───┬───┬───┐    |ESC*| *is the rotary encoder button, hold for light control toggle.
     *  | S | D | F |    └───-┘
     *  └───┴───┴───┘ 
     *┌───┬───┬───┬───┐
     *| Z | X | C | V |
     *└───┴───┴───┴───┘
     */
    [BEAT] = LAYOUT(
       KC_S, KC_D, KC_F, LT(FUNC, KC_ESC),
        KC_Z, KC_X, KC_C, KC_V
    ),
        [FUNC] = LAYOUT(
       QK_UNDERGLOW_HUE_UP, QK_UNDERGLOW_SATURATION_UP, QK_UNDERGLOW_VALUE_UP, LT(FUNC, KC_ESC),
        QK_UNDERGLOW_HUE_DOWN, QK_UNDERGLOW_SATURATION_DOWN, QK_UNDERGLOW_VALUE_DOWN, QK_UNDERGLOW_TOGGLE
    ),
};

#ifdef OLED_ENABLE
bool oled_task_user(void) {
    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);

    switch (get_highest_layer(layer_state)) {
        case BEAT:
            oled_write_P(PSTR("BEAT\n"), false);
            break;
        case FUNC:
            oled_write_P(PSTR("FUNC\n"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undefined"), false);
    }
    // Host Keyboard LED Status
    led_t led_state = host_keyboard_led_state();
    oled_write_P(led_state.num_lock ? PSTR("NUM ") : PSTR("    "), false);
    oled_write_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);
    oled_write_P(led_state.scroll_lock ? PSTR("SCR ") : PSTR("    "), false);
    
    return false;
};
#endif

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][1] = {
          // Mappings for 1st Encoder          // Mappings for 2nd Encoder
    [BEAT] = { ENCODER_CCW_CW(KC_G, KC_B)}, // Mapping for Base layer
    [FUNC] = { ENCODER_CCW_CW(KC_TRANSPARENT, KC_TRANSPARENT)} // Mapping for Layer 1
    // You can add more layers here if you need them, or you can also delete lines for layers you are not using
};
#endif