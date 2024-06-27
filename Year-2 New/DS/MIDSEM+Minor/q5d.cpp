#include <iostream>
using namespace std;

bool serealizedstring(char btstr[],int &i){
    static int c=1;
    if(btstr[i]=='\0')
        return (c==0)?1:0;
    else if(btstr[i]==',')
        return serealizedstring(btstr,++i);
    else if(btstr[i]>='0'&&btstr[i]<='9'){
        while(btstr[i]!=',')i++;
        c++;
        return serealizedstring(btstr,i);
    }else if(btstr[i]=='#'){
        c--;
        return serealizedstring(btstr,++i);
    }
}

int main(){
    //26
    //9,3,4,#,#,1,#,#,2,#,6,#,#
    char *str;
    int n,j=0;
    cout<<"Enter size of string: ";
    cin>>n;
    str=new char[n];
    cout<<"enter string: ";
    cin>>str;
    if(serealizedstring(str,j))
        cout<<"String is serealized.";
    else
        cout<<"Not serealized.";
    return 0;
}
