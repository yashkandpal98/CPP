#include<bits/stdc++.h>
using namespace std;


vector<int> sort(vector<int> arr)
{
	for(int i = 0; i < arr.size(); i++)
	{
		for(int j = i+1; j < arr.size(); j++)
		{
			if(arr[i] > arr[j])
			{
				arr[i] += arr[j];
				arr[j] = arr[i]-arr[j];
				arr[i] -= arr[j];
			}
		}
	}
	
	return arr;
}

vector<int> SCAN(vector<int> request, vector<int> cylinder, int dirn, int start, vector<int> dist)
{
	if(request.size() == 0) return dist;
	
	int read = 0, sum = 0;
	
	if(dirn == 1) // 1 = go right || -1 = go left
	{
		for(int i = 0; i < request.size(); i++)
		{
			if(request[i] > start)
			{
				read = i;
				break;
			}
		}
		
		for(int i = start; i < cylinder.size(); i++)
		{
			if(read > request.size()-1 || request.size() == 0)
			{
				dist[0]++;
				continue;
			}
			
			if(request[read] == cylinder[i])
			{
				dist[0] += sum;
				cout<<request[read]<<" ";
				request.erase(request.begin()+read);
				sum = 1;
			}
			else sum++;
		}
		
		dist[1]++;
		
		return SCAN(request, cylinder, -1, cylinder[cylinder.size()-1], dist);
	}
	else if(dirn == -1)
	{
		for(int i = request.size()-1; i >= 0; i--)
		{
			if(request[i] < start)
			{
				read = i;
				break;
			}
		}
		
		for(int i = start; i >= 0; i--)
		{
			if(read < 0 || request.size() == 0)
			{
				dist[0]++;
				continue;
			}
			
			if(request[read] == cylinder[i] || request.size() == 0)
			{
				dist[0] += sum;
				cout<<request[read]<<" ";
				request.erase(request.begin()+(read--));
				sum = 1;
			}
			else sum++;
		}
		
		dist[1]++;
		
		return SCAN(request, cylinder, 1, cylinder[0], dist);
	}
	
	return dist;
}

vector<int> SCANWrap(vector<int> request, vector<int> cylinder, int start, vector<int> dist)
{
	request = sort(request);
	cout<<"\nRequest array after sorting:\n";
	for(int i = 0; i < request.size(); i++) cout<<request[i]<<" ";
	cout<<"\nScanning sequence of requests:\n";
	return SCAN(request, cylinder, -1, start, dist);
}

vector<int> LOOK(vector<int> request, vector<int> cylinder, int dirn, int start, vector<int> dist)
{
	if(request.size() == 0) return dist;
	
	int read = 0, sum = 0, i;
	
	if(dirn == 1) // 1 = go right || -1 = go left
	{
		for(i = 0; i < request.size(); i++)
		{
			if(request[i] > start)
			{
				read = i;
				break;
			}
		}
		
		for(i = start; i < cylinder.size(); i++)
		{
			if(read > request.size()-1 || request.size() == 0) break;
			
			if(request[read] == cylinder[i])
			{
				dist[0] += sum;
				cout<<request[read]<<" ";
				request.erase(request.begin()+read);
				sum = 1;
			}
			else sum++;
		}
		
		dist[1]++;
		
		return LOOK(request, cylinder, -1, cylinder[i-1], dist);
	}
	else if(dirn == -1)
	{
		for(i = request.size()-1; i >= 0; i--)
		{
			if(request[i] < start)
			{
				read = i;
				break;
			}
		}
		
		for(i = start; i >= 0; i--)
		{
			if(read < 0 || request.size() == 0) break;
			
			if(request[read] == cylinder[i] || request.size() == 0)
			{
				dist[0] += sum;
				cout<<request[read]<<" ";
				request.erase(request.begin()+(read--));
				sum = 1;
			}
			else sum++;
		}
		
		dist[1]++;
		
		return LOOK(request, cylinder, 1, cylinder[i+1], dist);
	}
	
	return dist;
}

vector<int> LOOKWrap(vector<int> request, vector<int> cylinder, int start, vector<int> dist)
{
	request = sort(request);
	cout<<"\n\nRequest array after sorting:\n";
	for(int i = 0; i < request.size(); i++) cout<<request[i]<<" ";
	cout<<"\n\nScanning sequence of requests:\n";
	return LOOK(request, cylinder, -1, start, dist);
}

int main()
{
	vector<int> cylinder;
	vector<int> request;
	vector<int> dist;
	
	request.push_back(23);
	request.push_back(89);
	request.push_back(132);+
	request.push_back(42);
	request.push_back(187);
	
	dist.push_back(0);
	dist.push_back(0);
	
	for(int i = 0; i < 200; i++) cylinder.push_back(i);
	
	cout<<"Cylinder range = 0 to 199\n\nRequest array before sorting:\n";
	for(int i = 0; i < request.size(); i++) cout<<request[i]<<" ";
	
	dist = LOOKWrap(request, cylinder, 100, dist);
	cout<<"\n\n\nTotal no. of disk movements= "<<dist[1]<<endl;
	cout<<"Total distance travelled= "<<dist[0]<<endl;
	
	return 0;
}
