// test_sensor.c
#include <stdio.h>
#include "hal_sensor.h"

int main(void)
{
    float moisture;
    ErrorCode err;

    /* Test 1: Gọi với con trỏ hợp lệ */
    err = ReadSoilMoisture(&moisture);
    if (err == ERR_OK)
    {
        printf("Test 1 PASS: doc do am thanh cong, gia tri = %.1f%%\n", moisture);
    }
    else
    {
        printf("Test 1 FAIL: mong doi ERR_OK nhung nhan duoc ErrorCode = %d\n", err);
    }

    /* Test 2: Gọi với con trỏ NULL — mong đợi báo lỗi, không crash */
    err = ReadSoilMoisture(NULL);
    if (err == ERR_INVALID_PARAM)
    {
        printf("Test 2 PASS: phat hien NULL dung, ErrorCode = ERR_INVALID_PARAM\n");
    }
    else
    {
        printf("Test 2 FAIL: mong doi ERR_INVALID_PARAM nhung nhan duoc = %d\n", err);
    }

    /* Test 3: tương tự cho ReadAirTemperature() */
    float temperature;
    err = ReadAirTemperature(&temperature);
    if (err == ERR_OK)
    {
        printf("Test 3 PASS: doc nhiet do thanh cong, gia tri = %.1f C\n", temperature);
    }
    else
    {
        printf("Test 3 FAIL: mong doi ERR_OK nhung nhan duoc ErrorCode = %d\n", err);
    }

    return 0;
} 