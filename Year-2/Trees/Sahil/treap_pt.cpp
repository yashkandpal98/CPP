#include <iostream>

using namespace std;

typedef
struct trnode{
    struct trnode *lchild;
    int bdata;
    int hdata;
    struct trnode *rchild;
} *trptr;

trptr SLRotate(trptr t){
	trptr root = t->rchild;
	trptr rlc = root->lchild;
	root->lchild = t;
	t->rchild = rlc;
	
	return root;
}

trptr SRRotate(trptr t){
	trptr root = t->lchild;
	trptr rrc = root->rchild;
	root->rchild = t;
	t->lchild = rrc;
	
	return root;
}

trptr insert(trptr t, trptr node){
    trptr root = t;
    if(t != NULL){
        if(node->bdata <= t->bdata){
            t->lchild = insert(t->lchild, node);
            if(t->hdata > t->lchild->hdata)
                root = SRRotate(t);
        }
        else{
            t->rchild = insert(t->rchild, node);
            if(t->hdata > t->rchild->hdata)
                root = SLRotate(t);
        }
        return root;
    }
    else{
        return node;
    }
}

void prtVrtcle(trptr t, int gap){
    if(t != NULL){
        int n = gap;
        while(n--)
            cout << " ";
        cout << t->bdata << " " << t->hdata << endl;
        prtVrtcle(t->lchild, gap+1);
        prtVrtcle(t->rchild, gap+1);
    }
}

int main(){
    trptr t[6], root = NULL;
    t[0] = new(trnode);
    root = t[0];
    t[0]->bdata = 50;
    t[0]->hdata = 2;
    
    t[1] = new(trnode);
    t[1]->bdata = 30;
    t[1]->hdata = 5;
    root = insert(root, t[1]);
    
    t[2] = new(trnode);
    t[2]->bdata = 70;
    t[2]->hdata = 10;
    root = insert(root, t[2]);
    
    t[3] = new(trnode);
    t[3]->bdata = 20;
    t[3]->hdata = 10;
    root = insert(root, t[3]);
    
    t[4] = new(trnode);
    t[4]->bdata = 40;
    t[4]->hdata = 14;
    root = insert(root, t[4]);
    
    t[5] = new(trnode);
    t[5]->bdata = 80;
    t[5]->hdata = 5;
    root = insert(root, t[5]);
    
    prtVrtcle(root, 1);
    
    return 0;
}