/*Trong phần này,nút có cấu trúc như sau:
struct node
{
int MSSV;
char[] Name;
int Age;
node* ChildLeft;
node* ChildRight;
};*/

/*BST có gốc là root*/

/*Hàm FindInsert để tìm chỗ Insert node mới*/

/*Tìm vị trí(con trỏ) của 1 nút phù hợp của BST để làm cha của node x cần thêm vào*/

//Định nghĩa hàm:
node* FindInsert(node* root, int x)
{
		//Nếu cây là rỗng thì trả về con trỏ NULL
	if (root == NULL)
	{
		return NULL;
	}
		//Khai báo position:con trỏ tại vị trí đang duyệt
	node* position = root;
	while (position != NULL)
	{
		//Di chuyển con trỏ position tới vị trí thích hợp kế tiếp phụ thuộc thuộc tính khóa là MSSV
		if (x < position->MSSV)
		{
			position = position->ChildLeft;
		}
		else
		{
			position = position->ChildRight;
		}
	}
	return position;
}


/*Hàm chèn Node mới vào BST*/
/*Giả thiết đã xây dựng hàm CreateNode*/
void InsertNode(node* &root, int x)
{
		//Tạo node mới với các thuộc tính MSSV,Age,Name,ChildLeft=NULL,ChildRight=NULL
	node* newSV = CreateNode(x);
		//Nếu cây rỗng thì gán node vừa tạo làm gốc
	if (root == NULL)
	{
		root = newSV;
		return;
	}
	else
	{
		//parent là con trỏ tới vị trí tìm được trả về từ hàm FindInsert,con trỏ này khác NULL do root khác NULL
		node* parent = FindInsert(root, x);
		//Vị trí(con trái hay con phải) của node mới phụ thuộc vào MSSV
			if (parent->MSSV > x)
			{
				parent->ChildLeft = newSV;
			}
			else
			{
				parent->ChildRight = newSV;
			}
		}
	}
}