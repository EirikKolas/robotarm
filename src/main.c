/*
 * Copyright (c) 2012-2014 Wind River Systems, Inc.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/zephyr.h>
#include <logging/log.h>
#include <dk_buttons_and_leds.h>


#include "mpu_sensor.h"
#include <nrfx_twim.h>
#include "motor_control.h"	

#define LOG_MODULE_NAME app
LOG_MODULE_REGISTER(LOG_MODULE_NAME);

#define RUN_STATUS_LED DK_LED1
#define RUN_LED_BLINK_INTERVAL 1000

#define BTN1MASK 0b0001
#define BTN2MASK 0b0010
#define BTN3MASK 0b0100
#define BTN4MASK 0b1000

#define BTN_HANDLER_REPORTER(btnmask, btnstring, button_state, has_changed) 	\
	if(btnmask & button_state & has_changed){									\
		printk("%s turned on\n", btnstring);									\
																				\
		if(btnmask==BTN1MASK){													\
			dk_set_leds_state(BTN1MASK, BTN2MASK | BTN3MASK | BTN4MASK);		\
		}																		\
		if(btnmask==BTN2MASK){													\
			dk_set_leds_state(BTN2MASK, BTN1MASK | BTN3MASK | BTN4MASK);		\
		}																		\
		if(btnmask==BTN3MASK){													\
			dk_set_leds_state(BTN3MASK, BTN2MASK | BTN1MASK | BTN4MASK);		\
		}																		\
		if(btnmask==BTN4MASK){													\
			dk_set_leds_state(BTN4MASK, BTN2MASK | BTN3MASK | BTN1MASK);		\
		}																		\
	}																			

void my_button_handler(uint32_t button_state, uint32_t has_changed){

	BTN_HANDLER_REPORTER(BTN1MASK, "BTN1", button_state, has_changed)
	BTN_HANDLER_REPORTER(BTN2MASK, "BTN2", button_state, has_changed)
	BTN_HANDLER_REPORTER(BTN3MASK, "BTN3", button_state, has_changed)
	BTN_HANDLER_REPORTER(BTN4MASK, "BTN4", button_state, has_changed)
}

static void configure_dk_buttons_leds(void){
	
	int err;
	err = dk_leds_init();
	if(err){
		LOG_ERR("Couldn't init LEDS (err %d)", err);
		while(1){
			printf("Couldn't init LEDS\n"); 
		}
	}

	err = dk_buttons_init(my_button_handler);
	if(err){
		LOG_ERR("Couldn't init BTNS (err %d)", err);
	}
}


void init_all(){

	configure_dk_buttons_leds();
	
	#ifdef MPU_SENSOR_H
	mpu_sensor_init();
	#endif

	#ifdef MOTOR_CONTROL_H
	motor_init();
	#endif

}


void main(void)
{

	init_all();
	printf("Hello world\n");

	accel_values_t accel_values = {};
	int reps;

	for(;;){
		printf("hey\n");
		reps++;
		k_sleep(K_MSEC(RUN_LED_BLINK_INTERVAL));
		dk_set_leds_state(1<<RUN_STATUS_LED, 0);
		
		k_sleep(K_MSEC(RUN_LED_BLINK_INTERVAL));
		dk_set_leds_state(0, 1<<RUN_STATUS_LED);
		if (read_accel_values(&accel_values) == 0) {
    	        printk("# %d, Accel: X: %06d, Y: %06d, Z: %06d\n", reps, accel_values.x, accel_values.y, accel_values.z);
				//printf("newprint\n");
    	    }
    	k_sleep(K_MSEC(RUN_LED_BLINK_INTERVAL/3));
	}
}

//How far did I get???

//https://github.com/edvinand/Orbit

//I got here:

//What we are doing here is that we are telling the application that we want to connect the I2C0 interrupts to our nrfx_twim_0_irq_handler.

//ctrl+f for that in link and that is how far I got

