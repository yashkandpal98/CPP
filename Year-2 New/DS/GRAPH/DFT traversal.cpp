#include<iostream>
using namespace std;
struct queue
{
	int f;
	int r;
	int elements[50];
	int size;
};
void enqueue(queue &q,int x)
{
	if(q.f==(q.r+1)%q.size)
		cout<<"queue is full";
	else
	{
		if(q.r==-1)
			q.f=0;
		q.r=(q.r+1)%q.size;
		q.elements[q.r]=x;
		}	
}
int dequeue(queue &q)
{
	int t;
	if(q.f==-1)
		cout<<"stack is empty";
	else
	{
		t=q.elements[q.f];
		if(q.f==q.r)
		{
			q.f=-1;
			q.r=-1;
		}
		else
			q.f=(q.f+1)%q.size;
		}	
		return t;
}

void insert(int n,int a[20][20])
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			int k;
			cout<<"edge between "<<i+1<<" and "<<j+1<<"\n";
			cin>>k;
			a[i][j]=k;
		}
	}
}
void print(int n,int a[20][20])
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<a[i][j]<<" ";
		}
		cout<<"\n";
	}
}
int p[20]={0};
void DFT(int a[20][20],int u,int n,int cnt)
{
	int visited[5]={0};
	for(int i=0;i<cnt;i++)
	{
		if(p[i]==u)
			return;
	}
	if(cnt!=n-1)
	{
		p[cnt]=u;
		visited[u-1]=1;
		for(int i=0;i<n;i++)
		{
			if(a[u-1][i]==1)
			{
				if(!visited[i])
					DFT(a,i+1,n,cnt+1);
			}
		}
	}
	else
	{
		for(int j=0;j<cnt;j++)
			cout<<p[j]<<" ";
		cout<<u<<endl;	
	}
}
int main()
{
	struct queue q;
	q.f=-1;
	q.r=-1;
	q.size=50;
	cout<<"enter total number of verticess \n";
	int n;
	cin>>n;
	int a[20][20];
	cout<<"enter the edges \n 1=present \n 0=not present \n";
	insert(n,a);
	print(n,a);
	DFT(a,1,n,0);
}
