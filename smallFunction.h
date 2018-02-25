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
void deleteNode(Node* &root, Node* &node_to_del);
void deleteSubtree(Tree root, int mssv);
void searchNodeAndParent(Node* &curr, int mssv, Node* &parent);
