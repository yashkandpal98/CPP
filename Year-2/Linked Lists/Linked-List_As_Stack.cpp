#include<iostream>
#include<C:\Yash\Coding\C++\Year-2\Linked Lists\Linked-List_As_Queue.h>
using namespace std;

typedef struct node
{
	int data;
	node *next;
}*ptr;

bool isempty(ptr head)
{
	if(head==NULL) return true;
	else return false;
}

char menu1()
{
	char choice;

	cout<<"\t\tMENU:\n";
	cout<<"\n1. Add item\n2. Remove item\n3. Show list\n4. Exit\n";
	cout<<"Enter choice: ";cin>>choice;cout<<endl;

	return choice;
}

void insertfirst(ptr &head, ptr &tail, int x)
{
	ptr temp=new node;
	temp->data=x;
	temp->next=NULL;
	
	head=temp;
	tail=temp;
	
}

void push(ptr &head, ptr &tail, int x)
{
	if(isempty(head))insertfirst(head, tail, x);
	else
	{
		node *temp=new node;
		temp->data=x;
		temp->next=NULL;
		tail->next=temp;
		tail=temp;
	}
	
}

void pop(ptr head, ptr &tail)
{
	node *temp=new node;
	temp=head;
	if(temp->next==tail)
	{
		temp->next=NULL;
		tail=temp;
	}
	else pop(temp->next, tail);
}

void top(ptr head, ptr tail)
{
	if(isempty(head))cout<<"\nStack Empty\n";
	else
	{
		cout<<endl<<tail->data<<endl;
	}
}

void show(ptr current)
{
	if(isempty(current))cout<<"\nStack empty\n";
	else
	{
		cout<<"\nStack:\n\n";
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
	
	ptr head=NULL;
	ptr tail=NULL;

	while(true)
	{
		choice=menu1();
		
		switch (choice)
		{
			case '1':
				cout<<"\nEnter number: ";cin>>x; push(head, tail, x);
				break;

			case '2':
				pop(head, tail);
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
