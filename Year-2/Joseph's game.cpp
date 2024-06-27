#include<iostream>
#include<string>
#include<ctype.h>

using namespace std;

union u1
{
	int a;
	char b;
};

struct stru
{
	union u1 u;
	int tag;
};


class queue
{
	int s;
	int f;
	int r;
	struct stru A[100];

public:
	queue(int x = 100)
	{
		s = x;
		f = -1;
		r = -1;
	}
	int isempty()
	{
		if (f == -1)
			return 1;
		else
			return 0;
	}
	int isfull()
	{
		if ((r + 1) % s == f)
			return 1;
		else
			return 0;
	}

	void display()
	{
	if (f <= r)
		{
		for (int i = f; i <= r; i++)
		{
			if (A[i].tag == 1)
				cout << A[i].u.a << " ";
			else
				cout << A[i].u.b << " ";
			}
	}
		
		cout << endl;
	}
	void enqueue(stru x)
	{
		if (isfull() == 1)
		{
			cout << "Full Queue" << endl;
		}
		else
		{
			r = (r + 1) % s;

			A[r].tag = x.tag;
			if (x.tag == 1)
			{
				A[r].u.a = x.u.a;

			}
			else
			{
				A[r].u.b = x.u.b;
			}
			if (f == -1)
			{
				f = 0;
			}

		}
	}
	stru dequeue()
	{

		struct stru x;
		if (isempty() == 1)
		{
			x.tag = 0;
			return x;
		}
		else
		{
			struct stru x;
			
			x.tag = A[f].tag;

			if (A[f].tag == 1)
			{
				x.u.a = A[f].u.a;
			}
			if (A[f].tag == 2)
			{
				x.u.b = A[f].u.b;
			}
			
			if (r == f)
			{
				r = -1;
				f = -1;
			}
			else
			{
				f = (f + 1) % s;
			}
			return x;
		}
	}
	void evaluate()
	{
		while (f <= r)
		{
			//cout << "reaches" << endl;
			//display();
			if (f == r)
			{
				//cout << "End" << endl;
				if (A[r].tag == 1)
					cout << A[r].u.a << endl;
				else
					cout << A[r].u.b << endl;
				break;
			}
			else
			{
				if (A[f].tag==1)
				{
					if (A[f+1].tag ==1 && A[r].tag==2 )
					{
						struct stru p, q;
						p = dequeue();
						q = dequeue();
						char c = A[r].u.b;
						int d;
						//cout << f << ":" << r << endl;
						A[r].tag = 1;

						if (c == '+')
						{
							 d = (p.u.a + q.u.a);
						}
						 if (c == '-')
						{
							 d = (p.u.a - q.u.a);
						}
						if (c == '*')
						{
							 d = (p.u.a * q.u.a);
						}
						if (c == '/')
						{
							 d = ((float)p.u.a / q.u.a);
						}
						
						else
						{
							cout << "Shouldnt reach ehre" << endl;
						}
						A[r].u.a = d;
						//cout << d << endl;
						continue;
					}
					else
					{
						//cout << A[f].u.a << " :deeueue element" << endl;
						enqueue(dequeue());
					}
				}
				else
				{
					enqueue(dequeue());
				}
			}
		}
	}
};


int main()
{
	cout << "Enter Infix Expression" << endl;
	char x[100];
	cin >> x;
	cout << endl;
	//cout << "Entered expression:" << x << endl;
	int i;
	queue o(100);
	struct stru temp;

	for (i = 0; x[i] != '\0'; i++)//input epxression for evaluation into a queue
	{
		if (isdigit(x[i]))
		{
			temp.tag = 1;
			int m = (int)x[i]-'0';
			temp.u.a = m;
			o.enqueue(temp);
		}
		else
		{
			temp.tag = 2;
			temp.u.b = x[i];
			o.enqueue(temp);
		}
	}
	cout << endl;
	o.evaluate();
	return 0;
}