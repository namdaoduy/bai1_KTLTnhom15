// File: menuFunction.h
//
// Chứa các function chính dùng để
// bắt đầu việc thực hiện các thức năng
// trong menu

#include <iostream>
#include "startFunction.h"
#include "typedef.h"
#include "main.h"
#include "smallFunction.h"

using namespace std;

// Hàm: startCreateClass()
// Bắt đầu việc thực hiện tạo 1 lớp học mới
int startCreateClass() {
    // In ra màn hình thông báo hàm được gọi
    cout << "------------------" << endl
         << " THEM LOP HOC MOI " << endl
         << "------------------" << endl;

    // Tăng biến classCount lên 1
    classCount++;

    // biến thisClass để lưu thứ tự lớp đang được tạo
    int thisClass = classCount;

    // Thông báo lớp học đã được khởi tạo
    cout << " Lop so " << classCount << " da duoc tao!" << endl;

    // Tạo vòng lặp để thêm sinh viên
    while (1) {
        // Gọi hàm createStudent() để thêm thông tin sinh viên mới
        Student* newStudent = createStudent();
        // Gọi createNode() để gán student vừa tạo vào 1 node mới
        Node* new_node = createNode(newStudent);
        // Gọi hàm insertNode() để gán node mới vào cây
        insertNode(classRoot[thisClass], new_node);

        // Hỏi xem người dùng muốn tiếp tục thêm sinh viên không?
        cout << " Tiep tuc them sinh vien? (y/n): ";
        cin.ignore();
        // Biến confirm để lưu lựa chọn của người dùng nhập vào
        char confirm = 'n';
        cin >> confirm;
        if (confirm != 'y')
            break;
    }
    return 0;
}


// Hàm: startSearchStudent()
// Bắt đầu việc tìm kiếm sinh viên trong 1 cây
int startSearchStudent() {
    // In ra màn hình thông báo hàm được gọi
    cout << "--------------------" << endl
         << " TIM KIEM SINH VIEN " << endl
         << "--------------------" << endl;

    // Tạo vòng lặp
    while (1) {
        // Yêu cầu người dùng nhập MSSV và lớp cần tìm
        int mssv = 0;
        int class_num = 0;
        cout << " Nhap MSSV cua sinh vien can tim: ";
        cin >> mssv;
        cout << " Nhap lop can tim: ";
        cin >> class_num;

        // Thực hiện tìm kiếm
        Node* found_node = searchNode(classRoot[class_num], mssv);

        // In thông tin của sinh viên đó
        cout << " Tim thay sinh vien: " << endl
             << "--------------------" << endl;
        printStudent(found_node);

        // Hỏi xem người dùng muốn tiếp tục tìm kiếm không?
        cout << " Tiep tuc tim kiem? (y/n): ";
        cin.ignore();
        // Biến confirm để lưu lựa chọn của người dùng nhập vào
        char confirm = 'n';
        cin >> confirm;
        if (confirm != 'y')
            break;
    }
    return 0;
}


// Hàm: startAddStudent()
// Bắt đầu thêm sinh viên vào 1 lớp
int startAddStudent() {
    // In ra màn hình thông báo hàm được gọi
    cout << "----------------" << endl
         << " THEM SINH VIEN " << endl
         << "----------------" << endl;

    // Chọn lớp cần thêm sinh viên
    int class_num = 0;
    // Tạo vòng lặp để bắt nhập lại khi nhập sai lớp
    do {
        cout << " Nhap lop can them sinh vien: ";
        cin >> class_num;
    } while (class_num < 1 || class_num > classCount);

    // Tạo vòng lặp
    while (1) {
        // Gọi hàm createStudent() để thêm thông tin sinh viên mới
        Student* newStudent = createStudent();
        // Gọi createNode() để gán student vừa tạo vào 1 node mới
        Node* new_node = createNode(newStudent);
        // Gọi hàm insertNode() để gán node mới vào cây
        insertNode(classRoot[class_num], new_node);

        // Hỏi xem người dùng muốn tiếp tục thêm sinh viên không?
        cout << " Tiep tuc them sinh vien? (y/n): ";
        cin.ignore();
        // Biến confirm để lưu lựa chọn của người dùng nhập vào
        char confirm = 'n';
        cin >> confirm;
        if (confirm != 'y')
            break;
    }
    return 0;
}


