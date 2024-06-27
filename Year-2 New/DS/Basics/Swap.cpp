#include<iostream>
using namespace std;

void swap1(int x, int y)				//call by value
{
	x += y;
	y = x-y;
	x -= y;
	
	cout<<"After swap: "<<x<<" "<<y;
}


void swap2(int *x, int *y)				//call by pointer
{
	*x += *y;
	*y = *x-*y;
	*x -= *y;
	
	cout<<"After swap: "<<*x<<" "<<*y;
}


void swap3(int &x, int &y)				//call by reference
{
	x += y;
	y = x-y;
	x -= y;
	
	cout<<"After swap: "<<x<<" "<<y;
}


void swap4(const int &x, const int &y)	//call by constant reference
{
	int a = x;
	a += y;
	int b = a-y;
	a -= b;
	
	cout<<"After swap: "<<a<<" "<<b;
}


int main()
{
	int x = 3, y = 5;
	
	
//	cout<<"Before swap: "<<x<<" "<<y<<endl;
//	swap1(x, y);
//	
//	cout<<"\n\nBefore swap: "<<x<<" "<<y<<endl;
//	swap2(&x, &y);
//	
//	cout<<"\n\nBefore swap: "<<x<<" "<<y<<endl;
//	swap3(x, y);
	
	cout<<"\n\nBefore swap: "<<x<<" "<<y<<endl;
	swap4(x, y);
	cout<<"\nx, y value: "<<x<<" "<<y;
	
	return 0;
}
