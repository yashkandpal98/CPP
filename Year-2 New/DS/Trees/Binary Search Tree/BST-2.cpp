#include<iostream>
#include<math.h>
using namespace std;


//Structures
typedef struct bstnode
{
	bstnode *lchild, *rchild;
	int data;
} *bsptr;

typedef struct lnode
{
	bsptr data;
	lnode *next;
} *lptr;

struct stack
{
	lptr node;
};

//Addition and deletion
void add(bsptr &root, int x)
{
	if (!root)
	{
		bsptr root1 = new bstnode();
		root1->data = x;
		root1->lchild = root1->rchild = NULL;
		
		root = root1;
	}
	else
	{
		if (root->data <= x)
		{
			add(root->rchild, x);
		}
		else
		{
			add(root->lchild, x);
		}
	}
}

bsptr inOrderSuccessor(bsptr root)
{
	if(root->lchild) root = inOrderSuccessor(root->lchild);
	return root;
}

bsptr deleteNode(bsptr root, int x)
{
	if (root->data > x)
	{
		root->lchild = deleteNode(root->lchild, x);
	}
	else if (root->data < x)
	{
		root->rchild = deleteNode(root->rchild, x);
	}
	
	else
	{
		if (root->lchild == NULL)
		{
			bsptr temp = root->rchild;
			return temp;
		}
		
		else if (root->rchild == NULL)
		{
			bsptr temp = root->lchild;
			return temp;
		}
		
		bsptr temp = inOrderSuccessor(root->rchild);
		
		root->data = temp->data;
		
		root->rchild = deleteNode(root->rchild, temp->data);
	}
	return root;
}

//Height & search
int height(bsptr root)
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

bsptr search(bsptr root, int x)
{
	if(root != NULL)
	{
		if(root->data > x) return search(root->lchild, x);
		else if(root->data < x) return search(root->rchild, x);
		else return root;
	}
	else return NULL;
}

//Printing
void printCurrentLevel(bsptr root, int level, int l2)
{
	if (level == 1)
	{
		if(root == NULL)cout<<" ";
		else cout<<root->data;
		for(int i = 1; i <= (l2-1); i++)
		{
			cout<<" ";
		}
	}
	
	else if (level > 1)
	{
		if(root != NULL)
		{
			printCurrentLevel(root->lchild, level-1, l2);
			printCurrentLevel(root->rchild, level-1, l2);
		}
		else
		{
			cout<<" ";
			for(int i = 1; i <= (l2-1); i++) cout<<"   ";
		}
	}
}

void levelOrderPrint(bsptr root)
{
	for (int i = 0; i < height(root); i++)
	{
		int x = pow(2, height(root)-i);
		for(int j = 0; j < x/2; j++)
		{
			cout<<" ";
		}
		printCurrentLevel(root, i+1, x);
		cout<<endl;
	}
}

void inOrderPrint(bsptr root)
{
	if(root != NULL)
	{
		inOrderPrint(root->lchild);
		cout<<root->data<<" ";
		inOrderPrint(root->rchild);
	}
}

//Stack operations
void addfront(lptr &L, bsptr T)
{
	lptr temp = new lnode;
	temp->next = L;
	temp->data = T;
	L = temp;
}

void push(stack &S, bsptr T)
{
	addfront(S.node, T);
}

bsptr deletefront(lptr &L)
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

bsptr pop(stack &S)
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

//Key functions
void sum(bsptr T, int &s)															//Add greater node value to current node
{
	if(T->rchild != NULL) sum(T->rchild, s);
	T->data += s;
	s = T->data;
	if(T->lchild != NULL) sum(T->lchild, s);
}

