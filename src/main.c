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

    while (1) {
    }
    return 0; // never reached
}
