// File: typedef.h
//
// Định nghĩa các kiểu dữ liệu
// include vào các file cần sử dụng


// Định nghĩa kiểu: Student
// Các thuộc tính:
// - MSSV (thuộc tính khóa): lưu MSSV của sinh viên
// - name: tên sinh viên
// - age: tuổi sinh viên
typedef struct Student {
	int MSSV;
	char name[40];
	int age;
} Student;


// Định nghĩa kiểu: Node
// Các thuộc tính:
// - data: lưu dữ liệu của sinh viên, kiểu Student
// - child_left: lưu pointer tới con trái
// - child_right: lưu pointer tới con phải
typedef struct Node {
	Student data;
	Node* child_left;
	Node* child_right;
} Node;


// Kiểu Tree
// Là pointer đến Node root của cây
typedef Node* Tree;
