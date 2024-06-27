#include<iostream>
#define size 100
using namespace std;

union st
{
	char c1[100];
};

struct stack
{
	int top, length=size, a1[100];
	union st s1[size];
};

int main()
{
	struct stack stk;
	int count=1, i, low=0;
	char c;
	cout<<"Enter postfix expression by entering one element at a time:\n";
	for(i=0; i<size; i++)
	{
		char a[100];
		cin>>a;stk.s1[i]=a;
		count++;
	}
	
	for(i=0; i<count; i++)
	{
		if(stk.s1[i]!='+'&&stk.s1[i]!='-'&&stk.s1[i]!='*'&&stk.s1[i]!='/')stk.s1[i]=stk.a1[i];
		else
		{
			switch(stk.s1[i])
			{
				case "+":
				{
					stk.a1[i-1]+=stk.a1[i-2];
					break;
				}
				case "-":
				{
					stk.a1[i-1]-=stk.a1[i-2];
					break;
				}
				case "*":
				{
					stk.a1[i-1]*=a[i-2];
					break;
				}
				case "/":
				{
					stk.a1[i-1]/=a[i-2];
					break;
				}
			}
			for(int j=i-2; j>low; j--)
			{
				stk.a1[j]=stk.a1[j-1];
			}
			delete[] stk.a1[low];
			low++;
		}
	}
	
	cout<<"\n\nEvaluated expression: "<<stk.a1[count-1];
	return 0;
}
