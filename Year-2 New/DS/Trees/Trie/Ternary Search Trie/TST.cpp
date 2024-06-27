#include<iostream>
using namespace std;


typedef struct tstnode
{
    int tag;
    char key;
    tstnode *less, *equal, *great;
} *tstptr;


void add(tstptr &T, string s, int i)
{
    if(s[i])
    {   if(T == NULL)
        {
            T = new tstnode;
            T->key = s[i];
            T->less = T->great = NULL;
            T->equal = NULL;
            if(! s[i+1]) T->tag = 1;
            else
            {
                T->tag = 0;
                if(s[i+1] > s[i]) add(T->great, s, i+1);
                else if(s[i+1] < s[i]) add(T->less, s, i+1);
                else add(T->equal, s, i+1);
            }
        }
        else
        {
            if(s[i] > T->key) add(T->great, s, i);
            else if(s[i] < T->key) add(T->less, s, i);
            else if(i == 0 && s[i] == T->key) add(T, s, i+1);
            else add(T->equal, s, i+1);
        }
    }
}

bool search(tstptr T, string s, int i)
{
    if(T == NULL) return false;
    else
    {
        if(s[i])
        {
            if(s[i] == T->key)
            {
                if(T->tag == 1 && (! s[i+1])) return true;
                else if(T->tag == 0)
                {
                    if(! s[i+1]) return false;
                    else
                    {
                        if(s[i+1] < T->key) return(search(T->less, s, i+1));
                        else if(s[i+1] == T->key) return(search(T->equal, s, i+1));
                        else if(s[i+1] > T->key) return(search(T->great, s, i+1));
                    }
                }
                else return false;
                
                
            }
            
        }
        else return false;
    }
}

int height(tstptr T)
{
    if(T != NULL)
    {
        int m = max(height(T->less), height(T->equal));
        return(max(m, height(T->great))+1);
    }
    else return 0;
}

void printCurrentLevel(tstptr T, int level)
{
    if(T != NULL)
    {
        if(level == 0)
        {
            cout<<T->key<<" ";
        }
        else
        {
            printCurrentLevel(T->less, level-1);
            printCurrentLevel(T->equal, level-1);
            printCurrentLevel(T->great, level-1);
        }
    }
}

void levelOrderPrint(tstptr T)
{
    for(int i = 0; i < height(T); i++)
    {
        printCurrentLevel(T, i);
        if(i < height(T)-1) cout<<endl;
    }
}


int main()
{
    tstptr T = NULL;
    
    add(T, "in", 0);
    add(T, "at", 0);
    add(T, "inn", 0);
    
    levelOrderPrint(T);
    
    return 0;
}
