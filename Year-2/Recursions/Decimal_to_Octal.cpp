#include<iostream>
#include<cmath>
using namespace std;

int d2b(int x, int p)
{
	int a, s=0;
	if(x>0)
	{
		a=x%8;
		s+=a*pow(10,p)+d2b(x/8, p+1);
	}
	else return s;
}

int main()
{
	int x;
	cout<<"Enter number: ";cin>>x;cout<<endl;
	
	cout<<"\nOctal representation: "<<d2b(x, 0);
	
}
