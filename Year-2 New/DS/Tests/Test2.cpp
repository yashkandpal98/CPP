#include<iostream>
using namespace std;


void insert(int n, int a[10][10])
{
	for(int i = 0; i < n; i++) for(int j = 0; j < n; j++){
		cin>>a[i][j];
		cout<<"Edge between "<<i+1<<" and "<<j+1<<"\n";
	}
}


int main()
{
	int n;
	int a[10][10];
	cout<<"Enter number of vertices: "; cin>>n;
	
	cout<<"Enter edges:\n\n";
	insert(n, a);
	
	for(int i = 0; i < n; i++)
	{
	    for(int j = 0; j < n; j++)cout<<a[i][j]<<" ";
	    cout<<endl;
	}
	
	
	
}
