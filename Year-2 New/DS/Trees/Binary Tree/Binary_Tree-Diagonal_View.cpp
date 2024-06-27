#include<iostream>
using namespace std;

typedef struct bnode
{
	char data;
	bnode *lchild, *rchild, *adptr;
} *bptr;

typedef struct lnode
{
	bptr data;
	lnode *next;
} *lptr;

struct LQueue
{
	lptr f, r;
};


void addfirst(lptr &L, bptr x)
{
	lptr T = new lnode;
	T->data = x;
	T->next = L;
	L = T;
}

void addend(lptr &L, bptr x)
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

int deletefirst(lptr &L)
{
	if(L == NULL)
	{
		cout<<"\nEmpty";
		return -1;
	}
	else
	{
		int n = L->data->data;
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
			int x = L->data->data;
			L = NULL;
			return x;
		}
		else
		{
			if(L->next->next == NULL)
			{
				lptr T = L->next;
				L->next = NULL;
				return T->data->data;
			}
			else return(deleteend(L->next));
		}
	}
}

void print(lptr L)
{
	if(L == NULL)
	{
		cout<<"Empty";
	}
	else if(L->next == NULL) cout<<L->data->data<<" ";
	else
	{
		cout<<L->data->data<<" ";
		print(L->next);
	}
}

void enqueue(LQueue &LQ, bptr x)
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

void create(bptr &T)
{
	int c; cin>>c;
	if(c != -1)
	{
		T = new bnode;
		T->data = c;
		T->lchild = T->rchild = NULL;
		T->adptr = NULL;
		create(T->lchild);
		create(T->rchild);
	}
	else return;
}

int depth(bptr T)
{
    if(T == NULL) return 0;
    else return(1 + max(depth(T->lchild), depth(T->rchild)));
}

void printDiagonal(bptr T, LQueue LQ[], int x)
{
    if(T == NULL) return;
    else
    {
        enqueue(LQ[x], T);
        printDiagonal(T->lchild, LQ, x+1);
        printDiagonal(T->rchild, LQ, x);
    }
}

void diagonalPrint(bptr T)
{
    int d = depth(T);
    LQueue LQ[d];
    for(int i = 0; i < d; i++) LQ[i].f = LQ[i].r = NULL;
    
    printDiagonal(T, LQ, 0);
    
    for(int i = 0; i < d; i++)
    {
        while(LQ[i].f) cout<<dequeue(LQ[i])<<" ";
        cout<<endl;
    }
}


int main()
{
    bptr T = NULL;
    create(T);
    //8 3 1 -1 -1 -1 10 6 4 -1 -1 7 -1 -1 14 13 -1 -1 -1
    diagonalPrint(T);
    return 0;
}
