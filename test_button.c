#include <stdio.h>
#include "hal_button.h"

int main(void)
{
    //Nút 1: ON/OFF auto mode
    bool result;
    // Bước 1: kiểm tra trạng thái mặc định
    result = IsButton1Pressed();
    if(result==false){
        printf("Test 1 PASS: mac dinh la false\n");
    }
    else{
        printf("Test 1 FAIL: mong doi false nhung nhan duoc true\n");
    }
    // Bước 2: giả lập nhấn nút 1
    SimulateButton1Press(true);
    // Bước 3: kiểm tra lại, mong đợi đã đổi thành true
    result = IsButton1Pressed();
    if (result == true)
        printf("Test 2 PASS: sau khi simulate, gia tri la true\n");
    else
        printf("Test 2 FAIL: mong doi true nhung nhan duoc false\n");


    // Bước 1: kiểm tra trạng thái mặc định
    result = IsButton2Pressed();
    if(result==false){
        printf("Test 1 PASS: mac dinh la false\n");
    }
    else{
        printf("Test 1 FAIL: mong doi false nhung nhan duoc true\n");
    }
    // Bước 2: giả lập nhấn nút 1
    SimulateButton2Press(true);
    // Bước 3: kiểm tra lại, mong đợi đã đổi thành true
    result = IsButton2Pressed();
    if (result == true)
        printf("Test 2 PASS: sau khi simulate, gia tri la true\n");
    else
        printf("Test 2 FAIL: mong doi true nhung nhan duoc false\n");

    return 0;
}