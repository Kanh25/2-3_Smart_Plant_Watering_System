#ifndef HAL_ACTUATOR_H
#define HAL_ACTUATOR_H

#include "config.h"

void TurnPumpOn(void);
void TurnPumpOff(void);
void SPWS_UpdateLed(LedState_t ledState);   // ← sửa: void + có tham số

#endif