void comp(stack S1, stack S2, bsptr T1, bsptr T2)									//Print common nodes in a tree
{
	bsptr temp, temp1, temp2;
	while(T1 != NULL)
	{
		push(S1, T1);
		T1 = T1->lchild;
	}
	while(T2 != NULL)
	{
		push(S2, T2);
		T2 = T2->lchild;
	}
		
	while(S1.node != NULL && S2.node != NULL)
	{
		if(S1.node->data->data < S2.node->data->data)
		{
			if(S1.node->data->rchild != NULL)
			{
				temp = pop(S1);
				push(S1, temp->rchild);
				temp = temp->rchild;
				while(temp->lchild != NULL)
				{
					push(S1, temp->lchild);
					temp = temp->lchild;
				}
			}
			else pop(S1);
		}
		else if(S1.node->data->data > S2.node->data->data)
		{
			if(S2.node->data->rchild != NULL)
			{
				temp = pop(S2);
				push(S2, temp->rchild);
				temp = temp->rchild;
				while(temp->lchild != NULL)
				{
					push(S2, temp->lchild);
					temp = temp->lchild;
				}
			}
			else pop(S2);
		}
		else if(S1.node->data->data == S2.node->data->data)
		{
			temp1 = pop(S1); temp2 = pop(S2);
			cout<<temp1->data<<endl;
			if(temp1->rchild != NULL)
			{
				push(S1, temp1->rchild);
				temp1 = temp1->rchild;
				while(temp1->lchild !=NULL)
				{
					push(S1, temp1->lchild);
					temp1 = temp1->lchild;
				}
			}
			if(temp2->rchild != NULL)
			{
				push(S2, temp2->rchild);
				temp2 = temp2->rchild;
				while(temp2->lchild !=NULL)
				{
					push(S2, temp2->lchild);
					temp2 = temp2->lchild;
				}
			}
		}
	}
}

void sumcheck(bsptr T1, bsptr T2, stack S1, stack S2, int S)						//Print nodes whose sum = S
{
	bsptr temp, temp1, temp2;
	while(T1 != NULL)
	{
		push(S1, T1);
		T1 = T1->lchild;
	}
	while(T2 != NULL)
	{
		push(S2, T2);
		T2 = T2->rchild;
	}
		
	while(S1.node != NULL && S2.node != NULL)
	{
		if(S1.node->data->data + S2.node->data->data < S)
		{
			if(S1.node->data->rchild != NULL)
			{
				temp = pop(S1);
				push(S1, temp->rchild);
				temp = temp->rchild;
				while(temp->lchild != NULL)
				{
					push(S1, temp->lchild);
					temp = temp->lchild;
				}
			}
			else pop(S1);
		}
		else if(S1.node->data->data + S2.node->data->data > S)
		{
			if(S2.node->data->lchild != NULL)
			{
				temp = pop(S2);
				push(S2, temp->lchild);
				temp = temp->lchild;
				while(temp->rchild != NULL)
				{
					push(S2, temp->rchild);
					temp = temp->rchild;
				}
			}
			else pop(S2);
		}
		else if(S1.node->data->data + S2.node->data->data == S)
		{
			temp1 = pop(S1); temp2 = pop(S2);
			cout<<temp1->data<<" "<<temp2->data<<endl;
			if(temp1->rchild != NULL)
			{
				push(S1, temp1->rchild);
				temp1 = temp1->rchild;
				while(temp1->lchild !=NULL)
				{
					push(S1, temp1->lchild);
					temp1 = temp1->lchild;
				}
			}
			if(temp2->lchild != NULL)
			{
				push(S2, temp2->lchild);
				temp2 = temp2->lchild;
				while(temp2->rchild !=NULL)
				{
					push(S2, temp2->rchild);
					temp2 = temp2->rchild;
				}
			}
		}
	}
}

void levelstore(bsptr T, int level, int a[], int &i)
{
	if(level == 1 & T != NULL)
	{
		a[i] = T->data;
		i++;
	}
	else if(level > 1 && T != NULL)
	{
		levelstore(T->lchild, level-1, a, i);
		levelstore(T->rchild, level-1, a, i);
	}
}

