#include<iostream>
using namespace std;

struct stack
{
	int size, top = -1, data[200];
};

void push(stack &s, int x)
{
	if(s.top == s.size-1) cout<<"Stack full";
	else s.data[++s.top]=x;
}

int pop(stack &s)
{
	if(s.top == -1) cout<<"Stack empty";
	else return s.data[s.top--];
}

int tel(stack s)
{
	if(s.top == -1) cout<<"Stack empty";
	else return s.data[s.top];
}

int main()
{
	stack s1, s2;
	int n, x, y, z, a;
	
	cout<<"Enter number of elements: ";cin>>n;cout<<endl;
	
	cout<<"Enter elements:\n";
	for(int i = 0; i < n; i++)
	{
		cin>> x;
		push(s1, x);
	}
	
	cout<<"\nUnsorted Stack: ";
	for(int i = 0; i < n; i++)
	{
		cout<<s1.data[i]<<" ";
	}
	cout<<endl;
	
	while(s1.top != -1)
	{
		y = pop(s1);
		if(s2.top == -1) push(s2, y);
		else
		{
			z = tel(s2);
			while(y > z)
			{
				a = pop(s2);
				push(s1, a);
				if(s2.top != -1)z = tel(s2);
				else break;
			}
			push(s2, y);
		}
	}
	
	cout<<"\nSorted stack: ";
	for(int i = 0; i < n; i++)
	{
		cout<<pop(s2)<<" ";
	}
}
