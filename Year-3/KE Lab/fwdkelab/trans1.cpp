#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,k,n1;
	//srand(time(0));
	ofstream f;
	f.open("Database1.txt");
	int t=rand()%50;
	n=rand()%20;
	for(int i=1;i<=t;i++)
	{
		f<<"T"<<i<<"-> ";
	 	n1=rand()%n+1;
		set<int> s;
		for(int j=0;j<n1;j++)
		{
			k=rand()%n+1;
			s.insert(k);
		}
		set<int> :: iterator itr;
		for(itr=s.begin();itr!=s.end();itr++)
		{
			f<<*itr<<" ";
		}
		f<<"-\n";
	}
	f.close();
	return 0;
}
