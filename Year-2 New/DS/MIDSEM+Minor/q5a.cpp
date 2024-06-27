#include <iostream>
#include <string>
using namespace std;

typedef
struct hcnode{
    hcnode *lchild;
    char data;
    hcnode *rchild;
}*HPTR;

void create(HPTR &T,char c,string code,int i=0){
    if(T==NULL){
        T=new(hcnode);
        T->lchild=NULL;
        T->rchild=NULL;
        T->data='.';
    }
    if(i==code.length()){
        T->data=c;
        return;
    }
    if(code[i]=='0')
        create(T->lchild,c,code,i+1);
    else if(code[i]=='1')
        create(T->rchild,c,code,i+1);
}
void dlrprint(HPTR T){
    if(T!=NULL){
        cout<<T->data<<" ";
        dlrprint(T->lchild);
        dlrprint(T->rchild);
    }
}
int main(){
    //a 000 g 01 t 101 d 111 . .
    HPTR T1=NULL;
    char c1;
    string code1;
    cin>>c1>>code1;
    while(c1!='.'&&code1!="."){
        create(T1,c1,code1);
        cin>>c1>>code1;
    }
    dlrprint(T1);
    return 0;
}
