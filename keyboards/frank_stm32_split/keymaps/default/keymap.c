#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_frank(KC_GRAVE,KC_1,KC_2,KC_3,KC_4,KC_5,KC_MINUS,KC_TAB,KC_Q,KC_W,KC_E,KC_R,KC_T,KC_LPRN,KC_ESCAPE,KC_A,KC_S,KC_D,KC_F,KC_G,KC_LSHIFT,KC_Z,KC_X,KC_C,KC_V,KC_B,KC_RPRN,KC_LCTRL,KC_LGUI,KC_LALT,KC_LGUI,KC_LALT,KC_INSERT,MO(1),KC_HOME,KC_SPACE,KC_DELETE,KC_END,KC_EQUAL,KC_6,KC_7,KC_8,KC_9,KC_0,KC_BSPACE,KC_LBRACKET,KC_Y,KC_U,KC_I,KC_O,KC_P,KC_BSLASH,KC_H,KC_J,KC_K,KC_L,KC_SCOLON,KC_QUOTE,KC_RBRACKET,KC_N,KC_M,KC_COMMA,KC_DOT,KC_SLASH,KC_RSHIFT,KC_LEFT,KC_DOWN,KC_UP,KC_RIGHT,KC_RCTRL,MO(1),TG(2),KC_PGUP,KC_PGDOWN,KC_BSPACE,KC_ENTER),

  [1] = LAYOUT_frank(KC_TILD,KC_F1,KC_F2,KC_F3,KC_F4,KC_F5,KC_F6,KC_GRAVE,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_CAPSLOCK,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_MEDIA_PLAY_PAUSE,KC_TRANSPARENT,KC_TRANSPARENT,KC_F7,KC_F8,KC_F9,KC_F10,KC_F11,KC_F12,KC_BSPACE,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,LCTL(LGUI(KC_Q)),KC_MEDIA_PREV_TRACK,KC_MEDIA_NEXT_TRACK,KC_AUDIO_VOL_DOWN,KC_AUDIO_VOL_UP),

  [2] = LAYOUT_frank(KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_NUMLOCK,KC_KP_SLASH,KC_KP_ASTERISK,KC_KP_MINUS,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_KP_7,KC_KP_8,KC_KP_9,KC_KP_PLUS,KC_TRANSPARENT,KC_TRANSPARENT,KC_KP_4,KC_KP_5,KC_KP_6,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_KP_1,KC_KP_2,KC_KP_3,KC_ENTER,KC_TRANSPARENT,KC_KP_DOT,KC_KP_0,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT),

};

const uint16_t PROGMEM fn_actions[] = {
  [1] = TT(1)
};

layer_state_t layer_state_set_user(layer_state_t state) {

    uint8_t layer = get_highest_layer(state);

    frank_led_all_off();
    frank_board_led_1_off();
    frank_board_led_2_off();
    frank_board_led_3_off();
    switch (layer) {
      case 1:
        frank_board_led_1_on();
        break;
      case 2:
        frank_board_led_2_on();
        break;
      case 3:
        frank_board_led_2_on();
        break;
      case 4:
        frank_board_led_1_on();
        frank_board_led_2_on();
        break;
      case 5:
        frank_board_led_1_on();
        frank_board_led_3_on();
        break;
      case 6:
        frank_board_led_2_on();
        frank_board_led_3_on();
        break;
      case 7:
        frank_board_led_1_on();
        frank_board_led_2_on();
        frank_board_led_3_on();
        break;
      default:
        break;
    }
    return state;

};
