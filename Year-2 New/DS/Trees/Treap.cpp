#include<iostream>
using namespace std;

typedef struct tnode
{
    char k1;
    int k2;
    tnode *lchild, *rchild;
} *tptr;


bool checkTreap(tptr T)
{
    if(T == NULL) return true;
    else
    {
        if(T->lchild == NULL && T->rchild == NULL) return true;
        else
        {
            if(T->lchild == NULL && T->k1 < T->rchild->k1 && T->k2 < T->rchild->k2) return(checkTreap(T->rchild));
            else if(T->rchild == NULL && T->k1 > T->lchild->k1 && T->k2 < T->lchild->k2) return(checkTreap(T->lchild));
            else if(T->lchild != NULL && T->rchild != NULL)
            {
                if(T->k1 > T->lchild->k1 && T->k1 < T->rchild->k1 && int(T->k2) < int(T->lchild->k2) && int(T->k2) < int(T->rchild->k2)) return(checkTreap(T->lchild) && checkTreap(T->rchild));
                else return false;
            }
            else return false;
        }
    }
}

int height(tptr T)
{
    if(T == NULL) return 0;
    else return(1+ max(height(T->lchild), height(T->rchild)));
}

void create(tptr &T, tptr &parent, char k, int x)
{
    if(T == NULL)
    {
        T = new tnode;
        T->k1 = k;
        T->k2 = x;
        T->lchild = T->rchild = NULL;
    }
    else
    {
        if(int(T->k1) > int(k))
        {
            create(T->lchild, T, k, x);
            tptr temp = T->lchild;
            if(checkTreap(T) == false)
            {
                T->lchild = temp->rchild;
                temp->rchild = T;
                if(parent != NULL )
                {
                    if(parent->lchild == T) parent->lchild = temp;
                    else parent->rchild =temp;
                }
                T = temp;
            }
        }
        else if (int(T->k1) < int(k))
        {
            create(T->rchild, T, k, x);
            tptr temp = T->rchild;
            if(checkTreap(T) == false)
            {
                T->rchild = temp->rchild;
                temp->lchild = T;
                if(parent != NULL )
                {
                    if(T == parent->lchild) parent->lchild = temp;
                    else parent->rchild =temp;
                }
                T = temp;
            }
        }
    }
}

void inOrderPrint(tptr T)
{
    if(T != NULL)
    {
        inOrderPrint(T->lchild);
        cout<<T->k1<<" "<<T->k2<<endl;
        inOrderPrint(T->rchild);
    }
}

void printCurrentLevel(tptr T, int level)
{
    if(T != NULL)
    {
        if(level == 0)
        {
            cout<<T->k1<<" "<<T->k2<<"\t";
        }
        else
        {
            printCurrentLevel(T->lchild, level-1);
            printCurrentLevel(T->rchild, level-1);
        }
    }
}

void levelOrderPrint(tptr T)
{
    for(int i = 0; i < height(T); i++)
    {
        printCurrentLevel(T, i);
        cout<<endl;
    }
}


int main()
{
    tptr T = NULL, temp = NULL;
    create(T, temp, 'P', 45);
    create(T, temp, 'S', 59);
    create(T, temp, 'H', 21);
    create(T, temp, 'M', 37);
    create(T, temp, 'E', 32);
    create(T, temp, 'F', 3);
    levelOrderPrint(T);
    return 0;
}
