#include <iostream>
#include <cstdlib>
using namespace std;

union u{
    int opd;
    char opr;
};
typedef
struct lnode{
    struct btnode *data;
    lnode *next;
}*LPTR;
typedef
struct btnode{
    btnode *lchild;
    union u data;
    btnode *rchild;
    int tag;
} *BTPTR;
typedef
struct btqueue{
    LPTR f;
    LPTR r;
};
typedef btqueue *QPTR;
void l_enq(QPTR Q,int x){
    LPTR temp;
    temp=new(lnode);
    temp->data=x;
    temp->next=NULL;
    if(Q->r==NULL){
        Q->f=temp;
        Q->r=temp;
    }else{
        Q->r->next=temp;
        Q->r=Q->r->next;
    }
}
int l_deq(QPTR Q){
    if(Q->f==NULL)
        cout<<"Queue is empty.";
    else{
        int t=Q->f->data;
        if(Q->f==Q->r){
            Q->f=NULL;
            Q->r=NULL;
        }else
            Q->f=Q->f->next;
        return t;
    }
}
void btcreate(BTPTR &T){
    QPTR Q1=new(btqueue);
    Q1->f=NULL;
    Q1->r=NULL;
    int n,i=0;
    cout<<"Enter size of the expression: ";
    cin>>n;
    char A[n+1];
    cin.ignore();
    cout<<"Enter the expression: ";
    cin.getline(A,n+1);
    while(A[i]!='\0'){
        int ni=0;
        char n[6]="";
        if(A[i]==' ')i++;
        if(A[i]>='0'&&A[i]<='9'){
            int l=i;
            while(A[i]!=' ')
                i++;
            for(l;l<i;l++)
                n[ni++]=A[l];
            int nd=atoi(n);
            BTPTR temp=new(btnode);
            temp->tag=0;temp->lchild=NULL;
            temp->rchild=NULL;
            (temp->data).opd=nd;
            btpush(S1,temp);
        }else{
            BTPTR temp=new(btnode);
            temp->tag=1;
            temp->lchild=btpop(S1);
            temp->rchild=btpop(S1);
            (temp->data).opr=A[i++];
            btpush(S1,temp);
        }
    }
    T=btpop(S1);
}
int eval(char op,int op2,int op1){
    switch(op){
        case('+'):
            return op2+op1;
        case('-'):
            return op2-op1;
        case('*'):
            return op2*op1;
        case('/'):
            return op2/op1;
    }
}
int treeval(BTPTR T){
    if(T->tag==1)
        return eval(T->data.opr,treeval(T->rchild),treeval(T->lchild));
    else
        return T->data.opd;
}
int main(){
    //15
    //18 2 3 * + 12 -
    BTPTR T1=NULL;
    btcreate(T1);
    cout<<treeval(T1);
    return 0;
}

