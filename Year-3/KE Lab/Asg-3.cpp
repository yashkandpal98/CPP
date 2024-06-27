#include<bits/stdc++.h>

using namespace std;


vector<vector<int> > readFromFile()
{
	fstream database;
	string s;
	vector<int> basket;
	vector<vector<int> > transaction;
	
	database.open("Database.txt", ios::in);
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
	
	return transaction;
}

int checkFrequent(vector<vector<int> > transaction, vector<int>set)
{
	int count = 0;
	
	for(int i = 0; i < transaction.size(); i++)
	{
		int flag = 0;
		for(int j = 0; j < set.size(); j++)
		{
			for(int k = 0; k < transaction[i].size(); k++)
			{
				if(transaction[i][k] == set[j])
				{
					flag = 1;
					break;
				}
				else flag = 0;
			}
			if(flag == 0) break;
		}
		if(flag == 1) count++;
	}
	
	return count;
}

vector<int> setUnion(vector<int> itemSet1, vector<int> itemSet2)
{
	vector<int> newVec;
	int i = 0, j = 0;
	
	while(i < itemSet1.size() && j < itemSet2.size())
	{
		if(itemSet1[i] <= itemSet2[j])
		{
			newVec.push_back(itemSet1[i]);
			if(itemSet1[i++] == itemSet2[j]) j++;
		}
		else if(itemSet1[i] > itemSet2[j]) newVec.push_back(itemSet2[j++]);
	}
	
	if(i < itemSet1.size()) while(i < itemSet1.size()) newVec.push_back(itemSet1[i++]);
	if(j < itemSet2.size()) while(j < itemSet2.size()) newVec.push_back(itemSet2[j++]);
	
	return newVec;
}

vector<vector<int> > setGenerator(int setSize, vector<vector<int> > itemSet)
{
	vector<vector<int> > generatedSet;
	
	for(int i = 0; i < itemSet.size(); i++)
	{
		for(int j = i+1; j < itemSet.size(); j++)
		{
			vector<int> newSet = setUnion(itemSet[i], itemSet[j]);
			if(newSet.size() > setSize) continue;
			
			generatedSet.push_back(newSet);
			for(int k = 0; k < generatedSet.size()-1; k++)
			{
				if(generatedSet[k] == newSet)
				{
					generatedSet.erase(generatedSet.end());
					break;
				}
			}
		}
	}
	
	return generatedSet;
}

vector<vector<int> > sort(vector<vector<int> > set)
{
	for(int i = 0; i < set.size(); i++)
	{
		for(int j = i+1; j < set.size(); j++)
		{
			if(set[i] > set[j])
			{
				vector<int> t = set[i];
				set[i] = set[j];
				set[j] = t;
			}
		}
	}
	return set;
}

vector<vector<int> > prune(vector<vector<int> > set, vector<int> rejected)
{
	for(int i = 0; i < set.size(); i++)
	{
		int flag = 0, current = 0, count = 0;
		for(int j = current; j < rejected.size(); j++)
		{
			for(int k = current; k < set[i].size(); k++)
			{
				if(set[i][k] == rejected[j])
				{
					flag = 1;
					count++;
					current = k+1;
					break;
				}
				else flag = 0;
			}
			if(flag == 0) break;
		}
		if(count == rejected.size()) set.erase(set.begin()+i--);
	}
	
	return set;
}

void frequent(vector<vector<int> > transaction, int setSize, vector<vector<int> > itemSet, int minSup, vector<vector<int> > rejected)
{
	if(itemSet.size() == 1 && setSize > itemSet[0].size()) return;
	
	cout<<setSize<<"-item sets\n";
	
	vector<vector<int> > set;
	
	if(setSize == 1) set = itemSet;
	else set = setGenerator(setSize, itemSet);
	
	set = sort(set);
	
	if(setSize > 1)
	{
		cout<<"\nBefore pruning:\n";
		
		for(int i = 0; i < set.size(); i++)
		{
			for(int j = 0; j < set[i].size(); j++)cout<<set[i][j]+1<<" ";
			cout<<endl;
		}
		
		cout<<"\nAfter pruning:\n";
		
		for(int i = 0; i < rejected.size(); i++) set = prune(set, rejected[i]);
		
		for(int i = 0; i < set.size(); i++)
		{
			for(int j = 0; j < set[i].size(); j++)cout<<set[i][j]+1<<" ";
			cout<<endl;
		}
	}
	
	if(set.size() == 0) return;
	
	cout<<"\nFrequent item sets:\n";
	
	for(int i = 0; i < set.size(); i++)
	{
		int x = checkFrequent(transaction, set[i]);
		if(x < minSup)
		{
			rejected.push_back(set[i]);
			set.erase(set.begin()+i--);
		}
		else
		{
			cout<<set[i][0]+1;
			for(int j = 1; j < set[i].size(); j++) cout<<" "<<set[i][j]+1;
			cout<<"- "<<x<<endl;
		}
	}
	
	cout<<endl<<endl<<endl;
	
	if(set.size() == 0) return;
	
	frequent(transaction, setSize+1, set, minSup, rejected);
}


int main()
{
	float minSup = 35;
	vector<int> basket;
	vector<vector<int> > transaction = readFromFile(), itemSet, rejected;
	
	for(int i = 0; i < 10; i++)
	{
		basket.push_back(i);
		itemSet.push_back(basket);
		basket.clear();
	}
	basket.clear();
	
	frequent(transaction, 1, itemSet, minSup, rejected);
	
	return 0;
}
