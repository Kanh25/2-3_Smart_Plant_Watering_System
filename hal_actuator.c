#include <stdio.h>
#include "config.h"
#include "hal_actuator.h"

void TurnPumpOn(void){
    printf("BOM BAT\n");
}
void TurnPumpOff(void){
    printf("BOM TAT\n");
}
void SPWS_UpdateLed(LedState_t ledstate){
    switch (ledstate){
        case LED_NORMAL: 
            printf("LED: Xanh (binh thuong)\n");
            break;
        case LED_WATERING: 
            printf("LED: Vang (dang tuoi)\n");
            break;                                 
        case LED_LOW_MOISTURE_ALERT: 
            printf("LED: Do nhap nhay (canh bao do am thap)\n");
            break;                                    
        case LED_ERROR: 
            printf("LED: Do lien tuc (loi he thong)\n");
            break;
        default:
            printf("LED: Trang thai khong xac dinh\n");
            break;
    }
}