#include <iostream>
using namespace std;

typedef
struct bstnode{
    bstnode *lchild;
    bstnode *rchild;
    int data;
    int space;
} *BSTPTR;
typedef
struct lnode{
    BSTPTR data;
    lnode *next;
} *LPTR;

struct bst_queue{
    LPTR f;
    LPTR r;
};
typedef bst_queue *QPTR;
void bst_sort(BSTPTR T){
    static int c=0;
    if(T!=NULL){
        bst_sort(T->lchild);
        T->space=c++;
        bst_sort(T->rchild);
    }
}
void bst_enq(QPTR &Q,BSTPTR T){
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
BSTPTR bst_deq(QPTR Q){
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
void const_bst_preord(BSTPTR &T, int A[], int high, int low=0){
        T=new(bstnode);
        T->data=A[low];
        T->lchild=NULL;
        T->rchild=NULL;
        int j=low+2;
        if(j>high)
            return;
        while(A[j]<A[low])j++;
        const_bst_preord(T->lchild,A,j,low+1);
        const_bst_preord(T->rchild,A,high,j);
}
void tree_printer(BSTPTR T1){
    BSTPTR tag=new(bstnode),T2;
    bst_sort(T1);
    QPTR Q1=new(bst_queue);
    Q1->f=NULL;
    Q1->r=NULL;
    tag->data=-1;
    tag->lchild=NULL;
    tag->rchild=NULL;
    bst_enq(Q1,T1);
    bst_enq(Q1,tag);
    int prevsp=0;
    while(Q1->f!=NULL){
        T2=bst_deq(Q1);
        if(T2->data==-1){
            cout<<"\n";
            bst_enq(Q1,T2);
            prevsp=0;
            continue;
        }
        for(int i=0;i<T2->space-prevsp-1;i++)
            cout<<" ";
        cout<<T2->data;
        if(T2->lchild!=NULL)
            bst_enq(Q1,T2->lchild);
        if(T2->rchild!=NULL)
            bst_enq(Q1,T2->rchild);
        prevsp=T2->space;
        if(Q1->f->data==tag&&Q1->r->data==tag)
            break;
    }
}
int main(){
    BSTPTR T1=NULL;
    int arr[9]={18,12,5,2,9,16,36,20,45};
    const_bst_preord(T1,arr,9);
    bst_sort(T1);
    tree_printer(T1);
    return 0;
}
