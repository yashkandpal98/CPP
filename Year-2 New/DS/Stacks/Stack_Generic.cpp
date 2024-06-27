#include<iostream>
#include<string.h>
using namespace std;


union u1
{
	int i;
	char c;
	char st[20];
	float f;
};


struct stack
{
	int top, size, tag[50];
	u1 data[50];
};


void pop(stack &s)
{
	if (s.top == -1)cout<<"Empty";
	else
	{
		switch(s.tag[s.top])
		{
			case 1:
				cout<<s.data[s.top].i;
				break;
			case 2:
				cout<<s.data[s.top].c;
				break;
			case 3:
				cout<<s.data[s.top].f;
				break;
			case 4:
				cout<<s.data[s.top].st;
				break;
			default:
				break;
		}
	}
}

void push(stack &s, int it, char ch, char str[], float fl)
{
	switch(s.tag[s.top])
	{
		case 1:
			s.data[s.top].i = it;
			break;
		case 2:
			s.data[s.top].c = ch;
			break;
		case 3:
			s.data[s.top].f = fl;
			break;
		case 4:
			for(int i = 0; i < strlen(str); i++)
			{
				s.data[s.top].st[i] = str[i];
			}
			break;
		default:
			break;
	}
}



int main()
{
	stack s;
	s.top = -1;
	
	char c, str[20];
	int n, it;
	float f;
	
	cout<<"Enter number of elements: "; cin>>n;
	
	cout<<"1. Enter integer\n2. Enter character\n3. Enter float\n4. Enter string";
	
	for(int i = 0; i < n; i++)
	{
		cout<<"\nEnter choice: "; cin>>s.tag[i];
		switch(s.tag[i])
		{
			case 1:
				cout<<"\nEnter element: ";
				cin>>s.data[i].i;
				break;
			case 2:
				cout<<"\nEnter element: ";
				cin>>s.data[i].c;
				break;
			case 3:
				cout<<"\nEnter element: ";
				cin>>s.data[i].f;
				break;
			case 4:
				cout<<"\nEnter element: ";
				cin>>s.data[i].st;
				break;
			default:
				cout<<"\nWrong choice. Enter again\n";
				i--;
				break;
		}
	}
	
	
}
