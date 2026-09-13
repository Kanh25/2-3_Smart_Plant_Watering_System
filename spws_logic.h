    #ifndef SPWS_LOGIC_H     // "Nếu CONFIG_H CHƯA được định nghĩa thì..."
    #define SPWS_LOGIC_H     // "...định nghĩa CONFIG_H ngay bây giờ"

    #include "config.h"
    #include <stdbool.h>

    // Thay đổi chế độ
    void LogModeChange(SystemMode_t newMode);
    // Bắt đầu/kết thúc tưới
    void LogWateringEvent(bool isStarting);
    ErrorCode LogSensorData(const SensorData_t *data);
    ErrorCode SPWS_UpdateSensorData(const SystemSettings_t *settings,SystemState_t *state,SensorData_t *sensorData);
    ErrorCode SPWS_HandleModeButton(SystemState_t *state);
    #endif
