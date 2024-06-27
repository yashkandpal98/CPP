#include<iostream>
using namespace std;


void ind(int graph[20][20], int indegree[], int n)
{
    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) if(graph[j][i] == 1) indegree[i]++;
}
    

void topological(int graph[20][20], int indegree[], int visited[], int n)
{
    int flag = 0, v;
    for(int i = 0; i < n; i++)
    {  
        if(visited[i] != 1)
        {
            flag = 1;
            break;
        }
    }
    if(flag == 0)
    {
        cout<<"All choices completed";
        return;
    }
    
    cout<<"Available vertices are: ";
    for(int i = 0; i < n; i++) if(indegree[i] == 0 && visited[i] != 1) cout<<i+1<<" ";
    
    cout<<endl<<"Enter vertex to select: "; cin>>v;
    
    visited[v-1] = 1;
    for(int i = 0; i< n; i++) if(graph[v-1][i] == 1) indegree[i]--;
    topological(graph, indegree, visited, n);
}   


int main()
{
    int n;
    cout<<"Enter number of elements: "; cin>>n;
    int a[20][20], indegree[n] = {0}, visited[n] = {0};
    
    cout<<"Enter 1 if edge exists, 0 if not:\n";
    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) cin>>a[i][j];
    
    ind(a, indegree, n);
    
    topological(a, indegree, visited, n);
}


/*
14
0 0 0 0 0 1 0 0 0 0 0 0 0 0
0 0 0 0 0 0 1 0 0 0 0 0 0 0
0 0 0 0 0 0 0 1 0 0 0 0 0 0
0 0 0 0 0 1 1 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 1 0 0 0
0 0 0 0 0 0 0 0 0 1 0 0 0 0
0 0 0 0 0 0 0 0 1 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 1 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 1 1
0 0 0 0 0 0 0 0 0 0 0 1 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 1
0 0 0 0 0 0 0 0 0 0 0 0 0 1
0 0 0 0 0 0 0 0 0 0 0 0 0 1
0 0 0 0 0 0 0 0 0 0 0 0 0 0
1 4 2 3 6 5 7 8 11 9 13 10 12 14
*/
