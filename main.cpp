#include "menu.h"
#include "typedef.h"
#include <iostream>

// Các biến global:
// Tạo mảng classRoot để lưu các lớp đã được tạo
Tree classRoot[20] = {NULL};
// Biến classCount để đếm số lớp đã được tạo
int classCount = 0;


int main() {
    while (1) {
        displayMenu();
    }
    return 0;
}
