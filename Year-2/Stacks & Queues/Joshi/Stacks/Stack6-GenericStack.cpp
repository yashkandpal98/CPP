//Generic Stack
#include<iostream>
#include<string.h>
using namespace std;

union data
{
int rollno;
float gpa;
char name[30];	
};

struct Stack
{
	union data u[50];
	int tag[50];
	int top;
	int size;
};
void push(Stack &s);
void pull(Stack &s);
void peep(Stack &s);
bool stkEmpty(Stack &s)
{
	return(s.top==-1);
}
bool stkFull(Stack &s)
{
	return(s.top==s.size-1);
}

int main()
{
	struct Stack s;
	s.top=-1;
	int x,n,p;
	cout<<"Enter the size of the stack to be made?\n";
	cin>>n;
	s.size=n;
	
	bool cont=true;
	
	while(cont)
	{
		cout<<"What do you wish to do?\n\n1.Push\n2.Pull\n3.Peep\n";
		cin>>x;
		switch(x)
		{
			case 1: push(s);
				break;
			case 2: pull(s);
				break;
			case 3: peep(s);
				break;
			default:cout<<"Enter 1 , 2 or 3\n";
				break;
		}
		cout<<"\nDo you wish to perform more operations\nType 1 for Yes or 0 for No\n";
		cin>>p;
		(p==1)?cont=true : cont=false;
	 } 
	 return(0);
}

void push(Stack &s)
{
	int x;
	if(stkFull(s))
	cout<<"Stack is full\n";
	
	else
	{
		cout<<"What do you wish to push?\n1.Rollno\n2.Name\n3.GPA\n";
		cin>>x;
		s.top=s.top+1;
		switch(x)
		{
			case 1:
			int n;
			cout<<"Enter the rollno\n";
			cin>>n;
			s.u[s.top].rollno=n;
			s.tag[s.top]=1;
			break;
			case 2:
			cout<<"Enter the name\n";
			cin>>s.u[s.top].name;
			s.tag[s.top]=2;
			break;
			case 3:
				int g;
				cout<<"Enter the GPA\n";
				cin>>g;
				s.u[s.top].gpa=g;
				s.tag[s.top]=3;
				break;
			
		}
		
	}
}


void pull(Stack &s)
{
	if(stkEmpty(s))
	cout<<"Stack is empty\n";
	
	else
	{
		cout<<"Element removed is ";
		switch(s.tag[s.top])
		{
			case 1:
				cout<<s.u[s.top].rollno<<endl;
				s.u[s.top].rollno=0;
				break;
			case 3:
				cout<<s.u[s.top].gpa<<endl;
				s.u[s.top].gpa=0;
				break;
			case 2:
				cout<<s.u[s.top].name<<endl;
				break;
		}
		s.tag[s.top]=0;
		s.top-=1;
	}
}

void peep(Stack &s)
{
	if(stkEmpty(s))
	cout<<"Stack is empty\n";
	else
	{
		switch(s.tag[s.top])
		{
			case 1:
				cout<<"Rollno is "<<s.u[s.top].rollno<<endl;
				break;
			case 3:
				cout<<"GPA is "<<s.u[s.top].gpa<<endl;
				break;
			case 2:
				cout<<"Name is "<<s.u[s.top].name<<endl;
				break;
		}
	}
	
}


