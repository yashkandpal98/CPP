#include<bits/stdc++.h>
using namespace std;
ofstream fout("ResultAB.txt");
int getCount(set<int> S)
{
	ifstream fin("Database2.txt");
	set<int> Temp;
	int count=0;
	while(!fin.eof())
	{
		string t;
		fin>>t;
		//cout<<"T : "<<t<<endl;
		if(t[0]=='E') break;
		if(t[0]=='T')
		{
			if(S.size()==Temp.size())
			{
				count++;
			}
			Temp.clear();
		}
		else
		{
			string y=t.substr(1);
			int x=atoi(y.c_str());
			if(S.find(x)!=S.end())
			Temp.insert(x);
		}
	}
	if(S.size()==Temp.size())
		count++;
	return count;
}

void GetSubsets(vector<int> Array, int index, set<int> Cur, vector<set<int> > &Res)
{
	if(index>=Array.size())
	{
		if(Cur.size()!=0)
		Res.push_back(Cur);
		return;
	}
	GetSubsets(Array,index+1,Cur,Res);
	Cur.insert(Array[index]);
	GetSubsets(Array,index+1,Cur,Res);
}
void Display(set<int> S)
{
	set<int> :: iterator itr;
	for(itr=S.begin();itr!=S.end();itr++)
	{
		cout<<*itr<<" ";
		fout<<*itr<<" ";
	}
}
int SetUnion(set<int> R, set<int> S)
{
	set<int> T;
	set<int> :: iterator itr;
	for(itr=S.begin();itr!=S.end();itr++)
	{
		T.insert(*itr);
	}
	for(itr=R.begin();itr!=R.end();itr++)
	{
		T.insert(*itr);
	}
	if(T.size()==R.size()+S.size())
	{
		return 1;
	}
	return 0;
}
int main()
{
	ifstream fin("inputB.txt");
	vector<int> T;
	double minconf=50.0;
	set <pair<set<int> ,set<int> > >  M;
	while(!fin.eof())
	{
		string temp;
		fin>>temp;
		//cout<<temp<<"\n";
		if(temp[0]=='E') break;
		if(temp[0]=='L')
		{
			
		}
		else if(temp[0]=='.')
		{
			if(T.size()>1)
			{
				//cout<<"Here\n";
				vector<set<int> > P;
				set<int> R;
				GetSubsets(T,0,R,P);
				for(int i=0;i<P.size();i++)
				{
					//cout<<"Min\n";
					for(int j=0;j<P.size();j++)
					{
						if(SetUnion(P[i],P[j])!=0)
						{
							if(M.find(make_pair(P[i],P[j]))==M.end())
							{
								set<int> H;
								set<int> :: iterator it;
								for(it=P[i].begin();it!=P[i].end();it++)
								{
									H.insert(*it);
								}
								for(it=P[j].begin();it!=P[j].end();it++)
								{
									H.insert(*it);
								}
								int x=getCount(H);
								int y=getCount(P[i]);
								if(((double)x/y)*100>=minconf)
								{
									Display(P[i]);
									cout<<"=>";
									fout<<"=>";
									Display(P[j]);
									cout<<" Confidence : "<<(double) x/y;
									cout<<"\n";
									fout<<" Confidence : "<<(double) x/y;
									fout<<"\n";
								}
								M.insert({P[i],P[j]});
							}
						}
					}
				}
			}
			T.clear();
		}
		else
		{
			int x=atoi(temp.c_str());
			T.push_back(x);
		}
	}
}
