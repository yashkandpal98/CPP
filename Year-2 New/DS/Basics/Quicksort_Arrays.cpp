#include<iostream>
using namespace std;


int partition(int a[], int low, int high)
{
	int l = low+1, h = high, p = a[low];
	
	while(l < h)
	{
		while(a[l]<p) l++;
		while(a[h]>p) h--;
		
		if(l < h)
		{
			a[l] += a[h];
			a[h] = a[l] - a[h];
			a[l] -= a[h];
		}
	}
	
	a[low] += a[h];
	a[h] = a[low] - a[h];
	a[low] -= a[h];
	
	return h;
}

void quicksort(int a[], int low, int high)
{
	if( low < high)
	{
		int j = partition(a, low, high);
		quicksort(a, low, j-1);
		quicksort(a, j+1, high);
	}
}


int main()
{
	int n;
	cout<<"Enter number of elements: "; cin>>n;
	int a[n];
	
	cout<<"\n\nEnter elements:\n";
	for(int i = 0; i < n; i++)
	{
		cin>>a[i];
	}
	
	cout<<"\nUnsorted list: ";
	for(int i = 0; i < n; i++)
	{
		cout<<a[i]<<" ";
	}
	
	quicksort(a, 0, n-1);
	
	cout<<"\nSorted List: ";
	for(int i = 0; i < n; i++)
	{
		cout<<a[i]<<" ";
	}
	
	return 0;
}
