#include<iostream>
#include<string.h>
using namespace std;

typedef struct bstnode
{
	bstnode *lchild;
	char key[5];
	bstnode *rchild;
} *dptr;


dptr create(char x[5])
{
	dptr first= new bstnode;
	first->lchild=NULL; first->rchild=NULL;
	for(int i=0; i<strlen(x); i++)
	{
		first->key[i]=x[i];
	}
	return first;
}

void add(dptr &t, char x[5], int n, int i)
{
	if(i<n)
	{
		if(t==NULL) t=create(x);
		else
		{
			if(x[i]==1)
			{
				dptr temp=t;
				add(temp->rchild, x, n, i++);
			}
			else if(x[i]==0)
			{
				dptr temp=t;
				add(temp->lchild, x, n, i++);
			}
		}
	}
}

bool search(dptr t, char x[5], int count, int i)
{
	if(t!=NULL)
	{
		
		if(t->key[i]!=x[i])
		{
			count=0;
			if(x[i]==1) return search(t->rchild, x, count, i++);
			else if(x[i]==0) return search(t->lchild, x, count, i++);
		}
		else if(t->key[i]==x[i])
		{
			count=1;
			return search(t, x, count, i++);
		}
	}
	else
	{
		if(count==0) return false;
		else if(count==1) return true;
	}
}



int main()
{
	dptr root=NULL;
	add(root, "01101", 5, 0);
	add(root, "11011", 5, 0);
	add(root, "00001", 5, 0);
	add(root, "10101", 5, 0);
	add(root, "00111", 5, 0);
	add(root, "10011", 5, 0);
	
	char a[5];
	cout<<"Enter number to search: ";cin>>a;
	
	if(search(root, a, 0, 0))cout<<"\nFound\n";
	else cout<<"\nNot found\n";
	
	return 0;
}
