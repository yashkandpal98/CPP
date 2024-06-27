#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int a, b, x, i=0, n, sum=0, j, k=0, term, c;
	int A[1000], B[10000];
	cout<<"Enter number: ";cin>>a;
	x=a;
	cout<<"Enter number to multiply: ";cin>>b;
	while (10)
	{
		A[i]=x%10;
		i++;
		x/=10;
		if(x==0)
		{
			break;
		}
	}
	n=i+1;
	B[k]=0;
	for(i=0; i<n; i++)
	{
		for(j=0; j<k; j++)
		{
			B[j]=0;
		}
		if(B[k]!=0)
		{
			c=pow(10,k);
			term=(b/c);
			B[k]+=(A[i]*term)%10;
			B[k+1]=(A[i]*term)/10;
			k++;
		}
	}
	for(i=0; i<k; i++)
	{
		cout<<B[i];
	}
}
