#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
using namespace std;

struct record
{
	char name[10];
	char number[10];
};

class Buffer
{
	private:
		int n;
	
	public:
		char *buf;
		
		Buffer()
		{
			n=-1;
			buf=new char;
		}
		
		void pack(record S)
		{
			cout<<"Enter name: ";cin>>S.name;
			strcpy(buf, S.name);
			strcat(buf,"|");
			
			cout<<"Enter number: ";cin>>S.number;
			strcat(buf, S.number);
			strcat(buf, "#");
			
			n=strlen(buf);
		}
		
		void unpack(record S)
		{
			int i=0, l=0;
			while(buf[i]!='|')
			{
				buf[i]=S.name[i];
				i++;
				l++;
			}
			
			S.name[i]='\0';
			l++;
			i=0;
			
			while(buf[l]!='#')
			{
				buf[l]=S.number[i];
				i++;
				l++;
			}
			
			S.number[i]='\0';
			l++;
		}
		
		int blength()
		{
			return n;
		}
};


void Append()
{
	record S;
	Buffer B;
	int n, i=0;
	fstream file;
	
	file.open("Test 1.txt",ios::app);
	
	cout<<"\nEnter number of records: ";cin>>n;
	
	for(i=0; i<n; i++)
	{
		B.pack(S);
		file<<B.buf;
	}
	file.close();
}

void Mod()
{
	record S;
	Buffer B;
	fstream f;
	int n, i, p, l;
	
	cout<<"Enter position of record: ";cin>>p;
	
	f.open("Test 2.txt",ios::in|ios::out|ios::ate);
	
	f.seekp(0,ios::beg);
	
	l=B.blength();
	
	
}

void Search()
{
	record S;
	Buffer B;
	fstream file;
	int n, i;
	
	file.open("Test 1.txt",ios::out);
	
	
}

int main()
{
	Buffer B;
	record S;
	
	B.pack(S);
	int n=B.blength();
	cout<<B.buf<<endl<<n; 
	return 0;
}
