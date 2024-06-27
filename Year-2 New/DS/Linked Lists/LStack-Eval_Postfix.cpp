#include<iostream>
using namespace std;


union u1
{
	int i;
	char c;
};

typedef struct lnode
{
	int tag;
	u1 data;
	lnode *next;
} *lptr;

struct LStack
{
	lptr top;
};


void addfirst(lptr &L, u1 x, int t)
{
	lptr T = new lnode;
	T->tag = t;
	T->data = x;
	T->next = L;
	L = T;
}

void addend(lptr &L, u1 x, int t)
{
	if(L == NULL)
	{
		lptr T = new lnode;
		T->data = x;
		T->tag = t;
		T->next = NULL;
		L = T;
	}
	else addend(L->next, x, t);
}

u1 deletefirst(lptr &L)
{
	if(L == NULL)
	{
		cout<<"\nEmpty";
	}
	else
	{
		u1 n = L->data;
		L = L->next;
		return n;
	}
}

void print(lptr L)
{
	if(L == NULL)
	{
		cout<<"Empty";
	}
	else if(L->next == NULL)
	{
		if(L->tag == 0)cout<<""<<L->data.i<<" ";
		else cout<<L->data.c;
	}
	else
	{
		if(L->tag == 0)cout<<" "<<L->data.i<<" ";
		else cout<<L->data.c;
		print(L->next);
	}
}

void push(LStack &LS, u1 x, int t)
{
	addfirst(LS.top, x, t);
}

u1 pop(LStack &LS)
{
	u1 ret = deletefirst(LS.top);
	return ret;
}

u1 enter(u1 u, int tg)
{
	cout<<"Enter element: ";
	if(tg == 0) cin>>u.i;
	else if(tg == 1)
	{
		while(true)
		{
			cin>>u.c;
			if(isalnum(u.c))cout<<"Enter again: ";
			else break;
		}
	}
	return u;
}

u1 operate(u1 opt, u1 op2, u1 op1)
{
	u1 result;
	switch(opt.c)
	{
		case '+':
			result.i = op1.i + op2.i;
			break;
		case '-':
			result.i = op1.i - op2.i;
			break;
		case '*':
			result.i = op1.i * op2.i;
			break;
		case '/':
			result.i = op1.i / op2.i;
			break;
		default:
			break;
	}
	return result;
}

LStack solve(lptr L)
{
	LStack LS; LS.top = NULL;
	u1 opt, op1, op2;
	while(L != NULL)
	{
		push(LS, L->data, L->tag);
		if(LS.top->tag == 1)
		{
			opt = pop(LS);
			op2 = pop(LS);
			op1 = pop(LS);
			opt = operate(opt, op2, op1);
			push(LS, opt, 0);
		}
		L = L->next;
	}
	return LS;
}


int main()
{
	LStack LS;
	//LS.top = NULL;
	lptr L = NULL;
	int n, i = 0, tg;
	u1 u;
	cout<<"Enter length of expression: "; cin>>n;
	
	cout<<"0. Operand\n1. Operator\n\n\n";
	while(i < n)
	{
		cout<<"Enter tag: ";
		while(true)
		{
			cin>>tg;
			if(tg == 0 || tg == 1)
			{
				break;
			}
			else cout<<"Enter again: ";
		}
		u = enter(u, tg);
		addend(L, u, tg);
		cout<<endl;
		i++;
	}
	
	LS = solve(L);
	
	if(LS.top == NULL) cout<<"Expression invalid.";
	else
	{
		cout<<"\nExpression: "; print(L);
		cout<<"\nSolution: "<<pop(LS).i;
	}
}
