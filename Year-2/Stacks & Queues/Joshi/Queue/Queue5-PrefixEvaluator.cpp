#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
using namespace std;

union element
{
	int a[50];
	char b[50];
};
struct queue
{
	int front;
	int rear;
	int size;
	int tag[50];
	union element u; 
};

bool isEmpty(queue &Q)
{
	return(Q.front==Q.rear && Q.front==-1);
}
bool isFull(queue &Q)
{
	return((Q.rear+1)%Q.size==Q.front);
}
void Enqueue(queue &Q,char a);
void Enqueue1(queue &Q,int a); 
int Dequeue1(queue &Q);
char Dequeue2(queue &Q);
void Evaluate(queue &Q,int p, int q, char r)
{
	cout<<"Evaluate "<<p<<r<<q<<endl;
	switch(r)
	{
		case '*':p=p*q;
				break;
		case '/':p=p/q;
				break;
		case '+':p=p+q;
				break;
		case '-':p=p-q;
				break;
	}			
	cout<<p<<endl;
	Enqueue1(Q,p);
}

int main()
{
	struct queue Q;
	Q.front=-1;
	Q.rear=-1;
	char exp[50];
	
	int p,q;
	char r;
	
	cout<<"Enter the prefix expression to evaluate\n";
	cin.getline(exp,50);
	Q.size=strlen(exp);
	for(int i=0;i<strlen(exp);i++)
	{
		Enqueue(Q,exp[i]);	
	}
	while(Q.rear!=Q.front)
	{
		if(Q.tag[Q.front]==0)
		{
			r=Dequeue2(Q);
			if(Q.tag[Q.front]==1)
			{
				p=Dequeue1(Q);
				if(Q.tag[Q.front]==1)
				{
					q=Dequeue1(Q);
					Evaluate(Q,p,q,r);
				}
				else
				Enqueue1(Q,p);
			}
			else
			Enqueue(Q,r);
		}
		else
		{
			p=Dequeue1(Q);
			Enqueue1(Q,p);
		}		
	}
	cout<<Q.u.a[Q.front];
	return(0);
}

void Enqueue(queue &Q,char a)
{
	int b;
	if(Q.front==-1)
		Q.front+=1;
	
	Q.rear+=1;
	
	if(Q.rear>=Q.size)
	Q.rear=0;
	
	if(isdigit(a))
	{
		Q.tag[Q.rear]=1;
		b=int(a);
		b=b-48;
		Q.u.a[Q.rear]=b;//IMP to use atoi
		cout<<"Enqueue "<<b<<endl;
	}
	else
		{
		Q.tag[Q.rear]=0;
		Q.u.b[Q.rear]=a;
		cout<<"Enqueue "<<a<<endl;
		}
}
int Dequeue1(queue &Q)
{
	int x;
		x=Q.u.a[Q.front];
		Q.u.a[Q.front]=0;
		Q.tag[Q.front]=2;
	
	if(Q.front==Q.rear)
	{
		Q.front=-1;
		Q.rear=-1;
	}
	else{
	Q.front+=1;
	if(Q.front>=Q.size)
	Q.front=0;
	}
	cout<<"Dequeue "<<x<<endl;
	return(x);
}
void Enqueue1(queue &Q,int a)
{
	if(Q.front==-1)
		Q.front+=1;
	
	Q.rear+=1;
	
	if(Q.rear>=Q.size)
	Q.rear=0;
		Q.tag[Q.rear]=1;
		Q.u.a[Q.rear]=a;
		cout<<"Enqueue "<<a<<endl;
}
char Dequeue2(queue &Q)
{
	char y;
	y=Q.u.b[Q.front];
//	Q.u.a[Q.front]='\0';
//	Q.tag[Q.front]=2;
	
	if(Q.front==Q.rear)
	{
		Q.front=-1;
		Q.rear=-1;
	}
	else{
	Q.front+=1;
	if(Q.front>=Q.size)
	Q.front=0;
	}
	cout<<"Dequeue2 "<<y<<endl;
	return(y);
	
}

