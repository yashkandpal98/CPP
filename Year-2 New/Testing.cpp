#include<iostream>
using namespace std;

typedef struct node
{
	int data;
	node* next;
} *llist;

int main()
{
	llist head=new node;
	head->data=NULL;
	head->next=NULL;
	
	llist temp=new node;
	temp->data=1;
	temp->next=head;
	head=temp;
	
	llist t2=new node;
	t2=head;
	while(head->next!=NULL)
	{
		if(head->next==NULL)
		{
			delete head;
			break;
		}
		else head=head->next;
	}
	if(head==NULL)
	{
		cout<<"NULL";
	}
	else
	{
		while (head!=NULL)
		{
			cout<<head->data;
			head=head->next;
		}
	}
	return 0;
}
