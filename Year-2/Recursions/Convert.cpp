#include<iostream>
using namespace std;

void convert(int ,int);

int main()
{
	int n;
	
	cout<<"Enter the number"<<endl;
	cin>>n;
	
	cout<<"Binary: ";
	convert(n,2);
	cout<<endl;
	
	cout<<"Octal: ";
	convert(n,8);
	cout<<endl;
	
	cout<<"Hexadecimal: ";
	convert(n,16);
	return 0;
}

void convert(int n,int m)
{ 
	int r=n%m;
	
	if (n==0) return;
	convert(n/m,m);
	if (r<10) cout<<r;
	else 
	{
		char c=r-10+'A';
		cout<<c;
	}
}
