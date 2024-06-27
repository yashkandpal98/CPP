#include<bits/stdc++.h>

using namespace std;


int main()
{
	fstream database;
	string s;
	vector<int>basket;
	vector<vector<int> > transaction;
	
	database.open("Database-2.txt", ios::in);
	while(getline(database, s))
	{
		int i = 0;
		while(s[i] != '\0')
		{
			if(s[i++] != ' ') basket.push_back(s[i-1]-'0');
		}
		transaction.push_back(basket);
		basket.clear();
	}
	database.close();
	
	for(int i = 0; i < transaction.size(); i++)
	{
		for(int j = 0; j < transaction[i].size(); j++) cout<<transaction[i][j]+1<<" ";
		cout<<endl;
	}
	
	return 0;
}
