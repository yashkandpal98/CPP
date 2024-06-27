#include<iostream>
using namespace std;
struct bdnode
{
    int count;
    int key[20];
    struct bdnode *ptr[21];
};
typedef struct bdnode* BDPTR;
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
void sort(BDPTR &T, int k)
{
	int i = 0;
	while (i < T->count && T->key[i] < k)
	{
		i++;
	}
	for (int j = T->count; j > i; j--)
	{
		T->ptr[j + 1] = T->ptr[j];
	}
	for (int j = T->count; j > i; j--)
	{
		T->key[j] = T->key[j - 1];
	}
	T->key[i] = k;
	T->count++;
}
void overflow(BDPTR &T,int &k,int d,int &flag,BDPTR &P)
{
    int c = 0;
	if (T->ptr[0] == NULL && T->ptr[1] == NULL)
	{
		if (T->count < 2 * d)
		{
			sort(T, k);
			flag=0;
		}
		else
		{
			c = 1;
		}
	}
	else
	{
		int i = 0;
		while (i < T->count && T->key[i] < k)
		{
			i++;
		}
		overflow(T->ptr[i], k, d, flag, P);
		if (flag == 1)
		{
			if (T->count < 2 * d)
			{
				sort(T, k);
				int j = 0;
				while (T->key[j] != k)
				{
					j++;
				}
				T->ptr[j + 1] = P;
				flag=0;
			}
			else
			{
				c = 1;
			}
		}
	}
	if (c ==1)
	{
		BDPTR t1 = new bdnode;
		t1->count = 2 * d;
		for (int i = 0; i < 2 * d; i++)
		{
			t1->key[i] = T->key[i];
			t1->ptr[i] = T->ptr[i];
		}
		t1->ptr[2 * d] = T->ptr[2 * d];
		sort(t1, k);
		int ind = 0;
		while (t1->key[ind] != k)
		{
			ind++;
		}
		t1->ptr[ind + 1] = P;
		BDPTR t = new bdnode;
		for (int i = 0; i < d; i++)
		{
			T->key[i] = t1->key[i];
			T->ptr[i] = t1->ptr[i];
		}
		T->ptr[d] = t1->ptr[d];
		for (int i = d + 1; i < 2 * d + 1; i++)
		{
			T->ptr[i] = NULL;
			t->ptr[i] = NULL;
		}
		for (int i = 0; i < d; i++)
		{
			t->key[i] = t1->key[i + d + 1];
		}
		for (int i = 0; i < d + 1; i++)
		{
			t->ptr[i] = t1->ptr[i + d + 1];
		}
		T->count = d;
		t->count = d;
		k = t1->key[d];
		P = t;
		flag=1;
	}
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
        }
        else
        {
                        int flag=0;
                        BDPTR P=NULL;
                        overflow(T,n,d,flag,P);
                        if(flag==1)
                        {
                            int x;
                            BDPTR T1;
                            T1=new(bdnode);
                            for(int i=0;i<=2*d;i++)
                            {
                            T1->ptr[i]=NULL;
                            }
                            T1->count=1;
                            x=T1->count;
                            T1->key[0]=n;
                            T1->ptr[0]=T;
                            T1->ptr[1]=P;
                            T=T1;
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
struct queue
{
    int f;
    int r;
    int size;
    BDPTR element[50];
};
void enque(queue &q, BDPTR c)
{
    if((q.r+1)%q.size==q.f)
    {
        cout<<"Queue full \n";
    }
    else
    {
        if(q.f==-1)
        {
            q.f=0;
        }
        q.r=(q.r+1)%q.size;
        q.element[q.r]=c;
    }
}
BDPTR deque(queue &q)
{
    BDPTR t;
    if(q.f==((q.r+1)%q.size))
    {
        cout<<"Empty queue \n";
    }
    else
    {
        t=q.element[q.f];
        if(q.f==q.r)

        {
            q.f=-1;
            q.r=-1;
        }
        else
        {
            q.f=(q.f+1)%q.size;
        }
        return t;
    }
}
int sort(BDPTR T,int d,int A[])
{
    static int c=0;
    if(T!=NULL)
    {

        for(int i=0;i<(T->count);i++)
        {
            sort(T->ptr[i],d,A);
          A[c++]=T->key[i];
        }
        sort(T->ptr[T->count],d,A);
        return c;
    }

}
void print(BDPTR T,struct queue &q,int d,int A[])
{
    static int x=0;
    BDPTR T1;
    T1=new(bdnode);
    T1->count =-1;
    T1->ptr[2*d]=NULL;
    for(int i=0;i<2*d;i++)
    {
        T1->key[i]=-1;
        T1->ptr[i]=NULL;
    }

        if(q.f!=-1&&q.f!=q.r)
        {
              BDPTR T2;
            T2=deque(q);
            int n=0;
            while(A[n]!=T2->key[0])
            {
                n++;
            }
                for(int i=x;i<n;i++)
                {
                    cout<<"  ";
                }
                x=n+T2->count;


                for(int i=0;i<T2->count;i++)
                {
                    cout<<T2->key[i]<<" ";
                }
                for(int i=0;i<=2*d;i++)
                {
                    if(T->ptr[i]!=NULL)enque(q,T->ptr[i]);
                }
                if(q.element[q.f]->count==-1)
                {
                    cout<<endl;
                    x=0;
                    deque(q);
                        enque(q,T1);

                }
                print(q.element[q.f],q,d,A);

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
    //cout<<T->ptr[1]->key[0]<<endl;
    //sortorder(T,d);
        int A[50];
     BDPTR T1;
    T1=new(bdnode);
    T1->count=-1;
    T1->ptr[2*d]=NULL;
    for(int i=0;i<2*d;i++)
    {
        T1->key[i]=-1;
        T1->ptr[i]=NULL;
    }
    struct queue q;
    q.f=-1;
    q.r=-1;
    q.size=49;
    sort(T,d,A);

        enque(q,T);
        enque(q,T1);
        print(T,q,d,A);

return 0;
}
