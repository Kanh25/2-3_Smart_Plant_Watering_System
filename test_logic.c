#include <stdio.h>
#include <stdbool.h>
#include "spws_logic.h"

int main(void)
{
    // Thay đổi chế độ
    LogModeChange(MODE_AUTO);
    LogModeChange(MODE_MANUAL);

    LogWateringEvent(true);
    LogWateringEvent(false);

    // Test LogSensorData với dữ liệu hợp lệ
    SensorData_t sampleData;
    sampleData.soilMoisturePercent = 25.6;      // bạn tự điền 1 giá trị mẫu
    sampleData.airTemperatureCelsius = 20;    // bạn tự điền 1 giá trị mẫu

    ErrorCode err = LogSensorData(&sampleData);        // truyền gì vào đây?

    // Test LogSensorData với con trỏ NULL — kiểm tra validate
    ErrorCode err2 = LogSensorData(NULL);       // truyền gì để test NULL?
    if (err2 == ERR_INVALID_PARAM)
    {
        printf("Test NULL PASS\n");
    }

    return 0;
}