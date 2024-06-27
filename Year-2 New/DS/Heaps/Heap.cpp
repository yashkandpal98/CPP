#include<iostream>
using namespace std;


void insert(int heap[], int i, int data)
{
    if(i > 0 && data < heap[(i-1)/2])
    {
        heap[i] = heap[(i-1)/2];
        insert(heap, (i-1)/2, data);
    }
    else heap[i] = data;
}


int main()
{
    int n = 9, x;
    /*cout<<"Enter number of elements: "; cin>>n;
    cout<<endl;*/
    
    int heap[n];
    
    /*for(int i = 0; i < n; i++)
    {
        cin>>x;
        insert(heap, i, x, n);
    }*/
    
    insert(heap, 5, 0);
    insert(heap, 9, 1);
    insert(heap, 3, 2);
    insert(heap, 6, 3);
    insert(heap, 2, 4);
    insert(heap, 4, 5);
    insert(heap, 8, 6);
    insert(heap, 1, 7);
    insert(heap, 7, 8);
    
    for(int i = 0; i < n; i++) cout<<heap[i]<<" ";
    

/*9
5 9 3 6 2 4 8 1 7
*/
/*
    1
  2   4
 3 6 5 8
9 7
*/
    
    return 0;
}
    
    
    
