//PostfixToPrefix
//Prefix to postfix
#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;
struct Stack
{
	string u[50];//Array of strings
	int top;
};
void push(Stack &s,string p);
string pop(Stack &s);
int main()
{
	string exp;
	struct Stack s;
	s.top=-1;
	
	int i;
	
	string t1,t2;//IMP
	cout<<"Enter Postfix expression\n";
	cin>>exp;
	
	for(i=0;i<exp.length();i++)
	{
		if(exp[i]=='*'||exp[i]=='/'||exp[i]=='+'||exp[i]=='-')
		{
			t1=pop(s);//b
			t2=pop(s);//a
			t2=exp[i]+t2;//+a
			push(s,t2+t1);//Pushing +ab
		}
		else if(isalnum(exp[i]))
		{
			t1="";//VIMP to do this
			t1+=exp[i];
			push(s,t1);
		}
	}
	cout<<"Prefix expression is "<<s.u[s.top]<<endl;
	
	return(0);
}
void push(Stack &s,string p)
{
	s.top+=1;
	s.u[s.top]=p;
	//cout<<"Push "<<p<<endl;
}
string pop(Stack &s)
{
	string c;
	c=s.u[s.top];
	s.u[s.top]="";
	s.top-=1;
	//cout<<"Pop "<<c<<endl;
	return(c);
}
