//dec to bin
#include<iostream>
#include<string.h>
using namespace std;

string conv(int n, int base)
{
	string s="0123456789ABCDEF";
	string t="";//VIMP
	if(n<base)
		return(t+s[n]);//Cannot return as normal
	else
		return(conv(n/base,base)+s[n%base]);
}
int main()
{
	string s;
	int n,base;
	cout<<"Enter decimal number\n";
	cin>>n;
	cout<<"Enter base\n";
	cin>>base;
	s=conv(n,base);
	cout<<endl<<s<<endl;
	return(0);
}
