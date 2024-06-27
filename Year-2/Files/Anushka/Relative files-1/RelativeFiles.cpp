//DELIMITER FOR END OF FIELD:|
//DELIM FOR END OF RECORD:&

#include<iostream>
#include<fstream>
#include<string>
#include<cstring>

using namespace std;
struct Record
{
	char rno[4];
	char name[15];
	char age[10];
	
}S;

class Buffer
{
	private:
		int next;
	public:
		char *buf;
	Buffer()
	{
		next=-1;
		buf=new char;
	}
	void pack(Record S,int r)
	{
		int j;  
		   
			cout<<"\nEnter the roll number: ";
			cin>>S.rno;
			buf=S.rno;
			strcat(buf,"|");
			
			cout<<"\nEnter the name: ";
			cin>>S.name;
			strcat(buf,S.name);
			strcat(buf,"|");
			
			cout<<"\nEnter the age: ";
			cin>>S.age;
			strcat(buf,S.age);
			strcat(buf,"&");
			
		next=strlen(buf);
	}
	void unpack(Record &S1)
	{
	
		int i,l;
	    i=0;
		while(buf[i]!='|')
		{
		  S1.rno[i]=buf[i];
		  i++;	
		}
		
		S1.rno[i]='\0';
		l=strlen(S1.rno);
		l++;
		
		i=0;
		
		while(buf[l]!='|')
		{ 
		
		  S1.name[i]=buf[l];
		  
		  l++;
		  i++;	
		}
		S1.name[i]='\0';
		
		l++;
		i=0;
		while(buf[l]!='\0')
		{ 
		
		  S1.age[i]=buf[l];
		  
		  l++;
		  i++;	
		}
		S1.age[i]='\0';
		
		l++;
	
	}
	
}B1,B2,B3;


int main()
{
	Record S2,S3;
	fstream f;
	
	char a='y';
		int r=0;
		long pos;
		int r1,r2,r3,r4;
	do
	{
		cout<<"MENU"<<endl;
		cout<<"1.WRITE AND MODIFY 2.READ 3.SEARCH"<<endl;
		int ch;
		cin>>ch;
		switch(ch)
		{
		case 1:
			f.open("STUDENT.txt",ios::app);
			cout<<"\nEnter the number of records: ";
			int t;
			cin>>t;
			r=r+t;
			for(int k=0;k<t;k++)
			{
				B1.pack(S,r);
				f<<B1.buf;
			}
			f.close();
			
			f.open("STUDENT.txt",ios::binary|ios::out|ios::in|ios::ate);
			
			int rel;
			cout<<"\nEnter the relative position of where you want to write: ";
		     cin>>rel;
		     rel;
		     rel--;
		     r3=r;
		     r3++;
		     f.seekp(0,ios::beg);
		     f.seekp (((rel)*6));
		  	 B1.pack(S,r);
			 f<<B1.buf;
			f.close();
			break;
			
		case 2:
			f.open("STUDENT.txt",ios::in);
			//r1=r;
			//r2=r;
			f.seekg(0,ios::beg);
			while(!f.eof())
			{   
				f.getline(B2.buf,100,'&');
			
			  //  if(r>0)
			//	{
				cout<<"\n";
				B2.unpack(S2);
				cout<<"\nRoll number: "<<S2.rno;
				cout<<"\nName: "<<S2.name;
				cout<<"\nAge: "<<S2.age;
			//	r--;
		     //	}
			}
		   f.close();
			break;
			
		case 3:
			char roll[50];
	     cout<<"\n\nSearch a record using roll number\n";
	     cout<<"Enter the roll number: ";
	     cin>>roll;
	     f.open("STUDENT.txt",ios::in);
		 r4=r;
		while(!f.eof())
		{   
			f.getline(B2.buf,100,'&');
		
		    if(r4>0)
			{
			
			B2.unpack(S2);
			if(strcmp(S2.rno,roll)==0)
			{
			
			cout<<"\nRoll number: "<<S2.rno;
			cout<<"\nName: "<<S2.name;
			cout<<"\nAge: "<<S2.age;
			r4--;
		   }
	     	}
		}
		 f.close();
			    	
			
		}
		
		cout<<"Do you want to continue?"<<endl;
		cin>>a;
	}while(a=='y');
	/*
	int r;
	f.open("STUDENT.data",ios::out);
	cout<<"\nEnter the number of records: ";
		cin>>r;
		for(int k=0;k<r;k++)
		{
			B1.pack(S,r);
			f<<B1.buf;
		}
     int rel;
     cout<<"\nEnter the relative position of where you want to write: ";
     cin>>rel;
     rel;
     int r3=r;
     r3++;
     f.seekp(0,ios::end);
   long pos = f.tellp();
   f.seekp (pos-((r3-rel)*6));
  	B1.pack(S,r);
	f<<B1.buf;


	f.close();
	f.open("STUDENT.data",ios::in);
	char A[100];
	int r1=r,r2=r;
	int count=0;
	while(!f.eof())
	{   
		f.getline(B2.buf,100,'&');
	
	    if(r>0)
		{
		cout<<"\n";
		B2.unpack(S2);
		cout<<"\nRoll number: "<<S2.rno;
		cout<<"\nName: "<<S2.name;
		cout<<"\nAge: "<<S2.age;
		r--;
     	}
	}
   f.close();
	
	char roll[50];
     cout<<"\n\nSearch a record using roll number\n";
     cout<<"Enter the roll number: ";
     cin>>roll;
     ifstream f2;
     f.open("STUDENT.data",ios::in);

	while(!f.eof())
	{   
		f.getline(B2.buf,100,'&');
	
	    if(r1>0)
		{
		
		B2.unpack(S2);
		if(strcmp(S2.rno,roll)==0)
		{
		
		cout<<"\nRoll number: "<<S2.rno;
		cout<<"\nName: "<<S2.name;
		cout<<"\nAge: "<<S2.age;
		r1--;
	   }
     	}
	}
	 f.close();
	 Buffer B;
	ifstream f3;
     int s,y;
     f.open("STUDENT.data");
     f.seekg(0,ios::end);
     cout<<"\n";
      cout<<"\nEnter the relative position of the record: ";
	   cin>>y;
	   y--; 
     f.seekg(6*y,ios::beg);
     f.getline(B.buf,100,'&');
     B.unpack(S2);
	   	cout<<"\nRoll number: "<<S2.rno;
		cout<<"\nName: "<<S2.name;
		cout<<"\nAge: "<<S2.age;
     f.close();
     
 */
	return 0;
}