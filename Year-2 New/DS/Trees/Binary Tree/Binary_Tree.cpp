#include<iostream>
using namespace std;

typedef struct bnode
{
	char data;
	bnode *lchild, *rchild, *adptr;
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
void create(bptr &T)
{
	char c; cin>>c;
	if(c != '.')
	{
		T = new bnode;
		T->data = c;
		T->lchild = T->rchild = NULL;
		T->adptr = NULL;
		create(T->lchild);
		create(T->rchild);
	}
	else return;
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

int size(bptr T)
{
	if(T == NULL) return 0;
	else return(size(T->lchild) + size(T->rchild)+1);
}

void inOrderStore(char arr[], bptr T, int &i)
{
	if(T != NULL)
	{
		inOrderStore(arr, T->lchild, i);
		arr[i] = T->data; i++;
		inOrderStore(arr, T->rchild, i);
	}
}

void inOrderConvert(char arr[], bptr &T, int &i)
{
	if(T != NULL)
	{
		inOrderConvert(arr, T->lchild, i);
		T->data = arr[i]; i++;
		inOrderConvert(arr, T->rchild, i);
	}
}

void serialize(bptr T, string &s)
{
	if(T == NULL)
	{
		s += ".";
	}
	else
	{
		s += T->data;
		serialize(T->lchild, s);
		serialize(T->rchild, s);
	}
}

void deserialize(bptr &T, string s, int &i)
{
	if(s[i] == '.')i++;
	else 
	{
		T = new bnode;
		T->adptr = NULL;
		T->lchild = T->rchild = T->adptr = NULL;
		T->data = s[i];
		deserialize(T->lchild, s, ++i);
		deserialize(T->rchild, s, i);
	}
}

bool mirror(bptr T1, bptr T2)
{
	if(T1 != NULL && T2 != NULL)
	{
		if(T1->data == T2->data)
		{
			if((mirror(T1->lchild, T2->rchild)) && (mirror(T1->rchild, T2->lchild))) return true;
			else return false;
		}
		else return false;
	}
	else if(T1 == NULL && T2 == NULL) return true;
	else return false;
}

void levelstore(bptr arr[], bptr T, int level, int &i)
{
	if(T != NULL)
	{
		if(level == 1)
		{
			arr[i] = T;
			i++;
		}
		else if(level > 1)
		{
			levelstore(arr, T->lchild, level-1, i);
			levelstore(arr, T->rchild, level-1, i);
		}	
	}
}

void linkLevel(bptr T, int &j)
{
	bptr arr[50];
	int i = 0;
	
	if(j < height(T))
	{
		levelstore(arr, T, ++j, i);
		for(int k = 0; k < i-1; k++)
		{
			arr[k]->adptr = arr[k+1];
			arr[k] = NULL;
		}
		linkLevel(T, j);
	}
}

void convert(bptr &T)
{
	int x = size(T), i = 0;
	char arr[x];
	inOrderStore(arr, T, i);
	for(int j = 0; j < i; j++)
	{
		for(int k = j+1; k < i; k++)
		{
			if(arr[j] > arr[k])
			{
				arr[j] += arr[k];
				arr[k] = arr[j]-arr[k];
				arr[j] -= arr[k];
			}
		}
	}
	i = 0;
	inOrderConvert(arr, T, i);
}

//Tree printing
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

void printlevel(bptr T, int level)
{
	if(level > height(T)) return;
	
	bptr temp; stack S; S.node = NULL;
	while(level != 0)
	{
		push(S, T);
		if(T->lchild == NULL)
		{
			if(T->rchild == NULL)
			{
				if(level == 0) break;
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
	while(T != NULL)
	{
		cout<<T->data<<" ";
		T = T->adptr;
	}
}

void inOrderPrint(bptr T)
{
	if(T != NULL)
	{
		inOrderPrint(T->lchild);
		cout<<T->data;
		inOrderPrint(T->rchild);
	}
}


int main()
{
	bptr T1 = NULL, T2 = NULL;
	string str; int i = 0, j = 0;
	stack S; S.node = NULL;
	
	/*cout<<"Enter elements of Tree- 1:\n";create(T1);
	cout<<endl;
	cout<<"Enter elements of Tree- 2:\n";create(T1);
	
	if(mirror(T1, T2))cout<<"\n\nMirror Trees.\n";
	else cout<<"\n\nNot mirror Trees.\n";*/
	
	/*serialize(T1, str);
	cout<<endl<<str;*/
	
	cout<<"Enter preorder string: "; cin>>str;
	deserialize(T1, str, i);
	cout<<endl;
	
	/*convert(T1);
	inOrderPrint(T1);*/
	
	/*linkLevel(T1, j);
	printlevel(T1, 3);*/
	
	//cout<<height(T1);
	//postOrderPrint(T1, S);
	//inOrderPrint(T1);
}
