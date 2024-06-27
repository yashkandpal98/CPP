#include<iostream>
using namespace std;

typedef struct lnode
{
	int data;
	lnode *next;
}*lptr;

bool isempty(lnode *head)
{
	if(head==NULL) return true;
	else return false;
}

char menu()
{
	char choice;

	cout<<"\t\tMENU:\n";
	cout<<"\n1. Add item next\n2. Add item in front\n3. Add item after another\n4. Remove item from front\n5. Remove item from end\n6. Show list\n7. Add a sublist at the end\n8.Delete alternate elements\n9. Exit\n";
	cout<<"Enter choice: ";cin>>choice;cout<<endl;

	return choice;
}

void insertfirst(lnode *&head, lnode *&tail, int x)
{
	lnode *temp=new lnode;
	temp->data=x;
	temp->next=NULL;
	
	head=temp;
	tail=temp;
	
}

void insertend(lptr &head, lptr &tail, int x)
{
	if(isempty(head))insertfirst(head, tail, x);
	else
	{
		lnode *temp=new lnode;
		temp->data=x;
		temp->next=NULL;
		tail->next=temp;
		tail=temp;
	}
	
}

void insertend1(lptr &head, lptr &tail, lptr &h1, lptr &t1)
{
	if(isempty(head))
	{
		head=h1;
		tail=t1;
	}
	else
	{
		tail->next=h1;
		tail=t1;
	}
	
}

void insertfront(lptr &head, int x)
{
	lnode *temp=new lnode;
	temp->data=x;
	temp->next=head;
	head=temp;
}

lptr search(lptr head, int x)
{
	lnode *temp= new lnode;
	temp=head;
	int count;
	while(temp!=NULL)
	{
		if(temp->data==x) return temp;
		else return search(temp->next, x);
	}
	return NULL;
}

void insertafter(lptr &head, int r, int x)
{
	int ref=0;
	lnode *temp=new lnode; temp=head;
	while(temp!=NULL)
	{
		if(temp->data==r)
		{
			lnode *t2=new lnode;
			t2->data=x;
			t2->next=temp->next;
			temp->next=t2;
		}
	}
	
}

void removefront(lnode *&head, lnode *&tail)
{
	if(isempty(head))cout<<"\nLinked list empty\n";
	else if(head==tail)
	{
		delete head;
		head=NULL;
		tail=NULL;
	}
	else
	{
		lnode *temp=head;
		head=head->next;
		cout<<"\nDeleted Element is: "<<temp->data<<endl;
		delete temp;
	}
}

void del(lptr &L)
{
	lnode *temp=new lnode;
	temp=L;
	if(L!=NULL)
	{
		L=L->next;
		delete temp;
		del(L->next);
	}
	else return;
}

void removeend(lptr head, lptr &tail)
{
	lnode *temp=new lnode;
	temp=head;
	if(temp->next==tail)
	{
		temp->next=NULL;
		tail=temp;
	}
	else removeend(temp->next, tail);
}

void show(lnode *current)
{
	if(isempty(current))cout<<"\nLinked list empty\n";
	else
	{
		cout<<"\nLinked list:\n\n";
		while(current!=NULL)
		{
			cout<<current->data<<endl;
			current=current->next;
		}
	}
}


int main()
{
	
	int x; char choice;
	
	lptr head=NULL;
	lptr tail=NULL;

	while(true)
	{
		choice=menu();
		
		switch (choice)
		{
			case '1':
				cout<<"\nEnter number: ";cin>>x; insertend(head, tail, x);
				break;

			case '2':
				cout<<"\nEnter number to insert: ";cin>>x;insertfront(head, x);
				break;
			
			case '3':
				cout<<"\nEnter number to insert: ";cin>>x;
				int ref; cout<<"\nEnter number to insert after: "; cin>>ref;
				insertafter(head, ref, x);
				break;
			
			case '4':
				removefront(head, tail);
				break;
			case '5':
				removeend(head, tail);
				break;

			case '6':
				show(head);
				break;

			case '8':
				del(head);
				break;

			case '9':
				return 0;

			case '7':
				int n;
				cout<<"\nEnter number of elements in linked sublist: ";cin>>n;
				lptr h1=NULL;
				lptr t1=NULL;
				cout<<"\nEnter elements:\n";
				for(int i=0; i<n; i++)
				{
					cin>>x;
					insertend(h1, t1, x);
				}
				insertend1(head, tail, h1, t1);
		}
		
	}


	return 0;
}
