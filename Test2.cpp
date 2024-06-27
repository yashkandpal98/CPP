#include<bits/stdc++.h>
using namespace std;


int main()
{
	int n = (rand()%12)-1;
	vector<int> mstSet;
	int graph[n][n], key[n];
	for(int i = 0; i < n; i++)
	{
		graph[i][i] = -1;
		for(int j = i+1; j < n; j++) graph[i][j] = graph[j][i] = (rand()%12)-1;
	}
	
	key[0] = 0;
	for(int i = 1; i < n; i++) key[i] = INT_MAX;
	
	return 0;
}
