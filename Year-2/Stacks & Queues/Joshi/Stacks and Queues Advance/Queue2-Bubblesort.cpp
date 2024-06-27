//Bubble sort with 1 Queue and 'n' variables
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
//	cout<<"Enqueue "<<a<<endl;
	Q.element[Q.rear]=a;
}
int Dequeue(queue &Q)
{	
	int x;
//	cout<<Q.element[Q.front]<<" was dequeued\n";
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
	struct queue Q;
	Q.front=-1;
	Q.rear=-1;
	int x,i;
	cout<<"Enter the number of terms to sort\n";
	cin>>Q.size;
	
	for(i=0;i<Q.size;i++)
	{
		cout<<"Enter term "<<i+1<<endl;
		cin>>x;
		Enqueue(Q,x);
	}
	
	int c=0,d=0;//Intializing the no of times to sort
	
	while(d<Q.size)	
	{	//IMP yoy need a double while loop
		c=0;//INITIALISE here
		int a=0,b=0;//IMP to initialise
		while(c<Q.size)//or put c=1 and do while(c<=Q.size)
		{
			a=Dequeue(Q);
			if(a<b)
			{
				a=a+b;
				b=a-b;
				a=a-b;
			}
			Enqueue(Q,b);
			b=a;
			c++;//DO NOT forget
		}
		Enqueue(Q,a);//Forget this and all your elements will eventually be replaced with 0
		Q.front+=1;		//FORGET THIS AND AT THE END OF EACH TURN Q.FRONT=Q.REAR SO THE PROGRAM GETS CONFUSED---->YOU WASTED A LOT OF TIME TO FIGURE THIS OUT
		d++;//DO NOT forget
	}
	cout<<"The terms sorted in ascending order are :\n";
	i=0;
	while(!isEmpty(Q)) //while the queue is NOT empty DO NOT FORGET the !!!!!!!!!!!
	{
		x=Dequeue(Q);		
		if(i==0)
		{
			i=1;//Some error is dequeueing Q.size+1 terms with a random no at start????? :( so i did this ... uncomment the cout in enqueue and dequeue to see the NEGETIVITY :/
			continue;
		}
		cout<<x<<" ";
	}
	return(0);
}
