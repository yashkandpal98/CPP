#include<iostream>
using namespace std;
int main()
{
	int j=9;char a='Y', b;
	for(int i=1;i<=5;i++)
	{
		for(int k=1;k<i;k++)
		{
			cout<<" ";
		}
		for(int l=j;l>=1;l--)
		{
			b=char(a-j);
			if (i%2!=0)
			{
				cout<<a;
				a--;
			}
			else if(i%2==0)
			{
				cout<<b;
				b++;
			}
		}
		cout<<endl;
		j-=2;
		if(i%2==0)
			a=char(b-j);
	}
	
}
