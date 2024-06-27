#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>

using namespace std;

void bin(int n)
{
	if(n<2)
	cout<<n;
	else
	{
		bin(n/2);
		cout<<n%2;
	}
}
int main()
{
	int n;
	cout<<"Enter decimal number\n";
	cin>>n;
	bin(n);
	return(0);
}
