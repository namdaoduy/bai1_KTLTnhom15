// File: smallFunction.h
//
// Lưu prototype của các hàm trong smallFunction.cpp

Student* createStudent();
Node* createNode(Student* student);
Node* findInsert(Node* root, Node* new_node);
void insertNode(Node* &root, Node* new_node);
Node* searchNode(Tree root, int mssv);
void printTitle();
void printStudent(Node* node);
void printClass(Node* root);
void mergeClass(Node* root, Node* sub_root);
int deleteNode(Node* &root, int ID);
void deleteSubtree(Tree root, int mssv);
void searchNodeAndParent(Node* &curr, int mssv, Node* &parent);
void addStudent(Node* &root);