#include<iostream>
using namespace std;

struct queue
{
	int size, f=-1, r=-1, elements[50];
};

int isfull(queue q)
{
	if(q.f==(q.r+1)%q.size) return -1;
	else return 0;
}

int isempty(queue q)
{
	if(q.f==-1) return -1;
	else return 0;
}

void enqueue(queue &q, int x)
{
	if(isfull(q)==-1) cout<<"\nQueue full\n";
	else
	{
		if(isempty(q)==-1) q.f=0;
		q.r=(q.r+1)%q.size;
		q.elements[q.r]=x;
	}
}

int dequeue(queue &q)
{
	int t;
	if(isempty(q)==-1) cout<<"\nQueue empty\n";
	else
	{
		t=q.elements[q.f];
		if(q.f==q.r)
		{
			q.f=-1;
			q.r=-1;
		}
		else q.f=(q.f+1)%q.size;
		return t;
	}
}

void bubble(queue &q)
{
	int i, j, a[q.size];
	for(i=0; i<q.size; i++)
	{
		a[i]=dequeue(q);
	}
	for(i=0; i<q.size; i++)
	{
		for(j=0; j<q.size-1-i; j++)
		{
			if(a[j]>a[j+1])
			{
				a[j]+=a[j+1];
				a[j+1]=a[j]-a[j+1];
				a[j]-=a[j+1];
			}
		}
	}
	
	for(i=0; i<q.size; i++)
	{
		enqueue(q, a[i]);
	}
}

int main()
{
	queue q;
	int i, j;
	cout<<"Enter size of queue: ";cin>>q.size;cout<<endl;
	
	cout<<"\nEnter elements:\n\n";
	for(i=0; i<q.size; i++)
	{
		int x; cin>>x;
		enqueue(q, x);
	}
	
	cout<<"\nQueue:\n\n";
	for(int j=0; j<q.size; j++)
	{
		cout<<q.elements[j]<<endl;
	}
	
	bubble(q);
	
	cout<<"\nQueue:\n\n";
	for(int j=0; j<q.size; j++)
	{
		cout<<q.elements[j]<<endl;
	}
	
	return 0;
}
