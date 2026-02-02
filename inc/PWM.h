#ifndef PWM_H_
#define PWM_H_

#include "common.h"
#include "encoder.h"
#include "servo.h"

void PWMInit(void);
void PWMChange(Servo_t* sAdc, Servo_t* sEnc);

#endif