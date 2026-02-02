#ifndef SERVO_H_
#define SERVO_H_

#include "common.h"

#define SERV_TOP 27648
#define SERV_MAX (SERV_TOP/10)
#define SERV_MIN (SERV_TOP/20)

typedef struct Servo
{
  uint16_t position;
  uint16_t permission;
} Servo_t;

void servoInit(void);

#endif