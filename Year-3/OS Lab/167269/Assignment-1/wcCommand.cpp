#include<iostream>
#include<fstream>

using namespace std;

int main()
{
	fstream fileRead;
	string s;
	string s2;
	int count = 0;

	cin>>s;

	fileRead.open(s.c_str(), ios::in);

	while(!fileRead.eof())
	{
		fileRead>>s2;
		count++;
	}

	fileRead.close();

	cout<<endl<<count-1<<endl;

	return 0;
}
