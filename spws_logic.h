    #ifndef SPWS_LOGIC_H     // "Nếu CONFIG_H CHƯA được định nghĩa thì..."
    #define SPWS_LOGIC_H     // "...định nghĩa CONFIG_H ngay bây giờ"

    #include "config.h"
    #include <stdbool.h>

    // Thay đổi chế độ
    void LogModeChange(SystemMode_t newMode);
    // Bắt đầu/kết thúc tưới
    void LogWateringEvent(bool isStarting);
    ErrorCode LogSensorData(const SensorData_t *data);

    #endif
