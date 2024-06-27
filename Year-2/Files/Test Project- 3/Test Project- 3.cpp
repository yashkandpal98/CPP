#include<iostream>
#include<fstream>
#include<string.h>
#include<stdio>

using namespace std;

struct record
{
	char name[20];
	char number[20];
};

class Buffer
{
	private:
		n;
	
	public:
		char buf[42]; int i=0;
		Buffer()
		{
			n=-1;
		}
		
		void pack(record S)
		{
			cout<<"Enter name: ";cin>>S.name;
			strcpy(buf,S.name);
			strcat(buf,"|");
			
			cout<<"\nEnter number: ";cin>>S.number;cout<<endl;
			strcat(buf,S.number);
			strcat(buf,"#");
			
			n=strlen(buf);
		}
		
		void unpack(record S)
		{
			int l=1;
			while(buff[i]!='|')
			{
				S.name[i]=buf[i];
				i++;
				l++
			}
			
			i=0;
			
			while(buff[l]!='#')
			{
				S.name[i]=buf[l];
				i++;
				l++;
			}
			
			i=0;
		}
		
};

void Append()
{
	record S;
	Buffer B;
	
	int no;
	cout<<"\nEnter number of records to store: ";cin>>n;cout<<endl;
	fstream file;
	
	file.open("Record.txt",ios::out|ios::app)
	for(int i=1; i<=n; i++)
	{
		cout<<"\nRecord "<<i<<endl;
		B.pack(S);
		file<<B.buf;
		cout<<endl;
	}
	file.close();
}

void Mod()
{
	record S;
	Buffer B;
	
	fstream file;
	
	file.open("Record.txt",ios::out|ios::ate);
	int n;
	cout<<"\nEnter relative position of record to modify: ";cin>>n;cout<<endl;
	
	file.seekp(0,ios::beg);
	file.seekp(n*42,ios:;beg);
	B.pack(S);
	file<<B.buf;
}

void Search()
{
	record S;
	Buffer B;
	
	int n;
	cout<<"\nEnter relatove position of record to display: ";cin>>n;cout<<endl;
	fstream file;
	file.open("Record.txt",ios::in);
	
	file.seekg(0,ios::beg);
	file.seekg(n*42,ios::beg);
	
	while(file!='#')
	{
		file>>B.buf;
	}
	B.unpack(S);
	
	cout<<endl<<"\nName: "<<S.name<<endl;<<"Number: "<<S.number<<endl;
}

//Needs a delete function



