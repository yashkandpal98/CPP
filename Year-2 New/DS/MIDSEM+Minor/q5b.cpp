#include <iostream>
#include <string>
using namespace std;

const int k=3;

typedef
struct kdnode{
    struct inpkd data;
    kdnode *lchild;
    kdnode *rchild;
}*KPTR;

union u{
    char c;
    int n;
};
struct inpkd{
    int k1[k/3];
    union u k2[k/3];
    int t2[k/3];
    string k3[k/3];
};
bool comparekeys(inpkd k1,inpkd k2,int i){
    if(i>=0&&i<k/3){
        i=(i+1)%(k/3);

    }
}
void search_kd(KPTR T,inpkd key){
    static int i=0;
    if(T!=NULL){
        if(T->data[i]>key[i]){
            i=(i+1)%k;
            return find_kd(T->lchild,key);
        }else if(T->data[i]<key[i]){
            i=(i+1)%k;
            return find_kd(T->rchild,key);
        }else{
            int j=(i+1)%k,flag=1;
            while(j!=i){
                if(T->data[j]!=key[j]){
                    flag=0;
                    break;
                }
                j=(j+1)%k;
            }
            if(flag==1)
                return 1;
            else
                return find_kd(T->rchild,key);
        }
    }else
        return 0;
    if(i>=0&&i<=k/3){
        i=(i+1)%k;
    }
    else if(i>k/3&&i<=2*k/3){
        i=(i+1)%k;
    }
    else if(i>2*k/3&&i<=k){
        i=(i+1)%k;
    }

}
