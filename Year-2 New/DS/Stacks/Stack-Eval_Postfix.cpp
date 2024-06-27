#include<iostream>
#include<string.h>
using namespace std;


union u1
{
	int i1;
	char c;
};


struct stack
{
	int top, size, tag[50];
	u1 data[50];
};


void push(stack &s, u1 u, int t)
{
	if(s.top == s.size-1) cout<<"Stack full";
	else
	{
		s.data[++s.top] = u;
		s.tag[s.top] = t;
	}
}

u1 pop(stack &s)
{
	if(s.top == -1)cout<<"Stack empty";
	else
	{
		s.tag[s.top] == NULL;
		return(s.data[s.top--]);
	}
}

u1 enter(u1 u, int tg)
{
	cout<<"Enter element: ";
	if(tg == 1) cin>>u.i1;
	else if(tg == 2)
	{
		while(true)
		{
			cin>>u.c;
			if(isalnum(u.c))cout<<"Enter again: ";
			else break;
		}
	}
	return u;
}

u1 operate(u1 u4, u1 u3, u1 u2)
{
	u1 u;
	switch(u4.c)
	{
		case '+':
			u.i1 = u2.i1 + u3.i1;
			break;
		case '-':
			u.i1 = u2.i1 - u3.i1;
			break;
		case '*':
			u.i1 = u2.i1 * u3.i1;
			break;
		case '/':
			u.i1 = u2.i1 / u3.i1;
			break;
		default:
			break;
	}
	return u;
}


int main()
{
	stack s;
	s.top = -1; s.size = 0;
	
	cout<<"Enter length of expression: ";cin>>s.size;
	
	u1 u[s.size];
	u1 u2, u3, u4; int tg[s.size], i = 0;
	
	cout<<"1. Operand\n2. Operator\n\n\n";
	while(i < s.size)
	{
		cout<<"Enter tag: ";
		while(true)
		{
			cin>>tg[i];
			if(tg[i] == 1 || tg[i] == 2)
			{
				break;
			}
			else cout<<"Enter again: ";
		}
		u[i] = enter(u[i], tg[i]);
		cout<<endl;
		i++;
	}
	
	for(i = 0; i < s.size; i++)
	{
		push(s, u[i], tg[i]);
		if(s.tag[s.top] == 2)
		{
			u4 = pop(s);
			u3 = pop(s);
			u2 = pop(s);
			u4 = operate(u4, u3, u2);
			push(s, u4, 1);
		}
	}
	
	if(s.top != 0) cout<<"\n\nExpression not possible.";
	else
	{
		cout<<"\nExpression: ";
		for(i = 0; i < s.size; i++)
		{
			if(tg[i] == 1) cout<<u[i].i1;
			else cout<<u[i].c;
		}
		cout<<"\nSolution: "<<pop(s).i1<<" ";
	}
	
}
