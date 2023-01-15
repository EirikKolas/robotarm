#include "gpio.h"
#include <stdio.h>

int gpio_test(){

    printf("%i\n", 3);

    return 0; 
}


int gpio_init(){

    GPIO0->PIN_CNF[14] = 0b101; 

    return 0; 
}


int gpio_LED2_set(int LED2_status_to_set){  //Active low somehow? I'd forgotten this, that's weird. 

    //LED2 is P0.14: https://infocenter.nordicsemi.com/index.jsp?topic=%2Fug_nrf52840_dk%2FUG%2Fdk%2Fif_mcu.html

    if (LED2_status_to_set==1){
        GPIO0->OUTSET |= 1<<14; 
    }
    else if(LED2_status_to_set==0){
        GPIO0->OUTCLR |= 1<<14; 
    }

    return 0; 
}