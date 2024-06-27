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
		if ((s == 0))
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
	void addbehind(int x)
	{
		lptr temp = new lnode;
		temp->a = x;
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
	void rec(lptr ptr1, lptr ptr2, int a, int b)
	{
		if (ptr1 == ptr2 || ptr1->next==ptr2)
		{
			cout << "Middle most element:" << ptr2->a << endl;
		}
		else
		{
			lptr ptr = ptr1;
			while (ptr->next != ptr2)
			{
				ptr = ptr->next;
			}
			ptr2 = ptr;
			ptr1 = ptr1->next;
			rec(ptr1, ptr2, ptr1->a, ptr2->a);
		}
	}
	void recmain()
	{
		rec(h, t, h->a, t->a);
	}
};


int main()
{
	ll o;
	int n;
	cout << "Enter number of elements" << endl;
	cin >> n;
	while (n > 0)
	{
		int x;
		cin >> x;
		o.addbehind(x);
		n--;
	}
	o.recmain();
	return 0;
}
