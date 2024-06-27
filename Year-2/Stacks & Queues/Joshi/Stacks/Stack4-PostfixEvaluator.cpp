//Make the stack an int stack here
#include<iostream>
#include<string.h>
#include<string>
#include<conio.h>

using namespace std;

struct Stack
{
	int num[50];
	int top;
};
struct Stack s;

void push(int a);
void pop(char o);
int operation(int a, int b, char c)
{
	switch(c)
	{
		case '/':return(a/b);//no need to worry about break as we are already returning a vale
		case '*':return(a*b);
		case '+':return(a+b);
		case '-':return(a-b);
	}
}

int main()
{
	s.top=-1;
	char exp[50];
	cout<<"Enter postfix expression\n";
	cin.getline(exp,50);
	int i,n;
	
	for(i=0;i<strlen(exp);i++)
	{
		if(isdigit(exp[i]))
		{
			n=(int)exp[i]-48;//ie - ASCII value of 0 which is 48. So it starts from 0-9
			push(n);
		}
		else if(exp[i]=='*'||exp[i]=='/'||exp[i]=='+'||exp[i]=='-')
		{
			pop(exp[i]);
		}
	}
	cout<<"The result is "<<s.num[s.top]<<endl;
		
	return(0);
}
void push(int a)
{
	s.top+=1;
	s.num[s.top]=a;
}
void pop(char o)
{
	int a,b;
	a=s.num[s.top-1];
	b=s.num[s.top];
	s.num[s.top-1]=operation(a,b,o);
	s.num[s.top]=0;
	s.top-=1;
}
