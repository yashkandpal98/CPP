#include<iostream>
using namespace std;
int find(int a[],int x)
{
    if(a[x]==0)return x;
    else
    {
        return find(a,a[x]);

    }
}
struct node
{
    int d;
    int y;
    int z;
};
void create(int a[],int n,int x,int y)
{
    if(find(a,x)!=find(a,y))
    {
    if(a[x]==0&&a[y]==0)
    {
        a[y]=x;
    }
    else if(a[x]==0&&a[y]!=0)
    {
        a[x]=find(a,y);
    }
    else if(a[x]!=0&&a[y]==0)
    {
        a[y]=find(a,x);
    }
    else if(a[x]!=0&&a[y]!=0)
    {
        create(a,n,x,a[y]);
    }
    }


}
void bubble(node a[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(a[j].d>a[j+1].d)
            {
                node t;
                t.y=a[j].y;
                t.z=a[j].z;
                t.d=a[j].d;
                a[j].d=a[j+1].d;
                a[j].y=a[j+1].y;
                a[j].z=a[j+1].z;
                a[j+1].d=t.d;
                a[j+1].y=t.y;
                a[j+1].z=t.z;
            }
        }
    }

}

int main()
{
cout<<"Enter number of vertices \n";
int n;
cin>>n;
int a[n+1]={0};
struct node e[50];
int S[10][10];
for(int i=1;i<=n;i++)
{
    for(int j=1;j<=n;j++)
    {
        cin>>S[i][j];
    }

}
int g[10][10];
for(int i=1;i<=n;i++)
{
    for(int j=1;j<=n;j++)
    {
        g[i][j]=S[i][j];
    }
}
int x=0;
for(int i=1;i<=n;i++)
{
    for(int j=1;j<=n;j++)
    {
       if(g[i][j]!=0)
       {
           e[x].d=g[i][j];
           e[x].y=i;
           e[x].z=j;
           x++;
           g[j][i]=0;
       }
    }
}
bubble(e,x);
int path=0;
for(int i=0;i<x;i++)
{
         if(find(a,e[i].y)!=find(a,e[i].z))
     {
         cout<<e[i].y<<" "<<e[i].z<<endl;
         path+=e[i].d;
    }
     create(a,n,e[i].y,e[i].z);

}
cout<<path;
for(int i=0;i<x;i++)
{
 //cout<<e[i].d<< " "<<e[i].y<<" "<<e[i].z<<endl;
}
return 0;
}
