#include <iostream>
using namespace std;

const int d=1;

typedef
struct bdnode{
    int cnt;
    int keys[2*d+1];
    bdnode *ptr[2*d+2];
} *BDPTR;

typedef
struct lnode{
    BDPTR data;
    lnode *next;
} *LPTR;

struct bst_queue{
    LPTR f;
    LPTR r;
};
typedef bst_queue *QPTR;
void bst_enq(QPTR &Q,BDPTR T){
    LPTR temp=new(lnode);
    temp->data=T;
    temp->next=NULL;
    if(Q->f==NULL){
        Q->f=temp;
        Q->r=temp;
    }else{
        Q->r->next=temp;
        Q->r=Q->r->next;
    }
}
BDPTR bst_deq(QPTR Q){
    if(Q->f==NULL)
        return NULL;
    LPTR temp=Q->f;
    if(Q->r==NULL){
        Q->f=NULL;
        Q->r=NULL;
    }else{
        Q->f=Q->f->next;
    }
    return temp->data;
}
void nodesplit(BDPTR &T,BDPTR Tp){
    BDPTR temp=new(bdnode);
    for(int i=0;i<2*d+2;i++)
        temp->ptr[i]=NULL;
    int mid=d,m=mid+1,n=0;
    if(T->ptr[0]==NULL){
        temp->keys[0]=T->keys[mid];
        n=1;
    }
    while(m<2*d+1)
        temp->keys[n++]=T->keys[m++];
    m=mid+1;n=0;
    while(m<2*d+2)
        temp->ptr[n++]=T->ptr[m++];
    T->cnt=d;
    temp->cnt=d;
    if(T->ptr[0]==NULL)
        temp->cnt=d+1;
    if(Tp==NULL){
        Tp=new(bdnode);
        Tp->keys[0]=T->keys[mid];
        Tp->cnt=1;
        for(int i=0;i<2*d+1;i++)
            Tp->ptr[i]=NULL;
        Tp->ptr[0]=T;
        Tp->ptr[1]=temp;
        T=Tp;
    }else{
        int j=0,k=T->keys[mid];
        while(Tp->keys[j]<k&&j<Tp->cnt)j++;
        for(int n=Tp->cnt;n>j;n--)
            Tp->keys[n]=Tp->keys[n-1];
        Tp->cnt+=1;
        for(int n=Tp->cnt;n>j+1;n--)
            Tp->ptr[n]=Tp->ptr[n-1];
        Tp->keys[j]=k;

        Tp->ptr[j+1]=temp;
    }
}
void ins_bd(BDPTR &T,BDPTR Tp,int k){
    if(T==NULL){
        T=new(bdnode);
        T->cnt=1;
        T->keys[0]=k;
        for(int i=0;i<2*d+2;i++)
            T->ptr[i]=NULL;
        return;
    }
    if(T->ptr[0]!=NULL){
        int j=0;
        while(T->keys[j]<k&&j<T->cnt)j++;
        ins_bd(T->ptr[j],T,k);
    }else{
        int j=0;
        while(T->keys[j]<k&&j<T->cnt)j++;
        for(int n=T->cnt;n>j;n--)
            T->keys[n]=T->keys[n-1];
        T->cnt+=1;
        T->keys[j]=k;
    }
    if(T->cnt==2*d+1)
        nodesplit(T,Tp);
}
void treeprintlevel(BDPTR T){
    BDPTR T2,tag=new(bdnode);
    QPTR Q1=new(bst_queue);
    Q1->f=NULL;
    Q1->r=NULL;
    tag->cnt=-1;
    bst_enq(Q1,T);
    bst_enq(Q1,tag);
    while(Q1->f!=NULL){
        T2=bst_deq(Q1);
        if(T2->cnt==-1){
            cout<<"\n";
            if(Q1->f==NULL)
                break;
            bst_enq(Q1,T2);
            continue;
        }
        cout<<"(";
        int i=0;
        for(i;i<T2->cnt;i++){
            cout<<T2->keys[i];
            if(i!=T2->cnt-1)cout<<",";
            if(T2->ptr[i]!=NULL)
                bst_enq(Q1,T2->ptr[i]);
        }
        if(T2->ptr[i]!=NULL)
            bst_enq(Q1,T2->ptr[i]);
        cout<<") ";
    }
}
int main(){
    //3 7 9 1 6 4 8 2 5 -1
    //6 4 2 1 9 3 7 5 8 -1
    //7 61 21 59 32 37 52 55 69 67 48 -1
    BDPTR T1=NULL,T2=NULL;
    int k1;
    cout<<"Enter elements(-1 to terminate): ";
    cin>>k1;
    while(k1!=-1){
        ins_bd(T1,NULL,k1);
        cin>>k1;
    }
    cout<<"\n";
    treeprintlevel(T1);
    return 0;
}
