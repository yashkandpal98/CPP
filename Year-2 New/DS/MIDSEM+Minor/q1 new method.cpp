#include <iostream>
using namespace std;

typedef
struct bstnode{
    bstnode *lchild;
    int key;
    int *heap_ptr;
    bstnode *rchild;
}*BSTPTR;

void ins_heap(int H[],int &n,int k){
    if(k!=-1){
        H[++n]=k;
        for(int i=n;i>1;i--){
            if(H[i]<H[(i-1)/2])
                swap(H[i],H[(i-1)/2]);
        }
    }
}
void create(BSTPTR &T,int k,int x){
    if(T==NULL){
        T=new(bstnode);
        T->lchild=NULL;
        T->rchild=NULL;
        T->key=k;
        T->heap_ptr=new int [50];
        T->heap_ptr[0]=1;//storing size at index 0
        T->heap_ptr[1]=x;
    }else{
        if(k<T->key)
            create(T->lchild,k,x);
        else if(k>T->key)
            create(T->rchild,k,x);
        else
            ins_heap(T->heap_ptr,T->heap_ptr[0],x);
    }
}
void find_node(BSTPTR T,int k,int tag=0){
    static int i=1;
    if(tag==0){
        if(T!=NULL){
            if(k<T->key)
                find_node(T->lchild,k,tag);
            else if(k>T->key)
                find_node(T->rchild,k,tag);
            else if(k==T->key)
                find_node(T,k,1);
        }else
            cout<<-1;
    }else if(tag==1){
        if(i<=T->heap_ptr[0]){
            cout<<T->heap_ptr[i++]<<" ";
            find_node(T,k,1);
        }
    }
}
int main(){
    BSTPTR T1=NULL;
    int n1,n2;
    cout<<"Enter elements: (-1 -1 to terminate) ";
    cin>>n1>>n2;
    while(n1!=-1&&n2!=-1){
        create(T1,n1,n2);
        cin>>n1>>n2;
    }
    cout<<"Enter key to be found: ";
    cin>>n1;
    find_node(T1,n1);
}
