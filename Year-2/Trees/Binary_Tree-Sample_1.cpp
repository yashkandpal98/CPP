#include<iostream>
using namespace std;

struct BSTnode
{
	BSTnode *lchild;
	int key;
	BSTnode *rchild;
};
//typedef BSTnode *bstptr;

BSTnode *GetNewNode(int x)
{
	BSTnode *newnode=new BSTnode;
	newnode->key=x;
	newnode->lchild=newnode->rchild=NULL;
	return newnode;
}



void insert(BSTnode *&root, int x)
{
	if(root == NULL) root=GetNewNode(x);
	else if(x <= root->key) insert(root->lchild, x);
	else insert(root->rchild, x);
}

bool search(BSTnode *root, int x)
{
	if(root == NULL) return false;
	else if(root->key == x) return true;
	else if(x > root->key) return search(root->rchild, x);
	else return search(root->lchild, x);
}

void show(BSTnode *root)																//Preorder printing
{
	if(root!=NULL)
	{
		cout<<root->key<<" "<<endl;show(root->lchild);
		show(root->rchild);
	}
}



