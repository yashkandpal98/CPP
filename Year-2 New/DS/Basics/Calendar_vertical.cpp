#include<iostream>
#include<math.h>
using namespace std;

/*int monthprint31(int date, int count)
{
	for(date = 1; date <= 31; date++)
	{
		if(date < 10)
		{
			cout<<date<<"   ";
		}
		else
		{
			cout<<date<<"  ";
		}

		count++;
		if(count > 7)
		{
			count = 1;
			cout<<"\n  ";
		}
	}
	return count;
}


int monthprint30(int date, int count)
{
	for(date = 1; date <= 30; date++)
	{
		if(date < 10)
		{
			cout<<date<<"   ";
		}
		else
		{
			cout<<date<<"  ";
		}

		count++;
		if(count > 7)
		{
			count = 1;
			cout<<"\n  ";
		}
	}
	return count;
}
*/

/*int monthprint(int date, int count, int x, string day[7], string week[7][5])
{
	int count1 = 8-count;
	
	int count2 = 0;

	for( int i = 0; i < 7; i++)
	{
		cout<<day[i]<<"  ";
		if(count1 < 7)
		{
			if(count1 >= count)
			{
				cout<<"   ";
			}
		}
		else
		{
			count1 = 0;
		}
		for( int j = 0; j < 5; j++)
		{
			if(week[count1][j] == NULL || week[count1][j] > x)
			{
				count2++;
			}
			else
			{
				if(week[count1][j] < 10)
				{
					cout<<week[count1][j]<<"  ";
				}
				else
				{
					cout<<week[count1][j]<<" ";
				}
			}
		}
		cout<<endl;
		count1++;
	}
	
	return (8-count2);
}
*/


int main()
{
	int year, count = 0, c, y, a = 100, f1, f2, f3, x, z;
	int week[7][5] = {{1, 8, 15, 22, 29}, {2, 9, 16, 23, 30}, {3, 10, 17, 24, 31}, {4, 11, 18, 25}, {5, 12, 19, 26}, {6, 13, 20, 27}, {7, 14, 21, 28}};
	double b = 7;
	string month[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"}, day[7] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
	
	/*cout<<"Enter year to print: ";cin>>year;
	
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
		cout<<endl<<endl<<"\t"<<month[i]<<endl<<endl;
		
		if(i == 0 || i == 2|| i == 4 || i == 6 || i == 7 || i == 9 || i == 11) x = 31;  //for months with 31 days
		else if(i == 3 || i == 5 || i == 8 || i == 10) x = 30;						    //for months with 30 days
		else x = z;																		//for February
		
		int count1 = 8-count, count2 = 0;
	
		for( int k = 0; k < 7; k++)
		{
			cout<<day[k]<<"  ";
			if(count1 < 7)
			{
				if(count1 >= count)
				{
					cout<<"   ";
				}
			}
			else
			{
				count1 = 0;
			}
			for( int j = 0; j < 5; j++)
			{
				if(week[count1][j] == NULL || week[count1][j] > x)
				{
					count2++;
				}
				else
				{
					if(week[count1][j] < 10)
					{
						cout<<week[count1][j]<<"  ";
					}
					else
					{
						cout<<week[count1][j]<<" ";
					}
				}
			}
			cout<<endl;
			count1++;
		}
		
		count = 8-count2;									//printing 
	}*/


	count = 4;
	int count1 = 8-count;
	
	int count2 = 0;

	for( int i = 0; i < 7; i++)
	{
		cout<<day[i]<<"  ";
		if(count1 < 7)
		{
			if(count1 >= count)
			{
				cout<<"   ";
			}
		}
		else
		{
			count1 = 0;
		}
		for( int j = 0; j < 5; j++)
		{
			if(week[count1][j] == NULL || week[count1][j]>x)
			{
				count2++;
			}
			else
			{
				if(week[count1][j] < 10)
				{
					cout<<week[count1][j]<<"  ";
				}
				else
				{
					cout<<week[count1][j]<<" ";
				}
			}
		}
		cout<<endl;
		count1++;
	}
	
}
