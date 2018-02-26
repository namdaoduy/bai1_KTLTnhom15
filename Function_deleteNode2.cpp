// Hàm xóa Node khỏi 1 cây
//Trả về 0 khi cây đang rỗng,không thể xóa
//Trả về 1 khi xóa thành công
int deleteNode(Node* &Tree, int ID)
{
	if (Tree == NULL) return 0;
	//Đệ quy
	else if (Tree->data.MSSV>ID) return deleteNode(Tree->child_left, ID);
	else if (Tree->data.MSSV < ID) return deleteNode(Tree->child_right, ID);
	else
	{
		// Nếu Node cần xóa không có con trái thì
		// xóa Node này và nối con phải của nó vào vị trí vừa xóa
		// (con phải có thể là NULL khi Node cần xóa là lá)
		if (Tree->child_left == NULL)
		{
			Tree = Tree->child_right;
		}
		else if (Tree->child_right == NULL)
		{
			Tree = Tree->child_left;
		}

		// hoặc Xóa Node có đầy đủ cả 2 con
		else {
			// Thay thế Node cần xóa bởi NODE PHẢI NHẤT CỦA CÂY CON TRÁI
			// Khai báo most_right và father_most_right là cha của most_right
			Node* father_most_right = Tree->child_left;
			Node* most_right = father_most_right;
			//Nếu father_most_right không có con phải thì thao tác như sau
			if (father_most_right->child_right == NULL)
			{
				Tree->data = father_most_right->data;
				Tree->child_left = father_most_right->child_left;
			}
			else
			{
				//Vòng lặp tìm ra NODE PHẢI NHẤT CỦA CÂY CON TRÁI
				while (most_right->child_right != NULL)
				{
					father_most_right = most_right;
					most_right = most_right->child_right;
				}

				//Đưa thông tin của Node phải nhất vào Node cần xóa
				//Xóa Node
				Tree->data = most_right->data;
				father_most_right->child_right = most_right->child_left;
			}


		}
		return 1;//trả về 1 nếu thực hiện thành công
	}
}
