#include<iostream>
using namespace std;


bool outdegree(int a[20][20], int u, int n)
{
	for(int i = 0; i < n; i++) if(a[u-1][i] != -1) return true;
	return false;
}

void print(int preVertex[], int i)
{
    if(preVertex[i] == -1) cout<<i+1;
    else
    {
        print(preVertex, preVertex[i]-1);
        cout<<"->"<<i+1;
    }
}

void sort(int graph[20][20], int a[], int n, int x)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = i+1; j < n; j++)
        {
            if(graph[x][a[i]-1] > graph[x][a[j]-1])
            {
                a[i] += a[j];
                a[j] = a[i] - a[j];
                a[i] -= a[j];
            }
        }
    }
}

void dijkstra(int graph[20][20], int distance[], int preVertex[], int visited[], int source, int destination, int n)
{
	if((source == destination) || (!outdegree(graph, source, n)) || (visited[source-1] == 1)) return;
	else
	{
		int min[n], x = 0;
		for(int i = 0; i < n; i++) if(graph[source-1][i] != -1) min[x++] = i+1;

		sort(graph, min, x, source-1);

		for(int i = 0; i < n; i++)
		{
			if(graph[source-1][i] != -1)
			{
				if(distance[i] > distance[source-1]+graph[source-1][i])
				{
					distance[i] = distance[source-1]+graph[source-1][i];
					preVertex[i] = source;
				}
			}
		}

		if((visited[preVertex[source-1]-1] == 0) && (preVertex[source-1] != -1)) return;

		for(int i = 0; i < x; i++) dijkstra(graph, distance, preVertex, visited, min[i], destination, n);
		visited[source-1] = 1;
		for(int i = 0; i < x; i++) dijkstra(graph, distance, preVertex, visited, min[i], destination, n);
	}
}

void cover(int graph[20][20], int distance[], int preVertex[], int visited[], int source, int destination, int n)
{
    dijkstra(graph, distance, preVertex, visited, source, destination, n);
    print(preVertex, destination-1);
}

int main()
{
	int graph[20][20], n, source, destination;

	cout<<"Enter number of elements: "; cin>>n;

	int distance[n], preVertex[n], visited[n];

	for(int i = 0; i < n; i++)
	{
	    distance[i] = 1000;
	    preVertex[i] = 0;
	    visited[i] = 0;
	}

	/*-1 2 -1 1 -1 -1 -1
    -1 -1 -1 3 10 -1 -1
    4 -1 -1 -1 -1 5 -1
    -1 -1 2 -1 2 8 4
    -1 -1 -1 -1 -1 -1 6
    -1 -1 -1 -1 -1 -1 -1
    -1 -1 -1 -1 -1 1 -1 */

	cout<<"Enter weight if edge exists, and -1 if not:\n\n";

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			cin>>graph[i][j];
		}
	}

	cout<<endl<<endl;
	for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++) cout<<graph[i][j]<<" ";
        cout<<endl;
    }

    cout<<endl<<"Enter source vertex: "; cin>>source;
	cout<<"Enter destination vertex: "; cin>> destination;

	distance[source-1] = 0;
	preVertex[source-1] = -1;

    cout<<endl<<endl;

	cover(graph, distance, preVertex, visited, source, destination, n);
}
