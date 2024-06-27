#include<iostream>
using namespace std;

typedef struct  BSTnode
{
	BSTnode *lchild;
	int key;
	BSTnode *rchild;
} *bstptr;

bstptr GetNewNode(int x)
{
	bstptr newnode=new BSTnode;
	newnode->key=x;
	newnode->lchild=newnode->rchild=NULL;
	return newnode;
}



void insert(bstptr &root, int x)
{
	if(root == NULL) root=GetNewNode(x);
	else if(x <= root->key) insert(root->lchild, x);
	else insert(root->rchild, x);
}

bool search(bstptr root, int x)
{
	if(root == NULL) return false;
	else if(root->key == x) return true;
	else if(x > root->key) return search(root->rchild, x);
	else return search(root->lchild, x);
}

void show(bstptr root)
{
	if(root!=NULL)
	{
		show(root->lchild);
		cout<<root->key<<" "<<endl;
		show(root->rchild);
	}
}


int main()
{
	bstptr root=NULL;
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
