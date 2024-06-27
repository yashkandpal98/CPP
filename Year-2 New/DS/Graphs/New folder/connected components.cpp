#include<iostream>
using namespace std;


int indegree(int G[][20],int n,int v){
	int i, count = 0;
	for(i=1; i <= n; i++)
	{
		if(G[i][v]==1) count++;
	}
	return count;
}

void SCDFT(int G[][20], int u, int n, int count, int visited[], int num[])
{
	int i,j;
	static int m=1,c=0;
	
	visited[u]=1;
	c++;
	
	for(j=1;j<=n;j++)
	{
		if(G[u][j] == 1)
		{
			if(visited[j] != 1){
				SCDFT(G,j,n,count,visited,num);
			}
		}
	}

	num[u]=m++;
	c--;

	if(m<n && c==0)
	{
		for(i=1;i<=n;i++){
			if(visited[i]!=1){
				u=i;
				SCDFT(G,u,n,count,visited,num);
				break;
			}
		}
	}
}

int max(int num[],int n,int visited[])
{
	int m=0,i,c;
	for(i=1;i<=n;i++){
		if(m<num[i] && visited[i]!=1){
			m=num[i];
			c=i;
		}
	}
	return(c);
}

void DFT(int G[][20],int u,int n,int count,int visited[],int num[])
{
	int i,j;
	static int m=0;
	m++;
	visited[u]=1;
	for(j=1;j<=n;j++){
		if(G[u][j]==1){
			if(visited[j]!=1){
				cout<<j<<" ";
				DFT(G,j,n,count,visited,num);
			}
		}
	}
	if(m<n){
		u=max(num,n,visited);
		cout<<endl<<u<<" ";
		DFT(G,u,n,count,visited,num);
	}
}

int main()
{
	int i,j,n,d,v,u;
	
	cout<<"Enter no. of vertices\n"; cin>>n;
	
	int G[n+1][20],R[n+1][20], visited[n+1], num[n+1];
	cout<<"\nEnter edges\n";
	
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			cout<<"\nEnter edge between vertices "<<i<<" and "<<j<<" : ";
			cin>>G[i][j];
			R[j][i]=G[i][j];
		}
	}
	
	cout<<"\nEnter star vertex\n"; cin>>u;
	
	SCDFT(G,u,n,1,visited,num);
	
	for(i=1;i<=n;i++) visited[i]=0;
	
	u=max(num,n,visited);
	cout<<u<<" ";
	
	DFT(R,u,n,1,visited,num);
}
