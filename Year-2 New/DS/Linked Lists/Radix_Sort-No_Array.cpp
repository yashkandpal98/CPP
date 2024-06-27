#include<iostream>
#include<math.h>
using namespace std;


typedef struct lnode
{
	int data;
	lnode *next;
} *lptr;

typedef struct rnode
{
	int bkt;
	lptr blink;
	rnode *bnext;
} *rptr;


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

rptr search(rptr &R, int x)
{
	if(R != NULL)
	{
		if(R->bkt == x) return R;
		else return(search (R->bnext, x));
	}
	
}

void raddend(rptr &R, int x)
{
	if(R == NULL)
	{
		rptr R1 = new rnode;
		R1->bkt = x;
		R1->blink = NULL;
		R1->bnext = NULL;
		R = R1;
	}
	else
	{
		raddend(R->bnext, x);
	}
}

void rprint(rptr R)
{
	if(R != NULL)
	{
		cout<<R->bkt<<" ";
		rprint(R->bnext);
	}
	else if(R->bnext == NULL) cout<<R->bkt<<" ";
	else cout<<"Empty. ";
}

lptr radsort(lptr &L, int i)
{
	rptr rad1 = NULL, R1 = rad1; lptr temp = NULL;
	int m = pow(10, i+1), n = pow(10, i), j = 0;
	
	for(j = 0; j < 10; j++)
	{
		raddend(rad1, j);
	}
	
	while(L != NULL)
	{
		R1 = search(rad1, (L->data%m)/n);
		addend(R1->blink, L->data);
		L = L->next;
	}
	
	while(rad1 != NULL)
	{
		if(rad1->blink != NULL)
		{
			while(rad1->blink != NULL)
			{
				addend(temp, rad1->blink->data);
				rad1->blink = rad1->blink->next;
			}
		}
		rad1 = rad1->bnext;
	}
	return temp;
}


int main()
{
	lptr L = NULL;
	int n, i, dig, x;
	cout<<"Enter maximum number of digits: "; cin>>dig;
	cout<<"Enter number of elements: "; cin>>n;
	cout<<"\nEnter elements:\n";
	for(i = 0; i < n; i++)
	{
		cin>>x;
		addend(L, x);
	}
	
	cout<<"\nUnsorted list: "; print(L);
	for(i = 0; i < dig; i++)
	{
		L = radsort(L, i);
	}
	
	cout<<"\n\nSorted list: "; print (L);
	
	
	
	return 0;
}
