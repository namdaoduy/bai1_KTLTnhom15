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

	// Nhập các thông số
	cout << " Nhap MSSV: ";
	cin >> new_student->MSSV;

	cout << " Nhap ten sinh vien: ";
	cin.ignore();
	gets(new_student->name);

	cout << " Nhap tuoi sinh vien: ";
	cin >> new_student->age;

	return new_student;
}


Node* createNode(Student* student) {
    Node* new_node = new Node();
    new_node->data = *student;
    new_node->child_left = new_node->child_right = NULL;
    return new_node;
}


// Hàm findInsert để tìm chỗ Insert Node mới
// Tìm vị tr í(con trỏ) của 1 nút phù hợp của BST để làm cha của new_node cần thêm vào
Node* findInsert(Node* root, Node* new_node) {
	// Nếu cây là rỗng thì trả về root
	if (root == NULL) {
		return root;
	}

    // Khai báo position: con trỏ tại vị trí đang duyệt
	Node* position = root;

	while (position != NULL) {
		//Di chuyển con trỏ position tới vị trí thích hợp kế tiếp phụ thuộc thuộc tính khóa là MSSV
		if ((new_node->data).MSSV < (position->data).MSSV) {
			position = position->child_left;
		}
		else {
			position = position->child_right;
		}
	}
	return position;
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
}



// Tìm kiếm địa chỉ của Node có MSSV đã cho
Node* searchNode(Tree root, int mssv) {
    // Biến curr lưu Node đang duyệt, bắt đầu duyệt từ root
    Node* curr = root;

    // Duyệt cây và so sánh mssv với MSSV của Node hiện tại
	while (curr != nullptr && (curr->data).MSSV != mssv) {
        // Nếu mssv nhỏ hơn của Node hiện tại, duyệt cây con bên trái
        // không thì duyệt cây bên phải
		if (mssv < (curr->data).MSSV)
			curr = curr->child_left;
		else
			curr = curr->child_right;
	}

    return curr;
}



void printStudent(Node* node) {
    Student temp = node->data;
    cout << left << setw(15) << temp.MSSV << setw(20) << temp.name << setw(5) << temp.age << endl;
}

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
    if (sub_root != nullptr) {
        mergeClass(root, sub_root->child_left);
        insertNode(root, sub_root);
        mergeClass(root, sub_root->child_right);
    }
}



// Hàm xóa Node khỏi 1 cây
void deleteNode(Node* &root, Node* &node_to_del) {
	// Nếu Node cần xóa không có con trái thì
    // xóa Node này và nối con phải của nó vào vị trí vừa xóa
    // (con phải có thể là NULL khi Node cần xóa là lá)
	if (node_to_del->child_left == NULL)
        node_to_del = node_to_del->child_right;

	// hoặc nếu Node cần xóa không có con phải hoặc là nút lá,
    // xóa Node này và nối con trái của nó vào vị trí vừa xóa
	else if (node_to_del->child_right == NULL)
        node_to_del = node_to_del->child_left;

	// hoặc Xóa Node có đầy đủ cả 2 con
	else {
		// Thay thế Node cần xóa death SV bởi NODE PHẢI NHẤT CỦA CÂY CON TRÁI
		// Khai báo most_right và father_most_right là cha của most_right
		Node* father_most_right = node_to_del->child_left;
		Node* most_right = father_most_right;

		//Vòng lặp tìm ra NODE PHẢI NHẤT CỦA CÂY CON TRÁI
		while (most_right->child_right != NULL)
		{
			father_most_right = most_right;
			most_right = most_right->child_right;
		}

		//Đưa thông tin của Node phải nhất vào Node cần xóa
		//Xóa Node
		most_right->data = node_to_del->data;
		father_most_right->child_right = most_right->child_left;
	}
}





void deleteSubtree(Tree root, int mssv) {
    Node* sub_root = searchNode(root, mssv);
    while (sub_root != nullptr) {
        deleteNode(root, sub_root);
    }

}






// Tìm kiếm Node trong cây và cha của nó
// Input: biến để lưu node và parent
// Output: thay đổi giá trị của 2 biến đó
void searchNodeAndParent(Node* &curr, int mssv, Node* &parent) {
    // traverse the tree and search for the mssv
	while (curr != nullptr && (curr->data).MSSV != mssv)
	{
	    // update parent node as current node
		parent = curr;

        // if given mssv is less than the current node, go to child_left subtree
        // else go to child_right subtree
		if (mssv < (curr->data).MSSV)
			curr = curr->child_left;
		else
			curr = curr->child_right;
	}
}
