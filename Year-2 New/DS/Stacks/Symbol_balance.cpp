#include<iostream>
#include<string.h>
using namespace std;


struct stack
{
	int size, top = -1;
	char data[200];
};


void push(stack &s, char x)
{
	if(s.top == s.size-1) cout<<"Stack full";
	else s.data[++s.top]=x;
}

char pop(stack &s)
{
	if(s.top == -1) cout<<"Stack empty";
	else return s.data[s.top--];
}

char tel(stack s)
{
	if(s.top == -1) cout<<"Stack empty";
	else return s.data[s.top];
}


int main()
{
	stack s;
	char a[50], c, o = '(', p = ')';
	cout<<"Enter symbol sequence: ";cin>>a;
	
	int i = 0, n = strlen(a), tag = 0, flag = 0; s.size = n;
	
	while(i < n)
	{
		push(s, a[i]);
		i++;
		if(tel(s) == p)
		{
			if(s.top == 0)
			{
				flag = -1;
				break;
			}
			else flag = 0;
			while(tel(s) != o)
			{
				
				c = pop(s);
			}
			c = pop(s);
		}
	}
	
	//cout<<tel(s);
	
	if(flag == 0 && s.top == -1) cout<<"\n\nBalanced";
	else cout<<"\n\nNot balanced";
	
	
}
