#include<iostream>
using namespace std;


void Articulation(int a[20][20], int source, int size, int visited[], int parent[], int low[], int articulate[])
{
	low[source-1] = source;
    visited[source-1] = 1;
    
    for(int i = 0; i < size; i++)
    {
        if(a[source-1][i] == 1)
        {
            if(visited[i] == 0)
            {
                Articulation(a, i+1, size, visited, parent, low, articulate);
                parent[i] = source;
                low[source-1] = min(low[source-1], low[i]);
                if(articulate[source-1] != 1 && low[i] >= source && low[source-1] != source) articulate[source-1] = 1;
            }
            else
            {
                if(parent[source-1] != i+1) low[source-1] = min(low[source-1],  i+1);
            }
        }
    }
}


int main()
{
    int n, a[20][20], source;
    cout<<"Enter number of vertices: "; cin>>n;
    
    int visited[n], parent[n], low[n], articulate[n];
    
    for(int i = 0; i < n; i++)
    {
    	visited[i] = 0;
    	parent[i] = 0;
    	low[i] = 0;
    	articulate[i] = 0;
	}
    
    /*10
0 1 0 1 0 0 0 0 0 0
1 0 1 0 0 0 0 0 0 0
0 1 0 1 1 0 1 0 0 0
1 0 1 0 0 0 0 0 0 0
0 0 1 0 0 1 1 0 0 0
0 0 0 0 1 0 1 1 1 1
0 0 1 0 1 1 0 0 0 0
0 0 0 0 0 1 0 0 1 1
0 0 0 0 0 1 0 1 0 1
0 0 0 0 0 1 0 0 1 0
1
*/
    
    cout<<"Enter '1' if edge exists and '0' if not:\n";
    for(int i = 0; i < n; i++) for(int j = 0; j< n; j++) cin>>a[i][j];
    
    cout<<endl;
    
    cout<<"Enter source vertex: "; cin>>source;
    
    Articulation(a, source, n, visited, parent, low, articulate);
    
    cout<<"\nArticulation points in the graph are: ";
    for(int i = 0; i < n; i++) if (articulate[i] == 1) cout<<i+1<<" ";
    
    return 0;
}
