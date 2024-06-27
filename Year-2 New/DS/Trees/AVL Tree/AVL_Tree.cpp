#include<iostream>
#include<cmath>
using namespace std;


//Structures
typedef struct avlnode
{
	int data;
	avlnode *lchild, *rchild;
} *avlptr;

typedef struct lnode
{
	avlptr data;
	lnode *next;
} *lptr;

struct stack
{
	lptr node;
};


//Stack operations
void addfront(lptr &L, avlptr T)
{
	lptr temp = new lnode;
	temp->next = L;
	temp->data = T;
	L = temp;
}

void push(stack &S, avlptr T)
{
	addfront(S.node, T);
}

avlptr deletefront(lptr &L)
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

avlptr pop(stack &S)
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

//Height and search
int height(avlptr T)
{
	if(T == NULL) return -1;
	else return(max(height(T->lchild), height(T->rchild))+1);
}

avlptr inOrderSuccessor(avlptr root)
{
	if(root->lchild != NULL) root = inOrderSuccessor(root->lchild);
	return root;
}

void deepest(avlptr root, int level, int arr[], int &i)
{
	if(root != NULL)
	{
		if(level == 0)
		{
			arr[i] = root->data;
			i++;
		}
		else
		{
		    deepest(root->lchild, level-1, arr, i);
		    deepest(root->rchild, level-1, arr, i);
		}
	}
}

//Tree operations
void add(avlptr &T, int x)
{
	if(T == NULL)
	{
		T = new avlnode;
		T->lchild = T->rchild = NULL;
		T->data = x;
	}
	else
	{
		if(T->data > x) add(T->lchild, x);
		else if(T->data < x) add(T->rchild, x);
		else cout<<"Duplicate element.\n";
	}
}

bool checkBalance(avlptr T)
{
	if(T != NULL)
	{
		if(abs((height(T->lchild))-(height(T->rchild))) <= 1)return (checkBalance(T->lchild) && checkBalance(T->rchild));
		else return false;
	}
	else return true;
}

avlptr path(avlptr T, int x)
{
	if(T != NULL)
	{
		avlptr T2 = T;
		while(T2->data != x && T2 != NULL)
		{
			if(x > T2->data) T2 = T2->rchild;
			else if(x < T2->data) T2= T2->lchild;
			if(T2 == NULL) break;
		}
		if(T2 != NULL && T2->data == x) return T;
		else return NULL;
	}
	else return NULL;
}

void rotateSingle1(avlptr K3, avlptr K1, avlptr K2, avlptr parent)
{
	K3->rchild = K1->lchild;
	K1->lchild = K3;
	if(parent != NULL)
    {
        if(parent->lchild == K3) parent->lchild=K1;
    	else if(parent->rchild == K3) parent->rchild=K1;
    }
}

void rotateSingle2(avlptr K3, avlptr K1, avlptr K2, avlptr parent)
{
	K3->lchild = K1->rchild;
	K1->rchild = K3;
	if(parent != NULL)
    {
    	if(parent->rchild == K3) parent->rchild=K1;
       	else if(parent->lchild == K3) parent->lchild=K1;
    }
}

void rotateDouble1(avlptr K3, avlptr K1, avlptr K2, avlptr parent)
{
	K3->rchild = K2->lchild;
	K2->lchild = K3;
	K1->lchild = K2->rchild;
	K2->rchild = K1;
	if(parent != NULL)
    {
    	if(parent->lchild == K3) parent->lchild=K2;
    	else if(parent->rchild == K3) parent->rchild=K2;
    }
}

void rotateDouble2(avlptr K3, avlptr K1, avlptr K2, avlptr parent)
{
	K3->lchild = K2->rchild;
	K2->rchild = K3;
	K1->rchild = K2->lchild;
	K2->lchild = K1;
	if(parent != NULL)
    {
        if(parent->rchild == K3) parent->rchild=K2;
       	else if(parent->lchild == K3) parent->lchild=K2;
    }
}

void balance(avlptr &T, int x)
{
	if(checkBalance(T)) return;
	else
	{
		stack S; S.node = NULL;
		avlptr temp = T, K3, K2, K1, parent;
		while(temp->data != x && temp != NULL)
		{
			push(S, temp);
			if(x > temp->data) temp = temp->rchild;
			else if(x < temp->data) temp= temp->lchild;
		}
		push(S, temp);

		while(checkBalance(S.node->data) && S.node != NULL) pop(S);

		K3 = pop(S);

		if(S.node != NULL) parent = pop(S);
		else parent = NULL;

		if(height(K3->lchild) > height(K3->rchild)) K1 = K3->lchild;
		else K1 = K3->rchild;

		if(path(K1->lchild, x) != NULL) K2 = K1->lchild;
		else K2 = K1->rchild;

		if( (x > K3->data) && (x > K1->data) )
		{
			rotateSingle1(K3, K1, K2, parent);
			if(parent == NULL) T = K1;
		}
		else if( (x < K3->data) && (x < K1->data) )
		{
			rotateSingle2(K3, K1, K2, parent);
			if(parent == NULL) T = K1;
		}
		else if( (x > K3->data) && (x < K1->data) )
		{
			rotateDouble1(K3, K1, K2, parent);
			if(parent == NULL) T = K2;
		}
		else if( (x < K3->data) && (x > K1->data) )
		{
			rotateDouble2(K3, K1, K2, parent);
			if(parent == NULL) T = K2;
		}
	}

}

//Create and delete
void create(avlptr &T, int x)
{
	add(T, x);
	balance(T, x);
}

avlptr deleteNode(avlptr root, int x)
{
	if(root != NULL)
	{
		if (root->data > x) root->lchild = deleteNode(root->lchild, x);

		else if (root->data < x) root->rchild = deleteNode(root->rchild, x);

		else
		{
			if (root->lchild == NULL) return root->rchild;

			else if (root->rchild == NULL) return root->lchild;

			root->data = inOrderSuccessor(root->rchild)->data;

			root->rchild = deleteNode(root->rchild, root->data);
		}

		if(!checkBalance(root))
		{
			int arr[50], i = 0;
			deepest(root, height(root), arr, i);
			for(int j = 0; j < i; j++) balance(root, arr[j]);
		}
		return root;
	}
}


//Tree printing
void inOrderPrint(avlptr T)
{
	if(T != NULL)
	{
		inOrderPrint(T->lchild);
		cout<<T->data;
		inOrderPrint(T->rchild);
	}
}

void preOrderPrint(avlptr T)
{
	if(T != NULL)
	{
		cout<<T->data<<" ";
		preOrderPrint(T->lchild);
		preOrderPrint(T->rchild);
	}
}

void levelPrint(avlptr T, int level)
{
	if(T != NULL)
	{
		if(level == 0) cout<<T->data<<" ";
		else
		{
			levelPrint(T->lchild, level-1);
			levelPrint(T->rchild, level-1);
		}
	}
}


int main()
{
	avlptr T = NULL;

	create(T, 1);
	create(T, 2);
	create(T, 3);
	create(T, 4);
	create(T, 5);
	create(T, 6);
	create(T, 7);
	create(T, 15);
	create(T, 14);
	create(T, 13);
	create(T, 12);
	create(T, 11);
	create(T, 10);
	create(T, 9);
	create(T, 8);

	cout<<endl;
	T = deleteNode(T, 12);
	levelPrint(T, 3);

	cout<<endl;
	T = deleteNode(T, 13);
	levelPrint(T, 3);

	return 0;
}
