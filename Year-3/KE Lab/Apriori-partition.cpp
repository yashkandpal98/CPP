#include<bits/stdc++.h>

using namespace std;

struct data
{
	vector<int> set;
	int support;
};


vector<vector<int> > readFromFile()
{
	fstream database;
	vector<int> basket;
	vector<vector<int> > transaction;
	string str;
	
	database.open("Database-2.txt", ios::in);
	while(getline(database, str))
	{
		int i = 0;
		
		while(str[i] != '\0')
		{
			if(str[i++] != ' ') basket.push_back(str[i-1]-'0'+1);
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

vector<vector<int> > newSort(vector<vector<int> > set)
{
	for(int i = 0; i < set.size(); i++)
	{
		for(int j = i+1; j < set.size(); j++)
		{
			if((set[i].size() > set[j]. size()) || (set[i].size() == set[j].size() && set[i] > set[j]))
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

vector<data> frequent(vector<vector<int> > transaction, int setSize, vector<vector<int> > itemSet, double minSup, vector<vector<int> > rejected, vector<data> s)
{
	if(itemSet.size() == 1 && setSize > itemSet[0].size()) return s;
	
	cout<<setSize<<"-item sets\n";
	
	vector<vector<int> > set;
	data z;
	
	if(setSize == 1) set = itemSet;
	else set = setGenerator(setSize, itemSet);
	
	set = sort(set);
	
	if(setSize > 1)
	{
		cout<<"\nBefore pruning:\n";
		
		for(int i = 0; i < set.size(); i++)
		{
			for(int j = 0; j < set[i].size(); j++)cout<<set[i][j]<<" ";
			cout<<endl;
		}
		
		cout<<"\nAfter pruning:\n";
		
		for(int i = 0; i < rejected.size(); i++) set = prune(set, rejected[i]);
		
		for(int i = 0; i < set.size(); i++)
		{
			for(int j = 0; j < set[i].size(); j++)cout<<set[i][j]<<" ";
			cout<<endl;
		}
	}
	
	if(set.size() == 0) return s;
	
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
			z.set = set[i];
			z.support = x;
			s.push_back(z);
			cout<<set[i][0];
			for(int j = 1; j < set[i].size(); j++) cout<<" "<<set[i][j];
			cout<<"- "<<x<<endl;
		}
	}
	
	cout<<endl<<endl;
	
	if(set.size() == 0) return s;
	
	return frequent(transaction, setSize+1, set, minSup, rejected, s);
}

vector<data> checkGlobal(vector<vector<int> > transaction, vector<vector<int> > itemSet, double minSup, vector<data> s)
{
	data z;
	
	for(int i = 0; i < itemSet.size(); i++)
	{
		int x = checkFrequent(transaction, itemSet[i]);
		
		if(x < minSup) itemSet.erase(itemSet.begin()+i--);
		else
		{
			z.set = itemSet[i];
			z.support = x;
			s.push_back(z);
			cout<<itemSet[i][0];
			for(int j = 1; j < itemSet[i].size(); j++) cout<<" "<<itemSet[i][j];
			cout<<"- "<<x<<endl;
		}
	}
	
	cout<<endl<<endl<<endl;
	
	return s;
}

vector<vector<int> > clearDuplicates(vector<vector<int> > itemSet)
{
	for(int i = 0; i < itemSet.size(); i++) for(int j = i+1; j < itemSet.size(); j++) if(itemSet[i] == itemSet[j]) itemSet.erase(itemSet.begin()+j--);
	return itemSet;
}

vector<data> clearDuplicates(vector<data> set)
{
	for(int i = 0; i < set.size(); i++)
	{
		for(int j = i+1; j < set.size(); j++)
		{
			if(set[i].set == set[j].set)
			{
				set[i].support += set[j].support;
				set.erase(set.begin()+j);
			}
		}
	}
	
	return set;
}

vector<data> newSort(vector<data> set)
{
	for(int i = 0; i < set.size(); i++)
	{
		for(int j = i+1; j < set.size(); j++)
		{
			if((set[i].set.size() > set[j].set.size()) || (set[i].set.size() == set[j].set.size() && set[i].set > set[j].set))
			{
				data t = set[i];
				set[i] = set[j];
				set[j] = t;
			}
		}
	}
	
	return set;
}


int main()
{
	double minSup = 2;
	int count = 0;
	vector<data> st;
	vector<int> basket, a;
	vector<double> newMinSup;
	vector<vector<int> > transaction = readFromFile(), itemSet, rejected;
	vector<vector<vector<int> > > partition;
	
	for(int i = 0; i < 3; i++)
	{
		for(int j = count; j < count+transaction.size()/3; j++) itemSet.push_back(transaction[j]);
		partition.push_back(itemSet);
		newMinSup.push_back(itemSet.size()*minSup/transaction.size());
		itemSet.clear();
		count += transaction.size()/3;
	}
	
	if(count < transaction.size())
	{
		while(count < transaction.size()) itemSet.push_back(transaction[count++]);
		partition.push_back(itemSet);
		double x = itemSet.size()*minSup/transaction.size();
		newMinSup.push_back(x);
		itemSet.clear();
	}
	
	for(int i = 1; i < 6; i++)
	{
		basket.push_back(i);
		itemSet.push_back(basket);
		basket.clear();
	}
	
	cout<<"Local frequent itemsets:\n\n";
	for(int i = 0; i < partition.size(); i++)
	{
		cout<<"Partition "<<i+1<<":\n";
		st = (frequent(partition[i], 1, itemSet, newMinSup[i], rejected, st));
		cout<<endl<<endl;
	}
	
	itemSet.clear();
	for(int i = 0; i < st.size(); i++) itemSet.push_back(st[i].set);
	
	itemSet = clearDuplicates(itemSet);
	itemSet = newSort(itemSet);
	
	st = clearDuplicates(st);
	st = newSort(st);
	
	cout<<"\n\nGlobal itemset candidates:\n";
	for(int i = 0; i < st.size(); i++)
	{
		cout<<st[i].set[0];
		for(int j = 1; j < st[i].set.size(); j++) cout<<" "<<st[i].set[j];
		cout<<"- "<<st[i].support<<endl;
	}
	
	cout<<"\nGlobal frequent itemsets:\n\n";
	st = checkGlobal(transaction, itemSet, minSup, st);
	
	return 0;
}
