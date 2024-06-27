#include<iostream>
#include<cstdlib>
using namespace std;

typedef struct bstnode
{
	bstnode *lchild, *rchild;
	int data;
} *bsptr;

void add(bsptr &root, int x)
{
	if (root == NULL)
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


void inOrderPrint(bsptr root)
{
	if (root != NULL)
	{
		inOrderPrint(root->lchild);
		cout<<root->data<<"\n";
		inOrderPrint(root->rchild);
	}
}


void preOrderPrint(bsptr root)
{
	if (root != NULL)
	{
		cout<<root->data<<"\n";
		preOrderPrint(root->lchild);
		preOrderPrint(root->rchild);
	}
}


void postOrderPrint(bsptr root)
{
	if (root != NULL)
	{
		preOrderPrint(root->lchild);
		preOrderPrint(root->rchild);
		cout<<root->data<<"\n";
	}
}


void printCurrentLevel(bsptr root, int level)
{
	if (level == 1)
	{
		if(root == NULL)cout<<"   ";
		else cout<<root->data<<" ";
	}
	
	else if (level > 1)
	{
		printCurrentLevel(root->lchild, level-1);
		printCurrentLevel(root->rchild, level-1);
	}
}

bsptr inOrderSuccessor(bsptr root)
{
	if(root->lchild != NULL)
	{
		root = inOrderSuccessor(root->lchild);
	}
	return root;
}


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


void levelOrderPrint(bsptr root)
{
	for (int i = 0; i < height(root); i++)
	{
		for (int j = i; j <= height(root)-1; j++)
		{
			if (j == 1)
			{
				cout<<"  ";
			}
			else cout<<" ";
		}
		printCurrentLevel(root, i+1);
		cout<<endl;
	}
}

void printLeafNodes(bsptr root)
{
	if(root != NULL)
	{
		if(root->lchild == NULL && root->rchild == NULL) cout<<root->data<<" ";
		else
		{
			printLeafNodes(root->lchild);
			printLeafNodes(root->rchild);
		}
	}
}

void printNonLeafNodes(bsptr root)
{
	if(root != NULL)
	{
		if(root->lchild != NULL || root->rchild != NULL)
		{
			printNonLeafNodes(root->lchild);
			cout<<root->data<<" ";
			printNonLeafNodes(root->rchild);
		}
	}
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
			free(root);
			return temp;
		}
		
		else if (root->rchild == NULL)
		{
			bsptr temp = root->lchild;
			free(root);
			return temp;
		}
		
		bsptr temp = inOrderSuccessor(root->rchild);
		
		root->data = temp->data;
		
		root->rchild = deleteNode(root->rchild, temp->data);
	}
	
	return root;
}


void storeSorted(bsptr root, int arr[], int &i)
{
	if (root != NULL)
	{
		storeSorted(root->lchild, arr, i);
		arr[i++] = root->data;
		storeSorted(root->rchild, arr, i);
	}
}


int main()
{
	bsptr root = NULL;
	
	add(root, 4);
	add(root, 2);
	add(root, 6);
	//add(root, 1);
	add(root, 3);
	//add(root, 5);
	add(root, 7);
	
	cout<<"Inorder printing:\n";
	inOrderPrint(root);
	cout<<"\n";
	
	cout<<"Preorder printing:\n";
	preOrderPrint(root);
	cout<<"\n";
	
	cout<<"Postorder printing:\n";
	postOrderPrint(root);
	cout<<"\n";
	
	cout<<"Height of tree= "<<height(root)-1<<endl;
	
	cout<<"Printing level 2:\n";
	printCurrentLevel(root, 2);
	cout<<endl;
	
	cout<<"Level order printing:\n";
	levelOrderPrint(root);
	cout<<endl;
	
	cout<<"Deleting 4\n\n";
	root = deleteNode(root, 4);
	
	cout<<"Level printing after deleting 4:\n";
	levelOrderPrint(root);
	cout<<endl;
	
	cout<<"Leaf nodes:\n";
	printLeafNodes(root);
	cout<<endl;
	
	cout<<"Non- leaf nodes:\n";
	printNonLeafNodes(root);
	cout<<endl;
	
	return 0;
}
