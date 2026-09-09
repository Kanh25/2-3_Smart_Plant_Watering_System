#ifndef CONFIG_H     // "Nếu CONFIG_H CHƯA được định nghĩa thì..."
#define CONFIG_H      // "...định nghĩa CONFIG_H ngay bây giờ"


//3 ENUM
// Chế độ hoạt động của hệ thống
typedef enum {
    MODE_AUTO,      // Tự động
    MODE_MANUAL     // Thủ công
} SystemMode_t;

// Trạng thái bơm nước
typedef enum {
    PUMP_OFF,
    PUMP_ON
} PumpState_t;

// Trạng thái LED
typedef enum {
    LED_NORMAL,                // Xanh: bình thường, chờ
    LED_WATERING,               // Vàng: đang tưới
    LED_LOW_MOISTURE_ALERT,     // Đỏ nhấp nháy: cảnh báo nghiệp vụ (bơm chạy hết maxWateringDuration_s mà độ ẩm chưa lên ngưỡng)
    LED_ERROR                   // Đỏ liên tục: lỗi hệ thống/phần cứng (VD: cảm biến trả giá trị ngoài 0–100%)
} LedState_t;



//3 STRUCT
// Snapshot dữ liệu cảm biến tại 1 thời điểm — chỉ đọc, không theo dõi thời gian
typedef struct {
    float soilMoisturePercent;
    float airTemperatureCelsius;
} SensorData_t;

// Tham số cấu hình — do người dùng/nhà thiết kế đặt trước, ít thay đổi khi chạy
typedef struct {
    float minMoistureThreshold;       // Ngưỡng độ ẩm tối thiểu để bắt đầu tưới
    float maxMoistureThreshold;       // Ngưỡng độ ẩm tối đa để dừng tưới
    unsigned int maxWateringDuration_s; // Thời gian tưới tối đa (giây)
    unsigned int sensorReadInterval_s;  // Chu kỳ đọc cảm biến (giây)
    unsigned int manualWateringDuration_s; // Thời gian tưới thủ công (giây)
} SystemSettings_t;

// Trạng thái sống của hệ thống — thay đổi liên tục trong vòng lặp, chứa cả enum khác (composition)
typedef struct {
    SystemMode_t currentMode;
    PumpState_t pumpState;
    LedState_t ledState;
    unsigned int wateringTimeCounter; // Biến đếm thời gian đang tưới
    unsigned int sensorCheckCounter;  // Biến đếm cho chu kỳ đọc cảm biến
} SystemState_t;



//ERROR CODE
typedef enum {
    ERR_OK,                    // Thành công
    ERR_INVALID_PARAM,         // Con trỏ NULL hoặc tham số không hợp lệ
    ERR_SENSOR_OUT_OF_RANGE    // Giá trị cảm biến ngoài khoảng vật lý hợp lý
} ErrorCode;



#endif                // kết thúc khối #ifndef