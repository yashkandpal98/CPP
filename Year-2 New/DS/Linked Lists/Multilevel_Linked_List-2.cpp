#include<iostream>
#include<string.h>
using namespace std;

typedef struct mlnode
{
	union u
	{
		char n;
		mlnode *dlink;
	} data;
	
	int tag;		//0 = char, 1 = list;
	mlnode *next;
} *mlptr;

union u
{
	char n;
	mlnode *dlink;
};

void addend(mlptr &L, u x, int tg)
{
	if(L == NULL)
	{
		mlptr T = new mlnode;
		T->tag =tg;
		if(tg == 0)T->data.n = x.n;
		else T->data.dlink = x.dlink;
		
		T->next = NULL;
		L = T;
	}
	else
	{
		/*if(L->tag == 1)
		{
			char a;
			cout<<"Sublist detected. Add to sublist?(y/n)"; cin>> a;
			if(a == 'y') addend(L->data.dlink, x, tg);
		}*/
		addend(L->next, x, tg);
	}
}

int add(mlptr &L, mlptr MP[], char LName[], string str, int i)
{
	if(str[i] != NULL)
	{
		if(str[i] == '{')
		{
			mlptr T = new mlnode;
			T->tag = 1;
			T->data.dlink = NULL;
			L = T;
			i = add(L->data.dlink, MP, LName, str, ++i);
			i = add(L->next, MP, LName, str, i);
		}
		else if(str[i] == '}') return ++i;
		else if(65 <= str[i] && 90 >= str[i])
		{
			mlptr T = new mlnode;
			T->tag = 1;
			T->data.dlink = NULL;
			int k=0;
			while(k < strlen(LName))
			{
				if(LName[k] == str[i]) break;
				k++;
			}
			T->data.dlink = MP[k];
			T->next = NULL;
			L = T;
			
			i = add(L->next, MP, LName, str, ++i);
		}
		else
		{
			mlptr T = new mlnode;
			T->tag = 0;
			T->data.n = str[i];
			T->next = NULL;
			L = T;
			i = add(L->next, MP, LName, str, ++i);
		}
		return i;
	}
}

void print(mlptr L)
{
	if(L->next == NULL)
	{
		if(L->tag == 0) cout<<L->data.n<<" ";

		else
		{
			cout<<"{";
			print(L->data.dlink);
			cout<<"}";
		}
	}
	else if(L == NULL) cout<<"\nEmpty";

	else 
	{
		if(L->tag == 0) cout<<L->data.n<<" ";
		
		else
		{
			cout<<"{";
			print(L->data.dlink);
			cout<<"}";
		}
		print(L->next);
	}
}


int main()
{	
	string str = "ibjC{lD}{k{Bf}s}", str2 = "gh{kC}m", str3 = "nop", str4 = "qr";
	char LName[5] = {"ABCD"};
	mlptr MP[4];
	
	for(int i = 0; i < 4; i++)
	{
		MP[i] = NULL;
	}
	
	int i = add(MP[3], MP, LName, str4, 0);
	i = add(MP[2], MP, LName, str3, 0);
	i = add(MP[1], MP, LName, str2, 0);
	i = add(MP[0], MP, LName, str, 0);
	cout<<"{";
	print(MP[0]);
	cout<<"}";
	return 0;
}
