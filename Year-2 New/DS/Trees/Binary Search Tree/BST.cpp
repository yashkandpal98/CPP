#include<iostream>
using namespace std;


typedef struct trnode
{
    int tag;
    union u1
    {
        char word[50];
        trnode *ptr[27];
    } key;
} *trptr;


void newNode(trptr &T, string s)
{
    T = new trnode;
    T->tag = 0;
    for(int j = 0; j < s.size(); j++) T->key.word[j] = s[j];
    
}

void add(trptr &T, string s, int i)
{
    if(T == NULL)
    {
        T = new trnode;
        T->tag = 1;
        for(int j = 0; j < 27; j++)T->key.ptr[j] = NULL;
        
        newNode(T->key.ptr[int(s[i])-97], s);
    }
    else
    {
        if(T->tag == 0)                                                             //If data node is found
        {
            T->tag = 1;
            string s1;

            int j = 0;
            while(T->key.word[j]) s1 += T->key.word[j++];                            //Pushing existing data onto a string

            if(s == s1)                                                             //Checking for duplicate entry
            {
                cout<<"Duplicate entry.\n";
                T->tag = 0;
                return;
            }
            
            T = new trnode;
            T->tag = 1;
            for(int j = 0; j < 27; j++)T->key.ptr[j] = NULL;
            
            if(i == s1.size()) newNode(T->key.ptr[26], s1);
            else if(i < s1.size()) newNode(T->key.ptr[int(s1[i])-97], s1);

            if(i == s.size()) newNode(T->key.ptr[26], s);                           //If end of word is reached, store in extra node
            else if(i < s.size())                                                   //Else send string lower
            {
                if(T->key.ptr[int(s[i])-97] == NULL) newNode(T->key.ptr[int(s[i])-97], s);
                else add(T->key.ptr[int(s[i])-97], s, i+1);
            }
        }
        else                                                                        //If index node is found
        {
            if(T->key.ptr[26] != NULL && i == s.size())
            {
                cout<<"Duplicate entry.\n";
                return;
            }
            
            if(i == s.size()) newNode(T->key.ptr[26], s);                           //If end of word is reached, store in extra node
            else if(i < s.size())                                                   //Else send string lower
            {
                if(T->key.ptr[int(s[i])-97] == NULL) newNode(T->key.ptr[int(s[i])-97], s);
                else add(T->key.ptr[int(s[i])-97], s, i+1);
            }
        }
    }
}



int height(trptr T)
{
    if(T == NULL) return 0;
    else if(T->tag == 0) return 1;
    else
    {
        int ht = 0;
        for(int i = 0; i < 27; i++) ht = max(ht, height(T->key.ptr[i]));
        return (ht+1);
    }
}

void printCurrentLevel(trptr T, int level)
{
    if(T != NULL)
    {
        if(level == 0)
        {
            if(T->tag == 0) cout<<T->key.word;
            else
            {
                cout<<"Index";
                if(T->key.ptr[26] != NULL) cout<<"+"<<T->key.ptr[26]->key.word;
            }
            cout<<"\t";
        }
        else if(level > 0 && T->tag == 1) for(int i = 0; i < 26; i++) printCurrentLevel(T->key.ptr[i], level-1);
    }
}

void levelOrderPrint(trptr T)
{
    for(int i = 0; i < height(T); i++)
    {
        printCurrentLevel(T, i);
        if(i < height(T)-1) cout<<endl;
    }
}

bool search(trptr T, string s, int i)
{
    if(T == NULL || i > s.size()) return false;
    else
    {
        if(T->tag == 1)
        {
            if(i == s.size())
            {
                if(T->key.ptr[26] == NULL|| T->key.ptr[26]->key.word[i-1] != s[i-1]) return false;
                
                else return true;
            }
            else return(search(T->key.ptr[int(s[i])-97],s, i+1));
        }
        else
        {
            int j = 0; string s1;
            while(T->key.word[j]) s1 += T->key.word[j++];
            
            if(s1.size() == s.size())
            {
                while(s1[j]) if(s1[j] != s[j++]) return false;
                
                return true;
            }
            else return false;
        }
    }
}

trptr del(trptr &T, string s, int i)
{
    if(T == NULL || i > s.size()) cout<<"Element not found.\n";
    else
    {
        if(T->tag == 1)
        {
            if(i == s.size())
            {
                if(T->key.ptr[26] == NULL || T->key.ptr[26]->key.word[i-1] != s[i-1]) cout<<"Element not found.\n";
                
                else T->key.ptr[26] = NULL;
            }
            else return(del(T->key.ptr[int(s[i])-97],s, i+1));
        }
        else
        {
            int j = 0; string s1;
            while(T->key.word[j]) s1 += T->key.word[j++];
            
            if(s1.size() == s.size())
            {
                while(s1[j]) if(s1[j] != s[j++]) cout<<"Element not found.\n";
                
                T = NULL;
            }
            else cout<<"Element not found.\n";
        }
    }
}


int main()
{
    trptr T = NULL;
    
    add(T, "aab", 0);
    add(T, "abbbc", 0);
    add(T, "baa", 0);
    add(T, "bccaa", 0);
    add(T, "bc", 0);
    add(T, "cabb", 0);
    add(T, "a", 0);
    add(T, "abb", 0);
    add(T, "cab", 0);
    add(T, "bcc", 0);
    levelOrderPrint(T);
    
    cout<<endl<<endl;
    
    trptr temp = del(T, "b", 0);
    
    cout<<endl;
    
    levelOrderPrint(T);
    
    return 0;
}
