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

int length(lptr L)
{
	if(L == NULL) return 0;
	else return(1+(length(L->next)));
}

int intercheck(lptr L1, lptr L2)
{
	if(L1 == NULL || L2 == NULL)
	{
		return -7;
	}
	else
	{
		if(L1->data == L2->data) return L1->data;
		else return(intercheck(L1->next, L2->next));
	}
}


int main()
{
	lptr L1 = NULL; lptr L2 = NULL;
	
	addend(L1, 1);
	addend(L1, 2);
	addend(L1, 3);
	addend(L1, 4);
	addend(L1, 5);
	addend(L1, 6);
	addend(L1, 7);
	addend(L1, 8);
	addend(L1, 9);
	addend(L1, 10);
	
	addend(L2, 1);
	addend(L2, 2);
	addend(L2, 3);
	addend(L2, 4);

	L2->next->next->next->next = L1->next->next->next->next->next->next->next;
	
	int l1 = length(L1), l2 = length(L2);
	
	cout<<"Linked List- 1: "; print(L1);
	cout<<"\nLinked List- 2: "; print(L2);
	
	if(l1 > l2)
	{
		for(int i = 0; i < (l1-l2); i++)
		{
			L1 = L1->next;
		}
	}
	else
	{
		for(int i = 0; i < (l2-l1); i++)
		{
			L2 = L2->next;
		}
	}
	
	cout<<"\n\nIntersection found at element "<<intercheck(L1, L2);
	
	return 0;
}
