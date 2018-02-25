NODE* SearchNode(NODE* root,int x)
{
 cout<<"\nNhap ID cua sinh vien can tim: ";
 cin>>x;
 int i=0;
 while (i< countdata)
  {if (root == NULL)
        return NULL;
  if (root -> data[i].mssv == x)
        return root;
  if (root -> data[i].mssv > x)
      SearchNode(root -> child_left, x);
  else SearchNode(root -> child_right, x);
  i++
 }
}
void LNR(NODE* root, sinhvien data[], int countdata) //countdata la so sv cua lop, co the viet them ham dem so sv
{
 int i = 0;
 cout<<left<<setw(5)<<"dataT"<<setw(15)<<"ID"<<setw(20)<<"TEN"<<setw(5)<<"TUOI"
 while (i<countdata)
 {
  if (root != NULL){
       LNR (root -> child_left, sinhvien data[], countdata)
       cout<<left<<setw(5)<<i+1<<setw(15)<<data[i].mssv<<setw(20)<<data[i].name<<setw(5)
<<data[i].age;
  cout<<"\n";
       LNR(root->child_right, sinhvien data[], countdata);
   }
   i++;
 }
}
