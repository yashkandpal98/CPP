#include<iostream>
using namespace std;

typedef struct bstnode
{
	int data;
	bstnode *lchild, *rchild;
} *bstptr;

void insert(bstptr &root, int x)
{
	if(root == NULL)
	{
		bstptr t = new bstnode;
		t->data = x;
		t->lchild = t->rchild = NULL;
		root = t;
	}
	else
	{
		if(x > root->data) insert(root->rchild, x);
		else if(x < root->data) insert(root->lchild, x);
		else cout<<"Duplicate entry";
	}
}

void del(bstptr &root, int x)
{
	if(root != NULL)
	{
		if(x == root->data)
		{
			if(root->lchild != NULL)
			{
				root->data = root->lchild->data;
				del(root->lchild, root->lchild->data);
			}
			else if(root->rchild != NULL)
			{
				root->data = root->rchild->data;
				del(root->rchild, root->rchild->data);
			}
			else root = NULL;
		}
		else if(x > root->data) del(root->rchild, x);
		else del(root->lchild, x);
	}
	else cout<<"Entry does not edataist";	
}

int height(bstptr root)
{
	if(root == NULL) return 0;
	else return(max(height(root->lchild), height(root->rchild)) + 1);
}

void levelprint(bstptr &root, int lvl)
{
	if(root != NULL)
	{
		if(lvl == 0) cout<<root->data<<" ";
		else
		{
			levelprint(root->lchild, lvl-1);
			levelprint(root->rchild, lvl-1);
		}
	}
	
}

void levelorder(bstptr root)
{
	if(root != NULL)
	{
		int x = height(root);
		for(int i = 0; i < x; i++)
		{
			levelprint(root, i);
			cout<<endl;
		}
	}
	else cout<<"Tree is empty\n";
}

int longest(bstptr root)
{
	if(root == NULL) return 0;
	else
	{
		int x = max(longest(root->lchild), longest(root->rchild));
		if(((root->lchild != NULL && root->lchild->data == root->data -1)) || (root->rchild != NULL && root->rchild->data == root->data + 1))
		{
			x++;
		}
		return x;
	}
}

/*
int main()
{
	bstptr root = NULL;
	int t, x;
	cin>>x;
	while(x != -1)
	{
		insert(root, x);
		cin>>x;
	}
	
	cout<<endl;
	levelorder(root);
	
	cout<<"\n"<<longest(root)+1;
}
*/
