#include<iostream>
#include<cstring>
using namespace std;
struct btnode
{
    struct btnode *lchild;
    string data;
    struct btnode *rchild;
};
typedef struct btnode* BTPTR;
void create(BTPTR &T)
{
    char  n;
     cout<<"Enter child\n";
     cin>>n;
     if(n!='.')
     {
          T=new(btnode);
          T->data=n;
          T->lchild=NULL;
          T->rchild=NULL;
            create(T->lchild);
            create(T->rchild);
        return;
     }
}
int inorder(BTPTR T,string LDR[])
{
    static int i=0;
    if(T!=NULL)
     {
        inorder(T->lchild,LDR);
        LDR[i++]=T->data;
        inorder(T->rchild,LDR);
        return i;
     }
}

int preorder(BTPTR T,string DLR[])
{
    static int i=0;
    if(T!=NULL)
     {
        DLR[i++]=T->data;
        preorder(T->lchild,DLR);
        preorder(T->rchild,DLR);
        return i;
     }
}
int mid(string LDR,string DLR,int x)
{
    static int j=0;
     int n=LDR.length();
    for(int i=0;i<n;i++)
    {
        if(LDR[i]==DLR[x])
        {
            return i;
        }
    }
}

void create(string LDR,string DLR,BTPTR &T,int l,int &i,int a,int b)
{
    int m;
     m=mid(LDR,DLR,i);
    if(a>=l)
    {

        T=new(btnode);
        T->lchild=NULL;
        T->rchild=NULL;
        T->data=DLR[i];
        i=i+1;
        create(LDR,DLR,T->lchild,l,i,m-1,b);
        create(LDR,DLR,T->rchild,m+1,i,a,b);
    }
    if(a<l)return;

}
void print(BTPTR &T)
{

    if(T!=NULL)
    {
        print(T->lchild);
        cout<<T->data<<" ";
        print(T->rchild);
        return;

    }
}
int main()
{
BTPTR T;
string LDR,DLR;
int a,b,m;
cout<<"enter LDR \n";
cin>>LDR;
cout<<"Enter DLR \n";
cin>>DLR;
a=LDR.length();
b=DLR.length();
int i=0;
create(LDR,DLR,T,0,i,a-1,b);
print(T);
return 0;
}
