#include<iostream>
using namespace std;

typedef struct bnode
{	
	char data;
	int tag;
	bnode *lchild, *rchild;
} *bptr;

typedef struct lnode
{
	bptr data;
	lnode *next;
} *lptr;

struct stack
{
	lptr node;
};


//Stack operations
void addfront(lptr &L, bptr T)
{
	lptr temp = new lnode;
	temp->next = L;
	temp->data = T;
	L = temp;
}

void push(stack &S, bptr T)
{
	addfront(S.node, T);
}

bptr deletefront(lptr &L)
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

bptr pop(stack &S)
{
	return deletefront(S.node);
}

void print(lptr L)
{
	if(L == NULL) cout<<"Empty";
	else if(L->next == NULL) cout<<L->data->data;
	else
	{
		cout<<L->data->data<<" ";
		print(L->next);
	}
}

//Tree operations
void create(bptr &T, int tag, int arr[], int &i)
{
	char c; cin>>c;
	if(c != '.')
	{
		T = new bnode;
		T->data = c;
		T->lchild = T->rchild = NULL;
		T->tag = tag;
		arr[i] = tag;
		i++;
		create(T->lchild, tag-1, arr, i);
		create(T->rchild, tag+1, arr, i);
	}
	else return;
}

int size(bptr T)
{
	if(T == NULL) return 0;
	else return(size(T->lchild) + size(T->rchild)+1);
}

int height(bptr root)
{
	if (root == NULL)
	{
		return 0;
	}
	else
	{
		int lheight = height(root->lchild);
		int rheight = height(root->rchild);
		
		if(lheight >= rheight) return (lheight+1);
		else return (rheight+1);
	}
}

void leftview(bptr T, int level)
{
	if(level > height(T)) return;
	
	bptr temp; stack S; S.node = NULL;
	while(level != 0)
	{
		push(S, T);
		cout<<S.node->data->data;
		if(T->lchild == NULL)
		{
			if(T->rchild == NULL)
			{
				if(level == 0)break;
				else
				{
					pop(S);
					level ++;
					temp = pop(S);
					if(temp->rchild == NULL)
					{
						while(temp->rchild == NULL)
						{
							temp = pop(S);
							level++;
						}
						T = temp->rchild;
					}
					else T = temp->rchild;
				}
			}
			else
			{
				T = T->rchild;
			}
		}
		else T = T->lchild;
		level--;
	}
	cout<<T->data;
}

void topl(bptr &T,int x)
{
	static int a;
	if(T != NULL)
	{
		if(T->tag < x)
		{
			cout<<T->data<<" ";
			a=T->tag;
		}
		topl(T->lchild,a);
		topl(T->rchild,a);
	}
}

void topr(bptr &T,int x)
{
	static int a;
	if(T!=NULL)
	{
		if(T->tag>x)
		{
			cout<<T->data<<" ";
			a=T->tag;
		}
		topr(T->rchild,a);
		topr(T->lchild,a);
	}
}

void vertical(bptr T, int x)
{
	if(T != NULL)
	{
		if(T->tag == x)
		{
			cout<<T->data<<" ";
		}
		vertical(T->lchild, x);
		vertical(T->rchild, x);
	}
}

void postOrderPrint(bptr T, stack &S)
{
	bptr T1, T2;
	while(T != NULL)
	{
		push(S, T);
		T = T->lchild;
	}
	while(S.node != NULL)
	{
		if(S.node->data->rchild == NULL || S.node->data->rchild == T1)
		{
			T1 = pop(S);
			cout<<T1->data<<" ";
		}
		else
		{
			T2 = S.node->data->rchild;
			while(T2 != NULL)
			{
				push(S, T2);
				T2 = T2->lchild;
			}
		}
	}
}

void levelprint(bptr T, int level)
{
	if(T != NULL)
	{
		if(level == 1)
		{
			cout<<T->data;
		}
		else if(level > 1)
		{
			levelprint(T->lchild, level-1);
			levelprint(T->rchild, level-1);
		}
	}
}

int main()
{
	bptr T1 = NULL, T2 = NULL;
	string str; int i = 0, arr[50];
	stack S; S.node = NULL;
	cout<<"Enter elements of Tree- 1:\n";create(T1, 0, arr, i);
	cout<<endl;
	
	for(int j = 0; j < i; j++)
	{
		for(int k = j+1; k < i; k++)
		{
			if(arr[j] >= arr[k])
			{
				arr[j] += arr[k];
				arr[k] = arr[j]-arr[k];
				arr[j] -= arr[k];
			}
		}
	}
	
	for(int j = 0; j < i-1; j++)
	{
		if(arr[j+1] == arr[j])
		{
			for(int k = j; k < i-1; k++)
			{
				arr[k] = arr[k+1];
			}
			i--;
		}
	}
	
	for(int j = 0; j < i; j++)
	{
		vertical(T1, arr[j]);
		cout<<endl;
	}
	
	//rightView(T1, height(T1)-1);
	
	
	//leftview(T1, height(T1-1);
	
	/*topl(T1, 0);
	cout<<T1->data<<" ";
	topr(T1, 0);*/
	
	//cout<<height(T1);
	//postOrderPrint(T1, S);
	//inOrderPrint(T1);
}
