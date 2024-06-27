#include<iostream>
using namespace std;

#define d 1


typedef struct bdnode
{
    int size, key[2*d], tag;        //0 if leaf node, 1 if non-leaf
    bdnode *ptr[2*d+1], *parent;
}*bdptr;


void insertionSort(int a[], int n)
{
	for(int i = 0; i < n; i++)
	{
		int x = a[i], j = i;
		while(a[j-1] > x && j > 0)
		{
			a[j--] = a[j];
		}
		a[j] = x;
	}
}

int height(bdptr T)
{
    if(T == NULL) return 0;
    {
        int x= height(T->ptr[0]), y = x;
        for(int i = 1; i <= T->size; i++)
        {
            x = height(T->ptr[i]);
            if(x > y) y = x;
        }

        return 1+y;

    }
}

bdptr newNode(bdptr &T, int &x)
{
    bdptr T1 = new bdnode;
    T1->size = d;
    T1->parent = NULL;
    T->size = d;
    T1->tag = T->tag;
    for(int a = 0; a < 2*d+1; a++)T1->ptr[a] = NULL;
    int i = 0, j = 0;

    for(i = d; i < 2*d; i++) T1->key[i-d] = T->key[i];

    if(T->tag == 1) for(i = d+1; i <= 2*d; i++) T1->ptr[i-d] = T->ptr[i];

    if(x > T->key[T->size-1] && x < T1->key[0]) x = x;
    else if(x < T->key[T->size-1])
    {
        int y = T->key[T->size-1];

        i = T->size-2;
        while(i >= 0 && x < T->key[i]) T->key[i+1] = T->key[i--];
        T->key[i+1] = x;

        x = y;

        j = T->size-2;
        while(j >= i+1) T->ptr[j+1] = T->ptr[j--];
    }

    else if(x > T1->key[0])
    {
        int y = T1->key[0];
        i = 1;
        while(i <= T1->size-1 && x > T1->key[i]) T1->key[i-1] = T1->key[i++];
        T1->key[i-1] = x;

        x = y;

        j = 0;
        while(j <= i+1) T->ptr[j-1] = T->ptr[j++];
    }
    return T1;
}

void nodeSplit(bdptr &T, int x, bdptr ptr)
{
    if(T->parent == NULL)
    {
        bdptr temp = new bdnode;
        temp->key[0] = x;
        temp->size = 1;
        temp->tag = 1;

        for(int i = 2; i < 2*d+1; i++)temp->ptr[i] = NULL;
        temp->parent = NULL;

        temp->ptr[0] = T;
        temp->ptr[1] = ptr;

        T->parent = temp;
        ptr->parent = temp;
        ptr->tag = T->tag;
        T = temp;
    }

    else
    {
        if(T->parent->size < 2*d)
        {
            ptr->parent = T->parent;
            int i = 0, j = 0;
            while(x > T->parent->key[i] && i < T->parent->size) i++;

            j = i+1;
            T->parent->size++;
            while(j < T->parent->size)
            {
                T->parent->key[j] = T->parent->key[j-1];
                T->parent->ptr[j+1] = T->parent->ptr[j];
                j++;
            }
            T->parent->key[i] = x;

            T->parent->ptr[i+1] = ptr;
        }
        else
        {
            bdptr T1 = newNode(T->parent, x);
            //cout<<T->key[0]<<" "<<ptr->key[0]<<endl;
            //cout<<T->parent->key[0]<<" "<<T1->key[0]<<endl;
            T1->ptr[0] = ptr;
            nodeSplit(T->parent, x, T1);
            //cout<<T->parent->ptr[0]->parent->ptr[1]->key[0]<<endl;

            T->parent = T->parent->ptr[0];
            cout<<T->parent->key[0];
            T = T->parent;
        }
    }
}

void create(bdptr &T, bdptr parent, int x)
{
    if(T == NULL)
    {
        T = new bdnode;
        T->key[0] = x;
        T->tag = 0;
        T->size = 1;
        for(int i = 0; i < 2*d+1; i++) T->ptr[i] = NULL;
        T->parent = NULL;
    }
    else
    {
        if(T->size < (2*d))
        {
            if(T->tag == 0)
            {
                T->key[T->size++] = x;
                insertionSort(T->key, T->size);
            }
            else
            {
                for(int i = 0; i < T->size; i++)
                {
                    if(x < T->key[i])
                    {
                        create(T->ptr[i], T, x);
                        return;
                    }
                }
                create(T->ptr[T->size], T, x);
            }
        }
        else
        {
            if(T->tag == 0)
            {
                bdptr T1 = newNode(T, x);
                nodeSplit(T, x, T1);
                cout<<T->key[0]<<endl;
            }
            else
            {
                for(int i = 0; i < T->size; i++)
                {
                    if(x < T->key[i])
                    {
                        create(T->ptr[i], T, x);
                        return;
                    }
                }
                create(T->ptr[T->size], T, x);
            }
        }
    }
}

/*void inOrderPrint(bdptr T)
{
    if(T != NULL)
    {
        inOrderPrint(T->lchild);
        cout<<T->k1<<" "<<T->k2<<endl;
        inOrderPrint(T->rchild);
    }
}*/

void printCurrentLevel(bdptr T, int level)
{
    if(T != NULL)
    {
        if(level == 1)
        {
            for(int i = 0; i < T->size; i++) cout<<T->key[i]<<" ";
            cout<<"\t";
        }
        else for(int i = 0; i <= T->size; i++)printCurrentLevel(T->ptr[i], level-1);
    }
}

void levelOrderPrint(bdptr T)
{
    if(T != NULL)
    {
        for(int i = 0; i < height(T); i++)
        {
            printCurrentLevel(T, i+1);
            cout<<endl;
        }
    }
}


int main()
{
    bdptr T = new bdnode, temp = NULL;
    create(T, NULL, 3);
    create(T, NULL, 7);
    create(T, NULL, 9);
    create(T, NULL, 1);
    create(T, NULL, 6);
    create(T, NULL, 4);
    create(T, NULL, 8);
    create(T, NULL, 2);
    create(T, NULL, 5);
    cout<<T->parent->key[0];
    //cout<<T->key[0]<<" "<<T->ptr[0]->key[0];
    //levelOrderPrint(T);
    //printCurrentLevel(T, 1);
    return 0;
}
