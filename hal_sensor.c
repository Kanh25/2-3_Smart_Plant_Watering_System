#include <stdio.h>
#include "config.h"
#include "hal_sensor.h"


// Có thể thất bại (sensor lỗi, input không hợp lệ) → dùng ErrorCode
// đọc cảm biến độ ẩm đất (thô, trả về 1 giá trị)

ErrorCode ReadSoilMoisture(float *outValue){
    /* 1. Kiểm tra dữ liệu đầu vào hợp lệ  */
    if (outValue == NULL) {
        return ERR_INVALID_PARAM;
    }
    /*2. Gán giá trị giả lập độ ẩm */
    *outValue = 45.0f;

    /* 3. Báo thành công */
    return ERR_OK;
} 

// đọc cảm biến nhiệt độ (thô, trả về 1 giá trị)
ErrorCode ReadAirTemperature(float *outValue){
    /* 1. Kiểm tra dữ liệu đầu vào hợp lệ  */
    if (outValue == NULL) {
        return ERR_INVALID_PARAM;
    }
    /*2. Gán giá trị giả lập nhiệt độ */
    *outValue = 20.0f;

    /* 3. Báo thành công */
    return ERR_OK;
} 
