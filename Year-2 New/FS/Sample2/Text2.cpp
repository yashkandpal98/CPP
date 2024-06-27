#include<iostream>
#include<fstream>
#include<string>
#include<stdio.h>
using namespace std;

int main()
{
	string line;
	ofstream file("text2.txt");
	if(file.is_open())
	{
		file<<"This is a line\n";
		file<<"This is another line\n";
	}
	file.close();
	
	ifstream file2("text2.txt");
	
	while(file2)
	{
		getline(file2,line);
		if(!file2.eof()) cout<<line<<endl;
		else break;
	}
	file2.close();
	
	fstream file3, file4;
	file3.open("text2.txt",ios::in);
	file3.unsetf(ios::skipws);
	file4.open("newfile.txt",ios::out);
	char ch;
	while(!file3.eof())
	{
		if(file3.tellg()==5) file4<<"Edit";
		
		else 
		{
			file3>>ch;
			file4<<ch;
		}
	}
	file3.close();
	file4.close();
	remove("text2.txt");
	rename("newfile.txt","text2.txt");
	
	fstream file5;
	file5.open("text2.txt",ios::in);
	
	while(file5)
	{
		getline(file5,line);
		if(!file5.eof())cout<<line<<endl;
		else break;
	}
	
	file5.close();
	
	return 0;
}
