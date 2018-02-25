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
//Dinh nghia kieu cay
struct Node{
	sinhVien data;
	Node*left;
	Node*right;
};
//Ten kieu du lieu la Tree
typedef Node*Tree;
//Ham nhap thong tin sinh vien va luu vao x sinhvien nhapsinhVien(){
    sinhVien x ;
    
	cout << " MSSV: ";
    cin >> x.MSSV;
    cout << "Ho va ten: ";
    fflush(stind);
    gets(x.hoTen);
    cout << "Tuoi:";
    cin >> x.tuoi;
return x;
}
    
 //Tao cay rong
void Init(Tree &t){
	t = NULL;
};
//Them sinh vien x vao cay t
int insertNode(Tree &t, sinhVien x){
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
int classcounter = 0;//Bien dem so lop da tao
Tree Tr[1000];//Mang luu goc cua cac cay
//Ham tao lop moi
void createTree(){
	char test;
	classcounter++;
	Init(Tr[classcounter]);
	do{	
		sinhVien x;
		x = nhapsinhVien();
		int check = insertNode(Tr[classcounter], x);
		if (check == -1)
			cout << "\nSinh vien da ton tai";
		else if (check == 0)
			cout << "\nBo nho day";
		else cout << "\nThem thanh cong";
		cout << "\nBan co muon nhap tiep (y/n): ";	
		fflush(stdin);
		cin >> test;
		if (test != 'y') cout << "\nTao thanh cong lop " << classcounter;
	}while(test == 'y');
}
