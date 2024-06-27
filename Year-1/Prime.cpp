#include <iostream>
using namespace std;
int main()
{
	int m,n,flag;
	cout<<"Enter starting value: ";
	cin>>m;cout<<endl;
	cout<<"Enter ending value: ";
	cin>>n;cout<<endl;
	flag=0;
	while (m<n)
	{
		for(int i=2;i<m;i++)
		{
			if (m%i==0)
			{
				flag=1;
				break;
			}
			else
				flag=0;
		}
		if (flag==0)
		{
			cout<<m<<endl;
		}
		m++;
	}
}
