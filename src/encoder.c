#include "../inc/encoder.h"

Encoder_t encoder = {.position = 127, .resolution = 255};

extern Servo_t servEnc;

void encoderInit(void)
{
  EICRA = (1 << ISC11)|(1 << ISC21);
  EIMSK = (1 << INT1)|(1 << INT2);
}

ISR (INT1_vect)
{
  if((PIND & (1 << 1)) != 0)
  {
    EICRA |= (1 << ISC10);
    if((PIND & (1 << 0)) != 0)
    {
      encoder.position += 255/encoder.resolution;
    }
    else
    {
      encoder.position -= 255/encoder.resolution;
    }
  }
  else
  {
    EICRA &= ~(1 << ISC10);
    if((PIND & (1 << 0)) != 0)
    {
      encoder.position -= 255/encoder.resolution;
    }
    else
    {
      encoder.position += 255/encoder.resolution;
    }      
  }
  encoder.position %= 255;
  servEnc.position = encoder.position;
}

ISR (INT2_vect)
{
  encoder.position = 127;
  servEnc.position = encoder.position;
}