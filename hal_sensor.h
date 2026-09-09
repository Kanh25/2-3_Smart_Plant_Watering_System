#ifndef HAL_SENSOR_H     // "Nếu CONFIG_H CHƯA được định nghĩa thì..."
#define HAL_SENSOR_H     // "...định nghĩa CONFIG_H ngay bây giờ"
#include "config.h"


ErrorCode ReadSoilMoisture(float *outValue);
ErrorCode ReadAirTemperature(float *outValue); // đọc cảm biến nhiệt độ (thô, trả về 1 giá trị)





#endif