//Program to implement generic stacks.

#include<iostream>
#define size 1000
using namespace std;

union u
{
	int n;
	char c[100];
	float f;
};

struct stack
{
	int length=size;
	int tag[size];
	int top;
	union u u1[size];
};



void push(stack &s)
{
	if(s.top!=s.length)
	{
		s.top++;
		cout<<"\n\nEnter tag value: ";cin>>s.tag[s.top-1];
		if(s.tag[s.top-1]==1)
		{
			int a;
			cout<<"\nEnter element: "; cin>>a;
			s.u1[s.top-1].n=a;
		}
		else if(s.tag[s.top-1]==2)
		{
			char b;
			cout<<"\nEnter element: "; cin>>s.u1[s.top-1].c;
		}
		else if(s.tag[s.top-1]==3)
		{
			float c;
			cout<<"\n\nEnter element: "; cin>>c;
			s.u1[s.top-1].f=c;
		}
	}
	else cout<<"\n\nStack Overflow. Cannot Push any further";
}

void pop(stack &s)
{
	if (s.top==1) cout<<"\n\nStack empty";
	else s.top--;
	
	cout<<"\n\n\nDisplaying Elements:\n\n\n";
	for(int a=0; a<s.top; a++)
	{
		if(s.tag[a]==1)
		{
			cout<<s.u1[a].n<<endl;
		}
		else if(s.tag[a]==2)
		{
			cout<<s.u1[a].c<<endl;
		}
		else if(s.tag[a]==3)
		{
			cout<<s.u1[a].f<<endl;
		}
	}
}

int main()
{
	struct stack s;
	int a;
	
	cout<<"Enter length of stack: "; cin>>s.length;
	cout<<"\n\nEnter number of elements(<length): ";cin>>s.top;
	
	cout<<"\n\n\nEntering elements:\n\n\n";
	cout<<"1-> Input integer\n2-> Input String\n3-> Input float";
	
	for(a=0; a<s.top; a++)
	{
		cout<<"Element "<<a+1<<":\nEnter tag value: ";cin>>s.tag[a];
		if(s.tag[a]==1)
		{
			cout<<"Enter the integer: ";cin>>s.u1[a].n;
		}
		else if(s.tag[a]==2)
		{
			cout<<"Enter the string: ";cin>>s.u1[a].c;
		}
		else if(s.tag[a]==3)
		{
			cout<<"Enter the float: ";cin>>s.u1[a].f;
		}
		cout<<endl;
	}
	
	cout<<"\n\n\nDisplaying Elements:\n\n\n";
	for(a=0; a<s.top; a++)
	{
		if(s.tag[a]==1)
		{
			cout<<s.u1[a].n<<endl;
		}
		else if(s.tag[a]==2)
		{
			cout<<s.u1[a].c<<endl;
		}
		else if(s.tag[a]==3)
		{
			cout<<s.u1[a].f<<endl;
		}
	}
	
	push(s);
	
	cout<<"\n\n\nDisplaying Elements:\n\n\n";
	for(a=0; a<=s.top; a++)
	{
		if(s.tag[a]==1)
		{
			cout<<s.u1[a].n<<endl;
		}
		else if(s.tag[a]==2)
		{
			cout<<s.u1[a].c<<endl;
		}
		else if(s.tag[a]==3)
		{
			cout<<s.u1[a].f<<endl;
		}
	}
	
	pop(s);
	
	return 0;
}
