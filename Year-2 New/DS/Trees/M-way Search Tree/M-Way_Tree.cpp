#include<iostream>
using namespace std;

#define m 3


typedef struct mnode
{
	int size, key[m-1];
	mnode *ptr[m];
} *mptr;


void insertionSort(mptr T)
{
	for(int i = 0; i < T->size; i++)
	{
		int x = T->key[i], j = i;
		while(T->key[j-1] > x && j > 0)
		{
			T->key[j--] = T->key[j];
		}
		T->key[j] = x;
	}
}

void create(mptr &T, int x)
{
	if(T == NULL)
	{
		T = new mnode;
		T->key[0] = x;
		T->size = 1;
		for(int i = 0; i < m; i++) T->ptr[i] = NULL;
	}
	else
	{
		if(T->size < m-1)
		{
			T->key[T->size++] = x;
			insertionSort(T);
		}
		else
		{
			for(int i = 0; i < T->size; i++)
			{
				if(x < T->key[i])
				{
					create(T->ptr[i], x); return;
				}
			}
			create(T->ptr[T->size], x);

		}
	}
}

void sortOrder(mptr T)
{
    if(T != NULL)
    {
        for(int i = 0; i < T->size; i++)
        {
            sortOrder(T->ptr[i]);
            cout<<T->key[i]<<" ";
        }
        sortOrder(T->ptr[T->size]);
    }
}

bool search(mptr T, int x)
{
    if(T == NULL) return false;
    else
    {
        for(int i = 0; i < T->size; i++)
        {
            if(x < T->key[i]) return search(T->ptr[i], x);
            else if(x == T->key[i]) return true;
        }
        return search(T->ptr[T->size], x);
    }
}

int minimum(mptr T)
{
    if(T != NULL)
    {
        if(T->ptr[0] != NULL) return minimum(T->ptr[0]);
        else return T->key[0];
    }

}

int maximum(mptr T)
{
    if(T != NULL)
    {
        if(T->ptr[T->size] != NULL) return maximum(T->ptr[T->size]);
        else
        {
            int i = T->size;
            while(! T->ptr[i] && i > 0) i--;
            return T->key[i];
        }
    }

}

int main()
{
	mptr T = new mnode;
	create(T, 18);
	create(T, 20);
	create(T, 17);
	create(T, 19);
	create(T, 16);
	create(T, 21);

	cout<<2;
	return 0;
}
