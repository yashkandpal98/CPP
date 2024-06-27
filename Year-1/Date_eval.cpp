#include<iostream>
using namespace std;
int main()
{
	int d, m, y, pd, pm, py, nd, nm, ny;
	bool ValidDate;
	cout<<"Enter date: ";cin>>d;
	cout<<"\nEnter month: ";cin>>m;
	cout<<"\nEnter year: ";cin>>y;
	if ((y>0 && y<=2015) && (m>=1 && m<=12))
	{
		if (d>=1 && d<=31)
		{
			if (m==1 || m==3 || m==5 || m==7 || m==8 || m==10 || m==12)
			{
				ValidDate=true;
			}
		}
		else if (d>=1 && d<=30)
		{
			if (m==4 || m==6 || m==9 || m==11)
			{
				ValidDate=true;
			}
		}
		else if((d>=1 && d<=29) && m==2)
		{
			if (y%4==0)
			{
				ValidDate=true;
			}
		}
		else if((d>=1 && d<=28) && m==2)
		{
			if (y%4!=0)
			{
				ValidDate=true;
			}
		}
	}
	else
	{
		ValidDate=false;
	}
	if (ValidDate==true)
	{
		cout<<"\nDate is valid\n";
	}
	else
	{
		cout<<"\nDate is not valid\n";
	}
	pm=m; nm=m; pd=d; nd=d; py=y; ny=y;
	do
	{	
		if(d==31)
		{
			nd=1;
			if (m==12)
			{
				nm=1;
				ny+=1;
			}
			else
			{
				nm+=1;
			}
		}
		else if(d==30 &&(m==4 || m==6 || m==9 || m==11))
		{
			nm+=1;
			nd=1;
		}
		else if((d==29 && m==2) && m%4==0)
		{
			nm=3;
			nd=1;
		}
		else if((d==28 && m==2) && m%4!=0)
		{
			nd=1;
			nm+=1;
		}
		else
		{
			nd+=1;
		}
	}	while(ValidDate==true);

	if (d==1)
	{
		if (m==1)
		{
			pd=31;
			pm=12;
			py-=1;
		}
		else
		{
			pm-=1;
		}
		if (pm==2 || pm==4 || pm==6 || pm==9 || pm==11)
		{
			pd=31;
		}
		else if(m==3)
		{
			if (y%4==0)
				pd=29;
			else
				pd=28;
		}
		else
			pd=30;
	}
	else
		pd-=1;
	cout<<"\nPrevious date: "<<pd<<"/"<<pm<<"/"<<py<<"\n";
	cout<<"Next date: "<<nd<<"/"<<nm<<"/"<<ny<<"\n";
	return 0;
}
