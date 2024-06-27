//Double Recursion
#include<iostream>
#include<string>
using namespace std;

struct Stack
{
	int size;
	int element[50];
	int top;
};
void push(Stack &s,int a);
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

void bottomInsert(Stack &s, int a)
{
    if(stkEmpty(s))
		push(s,a);
	else
	{
		int temp = pop(s);
		bottomInsert(s,a);
		push(s,temp);
       }
}

void reverse(Stack &s)
{
    if(!stkEmpty(s))
	{
        int temp = pop(s);
		reverse(s);
		bottomInsert(s,temp);
	}
}

int main()
{
	struct Stack s;
	s.top=-1;
	int x,n,p,a;
	cout<<"Enter the size of the stack to be made?\n";
	cin>>n;
	s.size=n;
	
	bool cont=true;
	
	while(cont)
	{
		cout<<"What do you wish to do?\n\n1.Push\n2.Pull\n3.Peep\n4.Reverse\n5.Quit\n";
		cin>>x;
		switch(x)
		{
			case 1:
				cout<<"Enter the element to push\n";
				cin>>a;
			 	push(s,a);
				break;
			
			case 2: pop(s);
				break;
			case 3: peep(s);
				break;
			case 4:reverse(s);
				break;
			case 5:cont=false;
			break;
			default:cout<<"Invalid Input\n";
				break;
		}
		while(!stkEmpty(s))
		{
			a=pop(s);
			cout<<a<<" ";
		}
	 } 
	 return(0);
}
void push(Stack &s, int a)
{
	if(stkFull(s))
	cout<<"Stack is full\n";
	
	else
	{
		s.top=s.top+1;
		s.element[s.top]=a;
		cout<<"Push "<<a<<endl;
	}
}

int pop(Stack &s)
{
	if(stkEmpty(s))
	{
	cout<<"Stack is empty\n";
	return 0;
	}
	else
	{
		int a;
		cout<<"Element removed is "<<s.element[s.top]<<endl;
		a=s.element[s.top];
		s.element[s.top]=0;
		s.top-=1;
		return(a);
	}
}
void peep(Stack &s)
{
	if(stkEmpty(s))
	cout<<"Stack is empty\n";
	else
	cout<<"Top most element is "<<s.element[s.top]<<" which is present at index = "<<s.top<<endl;
}
