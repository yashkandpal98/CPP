#include<iostream>

using namespace std;

typedef struct lnode
{
	int data;
	lnode * next;
} *lptr;

class llist
{
	int size;

public:

	lptr head, tail;

	llist()
	{
		size = 0;
		head = tail = NULL;
	}

	void display()
	{
		if (head == NULL)
		{
			cout << "Linked List empty" << endl;

		}
		else
		{
			lptr p = new lnode();

			p = head;

			while (p != NULL)
			{
				cout << p->data<<","<<" ";
				p = p->next;
			}
		}
	}

	void addend(int x)
	{
		lptr p = new lnode();

		p->data = x;
		p->next = NULL;
		
		if (head == NULL)
		{
			head = p;
		}

		else
		{
			tail->next = p;
			tail = tail->next;
		}
		
		size++;
	}
	
	void addfront(int x)
	{
		lptr p = new lnode();
		p->data = x;
		if (head == NULL)
		{
			head = p;
		}
		else
		{
			p->next = head;
			head = p;
		}
		size++;
	}

	void deleteend()
	{
		if (head == NULL)
		{
			cout << "Linked List empty.\n";
		}
		else
		{
			lptr p = new lnode;
			p = head;
			if (tail == head)
			{
				head = tail = NULL;
			}
			else
			{
				while (p->next != tail)
				{
					p = p->next;
				}
				tail = p;
				tail->next = NULL;
			}
		}
	}

	void deletefront()
	{
		if (head == NULL)
		{
			cout << " Linked List empty.";
		}
		else
		{
			if (head == tail)
			{
				head = tail = NULL;
			}
			else
			{
				head = head->next;
			}
		}
	}
};


int main()
{
	llist obj;
	int n, i, a;

	cout << "Enter number of elements: "; cin >> n;

	cout << "Enter elements:\n";
	for (i = 0; i < n; i++)
	{
		cin >> a;
		obj.addend(a);
	}
	
	
	return 0;
}
