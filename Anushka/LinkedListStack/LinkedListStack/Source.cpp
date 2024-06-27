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

class stackll
{
	int s;

public:
	lptr L;//l1->front,l2->rear

	stackll()
	{
		s = 0;
		L  = NULL;
	}
	int isempty()
	{
		if (L == NULL)
			return -1;
		else
			return 0;
	}

	void push(int x)
	{
		lptr temp = new lnode;
		temp->a = x;
		if (L == NULL)
		{
			L  = temp;
			L->next = NULL;
		}
		else
		{
			lptr r;
			r = L;
			while(r->next!=NULL)
			{
				r = r->next;
			}
			r->next = temp;
			r = temp;
			r->next = NULL;
			
		}
		s++;//increementing size
	}

	int pop()
	{
		if (isempty() == -1)
			return -1;
		else
		{
			lnode *ptr = new lnode;
			lptr r;
			r = L;
			int x;
			if (L->next == NULL)
			{
				ptr = L;
				x = ptr->a;
				L = NULL;
				free(ptr);
				s--;
				return x;
			}
			else
			{ 
			while (r->next->next != NULL)
				{
					r = r->next;
				}
				ptr = r->next;
				r->next = NULL;
				int x = ptr->a;
				free(ptr);

				s--;
				return x;
		}
		}
	}
	int top()
	{
		if (isempty()==-1)
			return -1;
		else
		{
			lptr r;
			r = L;
			while (r->next!= NULL)
			{
				r = r->next;
			}
			int x = r->a;
			return x;

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
			ptr = L;
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
	stackll o;
	char a = 'n';
	do
	{
		int ch;
		cout << "Enter choice" << endl;
		cout << "1. Push 2. Pop 3. Display 4. Top" << endl;
		cin >> ch;
		int x; int y, m;
		switch (ch)
		{
		case 1:cin >> x; o.push(x);
			break;
		case 2:cout << o.pop() << endl;
			break;
		case 3:	o.show();
			break;
		case 4:cout << o.top() << endl;
			break;
		default:cout << "Inavlid input" << endl;
		}
		cout << "Do you want to continue?" << endl;
		cin >> a;
		cout << endl;
	} while (a == 'y');


	return 0;
}