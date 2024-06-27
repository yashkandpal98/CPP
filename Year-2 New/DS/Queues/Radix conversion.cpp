#include<iostream>
using namespace std;


struct element
{
	int data;
	char rad;
};

struct queue
{
	int f, r, size;
	element e[50];
};


void enqueue(queue &q, element x)
{
	if((q.r+1)%q.size == q.f)
	{
		cout<<"Full";
	}
	else
	{
		if(q.r == -1)
		{
			q.f = 0;
		}
		q.r = (q.r+1)%q.size;
		q.e[q.r] = x;
	}
}

element dequeue(queue &q)
{
	element t;
	if(q.f == -1)
	{
		cout<<"Queue Empty";
	}
	else
	{
		t= q.e[q.f];
		if(q.f == q.r) q.f = q.r = -1;
		else q.f = (q.f+1)%q.size;
	}
	
	return t;
}

void display(element x)
{
	switch(x.rad)
	{
		case 'b':
			if(x.data != 0)
			{
				int y = x.data%2;
				x.data /= 2;
				display(x);
				cout<<y;
			}
			break;
		case 'p':
			if(x.data != 0)
			{
				int y = x.data%10;
				x.data /= 10;
				display(x);
				switch (y)
				{
					case 1:
						cout<<"One ";
						break;
					case 2:
						cout<<"Two ";
						break;
					case 3:
						cout<<"Three ";
						break;
					case 4:
						cout<<"Four ";
						break;
					case 5:
						cout<<"Five ";
						break;
					case 6:
						cout<<"Six ";
						break;
					case 7:
						cout<<"Seven ";
						break;
					case 8:
						cout<<"Eight ";
						break;
					case 9:
						cout<<"Nine ";
						break;
					case 0:
						cout<<"Zero ";
						break;
				}
			}
			break;
		case 'o':
			if(x.data != 0)
			{
				int y = x.data%8;
				x.data /= 8;
				display(x);
				cout<<y;
			}
			break;
		case 'x':
			if(x.data != 0)
			{	
				int y = x.data%16;
				x.data /= 16;
				display(x);
				switch(y)
				{
					case 10:
						cout<<"A";
						break;
					case 11:
						cout<<"B";
						break;
					case 12:
						cout<<"C";
						break;
					case 13:
						cout<<"D";
						break;
					case 14:
						cout<<"E";
						break;
					case 15:
						cout<<"F";
						break;
					default:
						cout<<y;
				}
			}
			break;
	}
}


int main()
{
	 queue q; element x;
	
	cout<<"Enter number of elements: ";cin>>q.size;
	q.f = q.r = -1;
	
	cout<<"\nRadix Key:\n'b'- Binary\n'p'- Print digits in words\n'o'- Octal\n'x'- Hexadecimal\n\nEnter elements:\n\n\n";
	for(int i = 0; i < q.size; i++)
	{
		cout<<"Element "<<i+1;
		cout<<"\nEnter number: "; cin>>x.data;
		cout<<"Enter radix: "; cin>>x.rad;
		enqueue(q,x);
		cout<<endl<<endl;
	}
	
	
	for(int i = 0; i < q.size; i++)
	{
		x = dequeue(q);
		cout<<"Element "<<i+1<<endl<<endl<<"Number: "<<x.data<<"\nConverted with radix: ";
		display(x);
		cout<<endl<<endl<<endl;
	}
}