void path(bsptr T)																	//Root-to-leaf path to the deepest node
{
	int i = 0, a[height(T)];
	
	levelstore(T, height(T), a, i);
	for(int j = 0; j < i; j++)
	{
		bsptr temp = T;
		while(temp->data != a[j])
		{
			cout<<temp->data<<" ";
			if(a[j] > temp->data) temp = temp->rchild;
			else if(a[j] < temp->data) temp= temp->lchild;
			else break;
		}
		cout<<temp->data<<endl;
	}
}

int size(bsptr T)
{
	if(T == NULL)
	{
		return 0;
	}
	else return(1 + size(T->lchild) + size(T->rchild));
}

void inorderstore(bsptr T, int a[], int &i)
{
	if(T != NULL)
	{
		inorderstore(T->lchild, a, i);
		a[i] = T->data;
		i++;
		inorderstore(T->rchild, a, i);
	}
}

void convert(bsptr &T, int a[], int low, int high, int len)
{
	int mid = (high+low)/2;
	if(mid == low || mid == high) return;
	else
	{
		add(T, a[mid]);
		convert(T, a, low, mid, len);
		convert(T, a, mid, high, len);
	}
}

void merge(bsptr &T, bsptr T1, bsptr T2)											//Merge 2 BSTs
{
	int n1 = size(T1), n2 = size(T2), n = n1+n2, i1 = 0, i2 = 0, i = 0;
	int a[n], a1[n1], a2[n2];
	
	inorderstore(T1, a1, i1);
	inorderstore(T2, a2, i2);
	
	i1 = 0; i2 = 0; i = 0;
	
	while(true)
	{
		if(i1 == n1 && i2 == n2) break;
		else if(i1 < n1 && i2 < n2)
		{
			if(a1[i1] < a2[i2])
			{
				a[i] = a1[i1];
				i1++;
			}
			else if(a2[i2] < a1[i1])
			{
				a[i] = a2[i2];
				i2++;
			}
			else if(a1[i1] == a2[i2])
			{
				a[i] = a1[i1];
				i1++; i2++;
			}
			i++;
		}
		else
		{
			if(i1 == n1 && i2 < n2)
			{
				while(i2 != n2)
				{
					a[i] = a2[i2];
					i2++; i++;
				}
			}
			if(i2 == n2 && i1 < n1)
			{
				while(i1 != n1)
				{
					a[i] = a1[i1];
					i1++; i++;
				}
			}
			break;
		}
	}
	
	cout<<"Tree 1:\n";
	levelOrderPrint(T1);
	cout<<"\nTree 2:\n";
	
	levelOrderPrint(T2);
	convert(T, a, 0, i, i);
	add(T, a[0]);
	
	cout<<"\nMerged Tree:\n";
	levelOrderPrint(T);
}


int main()
{
	bsptr root = NULL, T = NULL, T1 = NULL, T2 = NULL;
	stack S1, S2;
	S1.node = NULL; S2.node = NULL;
	int s = 0;
	
	add(root, 8);
	add(root, 4);
	add(root, 12);
	add(root, 2);
	add(root, 6);
	add(root, 10);
	add(root, 14);
	add(root, 1);
	add(root, 3);
	add(root, 5);
	add(root, 7);
	add(root, 9);
	add(root, 11);
	add(root, 13);
	add(root, 15);
	
	add(T1, 18);
	add(T1, 12);
	add(T1, 36);
	add(T1, 5);
	add(T1, 16);
	add(T1, 20);
	add(T1, 95);
	add(T1, 2);
	add(T1, 9);
	add(T1, 6);
	
	add(T2, 20);
	add(T2, 16);
	add(T2, 40);
	add(T2, 12);
	add(T2, 36);
	add(T2, 90);
	add(T2, 9);
	add(T2, 13);
	
	levelOrderPrint(root);
	/*sum(root, s);
	cout<<endl<<endl;
	levelOrderPrint(root);*/
	
	//comp(S1, S2, T1, T2);
	
	//sumcheck(T1, T2, S1, S2, 45);
	
	//path(root);
	
	//merge(T, T2, root);
	
	return 0;
}
