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

void removedup(lptr &L)
{
	if(L->next != NULL)
	{
		if(L->next->data == L->data)
		{
			deleteele(L, L->data);
			removedup(L);
		}
		else removedup(L->next);
	}
}

int length(lptr L)
{
	if(L == NULL) return 0;
	else return(1+(length(L->next)));
}

int midele(lptr T1, lptr T2)
{
	if(T2->next == NULL)
	{
		return T1->data;
	}
	else if(T2->next->next == NULL)
	{
		return T1->next->data;
	}
	else
	{
		return midele(T1->next, T2->next->next);
	}
}

int neleend(lptr T1, lptr T2)
{
	if(T2 == NULL)
	{
		return T1->data;
	}
	else return neleend(T1->next, T2->next);
}

void revlist(lptr &L)
{
	if(L->next->next != NULL)
	{
		revlist(L->next);
	}
	lptr T = L->next;
	
	L->next = NULL;
	
	T->next = L;
}

lptr segregate(lptr &L, lptr &L2)
{
	if(L != NULL)
	{
		if(L->data%2 == 0) addfirst(L2, L->data);
		else addend(L2, L->data);
		
		return(segregate(L->next, L2));
	}
	else return L2;
}

lptr loopcheck(lptr L, lptr T1)
{
	if(T1 != L) return loopcheck(L->next, T1->next->next);
	else return T1;
}

int looplength(lptr L)
{
	lptr T1 = L;
	L = loopcheck(L, T1->next);
	T1 = L;
	int n = 1;
	T1 = T1->next;
	while(T1 != L)
	{
		n++;
		T1 = T1->next;
	}
	cout<<endl;
	return n;
}

int loopstart(lptr L, lptr T1)
{
	if(T1 != L) return loopstart(L->next, T1->next);
	else return T1->data;
}


int main()
{
	lptr L = NULL, L2 = NULL;
	
	int n;
	
	addend(L, 1);
	addend(L, 1);
	addend(L, 2);
	addend(L, 3);
	addend(L, 3);
	addend(L, 4);
	addend(L, 5);
	addend(L, 6);
	addend(L, 7);
	addend(L, 8);
	addend(L, 8);
	addend(L, 8);
	addend(L, 9);
	addend(L, 9);
	addend(L, 10);
	
	print(L);																		//print linked list recursively
	
	//cout<<endl<<length(L);														//Length of linked list
	
	//lptr T1 = L;
	//cout<<endl<<midele(L, T1);													//Middle element
	
	/*cout<<endl<<endl<<"Enter position of element from end: "; cin>>n;				//Nth element from the end
	for(int i = 0; i < n; i++)
	{
		T1 = T1->next;
	}
	cout<<neleend(L, T1);*/
	
	/*removedup(L);																	//Remove duplicate elements from a sorted linked list
	cout<<endl<<endl; print(L);*/
	
	/*while(T1->next != NULL)														//Reverse Linked List recursively
	{
		T1 = T1->next;
	}
	revlist(L);
	L = T1;
	cout<<endl<<endl; print(L);*/
	
	/*L = segregate(L, L2);
	cout<<endl<<endl; print(L);*/
	
	/*L->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next = L->next->next->next->next->next->next->next;
	
	lptr T1 = L;
	
	if(loopcheck(L, T1) != NULL)													//Check for loop, its length and starting point
	{
		cout<<"\n\nLoop of length "<<looplength(L)<<" found at element ";
		for(int i = 0; i < looplength(L); i ++)
		{
			T1 = T1->next;
		}
		cout<<loopstart(L, T1);
	}
	else cout<<endl<<endl<<"Loop not found";*/
	
	return 0;
}
