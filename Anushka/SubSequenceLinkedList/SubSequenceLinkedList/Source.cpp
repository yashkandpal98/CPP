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
	int isempty()
	{
		if (h == t &&h == NULL)
			return 1;
		else
			return 0;
	}
	void removebehind()
	{
		if (h == NULL)
			cout << "Linked list is empty" << endl;
		else
		{
			lnode *ptr = new lnode;


			if (t == h)
			{
				ptr = t;

				cout << "Element being deleted:" << ptr->a << endl;
				ptr->next = NULL;
				free(ptr);
				h = t = NULL;
				s--;
			}
			else
			{
				ptr = h;
				while (ptr->next != t)
				{
					ptr = ptr->next;
				}
				cout << "Element being deleted:" << t->a << endl;
				t = ptr;
				ptr = t->next;
				t->next = NULL;
				free(ptr);
				s--;
			}
		}
	}

};
ll o, o1;
void rec(lptr ptr1, lptr ptr2, int c,int s)
{
	if (ptr1 == NULL)
		return;
	if (c == s)
	{
		cout << "Sum of sub seq:";
		o1.show();
		cout << endl;
		while (o1.isempty() != 1)
			o1.removebehind();

	}
	else if (c > s || ptr2 == NULL)
	{
		ptr1 = ptr1->next;
		ptr2 = ptr2->next;
		while (o1.isempty() != 1)
			o1.removebehind();
		c = 0;
		rec(ptr1, ptr2, c, s);
	}
	else
	{
		if (c<s && c + ptr2->a>s)
		{
			ptr2=ptr2->next;
		}
		else
		{
			c = c + ptr2->a;
		}
	}
	rec(ptr1, ptr2, c, s);
}
void recmain(int x)
{
	lptr r;
	r = o.h->next;
	rec(o.h,r, 0, x);
}

int main()
{
	ll o,o1;
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
		o.addbehind(x);
	}
	cout << "Sub seq" << endl;
	int x;
	cin >> x;
	recmain(x);

}