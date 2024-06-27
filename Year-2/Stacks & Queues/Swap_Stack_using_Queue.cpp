#include<iostream>
using namespace std;

struct queue
{
	int size=50, f=-1, r=-1, elements[50];
};

struct stack
{
	int size=50, top=0, elements[50];
};

int isfull(queue q)
{
	if(q.f==(q.r+1)%q.size)return (-1);
	else return 0;
}

int isempty(queue q)
{
	if(q.f==-1)return (-1);
	else return 0;
}

void enqueue(queue &q, int x)
{
	if(isfull(q)==-1) cout<<"Queue full"<<endl;
	else
	{
		if(isempty(q)==-1)q.f=0;
		q.r=(q.r+1)%q.size;
		q.elements[q.r]=x;
	}
}

int dequeue(queue &q)
{
	int t;
	if(isempty(q)==-1)
	{
		cout<<"Queue empty"<<endl;
	}
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

void push(stack &s, int x)
{
	if(s.size==s.top)cout<<"Stack full"<<endl;
	else
	{
		s.elements[s.top]=x;
		s.top++;
	}
}

int pop(stack &s)
{
	if(s.top==0)cout<<"Stack empty"<<endl;
	else
	{
		s.top--;
		return s.elements[s.top];
	}
}


int main()
{
	struct queue q; struct stack s;
	
	int n, i, j, x;
	
	cout<<"Enter number of elements in the stack: ";cin>>n;cout<<endl;
	s.size=n;
	
	cout<<"Enter elements:\n\n";
	for(i=0; i<s.size; i++)
	{
		cin>>x;
		push(s, x);
	}
	
	cout<<endl;
	for(i=0; i<s.size; i++)
	{
		cout<<s.elements[i]<<endl;
	}
	
	q.size=s.size;
	cout<<endl;
	for(j=0; j<s.size; j++)
	{
		enqueue(q, pop(s));
	}
	
	
	cout<<endl;
	for(j=0; j<s.size;j++)
	{
		push(s, dequeue(q));
	}
	
	cout<<"Stack after reversing:\n";
	for(i=0; i<s.size; i++)
	{
		cout<<s.elements[i]<<endl;
	}
	
	return 0;
}
