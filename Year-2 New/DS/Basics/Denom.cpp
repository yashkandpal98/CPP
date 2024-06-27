#include<iostream>
using namespace std;

void denom(int d[], int n, int cost)
{
	if(cost > 0)
	{
		if(cost >= d[8-n])
		{
			cout<<d[8-n]<<" ";
			denom(d, n, cost-d[8-n]);
		}
		else
		{
			denom(d, n-1, cost);
		}
	}
	
}


int main()
{
	int d[8] = {200, 100, 50, 20, 10, 5, 2, 1}, cost;
	
	cout<<"Enter cost: "; cin>>cost; cout<<endl;
	
	denom(d, 8, cost);
}
