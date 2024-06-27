#include<iostream>
using namespace std;

struct lnode;
struct gnode;



typedef struct lnode
{
    gnode *link;
    lnode *next;
} *lptr;

typedef struct gnode
{
    char c;
    gnode *down;
    lptr left;
} *gptr;


void addEnd(lptr &L, gptr G)
{
    if(L == NULL)
    {
        L = new lnode;
        L->link = G;
        L->next = NULL;
    }
    else addEnd(L->next, G);
}

void link(gptr &G, char c)
{
    gptr G1 = G;
    while(G1->c != c)G1 = G1->down;
    addEnd(G->left, G1);
    addEnd(G1->left, G);
}

void add(gptr &G, char c, char a[], int i)
{
    if(G == NULL)
    {
        G = new gnode;
        G->c = c;
        G->left = NULL;
        G->down = NULL;
        
    }
    else
    {
        add(G->down, c, a, i);
        int i = 0;
        while(a[i])
        {
            if(G->c == a[i++])
            {
                link(G, c);
                break;
            }
        }
    }
}


int main()
{
    return 0;
}
