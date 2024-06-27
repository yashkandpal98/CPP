#include<iostream>
using namespace std;
void swap(int &x,int &y)
{
    int t;
    t=x;
    x=y;
    y=t;
}
void create(int H[],int n,int k)
{
    H[n]=k;
    int i=n;
    int j=(n-1)/2;
    while(H[i]<H[j]&&j!=0)
    {
        swap(H[i],H[j]);
        i=j;
        j=(i-1)/2;
    }
}
void sort(int H[],int n)
{
    if(n>0)
    {
    cout<<H[0]<<endl;
    H[0]=H[n-1];
    int i=0;
    while(i<n)
    {
    if((2*i+1<(n-1))&&((2*i)+2<(n-1)))
    {
        if(H[i]>H[(2*i)+1]||H[i]>H[(2*i)+2])
        {
            if(H[(2*i)+1]>H[(2*i)+2])
            {
                swap(H[i],H[(2*i)+2]);
            }
            else
            {
                swap(H[i],H[(2*i)+1]);
            }
        }
    }
    else if((2*i)+1==(n-1))
    {
        if(H[i]>H[(2*i)+1])
        {
            swap(H[i],H[(2*i)+1]);
        }
        break;
    }
    else if((2*i)+2==(n-1))
    {
         if(H[i]>H[(2*i)+1]||H[i]>H[(2*i)+2])
        {
            if(H[(2*i)+1]>H[(2*i)+2])
            {
                swap(H[i],H[(2*i)+2]);
            }
            else
            {
                swap(H[i],H[(2*i)+1]);
            }
        }
        break;
    }
    i++;
    }
    sort(H,n-1);
    }
}
int main()
{
    int H[20];
    int n;
    int i=0 ;
    cout<<"Enter key \n";
    cin>>n;
    while(n!=-1)
    {
        create(H,i,n);
        cin>>n;
        i++;
    }
    sort(H,i);
return 0;
}
