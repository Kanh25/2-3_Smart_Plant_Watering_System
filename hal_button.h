#ifndef HAL_BUTTON_H     // "Nếu CONFIG_H CHƯA được định nghĩa thì..."
#define HAL_BUTTON_H     // "...định nghĩa CONFIG_H ngay bây giờ"
#include <stdbool.h>

/* Biến static: chỉ tồn tại và "nhìn thấy được" bên trong file hal_button.c này,
   nhưng GIỮ NGUYÊN giá trị giữa các lần gọi hàm khác nhau (không mất đi sau mỗi lần gọi) */
static bool button1State;
static bool button2State;
// Không thể thất bại theo nghĩa lỗi (chỉ đọc GPIO HIGH/LOW) → dùng bool
bool IsButton1Pressed(void);
bool IsButton2Pressed(void);


/* Hàm phụ trợ để TEST giả lập việc nhấn nút — không phải hàm nghiệp vụ thật */
void SimulateButton1Press(bool pressed);
void SimulateButton2Press(bool pressed);
#endif