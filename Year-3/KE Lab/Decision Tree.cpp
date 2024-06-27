#include<bits/stdc++.h>

using namespace std;

typedef struct decnode
{
	string attr, prevAttrVal;
	vector<decnode*> children;
} *decptr;

vector<string> featureVector;
vector<vector<string> > trainingVector;


void readFromFile()
{
	fstream database;
	vector<string> basket;
	string str, s;
	int i = 0;
	
	database.open("Trainer.txt", ios::in);
	
	getline(database, str);
	while(str[i])
	{
		s += str[i];
		if(str[i] == '\t')
		{
			s.erase(s.end()-1);
			featureVector.push_back(s);
			s.clear();
		}
		i++;
	}
	featureVector.push_back(s);
	s.clear();
	
	featureVector.erase(featureVector.begin());
	
	while(getline(database, str))
	{
		i = 0;
		s.clear();
		
		while(str[i] != '\0')
		{
			s += str[i];
			if(str[i] == '\t')
			{
				s.erase(s.end()-1);
				basket.push_back(s);
				s.clear();
			}
			else if(str[i] == '-') s.clear();
			i++;
		}
		basket.push_back(s);
		s.clear();
		basket.erase(basket.begin());
		trainingVector.push_back(basket);
		basket.clear();
	}
	database.close();
}

decptr treeCreate(string s, string t)
{
	decptr temp = new decnode;
	temp->attr = s;
	temp->prevAttrVal = t;
	
	return temp;
}

void treeAdd(decptr &root, vector<string> featureVector, vector<string> trainingVector)
{
	if(trainingVector.size() == 0) return;
	else
	{
		featureVector.erase(featureVector.begin());
		
		if(featureVector.size() == 0)
		{
			root->children.push_back(treeCreate("", trainingVector[0]));
			return;
		}
		if(root->prevAttrVal == "")
		{
			if(root->children.size() == 0)
			{
				root->children.push_back(treeCreate(featureVector[0], trainingVector[0]));
				trainingVector.erase(trainingVector.begin());
				treeAdd(root->children[0], featureVector, trainingVector);
			}
			else
			{
				int flag = 0;
				for(int i = 0; i < root->children.size(); i++)
				{
					if(trainingVector[0] == root->children[i]->prevAttrVal)
					{
						flag = 1;
						trainingVector.erase(trainingVector.begin());
						treeAdd(root->children[i], featureVector, trainingVector);
						break;
					}
				}
				
				if(flag == 0)
				{
					root->children.push_back(treeCreate(featureVector[0], trainingVector[0]));
					trainingVector.erase(trainingVector.begin());
					treeAdd(root->children[0], featureVector, trainingVector);
				}
			}
		}
		else
		{
			if(root->children.size() == 0)
			{
				root->children.push_back(treeCreate(featureVector[0], trainingVector[0]));
				trainingVector.erase(trainingVector.begin());
				treeAdd(root->children[0], featureVector, trainingVector);
			}
			else
			{
				int flag = 0;
				for(int i = 0; i < root->children.size(); i++)
				{
					if(trainingVector[0] == root->children[i]->prevAttrVal)
					{
						flag = 1;
						trainingVector.erase(trainingVector.begin());
						treeAdd(root->children[i], featureVector, trainingVector);
						break;
					}
				}
				
				if(flag == 0)
				{
					root->children.push_back(treeCreate(featureVector[0], trainingVector[0]));
					trainingVector.erase(trainingVector.begin());
					treeAdd(root->children[0], featureVector, trainingVector);
				}
			}
		}
	}
}

void decisionTree(decptr &root, vector<string> featureVector, vector<vector<string> > trainingVector)
{
	for(int i = 0; i < trainingVector.size(); i++) treeAdd(root, featureVector, trainingVector[i]);
}

void printTree(decptr root)
{
	queue<decptr> printer;
	
	printer.push(root);
	printer.push(NULL);
	
	while(printer.size() >= 0)
	{
		decptr temp = printer.front();
		if(temp == NULL) cout<<endl;
		else
		{
			if(temp->prevAttrVal == "") cout<<"-";
			else cout<<temp->prevAttrVal;
			cout<<" "<<temp->attr<<"\t";
			for(int i = 0; i < temp->children.size(); i++) printer.push(temp->children[i]);
			printer.push(NULL);
		}
		printer.pop();
	}
}

int height(decptr root)
{
	if(root != NULL)
	{
		if(root->children.size() == 0) return 1;
		else
		{
			int max1 = height(root->children[0]);
			for(int i = 1; i < root->children.size(); i++) max1 = max(max1, height(root->children[i]));
			return max1+1;
		}
	}
	else return 0;
}

void levelPrint(decptr root, int level, int current)
{
	if(root != NULL)
	{
		if(current == level)
		{
			if(root->prevAttrVal == "") cout<<"-";
			else cout<<root->prevAttrVal;
			cout<<" "<<root->attr<<"\t";
		}
		else
		{
			for(int i = 0; i < root->children.size(); i++)
			{
				levelPrint(root->children[i], level, current+1);
			}
		}
	}
}

void levelOrderPrint(decptr root)
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
	/*string s1 = "a", s2 = "b";
	
	cout<<s1<<" "<<s2<<endl;
	
	s2.clear();
	
	cout<<s1<<" "<<(s2 == "")<<endl;
	
	s1.erase(s1.end()-1);
	
	cout<<s1<<" "<<s2;*/
	
	readFromFile();
	
	decptr root = treeCreate(featureVector[0], "");
	
	decisionTree(root, featureVector, trainingVector);
	levelOrderPrint(root);
	
	/*for(int i = 0; i < featureVector.size(); i++)cout<<featureVector[i]<<"\t";
	
	cout<<endl;
	
	for(int i = 0; i < trainingVector.size(); i++)
	{
		for(int j = 0; j < trainingVector[i].size(); j++) cout<<trainingVector[i][j]<<"\t";
		cout<<endl;
	}*/
	
	return 0;
}
