#include<iostream>
#include<fstream>

using namespace std;

int main()
{
	fstream file1, file2;
	int n=0;
	char c[3];
	
	file1.open("text1.txt",ios::in|ios::out);
	file1.seekp(2*4,ios::beg);
	
	while(file1!='|')
	{
		file>>c[n];
		c++
	}
	cout<<c;
	
	
	
	
	return 0;	
}
