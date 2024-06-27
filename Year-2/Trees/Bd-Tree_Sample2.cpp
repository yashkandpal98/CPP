#include<iostream>

using namespace std;



typedef struct bdnode
{
	int count, keys[5];
	bdnode *ptr[6], *pptr;
} *bdptr;


void create(bdptr &t, int x)
{
	int i;
	t->count=0;
	t->keys[0]=x;
	
}


bdptr sort(bdptr &t, int n)
{
	for(int i=0; i<n; i++)
	{
		for(int j=i+1; j<n; j++)
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
	return t;
}


void add(bdptr &t, int x)
{
	int i, j;
	if(t!=NULL)
	{
		if(t->count<=3)
		{
			for(i=0; i<4; i++)
			{
				if(t->keys[i]!=' ')t->count++;
				else 
				{
					t->keys[i]=x;
					t=sort(t, i+1);
					return;
				}
			}
		}
		
		else
		{
			
			
			
			bdptr temp2=new bdnode;
			bdptr t1=new bdnode;
			for(j=0; i<4; j++)
			{
				t1->keys[j]=t->keys[j];
				t1->ptr[j]=t->ptr[j];
			}
			t1->keys[j]=x;
			t1->ptr[j]=NULL;
			t1=sort(t1,5);
			
			for(j=2; j<4; j++)
			{
				t->keys[j]=' ';
				t->ptr[j]=NULL;
			}
			t->ptr[j]=NULL;
			
			add(t->pptr, t1->keys[2]);
			
			t->pptr->ptr[t->pptr->count]=t;
			t->pptr->ptr[t->pptr->count+1]=temp2;
			temp2->pptr=t->pptr;
			t->pptr=sort(t->pptr, t->pptr->count+1);
			t=t->pptr;
			
			for(j=2; j<5; j++)
			{
				temp2->keys[j-2]=t1->keys[j];
				temp2->ptr[j-2]=t1->ptr[j];
			}
			
		}
	}
	else create(t, x);
}


void show(bdptr t)
{
	int i;
	if(t!=NULL)
	{
		for(i=0; i<4; i++)
		{
			show(t->ptr[i]);
			if(t->keys[i]!=' ') cout<<t->keys[i]<<"\t";
			else break;
		}
		show(t->ptr[i]);
	}
}



int main()
{
	int i;
	bdptr root;
	create(root, 2);
	for(i=1; i<=4; i++)
	{
		root->keys[i]=' ';
		root->ptr[i]=NULL;
	}
	root->ptr[i]=NULL;
	root->pptr=NULL;
	add(root, 1);
	add(root, 8);
	add(root, 6);
	
	show(root);
	return 0;
}
