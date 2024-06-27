#include<iostream>
using namespace std;
int main()
{
	int m, n, h, o;
	cout<<"Enter number: ";cin>>n;cout<<"Octal representation:\n";
	m=n;
	while(m!=0)
	{
		o=m%8;
		cout<<o;
		m/=8;
	}
	cout<<"\nHexadecimal repersentation:\n";
	m=n;
	while(m!=0)
	{
		h=m%16;
		switch(h)
		{
			case 10:
				cout<<"A";break;
			case 11:
				cout<<"B";break;
			case 12:
				cout<<"C";break;
			case 13:
				cout<<"D";break;
			case 14:
				cout<<"E";break;
			case 15:
				cout<<"F";break;
			default:
				cout<<h;break;
		}
		m/=16;
	}
	return 0;
}
