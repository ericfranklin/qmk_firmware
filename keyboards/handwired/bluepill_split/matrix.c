#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <hal.h>
#include "timer.h"
#include "wait.h"
#include "print.h"
#include "matrix.h"
#include "i2c_master.h"
#include QMK_KEYBOARD_H

#ifndef DEBOUNCE
#define DEBOUNCE 10
#endif
#define SPLIT_HAND_PIN A0

static uint8_t mcp23017_reset_loop = 0;

volatile matrix_row_t matrix[MATRIX_ROWS];
volatile matrix_row_t raw_matrix[MATRIX_ROWS];
volatile uint8_t debounce_matrix[MATRIX_ROWS * MATRIX_COLS];

volatile bool leftHandSide = false;

static matrix_row_t read_cols(uint8_t row);

static void init_cols(void);

static void unselect_rows(void);

static void select_row(uint8_t row);

static void init_rows(void);

__attribute__((weak)) void matrix_init_user(void) {}

__attribute__((weak)) void matrix_scan_user(void) {}

__attribute__((weak)) void matrix_init_kb(void) {
  matrix_init_user();
}

__attribute__((weak)) void matrix_scan_kb(void) {
  matrix_scan_user();
}
void isKeyboardLeft(void){

    //setPinInput(SPLIT_HAND_PIN);
	//leftHandSide = readPin(SPLIT_HAND_PIN);
	leftHandSide = true;
}

void matrix_init(void) {

	isKeyboardLeft();
  mcp23017_status = init_mcp23017(leftHandSide);
  (void) mcp23017_reset_loop;
  init_rows();
  unselect_rows();
  init_cols();


  for (uint8_t i = 0; i < MATRIX_ROWS; i++) {
    matrix[i] = 0;
    raw_matrix[i] = 0;
    for (uint8_t j = 0; j < MATRIX_COLS; ++j) {
      debounce_matrix[i * MATRIX_COLS + j] = 0;
    }
  }
  matrix_init_quantum();
}

void matrix_power_up(void) {
  mcp23017_status = init_mcp23017(leftHandSide);

  init_rows();
  unselect_rows();
  init_cols();

  for (uint8_t i = 0; i < MATRIX_ROWS; i++) {
    matrix[i] = 0;
  }
}

matrix_row_t debounce_mask(matrix_row_t rawcols, uint8_t row) {
  matrix_row_t result = 0;
  matrix_row_t change = rawcols ^raw_matrix[row];
  raw_matrix[row] = rawcols;
  for (uint8_t i = 0; i < MATRIX_COLS; ++i) {
    if (debounce_matrix[row * MATRIX_COLS + i]) {
      --debounce_matrix[row * MATRIX_COLS + i];
    } else {
      result |= (1 << i);
    }
    if (change & (1 << i)) {
      debounce_matrix[row * MATRIX_COLS + i] = DEBOUNCE;
    }
  }
  return result;
}

matrix_row_t debounce_read_cols(uint8_t row) {
  // Read the row without debouncing filtering and store it for later usage.
  matrix_row_t cols = read_cols(row);
  // Get the Debounce mask.
  matrix_row_t mask = debounce_mask(cols, row);
  // debounce the row and return the result.
  return (cols & mask) | (matrix[row] & ~mask);;
}

uint8_t matrix_scan(void) {
//  if (mcp23017_status) {
//    if (++mcp23017_reset_loop == 0) {
//      mcp23017_status = init_mcp23017(leftHandSide);
//        if (!mcp23017_status) {
//            split_blink_all_leds();
//        }
//    }
//  }


  for (uint8_t i = 0; i < MATRIX_ROWS_PER_SIDE; i++) {
    select_row(i);
    select_row(i + MATRIX_ROWS_PER_SIDE);

    matrix[i] = debounce_read_cols(i);
    matrix[i + MATRIX_ROWS_PER_SIDE] = debounce_read_cols(i + MATRIX_ROWS_PER_SIDE);

    unselect_rows();
  }

  matrix_scan_quantum();
  return 0;
}

