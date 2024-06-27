//Reverse Stack with recursion
//LIFO Stack
#include<iostream>
#include<string>
using namespace std;

struct Stack
{
	int size;
	int element[50];
	int top;
};
void push(Stack &s);
int pop(Stack &s);
void peep(Stack &s);
bool stkEmpty(Stack &s)
{
	return(s.top==-1);
}
bool stkFull(Stack &s)
{
	return(s.top==s.size-1);
}
void rev(Stack &s)
{
	int c;
	c=pop(s);
	cout<<c<<" ";
	if(s.top!=-1)
	rev(s);
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
		cout<<"What do you wish to do?\n\n1.Push\n2.Pull\n3.Peep\n4.Reverse\n";
		cin>>x;
		switch(x)
		{
			case 1: push(s);
				break;
			case 2: pop(s);
				break;
			case 3: peep(s);
				break;
			case 4:
					rev(s);
					for(int j=0;j<=s.top;j++)
					cout<<s.element[j]<<" ";
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
		cout<<"Enter the element to push\n";
		cin>>x;
		s.top=s.top+1;
		s.element[s.top]=x;
	}
}
int pop(Stack &s)
{
	int c=0;
	if(stkEmpty(s))
	cout<<"Stack is empty\n";
	
	else
	{
	//	cout<<"Element removed is "<<s.element[s.top]<<endl;
		c=s.element[s.top];
		s.element[s.top]=0;
		s.top-=1;
	}
	return(c);
}
void peep(Stack &s)
{
	if(stkEmpty(s))
	cout<<"Stack is empty\n";
	else
	cout<<"Top most element is "<<s.element[s.top]<<" which is present at index = "<<s.top<<endl;
}
