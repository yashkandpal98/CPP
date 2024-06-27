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
	cout<<"\n1. Add item next\n2. Add item in front\n3. Add item after another\n4. Remove item from front\n5. Remove item from end\n6. Show list\n7. Add a sublist at the end\n8. Exit\n";
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

void insertfront(lptr &head, int x)
{
	lnode *temp=new lnode;
	temp->data=x;
	temp->next=head;
	head=temp;
}

void insertafter(lptr &head, int r, int x)
{
	int ref=0;
	lnode *temp=new lnode; temp=head;
	while(temp!=NULL)
	{
		if(temp->data==r)
		{
			ref=1;
			lnode *t2=new lnode;
			t2->data=x;
			t2->next=temp->next;
			temp->next=t2;
			break;
		}
		else
		{
			temp=temp->next; ref=0;
		}
	}
	
	if(ref==0)
	{
		cout<<"\nElement not matched\n";
	}
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

lptr search(lptr head, int x)
{
	lnode *temp= new lnode;
	temp=head;
	if (temp==NULL) return NULL;
	else if(temp->data==x) return temp;
	else search(temp->next, x);
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

void removemid(lptr &head, lptr &tail, int x)
{
	lnode *temp=new lnode;
	
	if(head->data==x)removefront(head, tail);
	else
	{
		temp=search(head, x);
		if(temp==NULL)cout<<"\nElement does not exist\n";

		while(temp->next!=NULL)
		{
			if(temp->next->data==x)
			{
				lnode *t2=new lnode;
				t2=temp->next->next;
				delete temp->next;
				temp->next=t2;
				cout<<"\nElement deleted\n";
				break;
			}
		}
	}
}

void removeend(lptr head, lptr &tail)
{
	lnode *temp=new lnode;
	temp=head;
	if(temp->next==tail)
	{
		cout<<"\nDeleted element is: "<<tail->data;
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
	lptr temp=NULL;

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
				cout<<"\nEnter element to delete: ";cin>>x;cout<<endl;
				removemid(head, tail, x);
				break;

			case '6':
				show(head);
				break;

			case '8':
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
