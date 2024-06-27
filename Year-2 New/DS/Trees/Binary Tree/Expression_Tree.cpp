#include<iostream>
using namespace std;


typedef struct expnode
{
	int tag;
	union u1
	{
		int value;
		char symbol;
	}data;
	expnode *lchild, *rchild;
} *exptr;

typedef struct lnode
{
	exptr data;
	lnode *next;
} *lptr;

struct stack
{
	lptr node;
};


//Stack operations
void addfront(lptr &L, exptr T)
{
	lptr temp = new lnode;
	temp->next = L;
	temp->data = T;
	L = temp;
}

void push(stack &S, exptr T)
{
	addfront(S.node, T);
}

exptr deletefront(lptr &L)
{
	if(L == NULL) cout<<"Empty";
	else
	{
		lptr T = L;
		L = L->next;
		return(T->data);
		delete T;
	}
}

exptr pop(stack &S)
{
	return deletefront(S.node);
}

//Tree functions
void createExpression(stack &S, int i, string str)
{
	if(i < str.size())
	{
		if(isdigit(str[i]))
		{
			exptr T = new expnode;
			int x = str[i]-'0';
			T->tag = 0;
			T->data.value = x;
			T->lchild = T->rchild = NULL;
			push(S, T);
			createExpression(S, i+1, str);
		}
		else
		{
			exptr T1 = pop(S);
			exptr T2 = pop(S);
			exptr T3 = new expnode;
			T3->data.symbol = str[i];
			T3->tag = 1;
			T3->rchild = T1;
			T3->lchild = T2;
			push(S, T3);
			createExpression(S, i+1, str);
		}
	}
}

int evaluate(exptr T)
{
	if(T->tag == 0) return T->data.value;
	else
	{
		switch(T->data.symbol)
		{
			case '+':
				return(evaluate(T->lchild) + evaluate(T->rchild));
			case '-':
				return(evaluate(T->lchild) - evaluate(T->rchild));
			case '*':
				return(evaluate(T->lchild) * evaluate(T->rchild));
			case '/':
				return(evaluate(T->lchild) / evaluate(T->rchild));
			default:
				break;
		}
	}
}


int main()
{
	stack S; S.node = NULL;
	exptr T;
	string str;
	cout<<"Enter postfix expression: "; cin>>str;
	
	createExpression(S, 0, str);
	
	T = pop(S);
	
	cout<<endl<<evaluate(T);
}
