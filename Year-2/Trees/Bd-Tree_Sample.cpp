#include<iostream>

using namespace std;



typedef struct bdnode
{
	int count; int keys[4];
	bdnode *ptr[5], *pptr;
} bdptr;

typedef struct bdnode2
{
	int count, keys[5];
	bdnode *ptr[6], *pptr;
} overflow;



void create(bdptr &t, int x)
{
	int i=0;
	t->keys[i]=x;
	for(i=0; i<=4; i++)
	{
		t->ptr[i]=NULL;
	}
	t->pptr=NULL;
}


void sort(bdptr &t)
{
	for(int i=0; i<4; i++)
	{
		for(int j=i+1; j<4; j++)
		{
			if(t->keys[i]>t->keys[j])
			{
				t->keys[i]+=t->keys[j];
				t->keys[j]=t->keys[i]-t->keys[j];
				t->keys[i]-=t->keys[j];
				
				bdptr temp=new bdnode;
				temp=t->ptr[i];
				t->ptr[i]=t->ptr[j];
				t->ptr[j]=temp;
			}
		}
	}
}


void add(bdptr &t, int x)
{
	if(t!=NULL)
	{
		int i, ct, a=0;
		for(i=0; i<4; i++;)
		{
			if(t->keys[i]!=NULL) ct=1;
			else 
			{
				t->keys[i]=x;
				sort(t);
				ct=0;
				break;
			}
		}
		if(ct==1)
		{
			
		}
	}
}
