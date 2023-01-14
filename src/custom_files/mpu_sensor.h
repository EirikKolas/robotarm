#ifndef MPU_SENSOR_H
#define MPU_SENSOR_H

#include <zephyr.h>
#include <logging/log.h>
#include <nrfx_twim.h>

/* Structure to hold acceleromter values.
 * All values are unsigned 16 bit integers
*/
typedef struct
{
    int16_t x;
    int16_t y;
    int16_t z;
}accel_values_t;


/*Structure to hold gyroscope values. 
 * All values are unsigned 16 bit integers
*/
typedef struct
{
    int16_t x;
    int16_t y;
    int16_t z;
}gyro_values_t;


int mpu_sensor_init();

int read_accel_values(accel_values_t * p_accel_values_destination);

int read_gyro_values();

#endif
