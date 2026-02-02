#include "../inc/adc.h"

extern Servo_t  servAdc;
uint16_t value = 0;

void adcInit(void)
{
  ADMUX = (1 << REFS0)|(1 << MUX0)|(1 << MUX1);
  ADCSRA = (1 << ADIE)|(1 << ADFR)|(1 << ADPS0)|(1 << ADEN)|(1 << ADPS1);
}

void adcStart(void)
{
  ADCSRA |= (1 << ADSC);
}

ISR (ADC_vect)
{
  value = (ADCH << 8)|ADCL;

  servAdc.position = value;
  
  ADCSRA &= ~(1 << ADIF);
}