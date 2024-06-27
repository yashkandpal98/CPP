//Number triangle
#include<iostream>
using namespace std;
int main()
{
	int n,i,j,k,r;
	cout<<"Enter number of rows: ";cin>>n;r=n;
	for(i=1;i<=n;i++)
	{
		for(j=n;j>i;j--)
		{
			cout<<" ";
		}
 	for(k=1;k<=i;k++)
		{
			cout<<k<<" ";
		}
		cout<<endl;
	}
	for(i=n-1;i>0;i--)
	{
		for (k=1;k<n-i+1;k++)
		{
			cout<<" ";
		}
		for(j=1;j<=i;j++)
		{
			cout<<j<<" ";
		}
		cout<<endl;
	}
}
