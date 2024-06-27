#include<iostream>
#include<math.h>
using namespace std;

/*int monthprint31(int date, int count, int x)
{
	for(date = 1; date <= x; date++)
	{
		if(count > 7)
		{
			count = 1;
			cout<<"\n  ";
		}

		if(date < 10)
		{
			cout<<date<<"   ";
		}
		else
		{
			cout<<date<<"  ";
		}
		count++;
	}
	return count;
}
*/

int monthprint(int date, int count, int x)
{
	for(date = 1; date <= x; date++)
	{
		if(count > 7)
		{
			count = 1;
			cout<<"\n  ";
		}

		if(date < 10)
		{
			cout<<date<<"   ";
		}
		else
		{
			cout<<date<<"  ";
		}
		count++;
	}
	return count;
}


/*int monthprintfeb(int date, int count, int x)
{
	for(date = 1; date <= x; date++)
	{
		if(count > 7)
		{
			count = 1;
			cout<<"\n  ";
		}

		if(date < 10)
		{
			cout<<date<<"   ";
		}
		else
		{
			cout<<date<<"  ";
		}
		if(count > 7)
		{
			count = 1;
			cout<<"\n  ";
		}
		count++;
	}
	return count;
}
*/

int main()
{
	int year, count = 0, c, y, a = 100, f1, f2, f3, date = 1, x, z;
	double b = 7;
	string month[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"}, day[7] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
	
	cout<<"Enter year to print: ";cin>>year;
	
	if(year % 4 == 0)
	{
		z = 29;
	}
	else
	{
		z = 28;
	}
	
	y = year % a;
	c = (year - y)/a;
	y -= 1;
	
	f1 = floor((2.6*11) - 0.2);
	f2 = floor(y/4);
	f3 = floor(c/4);
	
	count = 1 + ((1 + f1 - 2*c + y + f2 + f3)%7);
	
	cout<<endl;
	
	for(int i = 0; i < 12; i++)
	{
		cout<<endl<<endl<<"\t"<<month[i]<<endl<<"\n  ";
		for(int j = 0; j < 7; j++)														//printing days
		{
			cout<<day[j]<<" ";
		}
		cout<<"\n  ";
		for( int k = 1; k < count; k++)		   											//adjusting indent for 1st of every month
		{
			cout<<"    ";
		}
		
		if(i == 0 || i == 2|| i == 4 || i == 6 || i == 7 || i == 9 || i == 11) x = 31;  //for months with 31 days
		else if(i == 3 || i == 5 || i == 8 || i == 10) x = 30;						    //for months with 30 days
		else x = z;																		//for February
		
		count = monthprint(date, count, x);												//printing 
	}
	
	return 0;
}
