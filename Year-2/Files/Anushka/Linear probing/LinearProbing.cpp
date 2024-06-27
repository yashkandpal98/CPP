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
	
	int key()
	{
		Record S1;
		int i,l;
	    i=0;
		
		while(buf[i]!='|')
		{
		  S1.rno[i]=buf[i];
		  i++;	
		}
		
		S1.rno[i]='\0';
		int r=(int)S1.rno[0]-48;
		return r;
		
	}
	
}B1,B2,B3;

int n;

int hash(int k)//hashing function
{
	return k%n;
}

void create()
{
	fstream o;
	o.open("Record.txt",ios::out);
	o.close();
	o.open("Record.txt",ios::app);
	
	cout<<"Enter capacity of file:";
	cin>>n;
	cout<<endl;
	for(int i=0;i<n;i++)
	{
		o<<"     &";
	}
	o.close();
}

int read(int r)//returns recod position
{
	fstream f;
	Buffer B2;
	
	f.open("Record.txt",ios::in);
	f.seekg(0,ios::beg);
	f.seekg(r*6,ios::beg);
	
	f.getline(B2.buf,100,'&');
	f.close();
	
	if(B2.buf[0]!=' ')
	return 1;
	
	else
	return 0;
	/*int p=r;
	int c=0;
	
	while(!f.eof() && c<n)
		{   
			f.getline(B2.buf,100,'&');
			if(B2.buf[0]==' ')
			{
				cout<<"Position empty";
				return p;
			}
			p=(p+1)%n;
			c=(c+1)%n;
		}
	
	f.close();
	if(c==n)
	return -1;*/

}

void write(int r,Buffer &B)
{
	fstream o;
	o.open("Record.txt",ios::binary|ios::out|ios::in|ios::ate);
	o.seekp(0,ios::beg);
	o.seekp(r*6,ios::beg);
	
	o<<B.buf;
	
	o.close();	
}

void add(Buffer &B)
{
	
	int r=hash(B.key());
	int c=0;
	int pos=read(r);
	
	while(read(r)==1 && c!=n)
	{
		r=(r+1)%n;
		c++;
	}
	
	if(c<n)
	{
		write(r,B);	
		cout<<"Status:Record Added"<<endl;
	}
	
	else
	{
		cout<<"File capacity full"<<endl;
	}
	
	/*
	if(pos==-1)
	{
		cout<<"FULL"<<endl;
		o.close();

		return;
	}
	else
	{
	
		o.seekp(0,ios::beg);
		o.seekp(pos*6,ios::beg);
		o<<B.buf;
	}
	
	o.close();
*/
}

void display()
{
	Buffer B;
	
	fstream o;
	o.open("Record.txt",ios::in);
	o.seekg(0,ios::beg);
		
	while(!o.eof())
	{
		o.getline(B.buf,100,'&');
		if(B.buf[0]!=' ')
		{
		
		cout<<"\n";
		B.unpack(S);
		cout<<"\nRoll number: "<<S.rno;
		cout<<"\nName: "<<S.name;
		cout<<"\nAge: "<<S.age;
		}
		else
		{
			continue;
		}
	}
	
	o.close();
}

int search(int k)
{
	int c=0;
	int r=hash(k);
	Buffer B;
	ifstream o;
	o.open("Record.txt",ios::in);
	o.seekg(0,ios::beg);
		
	
	while(!o.eof() && c<n)
	{
		o.seekg(0,ios::beg);
		o.seekg(r*6,ios::beg);
		
		if(read(r)==1)
		{
			int pos=r;
			o.getline(B.buf,100,'&');
			
			if(B.key()==k)
				{
					cout<<"Found"<<endl;
					B.unpack(S);
					cout<<endl;
					cout<<"\nRoll number: "<<S.rno;
					cout<<"\nName: "<<S.name;
					cout<<"\nAge: "<<S.age;
					o.close();
					return pos;	
				}
		}
			r=(r+1)%n;
			c++;
		
	}
		o.close();

	return -1;	
}

void remove(int k)
{
	int r=search(k);
	if(r==-1)
		cout<<"Not found"<<endl;
	else
	{
		fstream o;
	o.open("Record.txt",ios::binary|ios::out|ios::in|ios::ate);
	o.seekp(0,ios::beg);
	o.seekp(r*6,ios::beg);
	
	o<<"     &";
	
	o.close();	
	}
}

int main()
{
	create();
	char a='y';
	do
	{
		int ch;
	cout<<"MENU"<<endl;
	cout<<"1.ADD 2.READ 3.SEARCH 4.DELETE"<<endl;
	cin>>ch;
	Buffer B1;
		
	switch(ch)
	{
		case 1:
		cout<<"\nEnter the number of records: ";
			int N;
			cin>>N;
			cout<<endl;
			for(int i=0;i<N;i++)
			{
				B1.pack(S,N);
				add(B1);
			}
		break;	
	
	case 2:display();break;
	case 3:cout<<"Enter key value:";int k;
		cin>>k;cout<<endl;
		search(k);
		break;
	case 4:cout<<"Key value to be deleted:";cin>>k;cout<<endl;
	remove(k);
	break;
	
	}
	
	
	cout<<endl<<"Do you want to coninute?"<<endl;
	cin>>a;		
	}while(a=='y');		
	return 0;
}
