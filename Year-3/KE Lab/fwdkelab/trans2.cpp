#include<bits/stdc++.h>
using namespace std;
int main()
{
	int item=8,t=41;
	ifstream fin;
	ofstream f;
	f.open("Result.txt");
	fin.open("Database1.txt");
	char ch;
	map<char,int> mp;
	for(int i=0;i<t;i++)
	{
		for(int j=0;j<5;j++)
		{
			fin>>ch;
			//cout<<ch;
		}
		while(ch!='-')
		{
			mp[ch]++;
			fin>>ch;
		}
	}
	f<<"\n-!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n";
	map<char,int>::iterator itr;
	for(itr=mp.begin();itr!=mp.end();itr++)
	{
		if(itr->first=='>')
		continue;
		
	f<<"Transaction "<<itr->first<<" is =>"<<itr->second<<" times"<<endl;
	
	cout<<"Transaction "<<itr->first<<" is =>"<<itr->second<<" times"<<endl;
	}
	fin.close();
	fin.open("Database1.txt");
	vector<int> v[item];
	for(int i=1;i<=t ;i++)
	{
		cout<<endl<<i<<" ---> ";
		fin>>ch;
		while(ch!='>')
		fin>>ch;
		fin>>ch;
		while(ch!='-')
		{
			v[ch-'0'].push_back(i);
			cout<<ch<<" ";
			fin>>ch;
		}
	}
	f<<"\n-----------------------------------------\n";
	cout<<"--------------------------------------------------\n";
	for(int i=1;i<item;i++)
	{
		cout<<i<<"=> ";
		f<<i<<"=> ";
		for(int j=0;j<v[i].size();j++)
		{
			//cout<<v[i][j]<<" ";
			f<<v[i][j]<<" ";
		}
		cout<<"\n";
		f<<"\n";
	}
	f<<"frequent item sets are the following----\n";
	char arr[50],c=0;
	for(itr=mp.begin();itr!=mp.end();itr++)
	{
		if(itr->first=='>')
		continue;
		if(itr->second>17)
		{
			
			f<<"Transaction "<<itr->first<<"\n";
			arr[c++]=itr->first;
		}
	}
	f<<"\n&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n";
	cout<<"========";
	fin.close();
	fin.open("Database1.txt");
	for(int i=0;i<c;i++)
	{
		for(int j=i+1;j<c;j++)
		{
			//cout<<arr[i]<<" "<<arr[j]<<"\n";
			
				int count=0;
				fin.close();
				fin.open("Database1.txt");
			for(int k=1;k<t;k++)
			{
				//cout<<endl<<i<<" ---> ";
				fin>>ch;
				//cout<<ch;
				while(ch!='>')
				fin>>ch;
				fin>>ch;
				int f1,f2;
				f1=0,f2=0;
				while(ch!='-')
				{
					//cout<<ch<<"--"<<arr[i]<<arr[j]<<"\n";
					if(ch==arr[i])
					f1=1;
					if(ch==arr[j])
					f2=1;
					 			
					fin>>ch;
				}
				//cout<<f1<<f2<<"\n";
					if(f1==1&&f2==1)
					count++;
			}
			//cout<<count<<" ";
			if(count>7)
			{	
				f<<arr[i]<<" "<<arr[j]<<" appeared "<<count<<" times together.\n";
				cout<<count<<" "<<arr[i]<<" "<<arr[j]<<"\n";
			}
		}
	}
	f<<"\n*************************************************\n";
	for(int i=0;i<c;i++)
	{
		for(int j=i+1;j<c;j++)
		{
			for(int l=j+1;l<c;l++)
			{
				
				int count=0;
				fin.close();
				fin.open("Database1.txt");
				for(int k=1;k<t;k++)
				{
					//cout<<endl<<i<<" ---> ";
					fin>>ch;
					//cout<<ch;
					while(ch!='>')
					fin>>ch;
					fin>>ch;
					int f1,f2,f3;
					f1=0,f2=0,f3=0;
					while(ch!='-')
					{
						//cout<<ch<<"--"<<arr[i]<<arr[j]<<"\n";
						if(ch==arr[i])
						f1=1;
						if(ch==arr[j])
						f2=1;
						if(ch==arr[l])
						f3=1;		
						fin>>ch;
					}
					if(f1==1&&f2==1&&f3==1)
					count++;
				}
				if(count>4)
				{	
					f<<arr[i]<<" "<<arr[j]<<" "<<arr[l]<<" appeared "<<count<<" times together.\n";
					cout<<count<<" "<<arr[i]<<" "<<arr[j]<<" "<<arr[l]<<"\n";
				}
			}
		}
	}
	f<<"\n::::::::::::::::::::::::::::::::::::::::::::::\n";
	for(int i=0;i<c;i++)
	{
		for(int j=i+1;j<c;j++)
		{
			for(int l=j+1;l<c;l++)
			{
				for(int m=l+1;m<c;m++)
				{
					int count=0;
					fin.close();
					fin.open("Database1.txt");
					for(int k=1;k<t;k++)
					{
						//cout<<endl<<i<<" ---> ";
						fin>>ch;
						//cout<<ch;
						while(ch!='>')
						fin>>ch;
						fin>>ch;
						int f1,f2,f3,f4;
						f1=0,f2=0,f3=0,f4=0;
						while(ch!='-')
						{
							//cout<<ch<<"--"<<arr[i]<<arr[j]<<"\n";
							if(ch==arr[i])
							f1=1;
							if(ch==arr[j])
							f2=1;
							if(ch==arr[l])
							f3=1;
							if(ch==arr[m])
							f4=1;		
							fin>>ch;
						}
						if(f1==1&&f2==1&&f3==1&&f4==1)
						count++;
					}
					if(count>2)
					{	
						f<<arr[i]<<" "<<arr[j]<<" "<<arr[l]<<" "<<arr[m]<<" appeared "<<count<<" times together.\n";
						cout<<count<<" "<<arr[i]<<" "<<arr[j]<<" "<<arr[l]<<" "<<arr[m]<<"\n";
					}
				}
			}
		}
	}
	f<<"\nnow, no other item sets are frequent\n";
	return 0;
}
