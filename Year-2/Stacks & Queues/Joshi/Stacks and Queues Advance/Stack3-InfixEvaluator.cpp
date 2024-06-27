//Infix evaluator W 1 stack

#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>

using namespace std;

union element
{
	int a;
	char b;
};
struct Stack
{
	int top;
	int tag[50];
	union element u[50];
};
int Operation(int a, int b, char c)
{
	switch(c)
	{
		case '/':return(a/b);//no need to worry about break as we are already returning a vale
		case '*':return(a*b);
		case '+':return(a+b);
		case '-':return(a-b);
	}
}
int pop1(Stack &s)
{
	int x=s.u[s.top].a;
	s.top-=1;
	return(x);
}
char pop0(Stack &s)
{
	char y=s.u[s.top].b;
	s.top-=1;
	return(y);
}
void push(Stack &s, int x, char y, bool digit)
{
	if(digit==true)
	{
		if(s.tag[s.top]==0&&s.tag[s.top-1]==1)
		{
			char q=pop0(s);
			int p=pop1(s);
			x=Operation(p,x,q);
			
		}
		s.top+=1;
		s.tag[s.top]=1;
		s.u[s.top].a=x;
	}
	else
	{
		if(y==')'&&s.u[s.top-1].b=='(')
		{
			s.u[s.top-1].b='\0';
			s.u[s.top-1].a=s.u[s.top].a;
			s.tag[s.top-1]=1;
			s.top-=1;
		}
		else
		{
			s.top+=1;
			if(y=='(')
				s.tag[s.top]=2;
			else
				s.tag[s.top]=0;
			s.u[s.top].b=y;
		}
	}
}
void op(Stack &s)
{
	if(s.tag[s.top]==1&&s.tag[s.top-1]==0&&s.tag[s.top-2]==1)
		{
			int x=pop1(s);
			char q=pop0(s);
			int p=pop1(s);
			x=Operation(p,x,q);
			push(s,x,'^',true);
		}	
}


int main()
{
	Stack s;
	s.top=-1;
	char exp[50];
	int i,x;
	cout<<"Enter the infix expression\n";
	cin.getline(exp,50);
	
	for(i=0;i<strlen(exp);i++)
	{
		if(isdigit(exp[i]))
		{
			x=(int)exp[i]-48;;
			push(s,x,'^',true);
		}
		else if(exp[i]=='*'||exp[i]=='/'||exp[i]=='+'||exp[i]=='-'||exp[i]=='('||exp[i]==')')
			push(s,1,exp[i],false);
		
	}
	while(s.top!=0)
	{
		op(s);
	}
	cout<<s.u[s.top].a<<endl;
	return 0;
	
}

