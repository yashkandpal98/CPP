#include<iostream>
using namespace std;
int main()
{
	int n,i,j,k,r,m=1;
	cout<<"Enter number of rows: ";cin>>n;r=n;
	for(i=1;i<=n;i++)
	{
		for(j=n;j>i;j--)
		{
			cout<<"@";
		}
 		for(k=1;k<2*i;k++)
		{
			if (k==2*i-1 && i!=n)
				cout<<m<<"@";
			else
				cout<<m;
			m++;
		}
		for(int m=1;m<n-i;m++)
		{
			cout<<"@";
		}
		cout<<endl;
	}
	for(i=n-1;i>0;i--)
	{
		for (k=1;k<n-i+1;k++)
		{
			cout<<"#";
		}
		for(j=1;j<2*i;j++)
		{
			if(j==2*i-1)
				cout<<m<<"#";
			else
				cout<<m;
			m++;
		}
		for(int m=1;m<n-i;m++)
		{
			cout<<"#";
		}
		cout<<endl;
	}
	return 0;
}