bool matrix_is_modified(void) {
  return true;
}

inline
bool matrix_is_on(uint8_t row, uint8_t col) {
  return (matrix[row] & (1 << col));
}

inline
matrix_row_t matrix_get_row(uint8_t row) {
  return matrix[row];
}

void matrix_print(void) {
}


static matrix_row_t read_cols(uint8_t row) {
//  if (row < MATRIX_ROWS_PER_SIDE) {
//    uint8_t data = 0xFF;
//    if (!mcp23017_status) {
////      uint8_t regAddr = I2C_GPIOB;
////      mcp23017_status = i2c_readReg(I2C_ADDR, regAddr, &data, 1, 10);
//    }
//    if (mcp23017_status) {
//      return 0;
//    }
//    return (~data) & 0x3F;
//  } else {
//      uint8_t data_p = (GPIOB -> IDR);
//      uint8_t data = data_p;
//    return ((~data) & 0x3f);
//  }

	uint32_t data_a = (GPIOA -> IDR);
	uint32_t data_b = (GPIOB -> IDR);

	uint8_t data = (uint8_t)(data_a >> 15) & (uint8_t)(data_b >> 3);
	return ~data;


}


static void init_cols(void) {
  palSetPadMode(GPIOA, 15, PAL_MODE_INPUT_PULLUP);

  palSetPadMode(GPIOB, 3, PAL_MODE_INPUT_PULLUP);
  palSetPadMode(GPIOB, 4, PAL_MODE_INPUT_PULLUP);
  palSetPadMode(GPIOB, 5, PAL_MODE_INPUT_PULLUP);
  palSetPadMode(GPIOB, 6, PAL_MODE_INPUT_PULLUP);
  palSetPadMode(GPIOB, 7, PAL_MODE_INPUT_PULLUP);
  palSetPadMode(GPIOB, 8, PAL_MODE_INPUT_PULLUP);
  palSetPadMode(GPIOB, 9, PAL_MODE_INPUT_PULLUP);
}

static void init_rows(void) {

	palSetPadMode(GPIOA, 3, PAL_MODE_OUTPUT_PUSHPULL);
	palSetPadMode(GPIOA, 2, PAL_MODE_OUTPUT_PUSHPULL);
	palSetPadMode(GPIOA, 1, PAL_MODE_OUTPUT_PUSHPULL);
	palSetPadMode(GPIOA, 0, PAL_MODE_OUTPUT_PUSHPULL);


	palSetPadMode(GPIOB, 1, PAL_MODE_OUTPUT_PUSHPULL);
	palSetPadMode(GPIOB, 0, PAL_MODE_OUTPUT_PUSHPULL);

	palSetPadMode(GPIOC, 15, PAL_MODE_OUTPUT_PUSHPULL);
  }

static void unselect_rows(void) {
  GPIOA->BSRR = 0b1111;
  GPIOB->BSRR = 0b11;
  GPIOB->BSRR = 0b1 << 15;
}

static void select_row(uint8_t row) {
//  if (row < MATRIX_ROWS_PER_SIDE) {
//    if (!mcp23017_status) {
////      uint8_t data = (0xFF & ~(1 << row));
////      mcp23017_status = i2c_writeReg(I2C_ADDR, I2C_GPIOA, &data, 1, 10);
//    }
//  } else {
//    GPIOB->BRR = 0x1 << (row+1);
//  }

	switch (row) {
		case 0:
		case 1:
		case 2:
		case 3:
			GPIOA->BRR = 0x1 << (row+1);
			break;
		case 4:
		case 5:
			GPIOA->BRR = 0x1 << (row-3);
			break;
		case 6:
			GPIOC->BRR = 0x1 << (15);
			break;
		default:
			break;
	}
}



