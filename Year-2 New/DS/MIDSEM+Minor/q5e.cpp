#include <iostream>
using namespace std;

typedef
struct lnode{
    int data;
    lnode *next;
}*LPTR;

void inpLL(LPTR &L){
    LPTR T;
    int n;
    cout<<"New Linked List\n";
    cout<<"Enter elements (-1 to terminate): ";
    cin>>n;
    while(n!=-1){
       LPTR temp;
       temp=new(lnode);
       temp->data=n;
       temp->next=NULL;
       if(L==NULL){
           L=temp;
           T=L;
       }else{
           T->next=temp;
            T=T->next;
       }
       cin>>n;
    }
}
int main(){
    //3 6 4 8 9 7 5 10 18 20 15 -1
    LPTR L1=NULL,T;
    inpLL(L1);
    T=L1;
    int i=0,flag=1;
    while(T!=NULL){
        LPTR T1=T;
        for(int j=0;j<i+1;j++)
            T1=T1->next;
        if(T1==NULL)
            break;
        if(T1->next==NULL){
            if(T1->data<T->data)
                flag=0;
            break;
        }
        if(T1->data<T->data||T1->next->data<T->data){
            flag=0;
            break;
        }
        T=T->next;i++;
    }
    if(flag)
        cout<<"true, sequence is a heap.";
    else
        cout<<"false, sequence is not a heap.";
}
