#include<bits/stdc++.h>
using namespace std;
ofstream fout("resultLABH.txt");
ofstream gout("resultCABH.txt");
void Display(set<int> S)
{
	set<int> :: iterator itr;
	for(itr=S.begin();itr!=S.end();itr++)
	{
		cout<<*itr<<" ";
	}
}
int getHashValue(set<int> S)
{
	int val=0;
	set<int> :: iterator itr;
	for(itr=S.begin();itr!=S.end();itr++)
	{
		val*=10;
		val+=*itr;
	}
	return val;
}
void Append(vector<set<int> >  &Res, vector<set<int> > Cur)
{
	for(int i=0;i<Cur.size();i++)
	{
		Res.push_back(Cur[i]);
	}
}
void GetSubsets(vector<int> Array,int k,set<int> Curset,vector<set<int> > &Res,int index)
{
	if(index>=Array.size()&&k==0)
	{
		Res.push_back(Curset);
		return;
	}
	if(index>=Array.size()) return ;
	GetSubsets(Array,k,Curset,Res,index+1);
	Curset.insert(Array[index]);
	GetSubsets(Array,k-1,Curset,Res,index+1);
}
vector<set<int> > HashBasedSearch(int noBuckets,int minsupcount)
{
	ifstream fin("Database2.txt");
	map<int, vector<set<int > > >  M;
	map<int,vector<set<int> > >  :: iterator itr;
	vector<int> T;
	map<set<int>,int > Ans;
	map<set<int> ,int> :: iterator it;
	vector<set<int> > R;
	while(!fin.eof())
	{
		string t;
		fin>>t;
		if(t[0]=='T'||t[0]=='E')
		{
			if(T.size()!=0)
			{
				vector<set<int> > Res;
				set<int> CurSet;
				GetSubsets(T,2,CurSet,Res,0);
				for(int i=0;i<Res.size();i++)
				{
					int hv=getHashValue(Res[i]);
					M[hv%noBuckets].push_back(Res[i]);
				}
			}
			T.clear();
		}
		else if(t[0]=='I')
		{
			int x=atoi(t.substr(1).c_str());
			T.push_back(x);
		}
		 if(t[0]=='E')
		{
			break;
		}
	}
	for(itr=M.begin();itr!=M.end();itr++)
	{
		if(itr->second.size()>=minsupcount)
		{
			for(int j=0;j<itr->second.size();j++)
			{
				Ans[itr->second[j]]++;
			}
		}
	}
	for(it=Ans.begin();it!=Ans.end();it++)
	{
		R.push_back(it->first);
	}
	/*cout<<"Answer: \n";
	for(int i=0;i<Ans.size();i++)
	{
		Display(Ans[i]);
		cout<<"\n";
	}*/
	return R;
}
bool hasInfrequentSubset(set<int> C, vector<set<int> > L,int k)
{
	vector<int> Temp;
	set<int> :: iterator itr;
	vector< set<int> > Ksub;
	set<int> T;
	for(itr=C.begin();itr!=C.end();itr++)
	{
		Temp.push_back(*itr);
	}
	GetSubsets(Temp,k-1,T,Ksub,0);
	/*for(int i=0;i<Ksub.size();i++)
	{
		for(itr=Ksub[i].begin();itr!=Ksub[i].end();itr++)
		{
			cout<<*itr<<" ";
		}
		cout<<endl;
	}*/
		
	for(int i=0;i<Ksub.size();i++)
	{
		int ff=0;
		for(int j=0;j<L.size();j++)
		{
			if(L[j]==Ksub[i]) 
			{
				ff=1;	
			}
		}
		if(ff==0) return true;
	}
	return false;
}
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
vector< set<int> > GenerateApriori(int minsupcount, vector< set<int> > PrevL, int k)
{
	// Returns Ck given Lk-1
	set<int> :: iterator itr,jtr;
	vector< set<int> > Res;
	for(int i=0;i<PrevL.size()-1;i++)
	{
		for(int j=i+1;j<PrevL.size();j++)
		{
			itr=PrevL[i].begin();
			jtr=PrevL[j].begin();
			int p=1;
			int flag=0;
			for(p=1;p<=k-2;p++)
			{
				if(*itr!=*jtr)
				{
					flag=1;
					break;
				}
				itr++;
				jtr++;
			}
			if(flag==0)
			{
				//cout<<"Here\n";
				set<int> H;
				itr=PrevL[i].begin();
				jtr=PrevL[j].begin();
				while(itr!=PrevL[i].end())
				{
					H.insert(*itr);
					itr++;
				}
				while(jtr!=PrevL[j].end())
				{
					H.insert(*jtr);
					jtr++;
				}
				if(!hasInfrequentSubset(H,PrevL,k))
				{
					//cout<<"There\n";
					Res.push_back(H);
				}
			}
		}
	}
	return Res;
}
int main()
{
	// Getting L1:
	vector< set<int> > L1;
	set<int> :: iterator itr;
	int minsupcount=2;
	for(int i=1;i<=5;i++)
	{
		set<int> Temp;
		Temp.insert(i);
		if(getCount(Temp)>=minsupcount)
		L1.push_back(Temp);
	}
	gout<<"C1: \n";
	for(int i=1;i<=5;i++)
	gout<<i<<endl;
	fout<<"L1: \n";
	for(int i=0;i<L1.size();i++)
	{
		for(itr=L1[i].begin();itr!=L1[i].end();itr++)
		{
			fout<<*itr<<" ";
		}
		fout<<endl;
	}
	for(int k=2;1;k++)
	{
		vector<set<int> > CK;
		if(k==2)
		CK=HashBasedSearch(7,minsupcount);
		else
		CK=GenerateApriori(minsupcount,L1,k);
		vector<set<int> > CKF;
		vector<set<int> > :: iterator it;
		for(int i=0;i<CK.size();i++)
		{
			if(getCount(CK[i])>=minsupcount)
				CKF.push_back(CK[i]);
		}
		if(CK.size()!=0)
		gout<<"C"<<k<<": \n";
		for(int i=0;i<CK.size();i++)
		{
			for(itr=CK[i].begin();itr!=CK[i].end();itr++)
			{
				gout<<*itr<<" ";
			}
			gout<<endl;
		}
		if(CKF.size()!=0)
		fout<<"L"<<k<<": \n";
		for(int i=0;i<CKF.size();i++)
		{
			for(itr=CKF[i].begin();itr!=CKF[i].end();itr++)
			{
				fout<<*itr<<" ";
			}
			fout<<endl;
		}
		if(CKF.size()==0)
		break;
		else
		L1=CKF;
	}
	return 0;
}
