//Bubble sorting n terms with 2 stacks
//NOTE cpp showed 0 0 0...till size of s1 the followed by the sorted elements while outputing
//THE problem was sorted by using a isFull() as shown so that 0 does not get pushed in unneccsarily each time

#include<iostream>
#include<string.h>
#include<cmath>
using namespace std;

struct Stack
{
	int top;
	int element[50];
	int size;
};
bool isEmpty(Stack &s)
{
	return(s.top==-1);
}
bool isFull(Stack &s)
{
	return(s.top==s.size-1);
}
void push(Stack &s, int a)
{
	if(!isFull(s))//IMP to avoid some error
	{
	s.top+=1;
//	cout<<"Push "<<a<<endl;
	s.element[s.top]=a;
	}
}
int pop(Stack &s)
{
	int a=s.element[s.top];
	cout<<"Pop "<<a<<endl;
	s.element[s.top]=0;
	s.top--;
	return(a);
}
int main()
{
	Stack s1,s2;
	s1.top=-1;
	s2.top=-1;
	int i,x,n;
	
	cout<<"Enter the number of terms to sort \n";
	cin>>n;
	s1.size=n;
	s2.size=n;
	
	for(i=0;i<s1.size;i++)
	{
		cout<<"Enter term "<<i+1<<"\n";
		cin>>x;
		push(s1,x);
	}
	
	int d=0;//Intializing the no of times to sort
	while(d<n)
	{
		int a=0,b=0;//I am sooo NOT repeating this mistake from the bubble sort with queues again
		while(!isEmpty(s1))
		{
			a=pop(s1);
			if(a<b)
			{
				a=a+b;
				b=a-b;
				a=a-b;
			}
			push(s2,b);
			b=a;
		}
		push(s1,a);
		while(!isEmpty(s2))
		{
			a=pop(s2);
			push(s1,a);
		}
		d++;
	}
	cout<<"The terms sorted in ascending order are :\n";
	while(!isEmpty(s1))//Do NOT FORGET the !
	{
		x=pop(s1);
		cout<<x<<"\n";
	}
	return(0);
}
