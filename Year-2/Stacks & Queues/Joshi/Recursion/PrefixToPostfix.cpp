#include<iostream>
#include<string.h>
using namespace std;

struct Stack
{
	string u[50];//Array of strings
	int top;
};
void push(Stack &s,string p);
string pop(Stack &s);
void emptyFill(Stack &s,int n)
{
	for(int i=n;i<=s.top-2;i++)
	{
		s.u[i]=s.u[i+2];//i+2 NOT i+1-DO NOT REPEAT THIS
	//	cout<<"EmptyFill "<<s.u[i]<<endl;
	}
	s.top-=2;
}

void convert(Stack &s)
{
	int i=0;
	string p,q,r;
	while(i<s.top-1)
	{
		p=s.u[i];
		q=s.u[i+1];
		r=s.u[i+2];
		if(p[0]=='*'||p[0]=='-'||p[0]=='+'||p[0]=='/')
		{
			if(isdigit(q[0])==true && isdigit(r[0])==true)
			{
			q+=r;
			q+=p;
			p=q;
			cout<<p<<endl;;
			s.u[i]=p;
			emptyFill(s,i+1);
			}
		}
		i++;
	}
	if(s.top!=0)
		convert(s);
}

int main()
{
	string exp,t;
	struct Stack s;
	s.top=-1;
	int i;

	cout<<"Enter the prefix expression\n";
	getline(cin,exp);
	
	for(i=0;i<exp.length();i++)
	{
		t="";
		t+=exp[i];
		push(s,t);
	}
	convert(s);
	cout<<"Postfix expression is "<<s.u[s.top]<<endl;
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
