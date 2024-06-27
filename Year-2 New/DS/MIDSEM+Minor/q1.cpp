#include <iostream>
using namespace std;

typedef
struct bstnode{
    bstnode *lchild;
    int key;
    struct heap *heap_ptr;
    bstnode *rchild;
}*BSTPTR;

struct heap{
    int H[50];
    int siz;
};

void ins_heap(int H[],int &n,int k){
    if(k!=-1){
        H[n]=k;
        for(int i=n;i>0;i--){
            if(H[i]<H[(i-1)/2])
                swap(H[i],H[(i-1)/2]);
        }
        int k1;
        cin>>k1;
        ins_heap(H,++n,k1);
    }
}
void create(BSTPTR &T,int k,int x){
    if(T==NULL){
        T=new(bstnode);
        T->lchild=NULL;
        T->rchild=NULL;
        T->key=k;
        T->heap_ptr=new(heap);
        T->heap_ptr->siz=0;
        T->heap_ptr->H[T->heap_ptr->siz++]=x;
    }else{
        if(k<T->key)
            create(T->lchild,k,x);
        else if(k>T->key)
            create(T->rchild,k,x);
        else
            ins_heap(T->heap_ptr->H,T->heap_ptr->siz,x);
    }
}
int main(){
    BSTPTR T1=NULL;
    int n1,n2,n3;
    cout<<"Enter number of elements: ";
    cin>>n3;
    for(int i=0;i<n3;i++){
        cin>>n1>>n2;
        create(T1,n1,n2);
    }
}
