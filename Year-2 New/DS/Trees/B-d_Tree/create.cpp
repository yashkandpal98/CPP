#include<iostream>
using namespace std;
struct bdnode
{
    int count;
    int key[20];
    struct bdnode *ptr[21];
};
typedef struct bdnode* BDPTR;
void create(BDPTR &T,int d,int n);
void swap(int&x,int &y)
{
int t;
t=x;
x=y;
y=t;
}
void bubble(int A[],int n)
{
    int i,j;
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if (A[j]>A[j+1])
            {
                swap(A[j],A[j+1]);
            }
        }
    }
}
int leaf(BDPTR &T,int d)
{
    if(T!=NULL)
    {
        int c=1;
        for(int i=0;i<=2*d;i++)
        {
            if(T->ptr[i]!=NULL)
            {
                c=0;
                break;
            }
        }
        return c;
    }
    else return 0;
}
void overflow(BDPTR &B,int a[],int x)
{
	for(int i=0;i<B->count;i++)
	{
		a[i]=B->key[i];
	}
	a[B->count]=x;
	bubble(a,B->count+1);
}
void add(BDPTR &B,int a[],int d)
{
	for(int i=0;i<d;i++)
	{
		B->key[i]=a[i];
	}
	B->count=d;
	BDPTR K,K1;
	K=B;
	K1=new(bdnode);
	for(int k=0;k<=2*d;k++)
		K1->ptr[k]=NULL;
	K1->count=d;
	int j=0;
	for(int i=d+1;i<2*d+1;i++)
		{
			K1->key[j]=a[i];
			j++;
		}
	B=NULL;
	create(B,d,a[d]);
	B->ptr[0]=K;
	B->ptr[1]=K1;
}
void create(BDPTR &T,int d,int n)
{
        if(T==NULL)
        {
            int x;
            T=new(bdnode);
            for(int i=0;i<=2*d;i++)
            {
             T->ptr[i]=NULL;
            }
            T->count=1;
            x=T->count;
            T->key[x-1]=n;
            return;
        }
        else
        {
            if(leaf(T,d)==1)
            {
                if(T->count<2*d)
                {
                    int x;
                T->count++;
                x=T->count;
                T->key[x-1]=n;
                bubble(T->key,T->count);
                 return;
                }
                else if(T->count==2*d)
                {
                    int a[21];
                    overflow(T,a,n);
                    add(T,a,d);
                    return;
                }
            }
            else if(leaf(T,d)==0)
            {
                 for(int i=0;i<T->count;i++)
                {
                    if(n<T->key[i])
                    {
                        create(T->ptr[i],d,n);
                        return;
                    }
                 }
                 create(T->ptr[T->count],d,n);
            }

         }
}

void sortorder(BDPTR &T,int d)
{
    if(T!=NULL)
    {

        for(int i=0;i<T->count;i++)
        {
           sortorder(T->ptr[i],d);
             cout<<T->key[i]<<endl;

        }
        sortorder(T->ptr[T->count],d);
    }

}
int main()
{
    BDPTR T;
    T=NULL;
    int x,d;
    cout<<"Enter the value of d\n";
    cin>>d;
    cout<<"Enter x \n";
    cin>>x;
    while(x!=-1)
    {
        create(T,d,x);
        cin>>x;
    }
    sortorder(T,d);
return 0;
}
