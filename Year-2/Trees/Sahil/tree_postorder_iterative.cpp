//print post order iteratively


#include<stack>
#include<iostream>
using namespace std;

struct btnode
{int data;
 btnode *lchild,*rchild;
 };


 class tree
 {public:
  btnode *root;
  string input;
  int index;
  int i;
  //list topv;
  
  
  int x,y;

  btnode *store[100];
  int istore;
  //queue revstore;


  tree()
  {index=0; istore=0;
  root =new btnode;
  root->lchild=NULL;
  root->rchild=NULL;
  
   }

  

  void input_tree(btnode *t)
  {//cout<<"\n enter 1 to continue: ";  			  	  //cin>>cont1;
   int x;
   //cout<<"\n input function: ";
   //cout<<"\n data to be stored in this node is: "<<input[index];
   t->data=input[index]-48;
   index++;
   t->lchild=NULL; //initializing with NULL values	
   t->rchild=NULL; //initializing with NULL values
   if(input[index]!='~')
   		{//cout<<"\n left child exists for "<<t->data;
   		 //cout<<"\n recursing to the node: ";
   		 t->lchild=new btnode;
   		 input_tree(t->lchild);
        }
    else {//cout<<"\n left child of "<<t->data<<" does not exist! ";
          index++;}
     // whatever existed at left pointer has been taken care of
    if(input[index]!='~')
   		{//cout<<"\n right child exists for "<<t->data;
   		 //cout<<"\n recursing to the node: ";
   		 t->rchild=new btnode;
   		 input_tree(t->rchild);
        }
    else {//cout<<"\n right child of "<<t->data<<" does not exist! ";
           index++;}
    //cout<<"\n input for "<<t->data<<" has been taken";
}

void printpre(btnode *root)
{stack <btnode*> s;

 btnode *l=root;
 s.push(l);
 while(!s.empty())
 {l=s.top();s.pop();
  cout<<l->data<<" ";
  if(l->rchild!=NULL)
  		s.push(l->rchild);
  if(l->lchild!=NULL)
  		s.push(l->lchild);
 }
}



};


int main()
{int choice,cont;
 tree t;
 cout<<"\n enter the tree: ";
 cin>>t.input;
 t.input_tree(t.root);
 cout<<"\n tree has been inputted!";
 cout<<"\n printing pre order iteratively: ";
 t.printpre(t.root);
 return 0;
}
