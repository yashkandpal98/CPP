#include<iostream>
using namespace std;
void add(int &x, int &y)
{
	cout<<"Sum from function= "<<x+y;
	x+=10;y+=5;
}
int main()
{
	int a=5, b=6;
	cout<<"Sum from main= "<<a+b<<"\n";
	add(a,b);
	cout<<"\nSum from main after function= "<<a+b;
	return 0;
}
