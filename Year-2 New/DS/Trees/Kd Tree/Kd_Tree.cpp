#include<iostream>
using namespace std;

int dimension = 2;

typedef struct kdnode
{
	int data[d];
	kdnode *lchild, *rchild;
} *kdptr;


void insert(kdptr &T, int d[], int i)
{
	if(T == NULL)
	{
		T = new kdnode;
		T->lchild = T->rchild = NULL;
		for(int j = 0; j < dimension; j++) T->data[j] = d[j];
	}
	else if(T->data[i] > d[i]) insert(T->lchild, d, (i+1)%dimension);
	else if(T->data[i] < d[i]) insert(T->rchild, d, (i+1)%dimension);
	else insert(T, d, (i+1)%dimension);
}

bool search(kdptr T, int x, int i)
{
	if(T != NULL)
	{
		if(T->data[i] == x) return true;
		else
		{
			for(int j = 0; j < d; j++) if(T->data == x) return true;
			
			if(T->data[i] > x) return search(T->lchild, x, (i+1)%dimension);
			else return search(T->rchild, x, (i+1)%dimension);
		}
	}
}

int main()
{
	return 0;
}
