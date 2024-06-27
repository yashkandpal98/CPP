#include<iostream>
using namespace std;
int main()
{
	int mon[12]={31,28,31,30,31,30,31,31,30,31,30,31}, d, m, y, a;
	
	string s[]={"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
	
	cout<<"Enter year: ";cin>>y;cout<<endl;
	
	if(((y%4==0)&&(y%100!=0)) || (y%400==0))
	{
		mon[1]=29;
	}
	
	y-=1;
		
	a=(y+y/4+y/400-y/100+1)%7;
	cout<<a<<endl<<endl;
	
	
	for(int i=0; i<12; i++)
	{
		cout<<s[i]<<endl;
		cout<<"Sun\tMon\tTue\tWed\tThu\tFri\tSat"<<endl;
		
		for(int x=0; x<a; x++)
		{
			cout<<"\t";
		}
		
		for(int z=1; z<=mon[i]; z++, a++)
		{
			if(a>=7)
			{
				a=0;
				cout<<endl;
			}
			if(z<10)cout<<z<<"\t";
			else cout<<z<<"\t";
		}
		
		cout<<endl;
	}
	
	return 0;
}
