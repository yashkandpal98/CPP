 #include<iostream>
using namespace std;
int main()
{
    cout<<"Enter number of vertex \n";
    int n,s,c;
    cin>>n;
    int a[n][n];
    int visit[n]={0};
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>a[i][j];
        }
    }
    cout<<"enter source vertex  \n";
    cin>>s;
    int path=0;
    int count=2;
    int b,d,p;
    int min;
    c=s;
            for(int j=0;j<n;j++)
            {
                if(a[c][j]!=0)
                {
                    if(a[c][j]<d)
                    {
                        d=a[c][j];
                        b=j;
                    }
                }
            }
            path+=d;
            visit[b]=1;
            visit[c]=1;
            cout<<c+1<<" "<<b+1<<endl;
    while(count<n)
    {
            d=100;
            for(int i=0;i<n;i++)
            {
                if(visit[i]==1)
                {
                    for(int j=0;j<n;j++)
                    {
                        if(visit[j]==0)
                        {
                            if(a[i][j]!=0)
                            {
                                if(a[i][j]<d)
                                {
                                    d=a[i][j];
                                    b=j;
                                    p=i;
                                }

                            }
                        }
                    }
                }
            }
            path+=d;
            visit[b]=1;
            cout<<p+1<<" "<<b+1<<endl;
            count++;
    }
    cout<<path;
return 0;
}
