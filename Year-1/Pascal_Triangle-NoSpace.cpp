#include<iostream>
using namespace std;
int main()
{
	int n, row, ncr=0, r   , j;
	cout<<"Enter number: ";cin>> row;
	for(n=0; n<row; n++)
	{
		for (r=0; r<=n; r++)
		{
			if(r==0 || n==0 || n==r)
			{
				ncr=1;
			}
			else
			{
				ncr*=(n-r+1)/r;
			}
			cout<< ncr<<" ";
		}
		cout<<endl;
	}
}
