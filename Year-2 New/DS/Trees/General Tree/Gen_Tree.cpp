#include<iostream>
using namespace std;

typedef struct gtnode
{
    char data;
    int tag;
    gtnode *fc, *n;
} *gtptr;

typedef struct btnode
{
    int data;
    btnode *lchild, *rchild;
} *btptr;


gtptr search(gtptr T, char x)
{
    if(!T || T->data == x) return T;
    else return(search(T->n, x));
}

gtptr addend(gtptr &T, char x)
{
    if(!T)
    {
        T = new gtnode;
        T->data = x;
        T->n = NULL;
        return T;
    }
    else return(addend(T->n, x));
}

void add(gtptr &T, string s, int &i)
{
    if(s[i])
    {
        if(s[i] == '}')
        {
            i++;
            return;
        }
        else
        {
            if(!T)
            {
                T = new gtnode;
                T->data = s[i++];
                T->fc = T->n = NULL;
                add(T, s, i);
            }
            else
            {
                if(s[i] == '{')
                {
                    add(T->fc, s, ++i);
                    add(T, s, i);
                }
                    
                else
                {
					cout<<s[i];
                    gtptr temp = addend(T, s[i++]);
                    add(temp, s, i);
                }
            }
        }
    }
}

void print(gtptr T)
{
    if(T)
    {
        cout<<T->data;
        if(T->fc)
        {
            cout<<"{";
            print(T->fc);
            cout<<"}";
        }
        print(T->n);
    }
}

void print(gtptr T, int i, int tag)
{
    if(!T) return;
    else
    {
        if(tag == 1) for(int a = 0; a < i; a++) cout<<" ";
        cout<<T->data;
        if(T->fc)
        {
            cout<<endl;
            print(T->fc, i+1, 1);
            if(T->n) cout<<endl;
            tag = 1;
        }
        else tag = 0;
        print(T->n, i, tag);
    }
}

int size(gtptr T)
{
    if(!T) return 0;
    else return(1+size(T->fc)+size(T->n));
}

int height(gtptr T)
{
    if(!T) return 0;
    else return(1+max(height(T->fc), height(T->n)));
}

void printCurrentLevel(gtptr T, int level)
{
    if(T)
    {
        if(level == 0)
        {
            cout<<T->data<<" ";
            printCurrentLevel(T->n, level);
        }
        else
        {
            printCurrentLevel(T->fc, level-1);
            printCurrentLevel(T->n, level);
        }
    }
}

void levelOrderPrint(gtptr T)
{
    for(int i = 0; i < height(T); i++)
    {
        printCurrentLevel(T, i);
        cout<<endl;
    }
}

int height(btptr T)
{
    if(!T) return 0;
    else return(1+max(height(T->lchild), height(T->lchild)));
}

void printCurrentLevel(btptr T, int level)
{
    if(T)
    {
        if(level == 0)
        {
            cout<<T->data<<" ";
        }
        else
        {
            printCurrentLevel(T->lchild, level-1);
            printCurrentLevel(T->rchild, level);
        }
    }
}

void levelOrderPrint(btptr T)
{
    for(int i = 0; i < height(T); i++)
    {
        printCurrentLevel(T, i);
        cout<<endl;
    }
}

void convert(gtptr T, btptr &T2, int s, btptr &temp)
{
    if(!T) T2 = NULL;
    else
    {
        temp->data = T->data;
        temp->lchild = temp->rchild = NULL;
        
        if(!T->fc)
        {
            levelOrderPrint(T2);
            T->tag = 1;
        }
        else
        {
            gtptr temp2 = T->fc, next;
            while(temp2) if(temp2->tag != 1) next = temp2;
        }
    }
}

void print1();


int main()
{
    gtptr T = NULL; btptr T2 = NULL;
    int i = 0;
    string s = "A{B{L{PQRS}CD}M{EF}J{H{I{MN}}}KT}";
    
    add(T, s, i);
    
    levelOrderPrint(T);
    
    return 0;
}
