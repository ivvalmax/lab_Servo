#include "../inc/PWM.h"

void PWMInit(void)
{
  TCCR1A = (1<<COM1A1)|(1<<COM1B1)|(1<<WGM10);
  TCCR1B = (1<<WGM12)|(1<<CS11)|(1<<WGM13);
  ICR1 = SERV_TOP;
  OCR1A = SERV_MIN;
  OCR1B = (SERV_MAX + SERV_MIN)/2;
}

void PWMChange(Servo_t* sAdc, Servo_t* sEnc)
{
  OCR1A = SERV_MIN + sAdc->position*2764/sAdc->permission;
  OCR1B = SERV_MIN + sEnc->position*2764/sEnc->permission;
}