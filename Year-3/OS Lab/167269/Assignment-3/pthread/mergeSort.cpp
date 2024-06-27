#include<bits/stdc++.h>
#include<pthread.h>

#define max 20
#define threadMax 4

using namespace std;

int a[max];
int part = 0;


void merge(int low, int mid, int high)
{
	int left[mid-low+1];
	int right[high-mid];
	
	int n1 = mid-low+1, n2 = high-mid, i, j;
	
	for(i = 0; i < n1; i++) left[i] = a[i+low];
	for(i = 0; i < n2; i++) right[i] = a[i+mid+1];
	
	
	int k = low;
	i = j = 0;
	
	while(i < n1 && j < n2)
	{
		if(left[i] <= right[j]) a[k++] = left[i++];
		else a[k++] = right[j++];
	}
	
	while(i < n1) a[k++] = left[i++];
	while(j < n2) a[k++] = right[j++];
}

void mergeSort(int low, int high)
{
	int mid = low+(high-low)/2;
	
	if(low < high)
	{
		mergeSort(low, mid);
		mergeSort(mid+1, high);
		merge(low, mid, high);
	}
}

void* mergeSort(void* arg)
{
	int threadPart = part++;
	
	int low = threadPart * (max/4);
	int high = (threadPart+1) * (max/4)-1;
	int mid = low + (high-low)/2;
	
	if(low < high)
	{
		mergeSort(low, mid);
		mergeSort(mid+1, high);
		merge(low, mid, high);
	}
}


int main()
{
	for(int i = 0; i < max; i++) a[i] = rand() % 100;
	
	cout<<"Unsorted array:\n";
	for(int i = 0; i < max; i++) cout<<a[i]<<" ";
	
	pthread_t thread[threadMax];
	
	for(int i = 0; i < threadMax; i++) pthread_create(&thread[i], NULL, mergeSort, (void*)NULL);
	
	for(int i = 0; i < 4; i++) pthread_join(thread[i], NULL);
	
	merge(0, (max/2-1)/2, max/2-1);
	merge(max/2, max/2+(max-1-max/2)/2, max-1);
	merge(0, (max-1)/2, max-1);
	
	cout<<"\n\nSorted array:\n";
	for(int i = 0; i < max; i++) cout<<a[i]<<" ";
	cout<<endl;
	
	return 0;
}
