#include <stdio.h>
#include <stdbool.h>
#include "config.h"
#include "hal_button.h"
#include "hal_actuator.h"
#include "hal_sensor.h"



// Thay đổi chế độ
void LogModeChange(SystemMode_t newMode){
    if (newMode == MODE_AUTO)
    {
        printf("[LOG] Da chuyen sang che do TU DONG (AUTO)\n");
    }
    else
    {
        printf("[LOG] Da chuyen sang che do THU CONG (MANUAL)\n");
    }
}


// Bắt đầu/kết thúc tưới
void LogWateringEvent(bool isStarting){
    if (isStarting == true){
        printf("[LOG] Bat dau tuoi nuoc\n");
    }    
    else{
        printf("[LOG] Ket thuc tuoi nuoc\n");
    }    
}
//In trạng thái sensor
ErrorCode LogSensorData(const SensorData_t *data){
    /* 1. Kiểm tra dữ liệu đầu vào hợp lệ  */
    if (data == NULL) {
        return ERR_INVALID_PARAM;
    }
    /*2. In giá trị sensor*/
    printf("[LOG] Do am dat: %.1f%% | Nhiet do: %.1f C\n",
           data->soilMoisturePercent, data->airTemperatureCelsius);
    return ERR_OK;
}


// hàm điều phối: kiểm tra đã tới chu kỳ đọc chưa, nếu rồi thì gọi 2 hàm trên, lưu vào SensorData_t
ErrorCode SPWS_UpdateSensorData(const SystemSettings_t *settings,SystemState_t *state,SensorData_t *sensorData){
    if(settings == NULL || state == NULL || sensorData == NULL){
        return ERR_INVALID_PARAM;
    }
}


// ErrorCode SPWS_RunAutoMode(const SensorData_t *sensorData,const SystemSettings_t *settings,SystemState_t *state);
// SPWS_RunManualMode()
// SPWS_HandleModeButton()



// typedef enum
// {
//     ERR_OK,                   // Thành công, không có lỗi
//     ERR_INVALID_PARAM,        // Con trỏ NULL được truyền vào, hoặc tham số đầu vào không hợp lệ
//     ERR_SENSOR_OUT_OF_RANGE   // Giá trị đọc được từ cảm biến nằm ngoài khoảng vật lý hợp lý (VD: độ ẩm < 0% hoặc > 100%)
// } ErrorCode;