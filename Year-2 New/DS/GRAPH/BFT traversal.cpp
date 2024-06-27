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

void BFT(int a[20][20],int u,queue q,int n)
{
	int visited[5]={0};
	
	enqueue(q,u);
	visited[u-1]=1;
	while(q.f!=-1)
	{
		u=dequeue(q);
		for(int i=0;i<n;i++)
		{
			if(a[u-1][i]==1)
			{
				if(visited[i]==0)
				{
					enqueue(q,i+1);
					visited[i]=1;
					
					cout<<u<<"->"<<i+1<<endl;
				}
				BFT(a,i+1,q,n);
			}
		}
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
	BFT(a,1,q,n);
}
