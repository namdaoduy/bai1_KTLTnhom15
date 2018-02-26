// File: smallFunction.cpp
//
// Lưu các function nhỏ dùng trong các function lớn

#include "typedef.h"
#include "main.h"
#include "smallFunction.h"
#include <iostream>
#include <cstdio>
#include <iomanip>


using namespace std;


// Hàm tạo dữ liệu Student mới
// Trả về địa chỉ của Student đó
Student* createStudent() {
	// Cấp phát dữ liệu
	Student* new_student = new Student;

	do {
		fflush(stdin);
		cin.clear();
		// Nhập các thông số
		cout << "    - Nhap MSSV: ";
		cin >> new_student->MSSV;
	} while (cin.fail() == 1);

	do {
		fflush(stdin);
		cin.clear();
		cout << "    - Nhap ten: ";
		gets(new_student->name);
	} while (cin.fail() == 1);

	do {
		fflush(stdin);
		cin.clear();
		cout << "    - Nhap tuoi: ";
		cin >> new_student->age;
	} while (cin.fail() == 1);

	// Trả về địa chỉ
	return new_student;
}



// Khởi tạo 1 Node mới và gán data là student vừa tạo
Node* createNode(Student* student) {
	// Cấp phát
    Node* new_node = new Node();

	// Gán dữ liệu
    new_node->data = *student;

	// Gán NULL cho 2 con trái và phải
    new_node->child_left = new_node->child_right = NULL;

	// Trả về địa chỉ của node vừa tạo
    return new_node;
}


// Hàm findInsert để tìm chỗ Insert Node mới
// Tìm vị trí (con trỏ) của 1 nút phù hợp của BST để làm cha của new_node cần thêm vào
Node* findInsert(Node* root, Node* new_node) {
	// Nếu cây là rỗng thì trả về root
	if (root == NULL) {
		return root;
	}

    // Khai báo position: con trỏ tại vị trí đang duyệt
	Node* position = root;

	// Khai báo parent: chứa cha của vị trí tìm được
	Node* parent = position;

	while (position != NULL) {
		parent = position;
		//Di chuyển con trỏ position tới vị trí thích hợp kế tiếp phụ thuộc thuộc tính khóa là MSSV
		if ((new_node->data).MSSV < (position->data).MSSV) {
			position = position->child_left;
		}
		else {
			position = position->child_right;
		}
	}

	return parent;
}


// Hàm chèn Node mới vào BST
// Input: root và Node mới được tạo
void insertNode(Node* &root, Node* new_node) {
	// Nếu cây rỗng, insert Node vào root
	if (root == NULL) {
		root = new_node;
		return;
	} else {
		// parent là con trỏ tới vị trí tìm được trả về từ hàm findInsert,
		// con trỏ này khác NULL do root khác NULL
		Node* parent = findInsert(root, new_node);

		// Vị trí (con trái hay con phải) của Node mới phụ thuộc vào MSSV
		if ((parent->data).MSSV > (new_node->data).MSSV) {
			parent->child_left = new_node;
		}
		else {
		parent->child_right = new_node;
		}
	}

	return;
}


// Hàm addStudent() vào 1 lớp
void addStudent(Node* &root) {
	// Tạo vòng lặp
    while (1) {
        // Gọi hàm createStudent() để thêm thông tin sinh viên mới
        Student* newStudent = createStudent();
        // Gọi createNode() để gán student vừa tạo vào 1 node mới
        Node* new_node = createNode(newStudent);
        // Gọi hàm insertNode() để gán node mới vào cây
        insertNode(root, new_node);

        // Hỏi xem người dùng muốn tiếp tục thêm sinh viên không?
        cout << " Tiep tuc them sinh vien? (y/n): ";
		cin.clear();
		fflush(stdin);
        // Biến confirm để lưu lựa chọn của người dùng nhập vào
        char confirm = 'n';
        cin >> confirm;
        if (confirm != 'y')
            break;
    }
    return;
}


