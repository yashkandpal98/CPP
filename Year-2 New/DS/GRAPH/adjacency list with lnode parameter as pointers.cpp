#include<bits/stdc++.h>
using namespace std;
typedef struct gnode * GTPTR;
struct lnode
{
	gnode* data;
	lnode *next;
};
struct gnode
{
	char c;
	gnode *down;
	lnode *adptr;
};

typedef struct lnode* LPTR;
GTPTR search(GTPTR G,char ch)
{
	if(G->c==ch)
		return G;
	else
		search(G->down,ch);	
}
void insert(LPTR &T,GTPTR G,char ch)
{
	if(T==NULL)
	{
		T=new lnode();
		T->data=search(G,ch);
		T->next=NULL;
	}
	else
		insert(T->next,G,ch);
}
GTPTR create(GTPTR &G,int n,int i,GTPTR T,GTPTR L)
{
//	GTPTR G=T;
	if(i<n)
	{
		cout<<"enter the name of vertex \n";
		char ch;
		cin>>ch;
		G->c=ch;
		G->adptr=NULL;
		G->down=NULL;
		G->down=new gnode();
		if(T!=NULL)
			G=T->down;
//		G=T;	
		create(G->down,n,i+=1,G,L);
	}
	cout<<"enter edges between "<<T->c<<" if present \n";
	cout<<"enter the vertices to which it is connected \n or press ! to end \n";
	char ch;
	cin>>ch;
	while(ch!='!')
	{
		insert(T->adptr,L,ch);
		cin>>ch;
	}
	return L;
}
int main()
{
	GTPTR G=NULL;
	G=new gnode();
	cout<<"enter total number of vertices \n";
	int n;
	cin>>n;
	GTPTR T=NULL;
	G=create(G,n,0,T,G);
	int i=0;
	while(i<n)
	{
		T=G;
		cout<<T->c<<"->";
		LPTR L=T->adptr;
		while(L!=NULL)
		{
			cout<<L->data->c<<",";
			L=L->next;
		}
		cout<<"\n";
		G=G->down;
		i++;
	}
	return 0;
}
