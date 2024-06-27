//2 Stacks VS 1 Array
#include<iostream>
#include<string.h>
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
void push(Stack &s, int a)
{
	s.top+=1;
//	cout<<"Push "<<a<<endl;
	s.element[s.top]=a;
}
int pop(Stack &s)
{
	int a=s.element[s.top];
//	cout<<"Pop "<<a<<endl;
	s.element[s.top]=0;
	s.top-=1;
	return(a);
}

int main()
{
	Stack s1,s2;
	s1.top=-1;
	s2.top=-1;
	
	cout<<"Enter the number of elements in Stack 1\n";
	cin>>s1.size;
	cout<<"Enter them\n";
	int i,x;
	for(i=0;i<s1.size;i++)
	{
		cin>>x;
		push(s1,x);
	}
	cout<<"\nEnter the no number of elements in Stack 2\n";
	cin>>s2.size;
	cout<<"Enter them\n";
	for(i=0;i<s2.size;i++)
	{
		cin>>x;
		push(s2,x);
	}
	cout<<"Filling Array\n";
	
	int a[100],n;
	n=s1.size+s2.size;
	int t1=0,t2=n-1;
	//while((t1+1)!=t2)	ie WHILE The array is NOT full ------>>>>>>> WRONG LOGIC AS YOU MISS THE LAST TIME POP SO  :)
	while(t1<t2)//As after the last pop t1=t2+1
	{
		if(!isEmpty(s1))
		{
			a[t1]=pop(s1);
			t1++;
		}
		if(!isEmpty(s2))
		{
			a[t2]=pop(s2);
			t2--;//MAKE sure it is -- NOT ++
		}
	}
	
	cout<<"The array is :";
	for(i=0;i<n;i++)
	cout<<a[i]<<" ";
	return(0);
}
