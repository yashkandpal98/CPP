#include<iostream>
using namespace std;


//Structure
typedef struct dlnode
{
	dlnode *left, *right;
	int data;
} *dlptr;


//DLL operations
void addfirst(dlptr &D, int x)
{
	dlptr T = new dlnode;
	T->data = x;
	T->left = NULL;
	T->right = D;
	if(D != NULL) D->left = T;
	D = T;
}

void addend(dlptr &D, int x)
{
	if(D == NULL)
	{
		dlptr T = new dlnode;
		T->data = x;
		T->left = T->right = NULL;
		D = T; 
	}
	else if(D->right == NULL)
	{
		dlptr T = new dlnode;
		T->data = x;
		T->right = NULL;
		T->left = D;
		D->right = T;
	}
	else addend(D->right, x);
}

void addafter(dlptr &L, int x, int y )
{
	if(L == NULL) 
	{
		cout<<"\nElement "<<x<<" does not exist. Adding to the end";
		addend(L, y);
	}
	
	else if(L->data == x)
	{
		dlptr T = new dlnode;
		T->data = y;
		T->right = L->right;
		T->right->left = T;
		T->left = L;
		T->left->right = T;
	}
		
	else addafter(L->right, x, y);
}

void addbefore(dlptr &L, int x, int y)
{
	if(L == NULL) 
	{
		cout<<"\nElement "<<x<<" does not exist. Adding to the end";
		addend(L, y);
	}
	
	else if(L->data == x) addfirst(L, y);
	
	else if(L->right->data == x) addafter(L, L->data, y);
	
	else addbefore(L->right, x, y);
}

int deletefirst(dlptr &L)
{
	if(L == NULL)
	{
		cout<<"\nEmpty";
		return -1;
	}
	else
	{
		int n = L->data;
		L = L->right;
		L->left->right = NULL;
		L->left = NULL;
		return n;
	}
}

int deleteend(dlptr &L)
{
	if(L == NULL)
	{
		cout<<"\nEmpty";
		return -1;
	}
	else if(L->right == NULL)
	{
		int x = L->data;
		L = NULL;
		return x;
	}
	else if(L->right->right == NULL)
	{
		dlptr T = L->right;
		T->left = NULL;
		L->right = NULL;
		return T->data;
	}
	else return(deleteend(L->right));
}

int deleteele(dlptr &L, int x)
{
	if(L == NULL)
	{
		cout<<"Empty";
		return -1;
	}
	else if(L->data == x)
	{
		deletefirst(L);
	}
	else if(L->data == x)
	{
		L->left->right = L->right;
		L->right->left = L->left;
		return(L->data);
	}
	else deleteele(L->right, x);
}

void print(dlptr L)
{
	if(L == NULL) cout<<"Empty";
	else if(L->right == NULL) cout<<L->data<<" ";
	else
	{
		cout<<L->data<<" ";
		print(L->right);
	}
}

bool search(dlptr head, dlptr tail)
{
	if(head == tail) return true;
	else if(head == NULL) return false;
	else return(search(head->right, tail));
}

//Sorting function
dlptr partition( dlptr &low, dlptr &high)
{
	dlptr l = low->right, h = high;
	
	while(!search(h, l))
	{
		while(l->data < low->data && l->right != NULL) l = l->right;
		while(h->data > low->data && h != NULL) h = h->left;
		
		if(!search(h, l))
		{
			l->data += h->data;
			h->data = l->data - h->data;
			l->data -= h->data;
		}
	}
	
	if(h->data >= low->data) return h;
	
	low->data += h->data;
	h->data = low->data - h->data;
	low->data -= h->data;
	
	return h;
}

void quicksort(dlptr &head, dlptr &tail)
{
	if(search(head->right, tail))
	{
		dlptr j = partition(head, tail);
		quicksort(head, j->left);
		if(j->right != NULL)quicksort(j->right, tail);	
	}
}


int main()
{
	dlptr D = NULL, temp;
	
	addend(D, 60);
	addend(D, 81);
	addend(D, 92);
	addend(D, 43);
	addend(D, 65);
	addend(D, 31);
	addend(D, 57);
	addend(D, 26);
	addend(D, 75);
	
	print(D);
	temp = D;
	
	while(temp->right != NULL) temp = temp->right;
	cout<<endl<<endl;
	
	quicksort(D, temp);
	print(D);
}
