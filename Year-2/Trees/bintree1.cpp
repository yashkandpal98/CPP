#include<iostream>
#include<cstring>
using namespace std;

typedef struct btnode
{
	struct btnode *lchild;
	char data;
	struct btnode *rchild;
}*BTPTR;
BTPTR T;


void create(BTPTR &T,string s)
{
	BTPTR n;
	static int i=0;
	if(s[i]!=0)
	{
		n=new(btnode);
		n->data=s[i];
		n->lchild=NULL;
		n->rchild=NULL;
		if(s[++i]!='.')
			create(n->lchild,s);	
		if(s[++i]!='.')	
			create(n->rchild,s);
		if(T==NULL)
		T=n;
	}
}

void preorder(BTPTR &T)
{
	if(T!=NULL)
	{
	  cout<<T->data;
	  preorder(T->lchild);
	  preorder(T->rchild);
	}
}

void inorder(BTPTR &T)
{
	if(T!=NULL)
	{
		inorder(T->lchild);
		cout<<T->data;
		inorder(T->rchild);
	}
}

void postorder(BTPTR &T)
{
	if(T!=NULL)
	{
		postorder(T->lchild);
		postorder(T->rchild);
		cout<<T->data;
	}
}

int main()
{
	BTPTR T=NULL;
	string s;
	cout<<"enter the string\n";
	cin>>s;
	create(T,s);
	inorder(T);
	cout<<"\n";
	preorder(T);
	cout<<"\n";
	
	postorder(T);
}
