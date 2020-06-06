/*
Copyright 2012,2013 Jun Wako <wakojun@gmail.com>

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

// Define layer names
#define _NORMAL 0
#define _FNONE 1
#define _FNTWO 2

// Highly Modified by Frank
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_NORMAL] = LAYOUT_bluepill_split( \
		/*	1			2			3			4			5			6			7			8			9 */		\
			KC_FN0, 	KC_FN0, 	KC_FN0, 	KC_FN0, 	KC_FN0, 	KC_FN0, 	RESET, 							\
			KC_ESC, 	KC_F1,  	KC_F2,  	KC_F3,  	KC_F4,  	KC_F5,  	KC_F6, 								\
			KC_GRAVE, 	KC_1,   	KC_2,   	KC_3,   	KC_4,   	KC_5,   	KC_6, 								\
			KC_TAB, 	KC_Q,   	KC_W,   	KC_E,   	KC_R,   	KC_T,   	KC_Y, 		KC_DELETE,					\
			KC_CAPS, 	KC_A,   	KC_S,   	KC_D,   	KC_F,   	KC_G,   	KC_H,		KC_END,					\
			KC_LSFT, 	KC_NUBS,	KC_Z,   	KC_X,   	KC_C,   	KC_V,   	KC_B,		KC_PGDOWN,					\
			KC_LCTL, 	KC_LGUI,	KC_LALT,      						KC_SPC,		KC_FN0,		KC_FN0)
};

/* Layer based ilumination, just binary */
layer_state_t layer_state_set_user(layer_state_t state) {
//  switch (get_highest_layer(state)) {
//  case _FNONE:
//    palSetPad(GPIOA, 0);  //OFF Color A
//    palClearPad(GPIOA, 1); //ON Color B
//    break;
//  case _FNTWO:
//    palClearPad(GPIOA, 0); //ON Color A
//    palClearPad(GPIOA, 1);  //ON Color B
//    break;
//  default: //  for any other layers, or the default layer
//    palClearPad(GPIOA, 0); //ON Color A
//    palSetPad(GPIOA, 1);  //OFF Color B
//    break;
//  }
  return state;
}
