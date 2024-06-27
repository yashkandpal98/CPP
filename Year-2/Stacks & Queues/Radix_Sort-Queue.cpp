#include<iostream>
using namespace std;
struct queue
{
	int f;
	int r;
	int size;
	int elements[50];
}q[10];

void enqueue(queue *q,int p,int x)
{
	if (q[p].f==-1) q[p].f=0;
	q[p].r=(q[p].r+1)%q[p].size;
	q[p].elements[q[p].r]=x;
}

int dequeue(queue *q,int p)
{
	int x;
	x=q[p].elements[q[p].f];
	if(q[p].f==q[p].r) q[p].f=q[p].r=-1;
	else q[p].f=(q[p].f+1)%q[p].size;
	return x;
}

int main()
{
	int a[50],m,n,k,x,z;
	
	cout<<"Enter no of elements: ";cin>>n;cout<<endl;
	
	cout<<"Enter maximum digits in a number: ";cin>>z;cout<<endl;
	for(int i=0;i<10;i++)
	{
		q[i].f=q[i].r=-1;
		q[i].size=100;
	}
	
	cout<<"Enter the elements:\n"<<endl;
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(k=1;k<=z;k++)
	{
		for(int i=0;i<n;i++)
		{
			int y=0,u=a[i];
			while(y<k)
			{
				x=u%10;
				u=u/10;
				y++;
			}

			for(int j=0;j<10;j++)
			{
				if(x==j)
				enqueue(q,x,a[i]);
			}
		}
	
		int l=0;
		for(int j=0;j<10;j++)
		{
			while(q[j].f!=-1)
			{
				m=dequeue(q,j);
				if(m!=0)
				{
					a[l]=m;
					l++;
				}
			}
		} 
	}
	
	cout<<"\nSorted array:"<<endl;
	for(int i=0;i<n;i++)
		cout<<a[i]<<endl;
	
	return 0;
}
