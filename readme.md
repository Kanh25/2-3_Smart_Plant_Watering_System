Lộ trình tổng thể (thứ tự viết)
1. config.h              ← enum + struct, không phụ thuộc file nào khác
2. hal_sensor.h/.c        ← đọc cảm biến, chỉ phụ thuộc config.h
3. hal_actuator.h/.c      ← điều khiển bơm + LED, chỉ phụ thuộc config.h
4. hal_button.h/.c        ← đọc nút nhấn, chỉ phụ thuộc config.h
5. spws_logic.h/.c        ← logic nghiệp vụ, phụ thuộc config.h + cả 3 file HAL trên
6. main.c                 ← điều phối toàn bộ, phụ thuộc tất cả các file trên
- Lý do thứ tự này (bạn đã tự đề ra nguyên tắc ở đầu bài — "module độc lập trước, function phụ thuộc sau"):
config.h không gọi hàm của ai, không phụ thuộc gì → viết trước tiên.
- 3 file HAL không gọi lẫn nhau, mỗi file độc lập, chỉ cần biết config.h → viết song song, thứ tự giữa chúng không quan trọng.
- spws_logic cần biết các hàm HAL đã tồn tại (qua file .h) để gọi chúng → viết sau HAL.
- main.c cần biết tất cả mọi thứ đã có → viết cuối cùng.
+ Ở mỗi file, ta sẽ theo đúng chu trình: thiết kế .h (interface) trước → rồi mới viết .c (implementation) → rồi test ngay — đúng nguyên tắc "Header trước implementation" và "Test ngay sau mỗi function" bạn đã đề ra.