#include<bits/stdc++.h>
using namespace std;
ofstream fout("ResultL.txt");
ofstream gout ("ResultC.txt");
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
	
	cout<<"Subsets k-1 "<<k<<": \n";
	for(int i=0;i<Ksub.size();i++)
	{
		for(itr=Ksub[i].begin();itr!=Ksub[i].end();itr++)
		{
			cout<<*itr<<" ";
		}
		cout<<endl;
	}
		
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
		if(ff==0)
		return true;
	}
	return false;
}
int getCount(set<int> S)
{
	ifstream fin("Database1.txt");
	set<int> Temp;
	int count=0;
	char ch;
	while(!fin.eof())
	{
		//cout<<endl<<i<<" ---> ";
		fin>>ch;
		if(ch=='T')
		{
			if(S.size()==Temp.size())
			{
				count++;
			}
			Temp.clear();
		}
		if(fin.eof())
		break;
		//cout<<ch;
		while(ch!='>')
		fin>>ch;
		fin>>ch;
		while(ch!='-')
		{
						
//		string t;
//		fin>>t;
		//cout<<"T : "<<t<<endl;
//		if(t[0]=='E') break;
//		if(t[0]=='T')
//		{
//			if(S.size()==Temp.size())
//			{
//				count++;
//			}
//			Temp.clear();
//		}
//		else
//		{
			//string y=t.substr(1);
			int x=ch-'0';
			if(S.find(x)!=S.end())
			Temp.insert(x);
			fin>>ch;
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
	int minsupcount=(41*20)/100;
	cout<<minsupcount<<"\n";
//	while(!fin.eof())
//	{
//			fin>>ch;
//				//cout<<ch;
//				while(ch!='>')
//				fin>>ch;
//				fin>>ch;
//				while(ch!='-')
//				{
//					set<int> Temp;
//					Temp.insert(ch-'0');
//					if(getCount(Temp)>=minsupcount)
//					L1.push_back(Temp);		
//					fin>>ch;
//				}
//	}
	for(int i=1;i<=7;i++)
	{
		set<int> Temp;
		Temp.insert(i);
		if(getCount(Temp)>=minsupcount)
		L1.push_back(Temp);
	}
	gout<<"C1: \n";
	for(int i=1;i<=7;i++)
	gout<<i<<endl;
	fout<<"L1 : \n";
	for(int i=0;i<L1.size();i++)
	{
		for(itr=L1[i].begin();itr!=L1[i].end();itr++)
		{
			fout<<*itr<<" ";
		}
//		fout<<endl;
		fout<<" Appears "<<getCount(L1[i])<<" times "<<endl;
	}
	for(int k=2;1;k++)
	{
		vector<set<int> > CK=GenerateApriori(minsupcount,L1,k);
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
			fout<<" Appears "<<getCount(CKF[i])<<" times "<<endl;
		}
		if(CKF.size()==0)
		break;
		else
		L1=CKF;
	}
	return 0;
}
