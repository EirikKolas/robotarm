#include "motor_control.h"

static const struct pwm_dt_spec pwm_led0 = PWM_DT_SPEC_GET(DT_ALIAS(pwm_led0));

int motor_init(){

    //LOG_INF("initializing motor\n");//Commenting in this will break code :)

    if (!device_is_ready(pwm_led0.dev)) {
    //LOG_ERR("Error: PWM device %s is not ready",
            //pwm_led0.dev->name);
    return -EBUSY;
	}

    pwm_set_dt(&pwm_led0, 20000000, 1500000);

    return 0;
}
