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

void removedup(lptr &L, int arr[], int len)
{
	int i, flag = 0;
	if(L != NULL)
	{
		for(i = 0; i < len; i++)
		{
			if(L->data == arr[i])
			{
				flag = 0;
				deleteele(L, L->data);
				break;
			}
			else
			{
				flag = 1;
			}
		}
		if(flag == 1) 
		{
			arr[len] = L->data;
			removedup(L->next, arr, ++len);
		}
		else removedup(L, arr, len);
		
	}
}

int length(lptr L)
{
	if(L == NULL) return 0;
	else return(1+(length(L->next)));
}

int add(lptr L1, lptr L2)
{
	if(L1->next == NULL && L2->next == NULL)
	{
		L1->data += L2->data;
		int carry = L1->data/10;
		L1->data %= 10;
		return carry;
	}
	else
	{
		L1->data += L2->data + add(L1->next, L2->next);
		int carry = L1->data/10;
		L1->data %= 10;
		return (carry);
	}
}

void pairrev(lptr &L)
{
	if(L->next != NULL)
	{
		L->data += L->next->data;
		L->next->data = (L->data)-(L->next->data);
		L->data -= L->next->data;
		pairrev(L->next->next);
	}
	else return;
}


int main()
{
	int x, y, z;
	lptr L, L1 = NULL, L2 = NULL, L3 = NULL;
	addend(L1, 5);
	addend(L1, 2);
	addend(L1, 1);
	addend(L, 1);
	addend(L1, 9);
	addend(L1, 8);
	addend(L2, 7);
	addend(L2, 1);
	addend(L2, 9);
	addend(L, 11);
	addend(L2, 7);
	addend(L, 10);
	addend(L, 4);
	addend(L, 3);
	addend(L, 5);
	//print(L); cout<<endl<<endl;
	
	x = length(L); cout<<x;
	
	/*int arr[length(L)], len = 1;
	
	removedup(L, arr, len);
	
	cout<<endl<<endl; print(L);*/
	
	cout<<"List 1:   "; print(L1); cout<<endl<<"List 2:   "; print(L2);
	
	//x = length(L1); y = length(L2);
	
	/*if(x >= y)
	{
		for(int i = 0; i < x-y; i++)
		{
			addfirst(L2, 0);
		}
	}
	else
	{
		for(int i = 0; i < y-x; i++)
		{
			addfirst(L1, 0);
		}
	}*/
	
	
	
	/*x = add(L1, L2);
	if(x > 0)
	{
		addfirst(L1, x);
	}
	cout<<endl<<"Sum   : "; print(L1);*/
	
	/*pairrev(L);
	print(L);*/
}
