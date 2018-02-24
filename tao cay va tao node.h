#include<iostream>
#include<stdlib.h>
#include<string.h>

using namespace std;
//Dinh nghia kieu du lieu sinh vien
struct sinhVien{
	int MSSV;
	char hoTen[40];
	int tuoi;
};
//creat node
struct Node{
	sinhVien data;
	Node*left;
	Node*right;
};
typedef Node*tree;
//Khoi tao cay
void init_tree(
tree& t)
{
   t = NULL;
}
//Kiem tra cay rong
int empty_tree(tree t)
{
   if(t== NULL)   return 1;

   else return 0;
}

//Them sinh vien x vao cay rong
int insertNode(tree &t, sinhVien x){
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
		else if(t->data.MSSV == x.MSSV);
			return -1;
	}
};


	
   
