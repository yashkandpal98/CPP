#include<iostream>
#include"Binary_Tree-Sample_1.cpp"
#include"Binary_Tree-Sample_2.cpp"
using namespace std;


int main()
{
	BSTnode *root=NULL;
	insert(root, 5);
	insert(root, 10);
	insert(root, 1);
	insert(root, 4);
	insert(root, 15);
	insert(root, 8);
	insert(root, 23);
	int x;
	cout<<"Enter element to search: ";cin>>x;cout<<endl;
	if(search(root, x)) cout<<"\nFound\n";
	else cout<<"\nNot found\n";
	cout<<"\nLDR display:\n\n"; show(root);	
	return 0;
}
