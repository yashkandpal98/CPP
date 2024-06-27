#include<iostream>
#include<fstream>
#include<string>
#include<cstring>

using namespace std;
struct Record
{
	char rno[4];
	char name[15];
	char age[3];
	char fptr[3];
	char bptr[3];	
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
	void pack(Record S)
	{
		int j;  
		   
			cout<<"Roll number: ";
			cin>>S.rno;
			buf=S.rno;
			strcat(buf,"|");
			
			cout<<"Name: ";
			cin>>S.name;
			strcat(buf,S.name);
			strcat(buf,"|");
			
			cout<<"Age: ";
			cin>>S.age;
			strcat(buf,S.age);
			strcat(buf,"|");
			
			
			strcat(buf,"-");
			strcat(buf,"|");
			
			strcat(buf,"-");
			
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
		
		while(buf[l]!='|')
		{ 
		
		  S1.age[i]=buf[l];
		  
		  l++;
		  i++;	
		}
		S1.age[i]='\0';
		l++;
		
		i=0;
		S.fptr[0]=buf[l];
		S.fptr[1]='\0';
		
		l=l+2;
		S.bptr[0]=buf[l];
		S.bptr[1]='\0';
		
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

int fold(char x)
{
	int r=(int)x-48;
		return r;
		
}

void returnlink(int &fp,int &bp,Buffer &B)
{
	B.unpack(S);

	
	if(S.fptr[0]!='-')
	fp=S.fptr[0]-'0';
	
	else
	{
	fp=-1;
	}
	
	if(S.bptr[0]!='-')
	bp=S.bptr[0]-'0';
	
	else
	{
	bp=-1;
	}
}

void editlink(int &fp,int &bp,Buffer &B)
{
	
	if(fp==-1)
	{
		
	}
	if(fp!=-1)
		{
		B.buf[6]=(char)(fp+48);
		
		}
	if(bp==-1)
	{
		
	}
	
	if(bp!=-1)
		{
		B.buf[8]=(char)(bp+48);
		}
}

int hash(int k)//hashing function
{
	return k%n;
}

void create()
{
	fstream o;
	o.open("Records.txt",ios::out);
	o.close();
	o.open("Records.txt",ios::app);
	
	cout<<"Enter capacity of file:";
	cin>>n;
	cout<<endl;
	for(int i=0;i<n;i++)
	{
		o<<"         &";
	}
	o.close();
}

int read(int r)//returns recod position
	{
		fstream f;
		Buffer B2;
		
		f.open("Records.txt",ios::in);
		f.seekg(0,ios::beg);
		f.seekg(r*10,ios::beg);
		
		int pos=r;
		f.getline(B2.buf,100,'&');
		f.close();
		
		if(B2.buf[0]!=' ')
		return pos;
		
		else
		return -1;	
	}
	
	void write(int r,Buffer &B)
	{
		fstream o;
		o.open("Records.txt",ios::binary|ios::out|ios::in|ios::ate);
		o.seekp(0,ios::beg);
		o.seekp(r*10,ios::beg);
		
		o<<B.buf;
		
		o.close();	
	}
	
	void add(Buffer &B)
	{
		fstream o;
		Buffer B1;
		int x=-1;
		int pl=-1, r=hash(B.key());
		int f,b;
		o.open("Records.txt",ios::binary|ios::out|ios::in|ios::ate);
		
		if(read(r)==-1)//if the position itself if empty
			{
			write(r,B);	
			}
			
		else
		{
			pl=r;
			int c=0;
			while(read(r)!=-1)
				{
					if(c==n)
					{
						cout<<"Full"<<endl;
						return;
					}
					o.seekg(0,ios::beg);
					o.seekg(r*10,ios::beg);
					o.getline(B1.buf,100,'&');
					returnlink(f,b,B1);
					
					if(f!=-1)
					{
						pl=r;
						r=(f)%n;
					}
					else
					{
						r=(r+1)%n;
					}
					c++;
				}
				
				x=-1;
				//cout<<x<<":"<<pl<<endl;
				editlink(x,pl,B);
				write(r,B);	
				
				o.seekg(0,ios::beg);
				o.seekg(pl*10,ios::beg);
				o.getline(B1.buf,100,'&');
			
				x=-1;
				//cout<<"Previosu link:"<<B1.buf<<endl;
				editlink(r,x,B1);
				//cout<<"Previosu link:"<<B1.buf<<endl;
				
				o.seekp(0,ios::beg);
				o.seekp(pl*10,ios::beg);
				o<<B1.buf;
				
		}
			
		
		o.close();
	}
	
	int search(int k)
	{
		fstream o;
		Buffer B1;
		int x=-1;
		int r=k%n;
		int f,b;
		o.open("Records.txt",ios::binary|ios::out|ios::in|ios::ate);
		int c=0;
			
		while(read(r)!=-1)
		{
			if(c==n)
			{
				return -1;
			}
			
			o.seekg(0,ios::beg);
			o.seekg(r*10,ios::beg);
			o.getline(B1.buf,100,'&');
			
			if(B1.key()==k)
			
			{
				cout<<"present"<<endl;
				B1.unpack(S);
				cout<<S.rno<<":"<<S.name<<":"<<S.age<<":"<<S.fptr<<":"<<S.bptr<<endl;
		
				return r;
			}
			
				returnlink(f,b,B1);
				
				if(f!=-1)
				{
					r=(f)%n;
				}
				else
				{
					r=(r+1)%n;
				}
			c++;
					
		}
			
		return -1;
	}
	
void remove(int k)
{
	fstream o;
	Buffer B1;
	int x=-1;
	int r=k%n;
	int f=-1,b=-1;
	o.open("Records.txt",ios::binary|ios::out|ios::in|ios::ate);
	
	int pos=search(k);
	
	if(pos==-1)
	cout<<"Cant be deleted"<<endl;
	
	else
	{
		o.seekg(pos*10,ios::beg);
		o.getline(B1.buf,100,'&');
		returnlink(f,b,B1);
		
		if(f==-1 && b==-1)
		{
			o.seekp(pos*10,ios::beg);
			o<<"         &";
			return;
		}
		
		else
		{
			int x=-1;
			
			if(b!=-1)
			{
			
			cout<<f<<":"<<b<<endl;
			o.seekg(0,ios::beg);//to edit backpointer
			o.seekg(b*10,ios::beg);
			o.getline(B1.buf,100,'&');
			
			if(f==-1)
			B1.buf[6]='-';
	
			if(f!=-1)
			B1.buf[6]=(char)(f+48);
			
			cout<<B1.buf<<endl;
			
			o.seekp(0,ios::beg);
			o.seekp(b*10,ios::beg);
			o<<B1.buf;
			}
			
			if(f!=-1)
			{
			cout<<f<<":"<<b<<endl;
			o.seekg(0,ios::beg);//to edit front pointer
			o.seekg(f*10,ios::beg);
			o.getline(B1.buf,100,'&');
			
			if(b==-1)
			B1.buf[8]='-';
	
			if(b!=-1)
			B1.buf[8]=(char)(b+48);
			
			cout<<B1.buf<<endl;
			
			o.seekp(0,ios::beg);
			o.seekp(f*10,ios::beg);
			o<<B1.buf;
			}
			
			o.seekp(0,ios::beg);//to edit current position
			o.seekp(pos*10,ios::beg);
			o<<"         &";
						
		}
	
	}
o.close();	
	
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
				B1.pack(S);
				add(B1);
			}
		break;	
	
	//case 2:display();break;
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

