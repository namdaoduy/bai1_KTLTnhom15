// FILE: menu.cpp
//
// Chứa các hàm để hiển thị menu chức năng
// và cho người dùng lựa chọn chức năng
//
// Gọi hàm displayMenu() khi muốn sử dụng menu

#include <iostream>
#include "menu.h"

using namespace std;

// Hiển thị menu các chức năng
void displayMenu() {
    // Hiển thị các tùy chọn
    cout << "------------------------------------------------------" << endl
         << "                         MENU                         " << endl
         << endl
         << " 1. Tao 1 lop hoc moi" << endl
         << " 2. Tim kiem sinh vien trong 1 lop hoc" << endl
         << " 3. Them sinh vien vao 1 lop hoc" << endl
         << " 4. Hop 1 lop hoc nho vao lop hoc lon" << endl
         << " 5. Xoa sinh vien" << endl
         << " 6. Xoa cay con???" << endl
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
        cout << " Chon chuc nang can thuc hien (1-9): ";

        cin >> selection;

        // Gọi các hàm tùy theo lựa chọn của người dùng
        switch (selection) {
            case 1:
                createNewClass();
                break;
            case 2:
                searchStudent();
                break;
            case 3:
                addStudent();
                break;
            case 4:
                mergeClass();
                break;
            case 5:
                deleteStudent();
                break;
            case 6:
                deleteSubtree();
                break;
            case 7:
                printClass();
                break;
            default:
                cout << " Input sai cu phap, vui long nhap lai!" << endl;
        }
    } while ((selection < 1) || (selection > 7));

    return;
}
