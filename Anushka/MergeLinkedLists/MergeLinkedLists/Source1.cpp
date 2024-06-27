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
	int removefront()
	{
		int x;
		if (h == NULL && t == NULL)
		{
			//cout << "Linked list is empty" << endl;
			return -1;
		}
		else
		{
			lptr temp = new lnode;
			temp = h;
			x = temp->a;
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
			return x;
		}
	}
	int top()
	{
		if (h == NULL)
			return -1;//empty
		else
			return h->a;
	}
};

int main()
{
	int x;
	ll a, b, c;
	int m, n;
	int i;
	cout << "Size of first linked list:" << endl;
	cin >> m;
	while (m > 0)
	{
		cin >> x;
		a.addbehind(x);
		m--;
	}
	cout << "Size of second linked list:" << endl;
	cin >> n;
	while (n > 0)
	{
		cin >> x;
		b.addbehind(x);
		n--;
	}
	int g = 0;
	while (a.isempty() != 1 && b.isempty() != 1)
	{

		if (a.top() < b.top())
		{
			c.addbehind(a.removefront());
		}
		else
		{
			c.addbehind(b.removefront());
		}

	}
	if (a.isempty() != 1)
	{
		c.addbehind(a.removefront());

	}
	if (b.isempty() != 1)
	{
		c.addbehind(b.removefront());

	}

	cout << endl;
	cout << "Merged List:";
	c.show();
	cout << endl;
	return 0;
}