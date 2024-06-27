#include<iostream>
using namespace std;

struct stack
{
	int top=-1;
	int elements[50];
}s[2];

void push(stack *s,int p,int x)
{
	if(s[p].top==-1)
	{
		s[p].top=0;
		s[p].elements[s[p].top]=x;
	}
	else
	{ 
	   s[p].top++;
	   s[p].elements[s[p].top]=x;
	}
}

int pop(stack *s,int p)
{
	return s[p].elements[s[p].top--];
}

int seetop(stack *s,int p)
{
	return s[p].elements[s[p].top];
}

int main()
{
	int n,x,y,z,a;

	cout<<"Enter no of elements: ";cin>>n;cout<<endl;

	cout<<"Enter the elements:\n"<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>x;
		push(s,0,x);
	}
	for (int j=0;j<1000;j++)
	{
		y=pop(s,0);
		if (s[1].top==-1) push(s,1,y);
		else
		{
			z=seetop(s,1);
			while(y>z)
			{
				a=pop(s,1);
				push(s,0,a);
				if (s[1].top!=-1) z=seetop(s,1);
				else break;
			}
			push(s,1,y);
		}
		if(s[0].top==-1) break; 
	}

	cout<<"\nSorted stack:"<<endl;
	for( int i=0;i<n;i++)
		cout<<pop(s,1)<<endl;
	return 0;
}
