#include<iostream>
using namespace std;


	


int main()
{
	int x, y, z;
	cin >> x >> y >> z;
	
	int  a[10][10][10];

	cout << endl << "Enter elements:\n";
	
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			for (int k = 0; k < z; k++)
			{
				cin >> a[i][j][k];
			}
		}
	}

	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			for (int k = 0; k < z; k++)
			{
				cout << a[i][j][k] << " ";
			}
			cout << "   ";
		}
		cout << endl;
	}
}

