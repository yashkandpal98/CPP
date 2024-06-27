#include<iostream>
using namespace std;


void merge(int a[], int l, int m, int h)
{
    int a1[(m-l+1)], b1[(h-m)], i, j, k = l;
    
    for( i = l; i <= m; i++) a1[i-l] = a[i];
    for( j = m+1; j <= h; j++) b1[j-m-1] = a[j];
    
    i = j = 0;
    
    while(i < m-l+1 && j < h-m)
    {
        if(a1[i] > b1[j]) a[k++] = b1[j++];
        else if(a1[i] < b1[j]) a[k++] = a1[i++];
        else a[k++] = a1[i++] = b1[j++];
    }
    
    if(i < m-l+1) while(i < m-l+1) a[k++] = a1[i++];
    if (j < h-m-1) while(j < h-m) a[k++]= b1[j++];
}

void mergeSort(int a[], int l, int h)
{
    if(l < h)
    {
        int m = (l+h)/2;
        mergeSort(a, l, m);
        mergeSort(a, m+1, h);
        merge(a, l, m, h);
    }
}


int main()
{
    int n;
    cout<<"Enter number of elements: "; cin>>n;
    int a[n];
    
    cout<<"\nEnter elements:\n";
    for(int i = 0; i < n; i++)cin>>a[i];
    
    cout<<"\nUnsorted list: ";
    for(int i = 0; i < n; i++) cout<<a[i]<<" ";
    
    cout<<endl;
    mergeSort(a, 0, n-1);
    
    cout<<"\nSorted list: ";
    for(int i = 0; i < n; i++) cout<<a[i]<<" ";
    
    return 0;
}
