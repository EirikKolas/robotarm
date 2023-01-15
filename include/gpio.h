#ifndef GPIO_H
#define GPIO_H

#include <stdint.h>

#define GPIO0 ((NRF_GPIO_REGS0*) 0x50000000) //gpio 0 base adress
#define GPIO1 ((NRF_GPIO_REGS1*) 0x50000300) //gpio 1 base adress

typedef struct {
	volatile uint32_t RESERVED0[321];
	volatile uint32_t OUT;
	volatile uint32_t OUTSET;
	volatile uint32_t OUTCLR;
	volatile uint32_t IN;
	volatile uint32_t DIR;
	volatile uint32_t DIRSET;
	volatile uint32_t DIRCLR;
	volatile uint32_t LATCH;
	volatile uint32_t DETECTMODE;
	volatile uint32_t RESERVED1_0[118];
	volatile uint32_t PIN_CNF[32];
} NRF_GPIO_REGS0;

typedef struct {
	volatile uint32_t RESERVED0[321];
	volatile uint32_t OUT;
	volatile uint32_t OUTSET;
	volatile uint32_t OUTCLR;
	volatile uint32_t IN;
	volatile uint32_t DIR;
	volatile uint32_t DIRSET;
	volatile uint32_t DIRCLR;
	volatile uint32_t LATCH;
	volatile uint32_t DETECTMODE;
	volatile uint32_t RESERVED1_1[118];
	volatile uint32_t PIN_CNF[10];
} NRF_GPIO_REGS1;

int gpio_test();

int gpio_LED2_set(int LED2_status_to_set); //Active low somehow? I'd forgotten this, that's weird. 

int gpio_init(); 

#endif //GPIO_H