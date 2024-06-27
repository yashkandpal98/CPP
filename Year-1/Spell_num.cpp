#include <iostream>
using namespace std;
int main()
{
	int n,h,t,o;
	cout<<"Enter the number: ";
	cin>>n;
	cout<<endl;
	o=n%10;
	t=((n-o)/10)%10;
	h=((n-t-o)/100)%10;
	
	if (h!=0)
	{
	
		switch (h)
		{
			case 1:
				cout<<"One";
				break;
			case 2:
				cout<<"Two";
				break;
			case 3:
				cout<<"Three";
				break;
			case 4:
				cout<<"Four";
				break;
			case 5:
				cout<<"Five";
				break;
			case 6:
				cout<<"Six";
				break;
			case 7:
				cout<<"seven";
				break;
			case 8:
				cout<<"Eight";
				break;
			case 9:
				cout<<"Nine";
				break;
			default:
				break;
		}
		cout<<" Hundred ";
	}
	
	if (t!=1)
	{
		switch(t)
		{
			case 2:
				cout<<"Twenty";
				break;
			case 3:
				cout<<"Thirty";
				break;
			case 4:
				cout<<"Forty";
				break;
			case 5:
				cout<<"Fifty";
				break;
			case 6:
				cout<<"Sixty";
				break;
			case 7:
				cout<<"Seventy";
				break;
			case 8:
				cout<<"Eighty";
				break;
			case 9:
				cout<<"Ninety";
				break;
			default:
				break;
		}
		cout<<" ";
	}
	
	else
	{
		switch(o)
		{
			case 0:
				cout<<"Ten";
				break;
			case 1:
				cout<<"Eleven";
				break;
			case 2:
				cout<<"Twelve";
				break;
			case 3:
				cout<<"Thirteen";
				break;
			case 4:
				cout<<"Fourteen";
				break;
			case 5:
				cout<<"Fifteen";
				break;
			case 6:
				cout<<"Sixteen";
				break;
			case 7:
				cout<<"Seventeen";
				break;
			case 8:
				cout<<"Eighteen";
				break;
			case 9:
				cout<<"Ninteen";
				break;
			default:
				break;
		}
	}
	if (o!=0 && t!=1)
	{
		switch(o)
		{
			case 1:
				cout<<"One";
				break;
			case 2:
				cout<<"Two";
				break;
			case 3:
				cout<<"Three";
				break;
			case 4:
				cout<<"Four";
				break;
			case 5:
				cout<<"Five";
				break;
			case 6:
				cout<<"Six";
				break;
			case 7:
				cout<<"Seven";
				break;
			case 8:
				cout<<"Eight";
				break;
			case 9:
				cout<<"Nine";
				break;
			default:
				break;
		}
	}
	return 0;
}
