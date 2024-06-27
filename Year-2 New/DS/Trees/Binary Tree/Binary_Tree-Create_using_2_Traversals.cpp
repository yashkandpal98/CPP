#include<iostream>
using namespace std;

typedef struct bnode
{
	char data;
	bnode *lchild, *rchild;
} *bptr;


void inOrderPrint(bptr T)
{
	if(T != NULL)
	{
		inOrderPrint(T->lchild);
		cout<<T->data;
		inOrderPrint(T->rchild);
	}
}

bptr createPreorder(bptr &T, string InString, string PreString, int &i)
{
	if(i < PreString.size())
	{
		T = new bnode;
		T->data = PreString[i];
		T->lchild = T->rchild = NULL;
		i++;
		
		if(PreString[i-1] == InString[0]) return T;
		
		int j = 0;
		string s1, s2;
		
		while(InString[j] != PreString[i-1])
		{
			s1 += InString[j];
			j++;
		}
		
		j++;
		
		while(InString[j])
		{
			s2 += InString[j];
			j++;
		}
		
		if(s1 != "")T->lchild = createPreorder(T->lchild, s1, PreString, i);
		if(s2 != "")T->rchild = createPreorder(T->rchild, s2, PreString, i);
		
		return T;
	}
}

bptr createPostorder(bptr T, string InString, string PostString, int &i)
{
	if(i >= 0)
	{
		T = new bnode;
		T->data = PostString[i];
		T->lchild = T->rchild = NULL;
		i--;
		
		if(PostString[i+1] == InString[0]) return T;
		
		int j = 0;
		string s1, s2;
		
		while(InString[j] != PostString[i+1])
		{
			s1 += InString[j];
			j++;
		}
		
		j++;
		
		while(InString[j])
		{
			s2 += InString[j];
			j++;
		}
		
		if(s2 != "")T->rchild = createPostorder(T->rchild, s2, PostString, i);
		if(s1 != "")T->lchild = createPostorder(T->lchild, s1, PostString, i);
		
		return T;
	}
}

bptr createPrePost(bptr T, string PreString, string PostString, int &i)
{
	if(i < PreString.size())
	{
		T = new bnode;
		T->data = PreString[i];
		T->lchild = T->rchild = NULL;
		i++;
		
		if(PostString[0] == PreString[i-1]) return T;
		
		int j = 0;
		string s1, s2;
		
		while(PostString[j] != PreString[i])
		{
			s1 += PostString[j];
			j++;
		}
		
		j++;
		
		while(j < PostString.length()-1)
		{
			s2 += PostString[j];
			j++;
		}
		cout<<s2[j]<<endl;
		if(s1 != "")T->lchild = createPrePost(T->lchild, PreString, s1, i);
		if(s2 != "")T->rchild = createPrePost(T->rchild, PreString, s2, i);
		
		return T;
	}
}


int main()
{
	bptr T = NULL;
	string InString = "dbeafc", PreString = "abdecf", PostString = "debfca";
	int i = 0, j = PostString.length()-1;
	
	T = createPrePost(T, PreString, PostString, i);
	
	//inOrderPrint(T);
}
