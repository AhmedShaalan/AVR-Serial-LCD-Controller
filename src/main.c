#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <LCD.h>

void initIO(void) {
}

int main(void) {
    initIO();

    /* Initialize LCD 					*/
    lcd_init();
    _delay_ms(1000);
    lcd_cursor_home();
    lcd_clear_display();

    // initialize UART to read only
    // wait for instruction
    // check if the instruction is command?
    // - if command, wait for the command
    // - excute command
    // if not instruction
    // - print

    while (1) {
    }
    return 0; // never reached
}
