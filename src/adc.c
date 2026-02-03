#include "../inc/adc.h"

uint16_t value = 0;

void adcInit(void)
{
  ADMUX = (1 << REFS0)|(1 << MUX0)|(1 << MUX1);
  ADCSRA = (1 << ADFR)|(1 << ADEN)|(1 << ADPS1)|(1 << ADPS0);
}

void adcStart(void)
{
  ADCSRA |= (1 << ADSC);
}

uint16_t adcRead(void)
{
  adcStart();
  while(!(ADCSRA & (1<<ADIF)));
  ADCSRA |= (1 << ADIF);

  return(ADC);
}

ISR (ADC_vect)
{
  
}