#include<bits/stdc++.h>
using namespace std;
struct lnode
{
	char data;
	lnode *next;
};
struct gnode
{
	char c;
	gnode *down;
	lnode *adptr;
};
typedef struct gnode * GTPTR;
typedef struct lnode* LPTR;

void insert(LPTR &G,char s)
{
	if(G==NULL)
	{
		G=new lnode();
		G->data=s;
		G->next=NULL;
		return;
	}
	else
		insert(G->next,s);
		
}
void create(GTPTR &M,LPTR L,int n)
{
	GTPTR G=M;
	char ch;
	cout<<"enter name of vertices or to end press ! \n";
	cin>>ch;
	int i=0;
	GTPTR T=NULL;
	while(i<n)
	{
		
		G->c=ch;
		if(i>=1)
			T->down=G;
		G->down=NULL;
		G->adptr=NULL;
		cin>>ch;
		while(ch!='!')
		{
			insert(G->adptr,ch);
			cin>>ch;
		}
		cout<<"enter elements for "<<i+1<<"th vertex \n";
		cin>>ch;
		T=G;
		G=G->down;
		i++;
		G=new gnode();
	}
}

int main()
{
	GTPTR G=NULL;
	int n;
	cout<<"enter total number of vertices in graph \n";
	cin>>n;
	GTPTR T=NULL;
	
	G=new gnode();
	create(G,NULL,n);
	int i=0;
	while(i<n)
	{
		T=G;
		cout<<T->c<<"->";
		LPTR L=T->adptr;
		while(L!=NULL)
		{
			cout<<L->data<<",";
			L=L->next;
		}
		cout<<"\n";
		G=G->down;
		i++;
	}
}
