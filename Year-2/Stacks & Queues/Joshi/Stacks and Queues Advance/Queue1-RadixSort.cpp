//Radix sort of upto 3 digit numbers - 5 variables
#include<iostream>
#include<string.h>
#include<cmath>
using namespace std;

struct queue
{
	int front;
	int rear;
	int size;
	int element[50]; 
};
bool isEmpty(queue &Q)
{
	return(Q.front==Q.rear && Q.front==-1);
}
bool isFull(queue &Q)
{
	return((Q.rear+1)%Q.size==Q.front);
}
void Enqueue(queue &Q,int a)
{
	if(Q.front==-1)
		Q.front+=1;
	
	Q.rear+=1;
	
	if(Q.rear>=Q.size)
	Q.rear=0;
	//cout<<"Enqueue "<<a<<endl;
	Q.element[Q.rear]=a;
}
int Dequeue(queue &Q)
{	
	int x;
	//cout<<Q.element[Q.front]<<" was dequeued\n";
	x=Q.element[Q.front];
	Q.element[Q.front]=0;
	if(Q.front==Q.rear)
	{
		Q.front=-1;
		Q.rear=-1;
	}
	else{
	Q.front+=1;
	if(Q.front>=Q.size)
	Q.front=0;
	}
	return(x);
}

int main()
{
	int i,x,c=0,n;
	int a[50],p;
	struct queue Q[10];
	for(i=0;i<10;i++)
	{
		Q[i].front=-1;
		Q[i].rear=-1;
		Q[i].size=20;
	}
	
	cout<<"Enter the number of terms to be sorted"<<endl;
	cin>>n;
	
	for(i=0;i<n;i++)
	{
		cout<<"Enter term "<<i+1<<endl;
		cin>>a[i];		
	}
	
	while(c<3)
	{
		for(i=0;i<n;i++)
		{
			p=pow(10,c);
			x=(a[i]/p)%10;
			Enqueue(Q[x],a[i]);
		}
		int j=0;
		for(i=0;i<n;i++)
		{
			while(isEmpty(Q[j]))
				j++;
			a[i]=Dequeue(Q[j]);
		}
		c++;
	}
	cout<<"\nThe sorted terms are\n";
	for(i=0;i<n;i++)
	cout<<a[i]<<" ";
	return(0);
}

