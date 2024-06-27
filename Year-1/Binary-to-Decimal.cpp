#include<iostream>
#include<cmath>
using namespace std;
int b2d(long long int x, int p)
{
	int r, s=0;
	if (x>0)
	{
		r=x%10;
		s+=(r*pow(2,p))+b2d(x/10,p+1);
	}
	else
	{
		return s;
	}
}
int main()
{
	int n;
	cout<<"Enter binary number: ";cin>>n;
	cout<<"\nDecimal represention: "<<b2d(n,0)<<endl;
	return 0;
}
