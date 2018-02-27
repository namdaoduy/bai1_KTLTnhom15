// File: menuFunction.h
//
// Chứa các function chính dùng để
// bắt đầu việc thực hiện các thức năng
// trong menu

#include <iostream>
#include <cstdio>
#include "startFunction.h"
#include "typedef.h"
#include "main.h"
#include "smallFunction.h"

using namespace std;


// Hàm: startCreateClass()
// Bắt đầu việc thực hiện tạo lớp học mới
int startCreateClass() {
    // In ra màn hình thông báo hàm được gọi
    cout << "------------------" << endl
         << " THEM LOP HOC MOI " << endl
         << "------------------" << endl;

    // Thông báo lớp học đã được khởi tạo
    cout << " Lop da duoc tao!" << endl
         << " Bat dau them sinh vien vao lop:" << endl;

    addStudent(classRoot);

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

        // Thực hiện tìm kiếm
        Node* found_node = searchNode(classRoot, mssv);
        if (found_node != NULL) {
            // In thông tin của sinh viên đó
            cout << " Tim thay sinh vien: " << endl
                 << "--------------------" << endl;
            printTitle();
            printStudent(found_node);
        }
        else {
            cout << " Khong tim thay sinh vien!" << endl;
        }
        

        // Hỏi xem người dùng muốn tiếp tục tìm kiếm không?
        cout << " Tiep tuc tim kiem? (y/n): ";
	    cin.clear();
	    fflush(stdin);
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

    addStudent(classRoot);

    return 0;
}


// Hàm: startMergeClass()
// Bắt đầu gộp 2 lớp đã tạo
int startMergeClass() {
    // In ra màn hình thông báo hàm được gọi
    cout << "------------------" << endl
         << " THEM MOT LOP NHO " << endl
         << "------------------" << endl;

    // Tạo 1 cây con mới
    Tree sub_tree = NULL;

    // Yêu cầu người dùng nhập vào lớp nhỏ
    cout << " Nhap lop hoc phu: " << endl;
    addStudent(sub_tree);
    
    // Gọi hàm mergeClass để hợp lớp phụ vào lớp chính
    mergeClass(classRoot, sub_tree);

    return 0;
}


// Hàm: startDeleteStudent()
// Bắt đầu xóa sinh viên của 1 lớp
int startDeleteStudent() {
    // In ra màn hình thông báo hàm được gọi
    cout << "---------------" << endl
         << " XOA SINH VIEN " << endl
         << "---------------" << endl;

    // Yêu cầu nhập mssv cần xóa
    int mssv = 0;
    do {
		fflush(stdin);
		cin.clear();
		// Nhập các thông số
		cout << " Nhap MSSV: ";
		cin >> mssv;
	} while (cin.fail() == 1);

    // Gọi hàm deleteNode() để xóa sinh viên
    deleteNode(classRoot, mssv);

    return 0;
}


// Hàm: startDeleteSubtree()
// Bắt đầu xóa 1 cây con
int startDeleteSubtree() {
    cout << "-------------" << endl
         << " XOA CAY CON " << endl
         << "-------------" << endl;

    // Yêu cầu nhập mssv của sinh viên làm gốc cây con cần xóa
    int mssv = 0;
    do {
		fflush(stdin);
		cin.clear();
		// Nhập các thông số
        cout << " Nhap mssv cua sinh vien goc: ";
		cin >> mssv;
	} while (cin.fail() == 1);

    // Gọi hàm deleteSubtree() để xóa cây con
    deleteSubtree(classRoot, mssv);

    return 0;
}


// Hàm: startPrintClass()
// Bắt đầu in ra thông tin sinh viên của cả lớp
int startPrintClass() {
    cout << "------------------" << endl
         << " IN LOP SINH VIEN " << endl
         << "------------------" << endl;


    printTitle();
    // Gọi hàm printClass() để in lớp
    printClass(classRoot);
    return 0;
}
