#include<iostream>
using namespace std;


void permute(string s, int low, int high)
{
    if(low == high) cout<<s<<endl;
    else
    {
        for(int i = low; i <= high; i++)
        {
            char temp = s[low];
            s[low] = s[i];
            s[i] = temp;
            permute(s, low+1, high);
            /*temp = s[low];
            s[low] = s[i];
            s[i] = temp;*/
        }
    }
}

int main()
{
    string s;
    cout<<"Enter string: "; cin>>s;
    
    cout<<"\nAll possible permutations:\n";
    permute(s, 0, s.size()-1);
}
