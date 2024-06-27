#include<iostream>
using namespace std;


struct stack
{
	int top = -1, size, data[50];
};


void push(stack &s, int x)
{
	if(s.top == s.size-1)
	{
		int x = 0;
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
		cout<<"Empty";
	}
	else
	{
		return(s.data[s.top--]);
	}
}


int main()
{
	stack s;
	
	int n, i = 0, j = 0;
	
	cout<<"Enter number of elements: "; cin>>n;
	s.size = n;
	int a[n], b[n];
	
	cout<<"\n\nEnter push sequence:\n";
	for(i = 0; i < n; i++)
	{
		cin>>a[i];
	}
	
	cout<<"\nEnter pop sequence:\n";
	for(i = 0; i < n; i++)
	{
		cin>>b[i];
	}
	
	i = j = 0;
	
	while(i < n)
	{
		while(b[j] != a[i] && i < n)
		{
			push(s, a[i]); cout<<"s ";
			i++;
		}
		
		push(s,a[i]); int a = pop(s);cout<<"s x ";
		i++; j++;
		
		
		while(b[j] = s.data[s.top])
		{
			int x = pop(s); cout<<"x ";
			j++;
		}
	}
	
	if(s.top == -1)
	{
		cout<<"\nPossible";
	}
	else cout<<"\nNot Possible";
	
	return 0;
}
