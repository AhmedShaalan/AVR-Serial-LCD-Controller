#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <LCD.h>
#include <UART.h>

#define CONTROL_CHAR 0xFE

void initIO(void) {
}

int main(void) {
    initIO();
    // used to store comming instruction
    uint8_t data = 0;

    // used to indicate that I received control char
    uint8_t receivedLCDControlChar = 0;

    lcd_init();

    UART_initRx();

    while (1) {
        data = UART_getChar();

        // check if the buffer is empty
        if (data == UART_BUFFER_EMPTY) {
            continue;
        }

        // check if received data is LCD control char
        if (data == CONTROL_CHAR) {

            // set control char flag
            receivedLCDControlChar = 1;

            // continue to get next char
            continue;
        }

        // check if LCD control char is set
        if (receivedLCDControlChar == 1) {

            // forward the command to the LCD
            lcd_exe_instruction(COMMAND_INSTRUCTION, data);

            receivedLCDControlChar = 0;
            continue;
        }

        // print if received data is not command
        lcd_exe_instruction(DATA_INSTRUCTION, data);
    }
}
