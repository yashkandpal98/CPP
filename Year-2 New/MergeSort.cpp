#include<iostream>
using namespace std;

void merge(int *a[], int n)
{
	int a1[n/2], a2[n/2], l1=n/2, l2=n/2, i=0, j=0, k=0;
	
	for(i=0; i<n; i++)
	{
		if(i<n/2)
		{
			a1[i]=*a[i];
		}
		else
		{
			a2[i-(n/2)]=*a[i];
		}
	}
	
	i=0;
	if(l1>0 && l2>0)
	{
		merge(&a1,l1);
		merge(&a2,l2);
		
		while(i<l1 && j<l2 && k<n);
		{
			if(a1[i]<a2[j])
			{
				*a[k]=a1[i];
				i++;
				k++;
			}
			else if(a2[j]<a1[i])
			{
				*a[k]=a2[j];
				j++;
				k++;
			}
		}
		if(i<l1 && j==l2)
		{
		    *a[k]=a1[i];
		}
		else if(j<l2 && i==l1)
		{
		    *a[k]=a2[j];
		}
	}
	else
	{
		if(a1[0]<a2[0])
		{
			*a[0]=a1[0];
			*a[2]=a2[0];
		}
		else
		{
			*a[0]=a2[0];
			*a[1]=a1[0];
		}
	}
}

int main()
{
	int n, i;
	
	cout<<"Enter number of elements: ";cin>>n;
	int a[10];
	
	cout<<"\n\nEnter elements:\n";
	for(i=0; i<n; i++)
	{
		cin>>a[i];
	}
	
	cout<<"\n\nYour array:\n";
	for(i=0; i<n; i++)
	{
		cout<<a[i]<<endl;
	}
	
	cout<<"\nSorted array:\n";
	merge(&a,n);
	for(int i=0; i<n; i++)
	{
		cout<<a[i]<<endl;
	}
}
