#include<iostream>
using namespace std;

typedef struct lnode
{
	int data;
	lnode *next;
}*lptr;

bool isempty(lptr head)
{
	if(head==NULL) return true;
	else return false;
}

char menu()
{
	char choice;

	cout<<"\t\tMENU:\n";
	cout<<"\n1. Add item\n2. Remove item\n3. Show list\n4. Exit\n";
	cout<<"Enter choice: ";cin>>choice;cout<<endl;

	return choice;
}

void insertfirst(lptr &head, lptr &tail, int x)
{
	lptr temp=new lnode;
	temp->data=x;
	temp->next=NULL;
	
	head=temp;
	tail=temp;
	
}

void enqueue(lptr &head, lptr &tail, int x)
{
	if(isempty(head))insertfirst(head, tail, x);
	else
	{
		lptr temp=new lnode;
		temp->data=x;
		temp->next=NULL;
		tail->next=temp;
		tail=temp;
	}
	
}

void dequeue(lptr &head, lptr &tail)
{
	if(isempty(head))cout<<"\nLinked list empty\n";
	/*else if(head==tail)
	{
		delete head;
		head=NULL;
		tail=NULL;
	}*/
	else
	{
		lptr temp=head;
		head=head->next;
		delete temp;
	}
}

void show(lptr current)
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
				cout<<"\nEnter number: ";cin>>x; enqueue(head, tail, x);
				break;

			case '2':
				dequeue(head, tail);
				break;

			case '3':
				show(head);
				break;

			case '4':
				return 0;
		}
		
	}


	return 0;
}
