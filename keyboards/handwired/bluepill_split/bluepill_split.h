#pragma once

#include "quantum.h"
#include "led.h"

/********************************************************************************/
/*	I2C communication with the  other board										*/
/********************************************************************************/
#define I2C_ADDR 0b01000000
#define I2C_IODIRA 0x0
#define I2C_IODIRB 0x1
#define I2C_GPIOA 0x12
#define I2C_GPIOB 0x13
#define I2C_OLATA 0x14
#define I2C_OLATB 0x15
#define I2C_GPPUA 0x0C
#define I2C_GPPUB 0x0D

extern volatile int mcp23017_status;

uint8_t init_mcp23017(bool leftHandSide);


/********************************************************************************/
/*	LED handling																*/
/********************************************************************************/

inline void ergodox_board_led_1_on(void) { palSetPad(GPIOC, 13); }
inline void ergodox_board_led_1_off(void) { palClearPad(GPIOC, 13); }

void split_blink_all_leds(void);






/********************************************************************************/
/*	Keyboard layout																*/
/********************************************************************************/

#define LAYOUT_bluepill_split( \
		K00, K01, K02, K03, K04, K05, K06, \
		K10, K11, K12, K13, K14, K15, K16, \
		K20, K21, K22, K23, K24, K25, K26, \
		K30, K31, K32, K33, K34, K35, K36, K37, \
		K40, K41, K42, K43, K44, K45, K46, K47, \
		K50, K51, K52, K53, K54, K55, K56, K57, \
		K60, K61, K62,           K65, K66, K67 ) \
												\
												\
												\
/* matrix positions each row below is a column on the keyboard */  	\
	{																\
	{K00, 	K01, 	K02, 	K03, 	K04, 	K05, 	K06, 	KC_NO},	\
	{K10, 	K11, 	K12, 	K13, 	K14, 	K15, 	K16, 	KC_NO},	\
	{K20, 	K21, 	K22, 	K23, 	K24, 	K25, 	K26, 	KC_NO},	\
	{K30, 	K31, 	K32, 	K33, 	K34, 	K35, 	K36, 	K37},	\
	{K40, 	K41, 	K42, 	K43, 	K44, 	K45, 	K46, 	K47},	\
	{K50, 	K51, 	K52, 	K53, 	K54, 	K55, 	K56, 	K57},	\
	{K60, 	K61, 	K62, 	KC_NO, 	KC_NO, 	K65, 	K66, 	K67}	\
	}

