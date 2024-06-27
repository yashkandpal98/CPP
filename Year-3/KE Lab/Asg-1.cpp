#include<bits/stdc++.h>

using namespace std;

int selectBasketSize()
{
	int y;
	do
	{
		y = rand();
	} while(y > 10 || y == 0);
	return y;
}

bool in(vector<int>itemList, int x)
{
	for(int i = 0; i < itemList.size(); i++) if(x == itemList[i]) return true;
	return false;
}

int selectItemNumber(vector<int> itemList, vector<int> basket)
{
	int y;
	do
	{
		y = rand();
	} while(!in(itemList, y) || in(basket, y));
	return y;
}

int main()
{
	fstream database;
	vector<int> itemList, basket;
	int x, y;
	
	for(int i = 0; i < 10; i++) itemList.push_back(i);
	
	database.open("Database-2.txt", ios::out);
	
	/*for(int i = 0; i < 150; i++)
	{
		x = selectBasketSize();
		for(int j = 0; j < x; j++) basket.push_back(-1);
		while(x-- != 0)
		{
			y = selectItemNumber(itemList, basket);
			basket.push_back(y);
			database<<y<<" ";
		}
		
		basket.clear();
		database<<endl;
	}*/
	
	for(int i = 0; i < 9; i++)
	{
		cin>>x;
		while(x != -1)
		{
			database<<x-1<<" ";
			cin>>x;
		}
		database<<endl;
	}
	
	database.close();
	
	return 0;
}
