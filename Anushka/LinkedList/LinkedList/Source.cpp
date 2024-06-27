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
	void addfront(int x)
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
			temp->next = h;
			h = temp;
		}
		s++;//increementing size
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
	void removebehind()
	{
		if (h==NULL)
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
	void removefront()
	{
		if (h==NULL && t==NULL)
			cout << "Linked list is empty" << endl;
		else
		{
			lptr temp = new lnode;
			temp = h;
			cout << "Element being deleted:" << temp->a << endl;

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
	/*lptr search(int x)
	{
		if (s <= 0)
		{
			return NULL;
		}
		else
		{
		lptr temp = new lnode;
		temp = h;
		while (temp!=NULL)
		{
			if (temp->a == x)
			{
				return temp;
			}
			else
				temp = temp->next;
		}
		return NULL;
		}
	}*/
	lptr search(lptr temp,int x)
	{
		if (temp == NULL)
			return NULL;
		if (temp->a == x)
			return temp;
		else
			return search(temp->next, x);
	}
	
	void addafter(int x,int y)//add value x after y
	{
		lptr d = search(h, y);
		lptr temp = new lnode;
		temp->a = x;
		temp->next = d->next;
		d->next = temp;
		
	}
};

int main()
{
	ll o;
	char a = 'n';
	do
	{
		int ch;
		cout << "Enter choice" << endl;
		cout << "1. Addfront 2. Addback 3. Removefront 4. Removeback  6. Show  7.Search 8.Addafter" << endl;
		cin >> ch;
		int x; int y, m;
		switch (ch)
		{
		case 1:cin >> x; o.addfront(x);
			break;
		case 2:cin >> x; o.addbehind(x);
			break;
		case 3:	o.removefront();
			break;
		case 4:o.removebehind();
			break;
		case 6:o.show();
			break;
		case 7:cin >> x; lptr t; t = o.search(o.h,x); 
			if (t == NULL)
				cout << "Absent" << endl;
			else
			{
				cout << "Element returned:" << t->a << endl;
			}
			break;
		case 8:cin >> x; int z;
			cin >> z;
			o.addafter(x, z);
			break;
		default:cout << "Inavlid input" << endl;
		}
		cout << "Do you want to continue?" << endl;
		cin >> a;
		cout << endl;
	} while (a == 'y');


	return 0;
}