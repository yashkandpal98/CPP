#include <iostream>
using namespace std;
typedef struct lnode{
    int data;
    lnode *next;

}*lptr;
lptr L=NULL;
lptr L1=NULL;
int r[100];
int b[100];
int h=1;
int w=1;
int e=1;
int c=0;
int const N=100;
int s;
int degree(int a[][N],int u,int n)
{     int x;
      for(int j=0;j<n;j++)
      {
        if(a[u][j]==1)
        {
            x++;
        }

      }
      return x;






}
void create(lptr &L,int u){
    lptr T;
    if(L==NULL)
    {
        L=new lnode;
        L->next=NULL;
        L->data=u;
       cout<<L->data;
    }
    else
    {
        T=L;
        while(T->next!=NULL)
        {
            T=T->next;
        }
           // cout<<"tumo";
            T->next=new lnode;
            T->next->data=u;
            T->next->next=NULL;
            cout<<T->data;
    }
}
void link(lptr &L,lptr &L1){
   lptr T=L;
   lptr P=L1;
    lptr Q;
      while(T->data!=L1->data)
    {
        T=T->next;
    }
        Q=T->next;

    T->next=L1->next;
    while(P->next!=NULL)
    {
        P=P->next;
    }
    P->next=Q;
    L1=NULL;







}
int visit(int b[],int k,int n)
{
    int f=0;
if(n==0){
    return 0;
}
    while(k!=b[f]&&f<n){
        f++;
    }
    if(f==n)
    {
        return 0;
    }
    else
    {
        return 1;
    }


}
void dfstraverse(int a[][N],int u,int n)
{int j;
    for(int i=0;i<n;i++)
    {
   // if(a[u][i]==1&&visit(b,i,h)!=1)
            if(a[u][i]==1)
            {
                a[u][i]=0;
                a[i][u]=0;
                //cout<<"sex";
                j=i;
                if(c==0){
                create(L,j);
              //  cout<<"namaan";
                //cout<<c;


                }
                else
                {
                   create(L1,j);
                   //cout<<"endl";


                }
                    if(c>0)
                    {
                        link(L,L1);
                    }

                //b[h]=j;
               // h++;
                 //cout<<j;
                 if(degree (a,j,n)==0)
                {     c++;
                //cout<<"akjshdg";

                    while(degree(a,L->data,n)==0)
                    {
                        L=L->next;
                    }
                    if(L==NULL)
                    {
                        cout<<"complete";
                    }

                     j=L->data;
                }
                dfstraverse(a,j,n);
            }
        }

 /*   for(int i=11



0;i<n;i++){
        if(visit(b,i,h)==0){
                cout<<i;
                  b[h]=i;
                  h++;
            dfstraverse(a,i,n);
        }

    }

*/




}
/*void path(int a[][N],int u,int v,int n){
int t;
    if(u!=v){


         for(int i=0;i<n;i++)
    {
        if(a[u][i]==1&&visit(c,i,e)!=1)
            {   t=i;
                c[e]=t;

             //   if(t!=v){
                    e++;



                if(t==v)
                {
                    for(int w=0;w<e;w++)
                    {
                        cout<<c[w]<<"  ";
                    }
                   cout<<endl;}
                path(a,t,v,n);
                e--;
            }

    }

    }





}*/

int main()
{  int n;
int a[100][100];
    cout<<"enter the no. of vertices"<<endl;
   cin>>n;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<"for i="<<i<<"and j="<<j<< "     ";
            cin>>a[i][j];
            cout<<endl;
         }
    }
    int v;
    cout<<"enter the starting vertex"<<endl;
    cin>>v;
   // cout<<"enter end vertex"<<endl;
    //int g,s;
    //cin>>g>>s;

    //b[0]=v;
   // c[0]=v;
    //r[0]=v;
    //cout<<v;
    create(L,v);

    dfstraverse(a,v,n);


  //  path(a,g,s,n);


    return 0;
}
