#include<iostream>
using namespace std;

struct queue
{
	int f;
	int r;
	int elements[50];
	int size;
};


void enqueue(queue &q,int x)
{
	if(q.f==(q.r+1)%q.size)
		cout<<"queue is full";
	else
	{
		if(q.r==-1)
			q.f=0;
		q.r=(q.r+1)%q.size;
		q.elements[q.r]=x;
		}	
}

int dequeue(queue &q)
{
	int t;
	if(q.f==-1)
		cout<<"stack is empty";
	else
	{
		t=q.elements[q.f];
		if(q.f==q.r)
		{
			q.f=-1;
			q.r=-1;
		}
		else
			q.f=(q.f+1)%q.size;
		}	
		return t;
}

void insert(int n, int a[10][10])
{
	for(int i = 0; i < n; i++) for(int j = 0; j < n; j++){
		cin>>a[i][j];
		cout<<"Edge between "<<i+1<<" and "<<j+1<<"\n";
	}
}

void dft(int a[10][10], int p[], int u, int n, int cnt)
{
    int visited[n] = {0};
    
    for(int i = 0; i < cnt; i++) if(p[i] == u) return;
    
    if(cnt != n-1)
    {
        p[cnt] = u;
        visited[u-1] = 1;
        for(int i = 0; i < n; i++) if(a[u-1][i] == 1) if(! visited[i]) dft(a, p, i+1, n, cnt+1);
    }
    else
    {
        for(int j = 0; j < cnt; j++) cout<<p[j]<<" ";
        cout<<u<<endl;
    }
}

void bft(int a[10][10], int p[], int u, int n, int count, queue &Q)
{
    int visited[n] = {0};
    
    for(int i = 0; i < n; i++) if(p[i] == u) return;
    
    if(count != n-1)
    {
        p[count] = u;
        enqueue(Q, u);
        
    }
    
}


int main()
{
    queue Q;
    Q.f = Q.r = -1;
	int n;
	int a[10][10], p[20] = {0};
	
	cout<<"Enter number of vertices: "; cin>>n;
	cout<<"Enter edges:\n\n";
	insert(n, a);
	
	for(int i = 0; i < n; i++)
	{
	    for(int j = 0; j < n; j++)cout<<a[i][j]<<" ";
	    cout<<endl;
	}
	
	cout<<endl;
	dft(a, p, 1, n, 0);
	
	return 0;
}
