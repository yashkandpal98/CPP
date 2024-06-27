#include<iostream>
using namespace std;


struct stack
{
	int top = -1, size = 0, data[50];
};

struct queue
{
	int f = -1, r = -1, size = 0, data[50];
};


void enqueue(queue &q, int x)
{
	if((q.r+1)%q.size == q.f) cout<<"Queue Full";
	
	else
	{
		if(q.r == -1) q.f = 0;
		
		q.r = (q.r+1)%q.size;
		q.data[q.r] = x;
	}
}

int dequeue(queue &q)
{
	int t;
	if(q.f == -1) cout<<"Queue Empty";
	
	else
	{
		t = q.data[q.f];
		
		if(q.f == q.r) q.f = q.r = -1;
		else q.f = (q.f+1)%q.size;
	}
	
	return t;
}

void push(stack &s, int x)
{
	if(s.top == s.size-1)
	{
		cout<<"Stack Full";
	}
	else
	{
		s.data[++s.top] = x;
	}
}

int pop(stack &s)
{
	if(s.top == -1)
	{
		cout<<"Stack Empty";
	}
	else
	{
		return(s.data[s.top--]);
	}
}

/*queue interleave(queue &q)
{
	stack s;
	queue q1;
	
	s.size = q.size/2;
	q1.size = q.size;
	
	for(int j = 0; j < s.size; j++) enqueue(q, dequeue(q));
	while(s.top != s.size) push(s, dequeue(q));
	{
		int i = dequeue(q);
		push(s, i);
	}
	cout<<s.top<<endl;
	
	while(s.top != -1) enqueue(q, pop(s));
	
	for(int j = 0; j < s.size; j++) enqueue(q, dequeue(q));
	
	while(s.top != s.size) push(s, dequeue(q));
	
	while(s.top != -1 && q.f != q.r) 
	{
		enqueue(q1, dequeue(q));
		enqueue(q1, pop(s));
	}
	
	return q1;
}*/


int main()
{
	queue q; stack s;
	int n, i, j, x, flag;
	
	cout<<"Enter number of elements: ";cin>>q.size;
	
	cout<<"Enter elements:\n";
	for(i = 0; i < q.size; i++)
	{
		cin>>n; enqueue(q, n);
	}
	
	cout<<"\nQueue: ";
	for(int i = 0; i < q.size; i++) cout<<q.data[i]<<" ";
	
	//q = interleave(q);
	
	/*cout<<"\n\nAfter interleaving: ";
	for(int i = 0; i < q.size; i++) cout<<q.data[i]<<" ";*/
	
}
