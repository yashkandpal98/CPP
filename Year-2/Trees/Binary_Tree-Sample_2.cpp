#include<iostream>
#include"Binary_Tree-Sample_1.cpp"
using namespace std;

void lview1(bstptr t)
{
	if(t!=NULL)
	{
		if(t->lchild!=NULL) lview1(t->lchild);
		cout<<t->key<<" ";
	}
}

void lview(bstptr t)
{
	if(t!=NULL)
	{
		cout<<t->key<<endl;
		if(t->lchild!=NULL) lview(t->lchild);
		else lview(t->rchild);
	}
}

void rview(bstptr t)
{
	if(t!=NULL)
	{
		cout<<t->key<<endl;
		if(t->rchild!=NULL)rview(t->rchild);
		else rview(t->lchild);
	}
}

void rview1(bstptr t)
{
	if(t!=NULL)
	{
		if(t->rchild!=NULL)rview1(t->rchild);
		cout<<t->key<<" ";
	}
}

void tview(bstptr t)
{
	if (t->lchild!=NULL)
	{
		lview1(t->lchild);
		cout<<t->key<<" ";
		if(t->rchild!=NULL)
		{
			rview1(t->rchild);
		}
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
	insert(root, 22);
	int x;
	cout<<"Enter element to search: ";cin>>x;cout<<endl;
	if(search(root, x)) cout<<"\nFound\n";
	else cout<<"\nNot found\n";
	
	cout<<"\nRight view of tree:\n";rview(root);cout<<endl;
	cout<<"\nLeft view of tree:\n";lview(root);cout<<endl;
	cout<<"\nTop view of tree:\n"; tview(root);cout<<endl;
	return 0;
}
