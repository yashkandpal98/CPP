#include<iostream>
using namespace std;
int main()
{
	int n, i, j;
	cout<<"Enter number of elements: ";cin>>n;
	int A[n];
	cout<<"\nEnter the elements:\n";
	for(i=0; i<n; i++)
	{
		cin>>A[i];
	}
	cout<<"\nElements before sorting:\n";
	for(i=0; i<n; i++)
	{
		cout<<A[i]<<endl;
	}
	cout<<"Elements after sorting:\n";
	for(i=0; i<n; i++)
	{
		for(j=0; j<n-i-1; j++)
		{
			if(A[j]>A[j+1])
			{
				A[j]+=A[j+1];
				A[j+1]=A[j]-A[j+1];
				A[j]-=A[j+1];
			}
		}
	}
	for(i=0; i<n; i++)
	{
		cout<<A[i]<<endl;
	}
}
