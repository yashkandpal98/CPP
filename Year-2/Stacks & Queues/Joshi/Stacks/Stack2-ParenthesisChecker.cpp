//PARENTHESIS BALANCE CHECKER

#include<iostream>
#include<string.h>
#include<conio.h>

using namespace std;

struct Stack
{
	char sym[50];
	int top;
};
void push(char a);
char pop();
struct Stack s;
bool isEmpty(Stack &s);

int main()
{
	bool isBalance=true;
	//Stack s;
	s.top=-1;
	char exp[50],a;
	cout<<"Enter the expression\n";
	cin.getline(exp,50);
	
	int i;
	for(i=0;i<strlen(exp);i++)
	{
		if(exp[i]=='('||exp[i]=='{'||exp[i]=='[')
			push(exp[i]);
		else
		{
			switch(exp[i])
			{
				case ')':
					a=pop();
					if(a=='['||a=='{'||a=='A')
						isBalance=false;
					break;
				case '}':
					a=pop();
					if(a=='['||a=='('||a=='A')
						isBalance=false;
					break;
				case ']':
					a=pop();
					if(a=='('||a=='{'||a=='A')
						isBalance=false;
					break;
			}
		}
	}
	if(s.top!=-1)
		isBalance=false;
		
	if(isBalance)
	cout<<"The given expression is Balanced"<<endl;
	else
	cout<<"The given expression is NOT Balanced"<<endl;
	
	return(0);
}
void push( char a)
{
	s.top+=1;
	s.sym[s.top]=a;
}
char pop()
{
	if(s.top==-1)
		return('A');
	char a=s.sym[s.top];
	s.top-=1;
	return(a);
}
bool isEmpty(Stack &s)
{
	return(s.top==-1);
}
