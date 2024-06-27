#include<iostream>
using namespace std;
int indegree(int G[][20],int n,int v){
	int i,count=0;
	for(i=1;i<=n;i++){
		if(G[i][v]==1)
			count++;
	}
	return count;
}
int nodegree(int G[][20],int u,int n){
	int i,s=0;
	for(i=1;i<=n;i++){
		if(G[u][i]==0){
			s++;
		}
	}
	if(s==n)
		return(1);
	else
		return(0);
}
void EulersPath(int G[][20],int u,int n,int count,int P[],int m,int Q[],int q){
	int j,k,i,ver;
	P[m]=u;
	if(nodegree(G,u,n)==0){
		cout<<"\nEnter vertex from below list:\n";
		for(i=1;i<=n;i++)
			if(G[u][i]==1)
				cout<<i<<" ";
		cout<<endl;
		cout<<"\nEnter vertex to go:\n";
		cin>>ver;
		G[u][ver]=0;
		G[ver][u]=0;
		if(q==-1)
			EulersPath(G,ver,n,count,P,m+1,Q,-1);
		else if(q!=-1)
			EulersPath(G,ver,n,count,P,m+1,Q,q+1);
	}
	else{
		int c=0;
		if(q==-1){
			for(k=0;k<=m;k++)
				Q[k]=P[k];
			q=k-1;
		}
		else if(q!=-1){
			for(k=0;k<=q;k++)
				if(Q[k]==P[0])
					break;
			for(i=k+1;i<=q;i++){
				P[m+i-k]=Q[i];
			}
			m=i-1;
			for(j=k;j<i+k;j++){
				Q[j]=P[j-k];
			}
			q=j-k-2;
		}
		for(i=1;i<=n;i++){
			for(j=0;j<=q;j++){
				if(Q[j]==i){
					if(nodegree(G,i,n)==0){
						c++;
						break;
					}
				}
			}
			if(c!=0)
				break;
		}
		if(c!=0){
		/*	cout<<P[0]<<" ";
			j=1;
			while(P[j]!=P[0]){
				cout<<P[j]<<" ";
				j++;
			}
			cout<<P[j];
			cout<<endl;*/
			EulersPath(G,i,n,count,P,0,Q,q+1);
		}
		else if(c==0){
			for(i=0;i<=q;i++){
				cout<<Q[i]<<" ";
			}
		}
	}
}
int main(){
	int i,j,n,d,v,u;
	cout<<"Enter no. of vertices\n";
	cin>>n;
	int G[n+1][20];
	int P[500],Q[500];
	int visited[n+1];
	cout<<"\nEnter edges\n";
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			cout<<"\nEnter edge between vertices "<<i<<" and "<<j<<" : ";
			cin>>G[i][j];
		}
	}
	cout<<"\nEnter star vertex\n";
	cin>>u;
	EulersPath(G,u,n,1,P,0,Q,-1);
	/*cout<<Q[0]<<" ";
	j=1;
	while(Q[j]!=Q[0]){
		cout<<Q[j]<<" ";
		j++;
	}
	cout<<Q[0];*/
}
