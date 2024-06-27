#include<bits/stdc++.h>
using namespace std;
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
void cycles(int a[20][20],int n)
{
	int edge=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			{
				if(a[i][j]==1)
					edge+=1;
			}
	}
	edge=edge/2;
	if(edge>(n-1))
		cout<<"cycle is present \n";
	else
		cout<<"cycle is not present \n";	
}
int p[20]={0};
void path(int a[20][20],int n,int v,int u,int cnt)
{
	if(v==u)
	{
		for(int j=0;j<cnt;j++)
		{
			cout<<p[j]+1<<"->";
		}
		cout<<u+1;	
		cout<<endl;
		return;
	}
	for(int i=0;i<cnt;i++)
	{
		if(p[i]==v) 
			return;
	}
	p[cnt]=v;
		for(int i=0;i<n;i++)
		{
			if(a[v][i]==1)
			{
				path(a,n,i,u,cnt+1);
			}
		}
}
float cycle(int a[20][20],int n,int v,int u,int cnt)
{
	float i=0.0;
	if(cnt>=3&&v==u)
		return 1.0/(2*cnt);
	for(int j=0;j<cnt;j++)
	{
		if(p[j]==v)	return 0;
	}	
	p[cnt]=v;
	for(int j=0;j<n;j++)
	{
		if(a[v][j]==1)
			i += cycle(a,n,j,u,cnt+1);
	}
	return i;
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
int degree(int g[20][20],int n,int v)
{
	int cnt=0;
	for(int i=0;i<n;i++)
	{
		if(g[v][i]==1)
			cnt++;
	}
	return cnt;
}
int indegree(int g[20][20],int n,int v)
{
	int cnt=0;
	for(int i=0;i<n;i++)
	{
		if(g[i][v]==1)
			cnt++;
	}
	return cnt;
}
int outdegree(int g[20][20],int n,int v)
{
	int cnt=0;
	for(int i=0;i<n;i++)
	{
		if(g[v][i]==1)
			cnt++;
	}
	return cnt;
}
void strong(int G[20][20],int n)
{
	int flg=0;
	int k=0;
	while(k<n)
	{
		int i=indegree(G,n,k);
		int j=outdegree(G,n,k);
		if(i+j==0)
		{
			cout<<"weakly connected \n";
			flg=1;
			break;
		}
		k++;
	}
	if(flg==0)
		cout<<"strongly connected \n";
	
}
int main()
{
	cout<<"enter total number of verticess \n";
	int n;
	cin>>n;
	int a[20][20];
	cout<<"enter the edges \n 1=present \n 0=not present \n";
	insert(n,a);
	print(n,a);
	cout<<indegree(a,n,4)<<"\n";
	cout<<outdegree(a,n,5)<<"\n";
	strong(a,n);
	for(int j=0;j<n;j++)
	{
		for(int k=0;k<n;k++)
		{
			if(j!=k)
			{
				cout<<"path between "<<j+1<<" and "<<k+1<<endl;
				int i=0;
				path(a,n,j,k,i);
			}
		}
	}
	float j=0.0;
	for(int i=0;i<n;i++)
	{
		j+=cycle(a,n,i,i,0);
		cout<<j<<" ";
	}
	cout<<"total number of cycles present is = "<<j<<endl;
}
