#include<iostream>
using namespace std;

union u
{
	int data;
	struct mlnode *mlink;
};

typedef struct mlnode
{
	int tag;
	union u var;
	mlnode *next;
} *mptr;

bool isempty(mptr head)
{
	if(head->next==NULL) return true;
	else return false;
}

void addfirst(mptr &head, mptr &tail)
{
	mlnode *temp=new mlnode;
	cout<<"\neEnter tag value: ";cin>>temp->tag;
	if(temp->tag==1)
	{
		int x;
		cout<<"\nEnter element: ";cin>>x;cout<<endl;
		temp->var.data=x;
	}
	else
	{
		cout<<"Sublist:\n";
		mptr h1=NULL, t1=NULL;
		addfirst(h1, t1);
	}
	head=tail=temp;
}

void addend(mptr &head, mptr &tail)
{
	if(isempty(head)) addfirst(head, tail);
	else
	{
		mlnode *temp=new mlnode;
		cout<<"\n1. Enter integer\n2.Enter sublist\nEnter tag value: ";cin>>temp->tag;
		if(temp->tag==1)
		{
			int x;
			cout<<"\nEnter integer: ";cin>>x;cout<<endl;
			temp->var.data=x;
		}
		else
		{
			cout<<"Sublist:\n";
			mptr h1=NULL, t1=NULL;
			addfirst(h1, t1);
		}
		temp->next=NULL;
		tail->next=temp;
		tail=temp;
		
	}
}

void display(mptr &ml)
{
	if(ml->tag==1)
	{
		cout<<ml->var.data;
		if(ml->next!=NULL) display(ml->next);
	}
	else
	{
		display(ml->var.mlink);
		if(ml->next!=NULL) display(ml->next);
	}
}

char menu()
{
	char choice;

	cout<<"\t\tMENU:\n";
	cout<<"\n1. Add item next\n2. Add item in front\n3. Add item after another\n4. Remove item from front\n5. Remove item from end\n6. Show list\n7. Exit\n";
	cout<<"Enter choice: ";cin>>choice;cout<<endl;

	return choice;
}


int main()
{
	char choice;
	mptr head=NULL, tail=NULL;
	while (true)
	{
		choice=menu();
		if (choice=='1')
		{
			addend(head, tail);
		}
		else if (choice=='2')
		{
			display(head);
		}
		else if (choice=='3') 
		{
			break;
		}
		else cout<<"\nWrong choice\n";
	}
	
}
