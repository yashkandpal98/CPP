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

class llqueue
{
	int s;

public:
	lptr f, r;

	llqueue()
	{
		s = 0;
		f = r = NULL;
	}
	
	void enqueuell(int x)
	{
		lptr temp = new lnode;
		temp->a = x;
		if (f == NULL)
		{
			f = r = temp;
			r->next = NULL;
		}
		else
		{
			r->next = temp;
			temp->next = NULL;
			r = temp;
		}
		s++;
	}
	void dequeuell()
	{
		if (s <= 0)
			cout << "Linked list is empty" << endl;
		else
		{
			lptr temp = new lnode;
			temp = f;
			cout << "Element being deleted:" << temp->a << endl;

			if (r == f)
			{
				f->next = NULL;
				free(temp);
				f = r = NULL;
				s--;
			}
			else
			{
				f = f->next;
				temp->next = NULL;
				free(temp);
				s--;
			}
		}
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
			ptr = f;
			while (ptr->next != NULL)
			{
				cout << ptr->a << " ";
				ptr = ptr->next;
			}
			cout << ptr->a << endl;
		}
	}	
};

int main()
{
	llqueue o;
	char a = 'n';
	do
	{
		int ch;
		cout << "Enter choice" << endl;
		cout << "1.Enqueue 2.Dequeue 3.Display" << endl;
		cin >> ch;
		int x; int y, m;
		switch (ch)
		{
		case 1:cin >> x; o.enqueuell(x);
			break;
		case 2:	o.dequeuell();
			break;
		case 3:o.show();
			break;
		default:cout << "Inavlid input" << endl;
		}
		cout << "Do you want to continue?" << endl;
		cin >> a;
		cout << endl;
	} while (a == 'y');


	return 0;
}