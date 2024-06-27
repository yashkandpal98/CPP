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
	if((q.r+1)%q.size == q.f)
	{
		cout<<"Full";
	}
	else
	{
		if(q.r == -1)
		{
			q.f = 0;
		}
		q.r = (q.r+1)%q.size;
		q.data[q.r] = x;
	}
}

int dequeue(queue &q)
{
	int t;
	if(q.f == -1)
	{
		cout<<"Queue Empty";
	}
	else
	{
		t= q.data[q.f];
		if(q.f == q.r) q.f = q.r = -1;
		else q.f = (q.f+1)%q.size;
	}
	
	return t;
}

void push(stack &s, int x)
{
	if(s.top == s.size-1)
	{
		cout<<"Full";
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


int main()
{
	queue q; stack s;
	int n, i, j, x, flag;
	
	cout<<"Enter number of elements: ";cin>>s.size;
	q.size = s.size/2;
	
	//cout<<q.size;
	
	cout<<"Enter elements:\n";
	for(i = 0; i < s.size; i++)
	{
		cin>>n; push(s, n);
	}
	
	for(j = 0; j < q.size; j++)
	{
		enqueue(q, pop(s));
	}
	
	if(s.size%2 != 0) x = pop(s);
	
	i = 0;
	while(i < q.size)
	{
		if(pop(s) == q.data[q.r])
		{
			flag = 1;
			for(j = 0; j < q.size-i-1; j++)
			{
				enqueue(q, dequeue(q));
			}
			dequeue(q);
		}
		else
		{
			flag = 0;
			break;
		}
		i++;
	}
	
	if(flag == 1) cout<<"\nPalindrome";
	else cout<<"\nNot palindrome";
}
