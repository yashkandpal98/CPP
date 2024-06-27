#include<iostream>
#include<fstream>
 using namespace std;
 
 int main()
 {
 	 int arr[20];
 	 int n,i,c,k;
 	 
     ofstream outf( "file1");
     cout<<"enter the total number of elements you want to enter";
     cin>>n;
     for( i=0; i<n; i++)
     {
     	 cout<<"enter the elements"<<endl;
     	 cin>>arr[i];
	 }



	cout<<"Sorting array using bubble sort technique...\n";
	for(i=0; i<(n-1); i++)
	{
		for(j=0; j<(n-i-1); j++)
		{
			if(arr[j]>arr[j+1])
			{
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
	 for(i=0; i<n; i++)
	 {
	 
	 	 outf<<ele[i]<<endl;
	 }
	
	 cout<<"enter the number of elements you want to enter in the second array";
	 cin>>r;
	 for(i=0; i<r; i++)
	 {
	 	 cin>>arr2[i];
	 }
	 
	 
	 for(i=0; i<(r-1); i++)
	{
		for(j=0; j<(r-i-1); j++)
		{
			if(arr[j]>arr[j+1])
			{
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
	 outf.close();
	 
	
	 ofstream outf("file 2")
	 cout<<"enter the number of elements you want to enter in the arr3";
	 cin>>l;
	 for(i=0; i<l; i++)	 
	 {
	 	cin>>arr3[i];
	 }
	 for(i=0; i<(l-1); i++)
	{
		for(j=0; j<(l-i-1); j++)
		{
			if(arr[j]>arr[j+1])
			{
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
	
	cout<<"enter the number of elements you want to enter in arr4"<<endl;
	cin>>d;
	for(i=0; i<d; i++)
	{
		 cin>>arr4[i];
	}
	for(i=0; i<(n-1); i++)
	{
		for(j=0; j<(n-i-1); j++)
		{
			if(arr[j]>arr[j+1])
			{
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
	outf.close();
	 
	
	 

 }
