#include<iostream>
#include<string.h>

using namespace std;

struct queue
{
	int front;
	int rear;
	int size;
	int element[50]; 
};
int Enqueue(queue &Q);
int Dequeue(queue &Q);

bool isEmpty(queue &Q)
{
	return(Q.front==Q.rear && Q.front==-1);
}
bool isFull(queue &Q)
{
	return((Q.rear+1)%Q.size==Q.front);
}

int main()
{
	struct queue Q;
	Q.front=-1;
	Q.rear=-1;
	cout<<"Enter size of queue\n";
	cin>>Q.size;
	bool cont =true;
	int x,a;
	while(cont)
	{
		cout<<"What would you like to do?\n1.Enqueue\n2.Dequeue\n3.Exit\n";
		cin>>x;
		switch(x)
		{
			case 1:a=Enqueue(Q);
			if(a==0)
				cout<<"Queue is full\n";
			break; 
			case 2:a=Dequeue(Q);
			if(a==0)
				cout<<"Queue is empty\n";
			break; 
			case 3:
				cont=false;
				break;
			default: cout<<"Inavlid option\n";
			break;
		}
	}
	
}
int Enqueue(queue &Q)
{
	if(isFull(Q))
		return(0);
		
	cout<<"Enter the element to enqueue\n";
	if(Q.front==-1)
		Q.front+=1;
	
	Q.rear+=1;
	
	if(Q.rear>=Q.size)
	Q.rear=0;
	
	cin>>Q.element[Q.rear];
	return(1);
}
int Dequeue(queue &Q)
{	
	if(isEmpty(Q))
		return(0);
	cout<<Q.element[Q.front]<<" was dequeued\n";
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
	return(1);
}
