#include<iostream>
#include<cstring>
using namespace std;
struct queue
{
	int f;
	int r;
	int elements[50];
	int size;
};
typedef
struct gnode
{
	int data;
	char c[20];
}*GTPTR;
typedef
struct lnode
{
	char s[20];
	int deg;
	lnode *next;
}*LPTR;
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
int a[20][20];
void print(int n)
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
int search(GTPTR G[],char a[],int i)
{
	if(strcmp(G[i]->c,a)!=0)
	{
		search(G,a,i+1);
	}
	else
		return G[i]->data;
}
void insert(GTPTR G[],int n)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			a[i][j]=0;
	}
	cout<<"enter the subjects where edges are present between a to b to end press !\n";
	char d[10],b[10];
	cin>>d>>b;
	while(d[0]!='!'&&b[0]!='!')
	{
		int i=search(G,d,0);
		int j=search(G,b,0);
		a[i][j]=1;
		cin>>d>>b;
	}
}
int indegree(int n,int v)
{
	int cnt=0;
	for(int i=0;i<n;i++)
	{
		if(a[i][v]==1)
			cnt++;
	}
	return cnt;
}
int main()
{
	int n;
	cout<<"enter the number of subjects \n";
	cin>>n;
	GTPTR G[n];
	cout<<"enter the name of subjects \n";
	int i=0;
	char ch[10];
	cin>>ch;
	while(i<n)
	{
		G[i]=new gnode();
		strcpy(G[i]->c,ch);
		G[i]->data=i;
		i++;
		if(i<n)
			cin>>ch;
	}
	insert(G,n);
//	for(int i=0;i<n;i++)
//	{
//		for(int j=0;j<n;j++)
//			a[i][j]=0;
//	}
	print(n);
	for(int i=0;i<n;i++)
		G[i]->data=indegree(n,search(G,G[i]->c,0));
	cout<<endl;	
	for(int i=0;i<n;i++)
		cout<<G[i]->data<<" ";
	cout<<"choose your first subject \n";
	cin>>ch;
	char x[n][10];
	for(int i=0;i<n;i++)
		x[i][0]='.';
	for(int i=0;i<n;i++)
		cout<<x[i][0]<<" ";	
	for(int i=0;i<n;i++)
	{
		if(strcmp(ch,G[i]->c)==0)
		{
			//strcpy(x[i],ch);
			for(int j=0;j<n;j++)
			{
				if(a[i][j]==1)
					G[j]->data-=1;	
			}		
		}		
	}
	int flg=1;
	while(flg!=n)
	{
		for(int i=0;i<n;i++)
		{
			if(G[i]->data==0)
			{
				strcpy(x[i],G[i]->c);
				flg+=1;
				for(int j=0;j<n;j++)
				{
					if(a[i][j]==1)
						G[j]->data-=1;	
				}
			}
		}
		cout<<"enter subjects you want to read \n";
		for(int i=0;i<n;i++)
		{
			if(x[i][0]!='.')
				cout<<x[i]<<"\t";
		}
		break;
		cout<<endl;
	}
				
}
