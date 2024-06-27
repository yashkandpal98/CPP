#include<iostream>
#include<fstream>
#include<string>
#include<stdio.h>
using namespace std;

int main()
{
	fstream file1, file2;
	file1.open("text1.txt", ios::in|ios::out|ios::ate);
	int x=file1.tellg();
	file1.seekg(0,ios::end);
	int y=file1.tellg();
	cout<<"File size: "<<y-x<<endl<<endl;
	file1.unsetf(ios::skipws);
	file2.open("newfile.txt",ios::in|ios::out|ios::app);
	char cha;
	while(!file1.eof())
	{
		file1>>cha;
		file2<<cha;
		if(file1.tellg()==3) file2<<"Edit";
	}
	remove("text1.txt");
	rename("newfile.txt","text1.txt");
	file1.close();file2.close();
	
	file1.open("text1.txt",ios::in);
	file1.unsetf(ios::skipws);
	while(!file1.eof())
	{	file1>>cha;
		if(file1.eof()) break;
		else cout<<cha;
	}
}
