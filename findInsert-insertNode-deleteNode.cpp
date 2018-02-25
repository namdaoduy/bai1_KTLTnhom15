/*Trong phần này,nút có cấu trúc như sau:
typedef struct Node
{
struct Student
	{
int MSSV;
char[40] name;
int age;
	}
Node* child_left;
Node* child_right;
} Node;*/

/*BST có gốc là root*/

/*Hàm findInsert để tìm chỗ Insert Node mới*/

/*Tìm vị trí(con trỏ) của 1 nút phù hợp của BST để làm cha của Node x cần thêm vào*/

//Định nghĩa hàm:
Node* findInsert(Node* root, int x)
{
		//Nếu cây là rỗng thì trả về con trỏ NULL
	if (root == NULL)
	{
		return NULL;
	}
		//Khai báo position:con trỏ tại vị trí đang duyệt
	Node* position = root;
	while (position != NULL)
	{
		//Di chuyển con trỏ position tới vị trí thích hợp kế tiếp phụ thuộc thuộc tính khóa là MSSV
		if (x < position->Student.MSSV)
		{
			position = position->child_left;
		}
		else
		{
			position = position->child_right;
		}
	}
	return position;
}


/*Hàm chèn Node mới vào BST*/
/*Input là con trỏ tới Node cần thêm và gốc của cây đích*/
/*Hàm này sử dụng hàm searchStudentLNR(Node* root, int MSSV) để tìm con trỏ tới node có MSSV cần thêm*/
void insertNode(Node* &root, int x)
{
	Node* newSV = searchStudentLNR(root,x);
		//Nếu cây rỗng thì gán Node vừa tạo làm gốc
	if (root == NULL)
	{
		root = newSV;
		return;
	}
	else
	{
		//parent là con trỏ tới vị trí tìm được trả về từ hàm findInsert,con trỏ này khác NULL do root khác NULL
		Node* parent = findInsert(root, x);
		//Vị trí(con trái hay con phải) của Node mới phụ thuộc vào MSSV
			if (parent->Student.MSSV > x)
			{
				parent->child_left = newSV;
			}
			else
			{
				parent->child_right = newSV;
			}
		}
	}
}


/*Chức năng xóa Sinh Viên*/
	/*Hàm này sử dụng hàm searchStudentLNR(Node* root, int MSSV) để tìm con trỏ tới node có MSSV cần xóa*/
	/*Xóa nút có khóa là x trên cây có gốc root*/
void deleteNode(Node* &root, int x)
	//Khai báo con trỏ deathSV trỏ tới node cần xóa
{
	Node* deathSV = searchStudentLNR(root, x);
		//Nếu Node cần xóa không có con trái,xóa Node này và nối con phải của nó vào vị trí vừa xóa(con phải có thể là NULL khi Node cần xóa là lá)
	if (deathSV->child_left == NULL) deathSV = deathSV->Right;
		//hoặc nếu Node cần xóa không có con phải hoặc là nút lá,xóa Node này và nối con trái của nó vào vị trí vừa xóa
	else if (deathSV->Right == NULL) deathSV = deathSV->Left;
		//hoặc Xóa Node có đầy đủ cả 2 con
	else
	{
		/*Thay thế Node cần xóa death SV bởi NODE PHẢI NHẤT CỦA CÂY CON TRÁI*/
		//Khai báo most_right và tree_most_right là cha của most_right
		Node* tree_most_right = deathSV->child_left;
		Node* most_right = tree_most_right;
		//Vòng lặp tìm ra NODE PHẢI NHẤT CỦA CÂY CON TRÁI
		while (most_right->child_right != NULL)
		{
			tree_most_right = most_right;
			most_right = most_right->child_right;
		}
		//Đưa thông tin của Node phải nhất vào Node cần xóa
		//Xóa Node 
		most_right->Student = deathSV->Student;
		tree_most_right->child_right = most_right->child_left;
		Delete most_right;
	}
	return 1;
}