// Hàm: startMergeClass()
// Bắt đầu gộp 2 lớp đã tạo
int startMergeClass() {
    // In ra màn hình thông báo hàm được gọi
    cout << "------------------" << endl
         << " GOP 2 LOP DA TAO " << endl
         << "------------------" << endl;

    // Yêu cầu người dùng nhập vào 2 lớp học
    int class_num = 0;
    int subclass_num = 0;
    cout << " Nhap lop hoc chinh: ";
    cin >> class_num;
    cout << " Nhap lop hoc phu: ";
    cin >> subclass_num;
    // Kiểm tra nếu đầu vào sai
    if (class_num < 1 || class_num > classCount || subclass_num < 1 || subclass_num > classCount || class_num == classCount) {
        cout << " Khong hop duoc lop!" << endl;
        return -1;
    }

    // Gọi hàm mergeClass để hợp lớp phụ vào lớp chính
    mergeClass(classRoot[class_num], classRoot[subclass_num]);

    return 0;
}


// Hàm: startDeleteStudent()
// Bắt đầu xóa sinh viên của 1 lớp
int startDeleteStudent() {
    // In ra màn hình thông báo hàm được gọi
    cout << "---------------" << endl
         << " XOA SINH VIEN " << endl
         << "---------------" << endl;

    // Yêu cầu nhập mssv và lớp cần xóa
    int mssv = 0;
    cout << "Nhap mssv: ";
    cin >> mssv;
    int class_num = 0;
    // Tạo vòng lặp để bắt nhập lại khi nhập sai lớp
    do {
        cout << " Nhap lop can xoa sinh vien: ";
        cin >> class_num;
    } while (class_num < 1 || class_num > classCount);

    // Tìm sinh viên
    Node* root = classRoot[class_num];
    Node* node_to_del = searchNode(classRoot[class_num], mssv);

    // Gọi hàm deleteNode() để xóa sinh viên
    deleteNode(root, node_to_del);

    return 0;
}


// Hàm: startDeleteSubtree()
// Bắt đầu xóa 1 cây con
int startDeleteSubtree() {
    cout << "-------------" << endl
         << " XOA CAY CON " << endl
         << "-------------" << endl;

    // Yêu cầu nhập mssv của sinh viên làm gốc cây con cần xóa
    int mssv;
    cout << " Nhap mssv cua sinh vien goc: ";
    cin >> mssv;

    // Nhập lớp cần xóa cây con
    int class_num = 0;
    // Tạo vòng lặp để bắt nhập lại khi nhập sai lớp
    do {
        cout << " Nhap lop can xoa cay con: ";
        cin >> class_num;
    } while (class_num < 1 || class_num > classCount);

    // Gọi hàm deleteSubtree() để xóa cây con
    deleteSubtree(classRoot[class_num], mssv);

    return 0;
}


// Hàm: startPrintClass()
// Bắt đầu in ra thông tin sinh viên của cả lớp
int startPrintClass() {
    cout << "------------------" << endl
         << " IN LOP SINH VIEN " << endl
         << "------------------" << endl;

    // Yêu cầu nhập lớp cần in
    int class_num = 0;
    // Tạo vòng lặp để bắt nhập lại khi nhập sai lớp
    do {
        cout << " Nhap lop can in: ";
        cin >> class_num;
    } while (class_num < 1 || class_num > classCount);

    // Gọi hàm printClass() để in lớp
    printClass(classRoot[class_num]);
    return 0;
}
