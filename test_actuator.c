#include "hal_actuator.h"

int main(void)
{
    TurnPumpOn();
    TurnPumpOff();

    SPWS_UpdateLed(LED_NORMAL);
    SPWS_UpdateLed(LED_WATERING);
    SPWS_UpdateLed(LED_LOW_MOISTURE_ALERT);
    SPWS_UpdateLed(LED_ERROR);

    return 0;
}