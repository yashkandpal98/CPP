#include<bits/stdc++.h>

using namespace std;


int solution(string S) {
    int count = 1, max = INT_MIN, x = 1;
    char c = S[0];
    
    for(int i = 1; i < S.length(); i++) {
        if(S[i] != c) {
            count++;
            c = S[i];
            x = 1;
        }
        else {
            count++;
            x++;
        }
        
        if(x == 3) {
            count = 2;
            x--;
        }
        
        if(count > max) max = count;
    }
    
    return max;
    /*baaabbabbb
    babba
    abaaaa*/
}

int main()
{
	string s;
	
	cin>>s;
	
	cout<<endl<<solution(s);
	
}
