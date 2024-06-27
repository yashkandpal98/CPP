#include<bits/stdc++.h>
using namespace std;


typedef struct fpnode
{
	vector<int> valueSup;
	vector<int> bmc;
	vector<fpnode*> child;
} *fpptr;


vector<vector<int> > readFromFile()
{
	fstream database;
	vector<int> basket;
	vector<vector<int> > transaction;
	string str;
	
	database.open("Database.txt", ios::in);
	while(getline(database, str))
	{
		int i = 0;
		
		while(str[i] != '\0') if(str[i++] != ' ') basket.push_back(str[i-1]-'0'+1);
		transaction.push_back(basket);
		basket.clear();
	}
	database.close();
	
	return transaction;
}

fpptr fpCreate(vector<int> valueSup)
{
	fpptr x = new fpnode;
	x->valueSup = valueSup;
	return x;
}

vector<vector<double> > frequentSingle(vector<vector<int> > transaction, vector<vector<double> > itemSet, double minSup)
{
	for(int i = 0; i < transaction.size(); i++)
	{
		int current = 0;
		for(int j = 0; j < transaction[i].size(); j++)
		{
			for(int k = current; k < itemSet.size(); k++)
			{
				if(itemSet[k][0] == transaction[i][j])
				{
					itemSet[k][1]++;
					current = k+1;
					break;
				}
			}
		}
	}
	
	for(int i = 0; i < itemSet.size(); i++) if(itemSet[i][1] < minSup) itemSet.erase(itemSet.begin()+i--);
	
	return itemSet;
}

vector<vector<double> > sort(vector<vector<double> > itemSet)
{
	for(int i = 0; i < itemSet.size(); i++)
	{
		for(int j = i+1; j < itemSet.size(); j++)
		{
			if(itemSet[i][1] < itemSet[j][1])
			{
				vector<double> x = itemSet[i];
				itemSet[i] = itemSet[j];
				itemSet[j] = x;
			}
		}
	}
	return itemSet;
}

double find(int x, vector<vector<double> > itemSet)
{
	for(int i = 0; i < itemSet.size(); i++) if(x == itemSet[i][0]) return itemSet[i][1];
	return -1;
}

vector<int> sort(vector<int> set, vector<vector<double> > itemSet)
{
	for(int i = 0; i < set.size(); i++) if(find(set[i], itemSet) == -1) set.erase(set.begin()+i--);
	
	for(int i = 0; i < set.size(); i++)
	{
		for(int j = i+1; j < set.size(); j++)
		{
			if(find(set[i], itemSet) < find(set[j], itemSet))
			{
				set[i] += set[j];
				set[j] = set[i] - set[j];
				set[i] -= set[j];
			}
		}
	}
	
	return set;
}

void fpAdd(fpptr &root, vector<int> transaction, int current)
{
	if(transaction.size() > 0)
	{
		if(root->valueSup[0] == -1)
		{
			if(root->child.size() == 0)
			{
				vector<int> valSup;
				valSup.push_back(transaction[0]);
				valSup.push_back(0);
				root->child.push_back(fpCreate(valSup));
				fpAdd(root->child[0], transaction);
			}
			else
			{
				int flag = 0;
				for(int i = 0; i < root->child.size(); i++)
				{
					if(transaction[0] == root->child[i]->valueSup[0])
					{
						fpAdd(root->child[i], transaction);
						flag = 1;
						break;
					}
				}
				if(flag == 0)
				{
					vector<int> valSup;
					valSup.push_back(transaction[0]);
					valSup.push_back(0);
					root->child.push_back(fpCreate(valSup));
					fpAdd(root->child[root->child.size()-1], transaction);
				}
			}
		}
		else
		{
			root->valueSup[1]++;
			transaction.erase(transaction.begin());
			
			if(transaction.size() == 0) return;
			else
			{
				if(root->child.size() == 0)
				{
					vector<int> valSup;
					valSup.push_back(transaction[0]);
					valSup.push_back(0);
					root->child.push_back(fpCreate(valSup));
					fpAdd(root->child[0], transaction);
				}
				else
				{
					int flag = 0;
					for(int i = 0; i < root->child.size(); i++)
					{
						if(transaction[0] == root->child[i]->valueSup[0])
						{
							fpAdd(root->child[i], transaction, current);
							flag = 1;
							break;
						}
					}
					if(flag == 0)
					{
						vector<int> valSup;
						valSup.push_back(transaction[0]);
						valSup.push_back(0);
						root->child.push_back(fpCreate(valSup));
						fpAdd(root->child[root->child.size()-1], transaction);
					}
				}
			}
		}
	}
	else return;
}

void fpTreeCreator(vector<vector<int> > transaction, vector<vector<double> > itemSet, fpptr &root)
{
	for(int i = 0; i < transaction.size(); i++)
	{
		vector<int> newSet = sort(transaction[i], itemSet);
		fpAdd(root, newSet, 0);
	}
}

int height(fpptr root)
{
	if(root != NULL)
	{
		if(root->child.size() == 0) return 1;
		else
		{
			int max = height(root->child[0]);
			for(int i = 1; i < root->child.size(); i++)
			{
				int x = height(root->child[i]);
				if(x > max) max = x;
			}
			return max+1;
		}
	}
	else return 0;
}

void levelPrint(fpptr root, int level, int current)
{
	if(root != NULL)
	{
		if(current == level) cout<<root->valueSup[0]<<":"<<root->valueSup[1]<<" ";
		else for(int i = 0; i < root->child.size(); i++) levelPrint(root->child[i], level, current+1);
	}
}

void levelOrderPrint(fpptr root)
{
	int h = height(root);
	for(int i = 0; i < h; i++)
	{
		levelPrint(root, i, 0);
		cout<<endl;
	}
}


int main()
{
	double minSup = 2;
	fpptr root;
	vector<double> basket;
	vector<int> rootVal;
	vector<vector<int> > transaction = readFromFile();
	vector<vector<double> > itemSet;
	
	rootVal.push_back(-1);
	rootVal.push_back(-1);
	root = fpCreate(rootVal);
	
	basket.push_back(1);
	basket.push_back(0);
	for(int i = 1; i < 10; i++)
	{
		basket[0] = i;
		itemSet.push_back(basket);
	}
	basket.clear();
	
	itemSet = frequentSingle(transaction, itemSet, minSup);
	itemSet = sort(itemSet);
	
	for(int i = 0; i < itemSet.size(); i++) root->bmc.push_back(0);
	
	fpTreeCreator(transaction, itemSet, root);
	
	levelOrderPrint(root);
	
	return 0;
}
