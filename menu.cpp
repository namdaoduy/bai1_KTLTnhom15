// FILE: menu.cpp
//
// Chứa các hàm để hiển thị menu chức năng
// và cho người dùng lựa chọn chức năng
//
// Gọi hàm displayMenu() khi muốn sử dụng menu

#include "typedef.h"
#include <iostream>
#include "menu.h"
#include "main.h"
#include "startFunction.h"
#include <cstdlib>
#include <cstdio>
#include <conio.h>

using namespace std;


// Hiển thị menu các chức năng
void displayMenu() {
    // Hiển thị các tùy chọn
    cout << "----------------------------------------------------------" << endl
         << "                           MENU                           " << endl
         << " 1. Tao 1 lop hoc moi" << endl
         << " 2. Tim kiem sinh vien trong 1 lop hoc" << endl
         << " 3. Them sinh vien vao 1 lop hoc" << endl
         << " 4. Hop 1 lop hoc nho vao lop hoc lon" << endl
         << " 5. Xoa sinh vien" << endl
         << " 6. Xoa cay con" << endl
         << " 7. In danh sach lop" << endl
         << endl;

    selectMenu();
    return;
}


// Gọi hàm chức năng tương ứng với lựa chọn người dùng nhập từ bàn phím
void selectMenu() {
    // selection: biến lưu trữ lựa chọn của người dùng
    int selection = 0;

    // Tạo vòng lặp để người dùng nhập lại khi nhập sai
    do {
        cout << " Chon chuc nang can thuc hien (1-7): ";
        cin.clear();
        cin >> selection;
        fflush(stdin);
    } while ((selection < 1) || (selection > 7));

    // Kiểm tra nếu lớp đã được tạo thì không cho chọn option 1
    if (selection == 1) {
        if (classRoot == NULL) {
            startCreateClass();
        } else {
            cout << " Lop da duoc tao tu truoc! Vui long chon option khac." << endl;
        }
    } 
    // Nếu lớp chưa được tạo thì không cho chọn các option 2 -> 7
    else if (classRoot == NULL) {
        cout << " Phai tao lop hoc truoc!" << endl;
    } 
    else {
        // Gọi các hàm tùy theo lựa chọn của người dùng
        switch (selection) {
        case 2:
            startSearchStudent();
            break;
        case 3:
            startAddStudent();
            break;
        case 4:
            startMergeClass();
            break;
        case 5:
            startDeleteStudent();
            break;
         case 6:
            startDeleteSubtree();
            break;
        case 7:
            startPrintClass();
            break;
        }
    }

    cout << " Press any key..." << endl
         << endl;
    getch();
    return;
}
