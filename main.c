#include "inc/common.h"
#include "inc/adc.h"
#include "inc/encoder.h"
#include "inc/PWM.h"
#include "inc/servo.h"

extern Servo_t servAdc, servEnc;

void allInit(void);

int main(void)
{

}

void allInit(void)
{
  adcInit();
  PWMInit();
  servoInit();
  encoderInit();

  sei();
}