// Tìm kiếm địa chỉ của Node có MSSV đã cho
Node* searchNode(Tree root, int mssv) {
    // Biến curr lưu Node đang duyệt, bắt đầu duyệt từ root
    Node* curr = root;

    // Duyệt cây và so sánh mssv với MSSV của Node hiện tại
	while (curr != NULL && (curr->data).MSSV != mssv) {
        // Nếu mssv nhỏ hơn của Node hiện tại, duyệt cây con bên trái
        // không thì duyệt cây bên phải
		if (mssv < (curr->data).MSSV)
			curr = curr->child_left;
		else
			curr = curr->child_right;
	}

    return curr;
}


// Hàm in thông tin sinh viên
void printStudent(Node* node) {
	// Gán dữ liệu SV trong node vào biến temp để tiện xử lý
    Student temp = node->data;

	// In ra thông tin sinh viên
    cout << left << "       " << setw(15) << temp.MSSV << setw(30) << temp.name << setw(5) << temp.age << endl;

	return;
}


// Hàm in ra đề mục cho danh sách thông tin sinh viên
void printTitle() {
	cout << left << "       " << setw(15) <<   "MSSV"  << setw(30) <<   "TEN"   << setw(5) <<   "TUOI" << endl
		 << "       --------------------------------------------------" << endl;
	return;
}


// Hàm in ra thông tin 1 lớp theo thứ tự tăng dần MSSV
void printClass(Node* root) {
	if (root != NULL) {
		printClass(root->child_left);
		printStudent(root);
		printClass(root->child_right);
	}
}


// Hợp lớp nhỏ vào lớp lớn, sử dụng duyệt LNR
// input: mã lớp lớn, mã lớp nhỏ
// output: thông báo lớp đã được gộp
void mergeClass(Node* root, Node* sub_root) {
    if (sub_root != NULL) {
        mergeClass(root, sub_root->child_left);
        insertNode(root, sub_root);
        mergeClass(root, sub_root->child_right);
    }
}


// Hàm xóa cây con khỏi cây lớn
// tại 1 node trên cây
void deleteSubtree(Tree &root, int mssv) {
	// Biến replace để lưu địa chỉ của node vừa thay thế vào chỗ sub_root
	Node* replace = NULL;

	// Dùng vòng lặp, xóa liên tiếp địa chỉ sub_root cho đến khi địa chỉ đó chỉ vào NULL
	do {
		replace = deleteNode(root, mssv);
		// Nếu replace != NULL thì tiếp tục lấy mssv của node đó để tiếp tục xóa
		if (replace != NULL)
			mssv = (replace->data).MSSV;
	}	
	while (replace != NULL);

	return;
}


// Hàm xóa Node khỏi 1 cây
// Trả về địa chỉ của node vừa được thay thế vào chỗ xóa
Node* deleteNode(Node* &root, int ID)
{
	if (root == NULL) return NULL;
	// Đệ quy
	else if (root->data.MSSV > ID) 
		return deleteNode(root->child_left, ID);
	else if (root->data.MSSV < ID) 
		return deleteNode(root->child_right, ID);
	else {
		// Nếu Node cần xóa không có con trái thì
		// xóa Node này và nối con phải của nó vào vị trí vừa xóa
		// (con phải có thể là NULL khi Node cần xóa là lá)
		if (root->child_left == NULL) {
			root = root->child_right;
		}
		else if (root->child_right == NULL) {
			root = root->child_left;
		}

		// hoặc Xóa Node có đầy đủ cả 2 con
		else {
			// Thay thế Node cần xóa bởi NODE PHẢI NHẤT CỦA CÂY CON TRÁI
			// Khai báo most_right và father_most_right là cha của most_right
			Node* father_most_right = root->child_left;
			Node* most_right = father_most_right;
			//Nếu father_most_right không có con phải thì thao tác như sau
			if (father_most_right->child_right == NULL) {
				root->data = father_most_right->data;
				root->child_left = father_most_right->child_left;
			}
			else {
				//Vòng lặp tìm ra NODE PHẢI NHẤT CỦA CÂY CON TRÁI
				while (most_right->child_right != NULL) {
					father_most_right = most_right;
					most_right = most_right->child_right;
				}

				// Đưa thông tin của Node phải nhất vào Node cần xóa
				// Xóa Node
				root->data = most_right->data;
				father_most_right->child_right = most_right->child_left;
			}
		}
		// Trả về địa chỉ node vừa được thay thế
		return root;
	}
}
