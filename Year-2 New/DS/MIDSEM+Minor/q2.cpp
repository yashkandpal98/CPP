#include <iostream>
using namespace std;

union u{
    char cs[20];
    int n;
    char c;
    struct mlnode *dlink;
};
struct mlnode{
    union u data;
    mlnode *next;
    int tag;
};
typedef mlnode *MPTR;

MPTR inpML(char ln[],MPTR &M,MPTR lp[]){
    MPTR temp=new(mlnode),T=M;
    cout<<"Enter tag(1-char, 2-down link,3-integer, 4-cstring -1 to terminate downlink): ";
    cin>>temp->tag;
    temp->next=NULL;
    if(temp->tag==1){
        cout<<"Enter character: ";
        cin>>(temp->data).c;
        if((temp->data).c>='A'&&(temp->data).c<='Z'){
            temp->tag=2;
            int j=0;
            while(ln[j]!=(temp->data).c)
                j++;
            if(lp[j]==NULL){
                cout<<"Enter "<<ln[j]<<endl;
                lp[j]=inpML(ln,lp[j],lp);
            }
            (temp->data).dlink=lp[j];
        }
    }
    else if(temp->tag==2)
        (temp->data).dlink=inpML(ln,temp,lp);
    else if(temp->tag==3){
        cout<<"Enter integer: ";
        cin>>temp->data.n;
    }else if(temp->tag==4){
        cout<<"Enter cstring: ";
        cin.ignore();
        cin>>temp->data.cs;
    }
    if(temp->tag==-1)
        return NULL;
    if(M==NULL){
        M=temp;
        T=M;
        inpML(ln,T,lp);
        return M;
    }else{
        T->next=temp;
        T=T->next;
        T->next=inpML(ln,T,lp);
        return T;
    }
 }
 void outML(MPTR M){
    if(M==NULL)
        return;
    else if(M->tag==1)
        cout<<(M->data).c<<",";
    else if(M->tag==2)
        outML((M->data).dlink);
    else if(M->tag==3)
        cout<<M->data.n<<",";
    else if(M->tag==4)
        cout<<M->data.cs<<",";
    outML(M->next);
 }
int main(){
    //4
    int n;
    cout<<"Enter number of lists: ";
    cin>>n;
    char lname[n];
    MPTR lptrs[n];
    cout<<"Enter the names: ";
    //A C G
    for(int i=0;i<n;i++){
        cin>>lname[i];
        lptrs[i]=NULL;
    }
    cout<<"Enter for list "<<lname[0]<<endl;
    //3 5 3 18 1 C 3 7 1 p 3 3 4 btech 1 G 3 27 1 r 4 cse -1 3 45 -1 2 3 36 1 s 1 G 4 nitw -1 3 9 -1
    inpML(lname,lptrs[0],lptrs);
    cout<<"{";
    outML(lptrs[0]);
    cout<<"}";
}

