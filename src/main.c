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
    uint8_t receivedData = 0;

    lcd_init();
    UART_initRx();

    while (1) {
        // wait for instruction
        receivedData = UART_readChar();

        // check if the instruction is a command
        if (receivedData == CONTROL_CHAR) {

            // forward the command to the LCD
            lcd_exe_instruction(COMMAND_INSTRUCTION, UART_readChar());
            continue;
        }

        // print if not command
        lcd_exe_instruction(DATA_INSTRUCTION, receivedData);
    }
}
