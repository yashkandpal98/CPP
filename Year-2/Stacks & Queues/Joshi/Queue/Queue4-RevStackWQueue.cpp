#include<iostream>
#include<string>
using namespace std;

struct Stack
{
	int size;
	int element[50];
	int top;
};
void push(Stack &s,int x);
int pull(Stack &s);
void peep(Stack &s);
bool stkEmpty(Stack &s)
{
	return(s.top==-1);
}
bool stkFull(Stack &s)
{
	return(s.top==s.size-1);
}

struct queue
{
	int front;
	int rear;
	int element[50]; 
};
void Enqueue(queue &Q, int t);
int Dequeue(queue &Q);
bool isEmpty(queue &Q)
{
	return(Q.front==Q.rear && Q.front==-1);
}

/*void rev(Stack &s,queue &Q)
{
	int a;
	a=Dequeue(Q);
	while(!isEmpty(Q))
		rev(s,Q);
	push(s,a);
	
}*/

int main()
{
	struct Stack s;
	struct queue Q;

	s.top=-1;
	int x,n,p,a;
	cout<<"Enter the size of the stack to be made?\n";
	cin>>n;
	s.size=n;
	
	bool cont=true;
	
	
	while(cont)
	{
		
		Q.front=-1;
		Q.rear=-1;
		cout<<"What do you wish to do?\n\n1.Push\n2.Pull\n3.Peep\n4.Reverse\n5.Exit\n\n";
		cin>>x;
		switch(x)
		{
			case 1:
			if(stkFull(s))
			{
			cout<<"Stack is full\n";
			break;
			}
			cout<<"Enter the element to push\n";
				cin>>a; 
				push(s,a);
				break;
			case 2: pull(s);
				break;
			case 3: peep(s);
				break;
			case 4:
				while(s.top!=-1)
				{
					a=pull(s);
					Enqueue(Q,a);
				}
				
				while(!isEmpty(Q))
				{
					a=Dequeue(Q);
					push(s,a);
				}
				break;
			case 5:cont=false;
				break;	
			default:cout<<"Invalid input\n";
				break;
		}
	 } 
	 return(0);
}

void push(Stack &s, int x)
{

		s.top=s.top+1;
		s.element[s.top]=x;
}
int pull(Stack &s)
{
	int y=0;
	if(stkEmpty(s))
	cout<<"Stack is empty\n";
	
	else
	{
		cout<<"Element removed is "<<s.element[s.top]<<endl;
		y=s.element[s.top];
		s.element[s.top]=0;
		s.top-=1;
	}
	return(y);
}
void peep(Stack &s)
{
	if(stkEmpty(s))
	cout<<"Stack is empty\n";
	else
	cout<<"Top most element is "<<s.element[s.top]<<" which is present at index = "<<s.top<<endl;
}

void Enqueue(queue &Q, int t)
{
	if(Q.front==-1)
		Q.front+=1;
	cout<<"Enqueue :"<<t<<endl;
	Q.rear+=1;	
	Q.element[Q.rear]=t;
}
int Dequeue(queue &Q)
{	
int y;
	cout<<Q.element[Q.front]<<" was dequeued\n";
	y=Q.element[Q.front];
	Q.element[Q.front]=0;
	if(Q.front==Q.rear)
	{
		Q.front=-1;
		Q.rear=-1;
	}
	else
	Q.front+=1;
	return(y);
}
