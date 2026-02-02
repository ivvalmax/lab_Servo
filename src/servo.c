#include "../inc/servo.h"

Servo_t servAdc = {.position= 0, .permission = 1023};
Servo_t servEnc = {.position= 127, .permission = 255};

void servoInit(void)
{
  DDRB = (1 << PB5)|(1 << PB6);
}