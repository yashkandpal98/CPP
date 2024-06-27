#include<iostream>
#include<cmath>
using namespace std;


//Structures
struct s
{
	int freq;
	char c;
};

union u
{
	s info;
	int total; 
};

typedef struct hnode
{
	string code;
	int tag;				//1 for total 0 for information
	u data;
	hnode *lchild, *rchild;
} *hptr;

typedef struct lnode
{
	hptr tree;
	lnode *next;
} *lptr;

struct queue
{
	lptr f, r;
};


//Queue Operations
int size(lptr L)
{
	if(L != NULL)return (1+size(L->next));
	else return 0;
}

void addfirst(lptr &L, hptr x)
{
	lptr T = new lnode;
	T->tree = x;
	T->next = L;
	L = T;
}

void addend(lptr &L, hptr T)
{
	if(L == NULL)
	{
		lptr temp = new lnode;
		temp->tree = T;
		temp->next = NULL;
		L = temp;
	}
	else addend(L->next, T);
}

hptr deletefront(lptr &L)
{
	if(L != NULL)
	{
		hptr temp = L->tree;
		L = L->next;
		return temp;
	}
}

void addafter(lptr &L, hptr x, hptr y )
{
	if(L == NULL ) addend(L, y);
	
	else if(L->tree == x)
	{
		lptr T = new lnode;
		T->tree = y;
		T->next = L->next;
		L->next = T;
	}
		
	else addafter(L->next, x, y);
}

void addbefore(lptr &L, hptr x, hptr y)
{
	if(L == NULL) addend(L, y);
	
	else if(L->tree == x) addfirst(L, y);
	
	else if(L->next->tree == x) addafter(L, L->tree, y);
	
	else addbefore(L->next, x, y);
}

lptr rear(lptr &f)
{
	if(f != NULL)
	{
		if(f->next == NULL) return f;
		else return(rear(f->next));
	}
	else return f;
}

void enqueue(queue &Q, hptr T)
{
	
	if(Q.f == NULL)
	{
		addend(Q.f, T);
		Q.r = Q.f;
	}
	else
	{
		addend(Q.r, T);
		Q.r = Q.r->next;
	}
}

void enqueue(lptr &L, hptr x)
{
	if(L == NULL) addfirst(L, x);
	else
	{
		if(x->tag == 0)
		{
			if(L->tree->tag == 0)
			{
				if(x->data.total <= L->tree->data.total) addbefore(L, L->tree, x);
				else enqueue(L->next, x);
			}
			else
			{
				if(x->data.total <= L->tree->data.info.freq) addbefore(L, L->tree, x);
				else enqueue(L->next, x);
			}
		}
		else
		{
			if(L->tree->tag == 0)
			{
				if(x->data.total <= L->tree->data.total) addbefore(L, L->tree, x);
				else enqueue(L->next, x);
			}
			else
			{
				if(x->data.total <= L->tree->data.info.freq) addbefore(L, L->tree, x);
				else enqueue(L->next, x);
			}
		}
	}
}

hptr dequeue(queue &Q)
{
	if(Q.f != NULL)
	{
		if(Q.f == Q.r) Q.r = NULL;
		return(deletefront(Q.f));
	}
	else cout<<"\nEmpty\n";
}

//Huffman compression
hptr create(queue &Q)
{
	if(size(Q.f) > 1)
	{
		int x, y;
		
		hptr T1 = dequeue(Q);
		if(T1->tag == 0) x = T1->data.info.freq;
		else x = T1->data.total;
		
		hptr T2 = dequeue(Q);
		if(T2->tag == 0) y = T2->data.info.freq;
		else y = T2->data.total;
		
		hptr T = new hnode;
		T->tag = 1;
		T->data.total = x+y;
		T->lchild = T1;
		T->rchild = T2;
		
		enqueue(Q.f, T);
		rear(Q.r);
		
		return create(Q);
	}
	else return Q.f->tree;
}

hptr add(s x)
{
	hptr T = new hnode;
	T->tag = 0;
	T->data.info.c = x.c;
	T->data.info.freq = x.freq;
	T->lchild = T->rchild = NULL;
	return T;
}

void code(hptr &T, string s)
{
	if(T != NULL)
	{
		if(T->tag == 0) T->code += s;
		code(T->lchild, s+'0');
		code(T->rchild, s+'1');
	}
}

void print(hptr T)
{
	if(T != NULL)
	{
		print(T->lchild);
		if(T->tag == 0) cout<<T->data.info.c<<" "<<T->data.info.freq<<" "<<T->code<<endl;
		print(T->rchild);
	}
}


int main()
{
	queue Q; Q.f = NULL; Q.r = NULL;
    
    string str;
    //cout<<"Enter string to be compressed: "; cin>>str;
    str = "Hello. How are you?";
    
	int x = str.size(), i = 0, flag = 0;
    s arr[x];
    
    for(int j = 0; j < x; j ++)
    {
    	int count = 1;
    	if(str[j] == '@') continue;
    	arr[i].c = str[j];
    	for(int k = j+1; k < x; k++)
    	{
    		if(str[k] == str[j])
    		{
    			count++;
    			str[k] = '@';
			}
		}
		arr[i].freq = count;
		i++;
	}
	
	for(int j = 0; j < i; j++)
	{
		for(int k = j+1; k < i; k++)
		{
			if(arr[k].freq < arr[j].freq)
			{
				s temp = arr[j];
				arr[j] = arr[k];
				arr[k] = temp;
			}
		}
	}
	
	for(int j = 0; j < i; j++) enqueue(Q, add(arr[j]));
	
	hptr T = create(Q);
	
	code(T, "");
	
	print(T);
	
	return 0;
}


