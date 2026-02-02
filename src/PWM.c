#include "../inc/PWM.h"

void PWMInit(void)
{
  TCCR1A = (1<<COM1A1)|(1<<COM1B1)|(1<<WGM10);
  TCCR1B = (1<<WGM12)|(1<<CS11)|(1<<WGM13);
  OCR1AH = 0;
  OCR1AL = 0;
  OCR1BH = 0;
  OCR1BL = 0;
}

void PWMChange(Encoder_t* ledPtr)
{
  
}