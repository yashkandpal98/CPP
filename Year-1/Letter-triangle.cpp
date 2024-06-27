#include<iostream>
using namespace std;
int main()
{
	char a='A', b;
	int i, j, n;
	cout<<"Enter number of rows(max 26): "; cin>>n;
	for(i=1;i<=n;i++)
	{
		b=a;
		for(j=1;j<=i;j++)
		{
			cout<<b<<" ";
			b++;
		}
		cout<<endl;
	}
	return 0;
}
