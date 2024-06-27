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
	rnode *left;
	lptr blink;
	rnode *right;
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

void raddend(rptr &R)
{
	if(R == NULL)
	{
		rptr R1 = new rnode;
		R1->blink = NULL;
		R1->right = NULL;
		R1->left = NULL;
		R = R1;
	}
	else if(R->right == NULL)
	{
		rptr R1 = new rnode;
		R1->blink = NULL;
		R1->right = NULL;
		R1->left = R;
		R->right = R1;
	}
	else
	{
		raddend(R->right);
	}
}

void rprint(rptr R)
{
	if(R != NULL)
	{
		cout<<1<<" ";
		rprint(R->right);
	}
	else if(R->right == NULL) cout<<1<<" ";
	else cout<<"Empty";
}

lptr radsort(lptr &L, int i)
{
	rptr rad1 = NULL; lptr T1 = NULL;
	int m = pow(10, i+1), n = pow(10, i), j = 0, diff = 0, curr = 0, prev = 0;
	
	for(j = 0; j < 10; j++)
	{
		raddend(rad1);
	}
	rptr R1 = rad1;
	
	while(L != NULL)
	{
		curr = (L->data%m)/n;
		diff = curr-prev;
		if(diff >= 0)
		{
			while(diff != 0)
			{
				R1 = R1->right;
				diff--;
			}
		}
		else
		{
			while(diff != 0)
			{
				R1 = R1->left;
				diff++;
			}
		}
		addend(R1->blink, L->data);
		L = L->next;
		prev = curr;
	}
	
	while(rad1 != NULL)
	{
		if(rad1->blink != NULL)
		{
			while(rad1->blink != NULL)
			{
				addend(T1, rad1->blink->data);
				rad1->blink = rad1->blink->next;
			}
		}
		rad1 = rad1->right;
	}
	return T1;
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
	cout<<"\n\nSorted list  : "; print (L);
	
	return 0;
}
