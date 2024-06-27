#include<iostream>
#include<cmath>
#include<string>

using namespace std;

union U
{
	int in;
	char ch;
};

struct S
{
	U u ;
	int tag;
};

struct stack
{
	int top;
	struct S element[50];
	int size;
};

bool isemp(stack &s)
{
	return (s.top==-1) ? 1 : 0;
}

bool isfull(stack &s)
{
	return(s.top==s.size) ? 1 : 0;
}

void push(stack & s,union U x,int tag)
{
	if(isfull(s)) return;
	if(tag==1)
	{
		s.element[s.top+1].tag=1;
		s.element[++s.top].u.in=x.in;
	}
	else
	{
		s.element[s.top+1].tag=2;
		s.element[++s.top].u.ch=x.ch;
	}
}

int pop(stack &s)
{
	if(isemp(s))
	return 0;
	else
	{
		if(s.element[s.top].tag==1) return s.element[s.top--].u.in;
		else return s.element[s.top--].u.ch;
	}
}
int peep(stack &s)
{
	if(isemp(s))
	return 0;
	else
	{
		if(s.element[s.top].tag==1) return s.element[s.top].u.in;
		else return s.element[s.top].u.ch;
	}
}

int evaluate(string &);
int number (string &);

int main()
{
	string s="(((5+(3-6))+3)\n\n";
	cout<<s;
	union U myu;
	cout<<"Ans is: "<<evaluate(s);
}

int number (string &mys)
{
	int num=0,j=0;
	for(int i=mys.length()-1;i>=0;i--)
	{
	num+=pow(10,j++)*(mys[i]-48);
	}
	return num;
}

int evaluate(string & str)
{
	stack s;
	s.top=-1;
	s.size=str.length();
	
	for(int i=0;i<str.length();i++)
	{
		if(isdigit(str[i]))
		{
			string mys;
			mys.push_back(str[i]);
			while(isdigit(str[++i]))
			{
				mys.push_back(str[i]);
			}
			i--;
			union U myu ;
			myu.in=number(mys);
			push(s,myu,1);
		}
		else if(str[i]== ' ') continue;
		else if(str[i]=='(')
		{
			union U myu;
			myu.ch='(';
			push(s,myu,2);
		}
		else if(str[i]=='*' || str[i]=='+' || str[i]== ' /' || str[i]=='-')
		{
			union U myu;
			myu.ch=str[i];
			push(s,myu,2);
		}
		else
		{
			union U u1;
			int myu1=pop(s);
			char myu2=pop(s);
			char myu3=pop(s);
			switch(myu2)
			{
				case'+' : u1.in=myu3+myu1; break;
				case'-' : u1.in=myu3-myu1; break;
				case'/' : u1.in=myu3/myu1; break;
				case'*' : u1.in=myu3*myu1; break;
			}
			pop(s);
			push(s,u1,1);
		}
	}
	return pop(s);
}
