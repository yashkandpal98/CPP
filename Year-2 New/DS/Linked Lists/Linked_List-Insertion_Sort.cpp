#include<iostream>
using namespace std;

typedef struct lnode
{
	int data;
	lnode *next;
} *lptr;


void addfirst(lptr &L, int x)
{
	lptr T = new lnode;
	T->data = x;
	T->next = L;
	L = T;
}

void addend(lptr &L, int x)
{
	if(L == NULL)
	{
		lptr T = new lnode;
		T->data = x;
		T->next = NULL;
		L = T;
	}
	else addend(L->next, x);
}

void addafter(lptr &L, int x, int y )
{
	if(L == NULL ) 
	{
		cout<<"\nElement "<<x<<" does not exist. Adding to the end";
		addend(L, y);
	}
	
	else if(L->data == x)
	{
		lptr T = new lnode;
		T->data = y;
		T->next = L->next;
		L->next = T;
	}
		
	else addafter(L->next, x, y);
}

void addbefore(lptr &L, int x, int y)
{
	if(L == NULL) 
	{
		cout<<"\nElement "<<x<<" does not exist. Adding to the end";
		addend(L, y);
	}
	
	else if(L->data == x) addfirst(L, y);
	
	else if(L->next->data == x) addafter(L, L->data, y);
	
	else addbefore(L->next, x, y);
}

int deletefirst(lptr &L)
{
	if(L == NULL)
	{
		cout<<"\nEmpty";
		return -1;
	}
	else
	{
		int n = L->data;
		L = L->next;
		return n;
	}
}

int deleteend(lptr &L)
{
	if(L == NULL)
	{
		cout<<"\nEmpty";
		return -1;
	}
	else
	{
		if(L->next == NULL)
		{
			int x = L->data;
			L = NULL;
			return x;
		}
		else
		{
			if(L->next->next == NULL)
			{
				lptr T = L->next;
				L->next = NULL;
				return T->data;
			}
			else return(deleteend(L->next));
		}
	}
}

int deleteele(lptr &L, int x)
{
	if(L == NULL)
	{
		return -1;
	}
	else if(L->data == x)
	{
		deletefirst(L);
	}
	else if(L->next->data == x)
	{
		lptr T = L->next;
		L->next = L->next->next;
		return(T->data);
		delete(T);
	}
	else deleteele(L->next, x);
}

void print(lptr L)
{
	if(L == NULL)
	{
		cout<<"Empty";
	}
	else if(L->next == NULL) cout<<L->data<<" ";
	else
	{
		cout<<L->data<<" ";
		print(L->next);
	}
}

void add(lptr &L, int x)
{
	if(L == NULL) addfirst(L, x);
	else
	{
		if(x <= L->data) addbefore(L, L->data, x);
		else add(L->next, x);
	}
}


int main()
{
	lptr L = NULL;
	int n;
	
	cout<<"Enter number of elements: "; cin>>n;
	int a[n];
	
	cout<<endl<<"Enter elements:\n";
	for(int i = 0; i < n; i ++)
	{
		cin>>a[i];
		add(L, a[i]);
	}
	
	cout<<endl<<endl<<"Unsorted List: ";
	for(int i = 0; i < n; i ++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl<<"Sorted List: ";
	print(L);
	
}
