#include<iostream>
#include<cstring>
#include<string>
#include<iomanip>
#include<stdlib.h>
#include<stdio.h>
#include<cmath>

using namespace std;

typedef struct lnode
{
	int e;
	int c;
	lnode *next;
}*lptr;

class ll
{
	int s;

public:
	lptr h, t;//l1->front,l2->rear

	ll()
	{
		s = 0;
		h = t = NULL;
	}
	int isempty()
	{
		if (h == NULL)
			return 1;
		else
			return 0;
	}
	void show()
	{
		if (h == NULL)
		{
			cout << "Linked list is empty" << endl;
		}
		else
		{
			lnode *ptr = new lnode;
			ptr = h;
			while (ptr->next != NULL)
			{
				cout << ptr->e << ":" << ptr->c << endl;
				ptr = ptr->next;
			}
			cout << ptr->e << ":" << ptr->c << endl;
		}
	}
	void addbehind(int x,int y)
	{
		lptr temp = new lnode;
		temp->e = x;
		temp->c = y;
		if (h == NULL)
		{
			h = t = temp;
			h->next = NULL;
		}
		else
		{
			t->next = temp;
			temp->next = NULL;
			t = temp;
		}
		s++;
	}
	void removefront(int &x,int &y)
	{
		if (h == NULL && t == NULL)
		{
			cout << "Linked list is empty" << endl;
			
		}
		else
		{
			lptr temp = new lnode;
			temp = h;
			x = temp->e;
			y = temp->c;
			if (t == h)
			{
				h->next = NULL;
				free(temp);
				h = t = NULL;
				s--;
			}
			else
			{
				h = h->next;
				temp->next = NULL;
				free(temp);
				s--;
			}
		}
	}
	int top()
	{
		if (h == NULL)
			return -1;//empty
		else
			return h->e;
	}
};

int main()
{
	int A[100];
	ll L[3];
	int n;
	int i;
	i = 2;
	while (i > 0)
	{
		cout << "Enter no of terms" << endl;
		cin >> n;
		for (int j = 0; j < 100; j++)
			A[j] = 0;
		
		while (n > 0)
		{
			int e, c;
			cin >> e;
			cin >> c;
			A[e] = c;
			
			n--;
		}
		
		for (int k = 0; k < 100; k++)
		{
			if (A[k] != 0)
				L[i].addbehind(k, A[k]);
			else
				continue;
		}
		i--;
	}
	//L[2].show();
	//L[1].show();
	int e = 0, c = 0;
	int u=0, v=0;
	while (L[2].isempty() != 1 && L[1].isempty() != 1)
	{
		if (L[1].top() ==L[2].top())
		{
			L[1].removefront(u, v);
			L[2].removefront(e, c);
			L[0].addbehind(e, v + c);

		}
		else if (L[1].top() < L[2].top())
		{
			L[1].removefront(e, c);
			L[0].addbehind(e,c);
		}
		else
		{
			L[2].removefront(e, c);
			L[0].addbehind(e, c);

		}

	}
	if (L[2].isempty() != 1)
	{
		while (L[2].isempty() != 1)
		{
			L[2].removefront(e, c);
			L[0].addbehind(e, c);

		}

	}
	if (L[1].isempty() != 1)
	{
		while (L[1].isempty() != 1)
		{
			L[1].removefront(e, c);
			L[0].addbehind(e, c);

		}
	}

	cout << endl;
	cout << "Merged List:";
	cout << endl;
	L[0].show();
	cout << endl;
	return 0;
}