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

struct Stack
{
	int e[50];
	int top;	
};

int Enqueue(queue &Q, int t);
int Dequeue(queue &Q);

bool isEmpty(queue &Q)
{
	return(Q.front==Q.rear && Q.front==-1);
}
bool isFull(queue &Q)
{
	return((Q.rear+1)%Q.size==Q.front);
}

void push(Stack &s, int a)
{
	s.top=s.top+1;
	s.e[s.top]=a;
	//cout<<s.e[s.top]<<"\n";
}
int pop(Stack &s)
{
	int a;
	a=s.e[s.top];
	s.e[s.top]=0;
	s.top-=1;
	return(a);
}

int main()
{
	struct queue Q;
	struct Stack s;
	
	s.top=-1;
	
	Q.front=-1;
	Q.rear=-1;
	cout<<"Enter size of queue\n";
	cin>>Q.size;
	bool cont =true;
	int x,a,t;
	while(cont)
	{
		cout<<"\nWhat would you like to do?\n1.Enqueue\n2.Dequeue\n3.Reverse\n4.Exit\n";
		cin>>x;
		switch(x)
		{
			case 1:
			cout<<"Enter the element to enqueue\n";
			cin>>t;
			a=Enqueue(Q,t);
			if(a==0)
				cout<<"Queue is full\n";
			break; 
			case 2:a=Dequeue(Q);
			if(a==0)
				cout<<"Queue is empty\n";
			break; 
			case 3:
			while(!isEmpty(Q))
			{
				a=Dequeue(Q);
				push(s,a);
			}
			Q.front=-1;
			Q.rear=-1;
			while(s.top!=-1)
			{
				a=pop(s);
				Enqueue(Q,a);
			}
			break;
			case 4:
				cont=false;
				break;
			default: cout<<"Inavlid option\n";
			break;
		}
	}
	return(0);
}
int Enqueue(queue &Q, int t)
{
	if(isFull(Q))
		return(0);
		
	if(Q.front==-1)
		Q.front+=1;
	
	Q.rear+=1;
	
	if(Q.rear>=Q.size)
	Q.rear=0;
	
	Q.element[Q.rear]=t;
	return(1);
}
int Dequeue(queue &Q)
{	
int y;
	if(isEmpty(Q))
		{
		cout<<"Queue is empty\n";
		return(0);
		}
	cout<<Q.element[Q.front]<<" was dequeued\n";
	y=Q.element[Q.front];
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
	return(y);
}
