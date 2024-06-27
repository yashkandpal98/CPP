//Second Try For some reason you must declare the structure globally AND the push pop peep should not have the stack as a parameter 
// OR just use Stack &s as parameter in the functions
#include<iostream>
#include<string>
using namespace std;

struct Stack
{
	int size;
	int element[50];
	int top;
};
void push();
void pop();
void peep();
bool stkEmpty(Stack s)
{
	return(s.top==-1);
}
bool stkFull(Stack s)
{
	return(s.top==s.size-1);
}
struct Stack s;
int main()
{
	s.top=-1;
	int x,n,p;
	cout<<"Enter the size of the stack to be made?\n";
	cin>>n;
	s.size=n;
	
	bool cont=true;
	
	while(cont)
	{
		cout<<"What do you wish to do?\n\n1.Push\n2.Pop\n3.Peep\n";
		cin>>x;
		switch(x)
		{
			case 1: push();
				break;
			case 2: pop();
				break;
			case 3: peep();
				break;
			default:cout<<"Enter 1 , 2 or 3\n";
				break;
		}
		cout<<"\nDo you wish to perform more operations\nType 1 for Yes or 0 for No\n";
		cin>>p;
		(p==1)?cont=true : cont=false;
	 } 
}

void push()
{
	int x;
	if(stkFull(s))
	cout<<"Stack is full\n";
	
	else
	{
		cout<<"Enter the element to push\n";
		cin>>x;
		s.top=s.top+1;
		s.element[s.top]=x;
	}
}
void pop()
{
	if(stkEmpty(s))
	cout<<"Stack is empty\n";
	
	else
	{
		cout<<"Element removed is "<<s.element[s.top]<<endl;
		s.element[s.top]=0;
		s.top-=1;
	}
}
void peep()
{
	if(stkEmpty(s))
	cout<<"Stack is empty\n";
	else
	cout<<"Top most element is "<<s.element[s.top]<<" which is present at index = "<<s.top<<endl;
}
