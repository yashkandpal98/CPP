#include<iostream>
using namespace std;


struct element
{
	int value, count;
};

struct stack
{
	int size, top = -1;
	element data[200];
};

typedef struct mnode
{
	int data, count;
	mnode *next[50];
} *mptr;

void push(stack &s, int x, int y)
{
	if(s.top == s.size-1) cout<<"Stack full";
	else 
	{
		s.data[++s.top].value = x;
		s.data[s.top].count = y;
	}
}

element pop(stack &s)
{
	if(s.top == -1) cout<<"Stack empty";
	else return s.data[s.top--];
}

element tel(stack s)
{
	if(s.top == -1) cout<<"Stack empty";
	else return s.data[s.top];
}

int find(mptr L, stack &s, int tag, int f)
{
	if(L != NULL)
	{
		push(s, L->data, L->count);
		while(tel(s).count >= 0)
		{
			tag = find(L->next[tel(s).count-1], s, tag, f);
			element e = pop(s);
			e.count -= 1;
			push(s, e.value, e.count);
			if(tag == 1) 
			{
				cout<<L->data<<"->";
				return(tag);
				break;
			}
		}
		
		if(L->data == f)
		{
			cout<<L->data<<"->";
			return 1;
		}
		else return 0;
		
	}
}


int main()
{
	int tag = 0;
	return 0;
}
