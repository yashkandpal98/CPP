#include<iostream>
#include<math.h>
using namespace std;

typedef struct lnode
{
	int data;
	lnode *next;
} *lptr;

struct LQueue
{
	lptr f, r;
};


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

void enqueue(LQueue &LQ, int x)
{
	if(LQ.f == NULL)
	{
		addend(LQ.f, x);
		LQ.r = LQ.f;
	}
	else
	{
		addend(LQ.r, x);
		LQ.r = LQ.r->next;
	}
}

int dequeue(LQueue &LQ)
{
	if(LQ.f == LQ.r) LQ.r = NULL;
	return(deletefirst(LQ.f));
}

void radsort(lptr &L, int i)
{
	LQueue T1[10]; lptr T2 = NULL;
	int m = pow(10, i+1), n = pow(10, i);
	
	for(int i = 0; i < 10; i++)
	{
		T1[i].f = T1[i].r = NULL;
	}
	
	while(L != NULL )
	{
		enqueue(T1[(L->data%m)/n], L->data);
		L = L->next;
	}
	
	for(int i = 0; i < 10; i++)
	{
		if(T1[i].f != NULL)
		{
			while(T1[i].f != NULL)
			{
				addend(T2, dequeue(T1[i]));
			}
		}
	}
	L = T2;
}


int main()
{
	LQueue LQ;
	LQ.f = LQ.r = NULL;
	lptr L = NULL;
	int dig, n, i = 0, x;
	cout<<"Enter max digits of elements: "; cin>>dig; cout<<endl;
	cout<<"Enter number of elements: "; cin>>n; cout<<endl<<endl;
	
	cout<<"Enter elements:\n";
	for(i = 0; i < n; i++)
	{
		cin>>x;
		addend(L, x);
	}
	
	cout<<"\nUnsorted List: "; print(L);
	
	for(i = 0; i < dig; i++)
	{
		radsort(L, i);
		
	}
	
	cout<<"\n\nSorted List: "; print(L);
	
	
	return 0;
}
