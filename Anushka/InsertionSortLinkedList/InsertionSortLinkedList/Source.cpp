#include<iostream>
#include<iomanip>
#include<stdlib.h>
#include<stdio.h>
#include<cmath>

using namespace std;

typedef struct lnode
{
	int a;
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
	void show()
	{
		if (h==NULL)
		{
			cout << "Linked list is empty" << endl;
		}
		else
		{
			lnode *ptr = new lnode;
			ptr = h;
			while (ptr->next != NULL)
			{
				cout << ptr->a << " ";
				ptr = ptr->next;
			}
			cout << ptr->a << endl;
		}
	}

	void add(int x)
	{
		lptr p = new lnode;
		lptr r;
		p->a = x;
		if (h == NULL)
		{
			h = p;
			t = h;
			h->next = NULL;
			return;
		}
		else if (h->a > x)
		{
			p->next = h;
			h = p;
			return;
		}
		else if (t->a < x)
		{
			t->next = p;
			t = p;
			t->next = NULL;
			return;
		}
		else
		{
			r = h;
			while (r->next != NULL)
			{
				if (r->a <= x && r->next->a > x)
				{
					p->next = r->next;
					r->next = p;
					break;
				}
				else
					r = r->next;
			}
			
		}
	}
	
};

int main()
{
	ll o;
	int A[100];
	int n;
	int i;
	cout << "Enter size" << endl;
	cin >> n;
	cout << "Input" << endl;
	for (i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		o.add(x);
	}

	/*for (i = 0; i < n; i++)
	{
		o.add(A[i]);
	}*/
	cout << endl;
	cout << "Sorted array:";
	o.show();
	cout << endl;
	return 0;
}	