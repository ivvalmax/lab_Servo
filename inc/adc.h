#ifndef ADC_H_
#define ADC_H_

#include "common.h"

void adcInit(void);
void adcStart(void);
uint16_t adcRead(void);

#endif