#include <stdio.h>
#include "hal_button.h"


/* Biến static: chỉ tồn tại và "nhìn thấy được" bên trong file hal_button.c này,
   nhưng GIỮ NGUYÊN giá trị giữa các lần gọi hàm khác nhau (không mất đi sau mỗi lần gọi) */
static bool button1State = false;
static bool button2State = false;

// Không thể thất bại theo nghĩa lỗi (chỉ đọc GPIO HIGH/LOW) → dùng bool
bool IsButton1Pressed(void){
    return button1State; // Giả lập: mặc định chưa nhấn, sẽ dùng file test để giả lập việc "nhấn"
}
bool IsButton2Pressed(void){
    return button2State;
}

/* Hàm phụ trợ để TEST giả lập việc nhấn nút — không phải hàm nghiệp vụ thật */
void SimulateButton1Press(bool pressed)
{
    button1State = pressed;   // ghi thẳng vào biến static — có tác dụng thật, lưu lại được
}
void SimulateButton2Press(bool pressed)
{
    button2State = pressed;
}