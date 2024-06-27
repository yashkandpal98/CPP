#include<iostream>
#include<cstdlib>
using namespace std;

int d;

class queue
{
	public :
		int front,rear,size,a[50];
		void enque(int c);
		int delque();
		queue()
		{
			front=-1;
			rear=-1;
			size=50; 
		}
};

void queue::enque(int c)
{
	if((rear+1)%size==front) cout<<"full";

	else if(front==-1)
	{
		rear++;
		a[++front]=c;
	}

	else
	{
		rear=(rear+1)%size;
		a[rear]=c;
	}
}


int queue::delque()
{
	int d;
	if(front<=-1)
	{
		cout<<"empty";
		exit(1);
	}
	else if(front==rear)
	{
		d=a[front];
		front=-1;rear=-1;
		return d;
	}
	else
	{
		d=a[front];
		front=(front+1)%size;
		return d;
	}
}


int main()
{
	queue q;
	int e,f,i,j,k,l,m,n,p;
	
	cout<<"Enter no of integers: ";cin>>d;cout<<endl;
	int b[50];
	int c=0;
	
	cout<<"\nEnter the elements:\n"<<endl;
	for(i=0;i<d;i++)
	{
		cin>>e;
		q.enque(e);
	}
	
	for(i=d;i>0;i--)
	{
	    m=0;k=0;
	    for(j=0;j<i;j++)
	    {
	    	n=q.delque();                 
	    	if(m<n)                                   // IF MAXIMUM THEN BEFORE THEN STORE POSITION
		    {                                                //AND CHANGE     M     VALUE
			    k=j;
	    		m=n;
		    }
		    q.enque(n);
	    }
	    for(l=0;l<k;l++)
	    {
	       p=q.delque();              // GO TO THAT POSITION WHICH HAVE TO SHOW AND AGAIN
	       q.enque(p);                //STORE IN QUEUE
	    }
	    b[c++]=q.delque();
	}
	
	
	cout<<"\nSorted array:\n"<<endl;
	for (i=d-1;i>=0;i--)
		cout<<b[i]<<" ";
	return 0;
}
