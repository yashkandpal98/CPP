#include<iostream>
using namespace std;
int main()
{
	int i, n;
	cout<<"Enter number of elements: ";cin>>n;
	int A[n];
	for(i=0; i<n; i++)
	{
		cin>>A[i];
	}
	cout<<"\nElements of the array:\n";
	for(i=0; i<n; i++)
	{
		cout<<A[i];
	}
	return 0;
}
