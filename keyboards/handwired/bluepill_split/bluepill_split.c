#include "bluepill_split.h"
#include "i2c_master.h"

volatile int mcp23017_status = 0x20;
uint8_t i2c_initializied = 0;

uint8_t init_mcp23017(void) {
    if (!i2c_initializied) {
        i2c_init();
        i2c_initializied = 1;
    }

    uint8_t data[2];
    data[0] = 0x0;
    data[1] = 0b00111111;
    mcp23017_status = i2c_writeReg(I2C_ADDR, I2C_IODIRA, data, 2, 50000);
    if (mcp23017_status) goto out;
    data[0] = 0xFFU;
    mcp23017_status = i2c_writeReg(I2C_ADDR, I2C_GPIOA, data, 1, 5000);
    if (mcp23017_status) goto out;
    mcp23017_status = i2c_writeReg(I2C_ADDR, I2C_GPPUB, data+1, 1, 2);
    if (mcp23017_status) goto out;

 out:
    return mcp23017_status;
    // i2c_readReg(I2C_ADDR, );
}



void split_blink_all_leds(void)
{
	// TODO: Blink all leds

//    ergodox_led_all_off();
//    // ergodox_led_all_set(LED_BRIGHTNESS_DEFAULT);
//    ergodox_board_led_1_on();
//    wait_ms(50);
//    ergodox_board_led_2_on();
//    wait_ms(50);
//    ergodox_board_led_3_on();
//    wait_ms(50);
//    ergodox_board_led_1_off();
//    wait_ms(50);
//    ergodox_board_led_2_off();
//    wait_ms(50);
//    ergodox_board_led_3_off();
}
