#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;
//Dinh nghia kieu du lieu sinh vien
struct Student {
	int MSSV;
	char Name[40];
	int Age;	
};
//Dinh nghia kieu cay
struct Node{
	Student data;
	Node* left;
	Node* right;
};
//Ten kieu du lieu la Tree
typedef Node* Tree;
//Ham nhap thong tin sinh vien va luu vao x
Student nhapstudent(){
	Student x;
	cout << "\nMSSV: ";
	cin >> x.MSSV;
	cout << "Name: ";
	fflush(stdin);
	gets(x.Name);
	cout << "Age: ";
	cin >> x.Age;
	return x;
}
//Tao cay rong
void Init(Tree &t){
	t = NULL;
};
//Them sinh vien x vao cay t
int insertNode(Tree &t, Student x){
	if (t == NULL){
		Node* p = new Node;
		p->data = x;
		p->left = p->right = NULL;
		t = p;
		return 1;
	}
	if (t != NULL){
		if (t->data.MSSV < x.MSSV) 
			return insertNode(t->right, x);
		if (t->data.MSSV > x.MSSV)
			return insertNode(t->left, x);
			return -1;
	}
};
int classcounter = 0;//Bien dem so lop da tao
Tree Tr[500];//Mang luu goc cua cac cay
//Ham tao lop moi
void createTree(){
	char test;
	classcounter++;
	Init(Tr[classcounter]);
	do{	
		Student x;
		x = nhapstudent();
		int check = insertNode(Tr[classcounter], x);
		if (check == -1)
			cout << "\nStudents exist";
		else if (check == 0)
			cout << "\nMemory full";
		else cout << "\nAdd to student ";
		cout << "\nDo you want import (y/n): ";	
		fflush(stdin);
		cin >> test;
		if (test != 'y') cout << "\nCreate class successfull " << classcounter;
	}while(test == 'y');
}
