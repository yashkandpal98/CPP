// avl


int cont1;


#include<iostream>
using namespace std;



struct btnode
{int data;
 btnode *lchild,*rchild;
 };

 



 class queue
	{public:
	 btnode *s[100];
	 int total;
	 int front,rear;
	 queue()
	   {front=-1;
	    rear=-1;
	    total=0;}

	 void add(btnode *a)
	 {if(!total)
	 	front=0;

	 	rear++;
	 	if(rear>99)
	 		rear-=100;
	  s[rear]=a;
	  //cout<<"\n the element whose pointer is added to the rear is: "<<a->data;
	  total++;
	  //cout<<"\n the queue total is: "<<total;
	  //cout<<"\n calling to display(): ";
	  //display();
	 }

	 /*void add()
	 {cout<<"\n enter the element to be added to the rear: ";
	 btnode *a;
	 cin>>a;
	 if(!total)
	 	front=0;
	 rear++;
	 if(rear>99)
	 		rear-=100;
	 s[rear]=a;
	 total++;
	 }
 */
	 void remove()
	  {cout<<"\n the element whose pointer to be removed from the queue is: "<<s[front]->data;
	   front++;
	   if(front>99)
	   	front-=100;
	   total--;
	   if(!total)
		{front=-1; rear=-1;}
	  }

	 btnode* rremove()   // extra r is used to denote that it returns a value. can't overload directly
	 	{btnode *a=s[front];
	 	 //cout<<"\n the element whose pointer to be removed from the queue is: "<<s[front];
	 	 front++;
	 	 if(front>99)
	   		front-=100;
	 	 total--;

	 	 if(!total)
		{front=-1; rear=-1;}
	 	 return a;
	 	}


	 void display()
    {cout<<"\n displaying queue front to rear: ";
     int i;
     if(front<=rear)
     	for(i=front;i<=rear;i++)
      		cout<<s[i]->data<<" ";
     else 
     	{for(i=front;i<100;i++)
      		cout<<s[i]->data<<" ";
      	 for(i=0;i<=rear;i++)
      		cout<<s[i]->data<<" ";
        }
	}

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
  queue revstore;


  tree()
  {index=0;istore=0;
  root =new btnode;
  root->lchild=NULL;
  root->rchild=NULL;
  
   }

  void input_tree_bst_store(btnode *l,int x)
  	{ if(x>l->data)
  		{if(l->rchild!=NULL)
  		   input_tree_bst_store(l->rchild,x);
  		 else {l->rchild=new btnode; 
  		       l->rchild->data=x;
  		       l->rchild->lchild=NULL;
  		       l->rchild->rchild=NULL;
  		      }
  		}
  	  else
  	    {  if(l->lchild!=NULL)
  		   input_tree_bst_store(l->lchild,x);
  		 else {l->lchild=new btnode; 
  		       l->lchild->data=x;
  		       l->lchild->lchild=NULL;
  		       l->lchild->rchild=NULL;
  		      }



  	    }
  	}


  void input_tree_bst()
  {int x;
  	while(index!=input.length())
  		{x=input[index]-48;
  		 cout<<"\n storing: "<<x;
  		 input_tree_bst_store(root,x);
  		 index++;
  		}
  }

  void input_tree(btnode *t)
  {//cout<<"\n enter 1 to continue: ";
   			  	  //cin>>cont1;
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


btnode *leftshift(btnode *k1)  //k1 comes to the left
	{btnode *k3=k1->rchild;
	 btnode *temp=k3->lchild;
	 k3->lchild=k1;
	 k1->rchild=temp;
	 return k3;
	}

btnode *rightshift(btnode *k1)
	{btnode *k3=k1->lchild;
	 btnode *temp=k3->rchild;
	 k3->rchild=k1;
	 k1->lchild=temp;
	 return k3;
	}


btnode *leftshift2(btnode *k1) //k1 comes to the left
	{btnode *k3=k1->rchild;
	 btnode *k2=k3->lchild;
	 btnode *b=k2->lchild;
	 btnode *c=k2->rchild;
	 k2->lchild=k1;
	 k2->rchild=k3;
	 k1->rchild=b;
	 k3->lchild=c;
	 return k2;

	 }


btnode *rightshift2(btnode *k1) 
	{btnode *k3=k1->lchild;
	 btnode *k2=k3->rchild;
	 btnode *b=k2->rchild;
	 btnode *c=k2->lchild;
	 k2->rchild=k1;
	 k2->lchild=k3;
	 k1->lchild=b;
	 k3->rchild=c;
	 return k2;

	 }




void all_layer(btnode *l)
 {	//creating dummy flag;
    btnode *flag=new btnode;
    flag->lchild=new btnode;
    flag->rchild=flag->lchild;
    flag->data=100;
    //cout<<"\n dummy flag created";
    											//cout<<"\n enter 1 to continue: ";
   			  	  								//cin>>cont1;
   	queue q; q.add(l);
   	//cout<<"\n function has been terminated and added the root to queue";
   												//cout<<"\n enter 1 to continue: ";
   			  	  								//cin>>cont1;
   	q.add(flag);
   	//cout<<"\n added the flag to the queue";
   	 btnode *el;
  	//cout<<"\n qtotal is: "<<q.total;
 	

 	while(q.total>1)
 		{										//cout<<"\n enter 1 to continue: ";
   			  	  								//cin>>cont1;
   		  el=q.rremove();
   		  //cout<<"\n removed from the queue pointing to: "<<el->data; 
   	                                            //cout<<"\n enter 1 to continue: ";
   			  	  								//cin>>cont1;

 	 			//do
 	 				//{
 	 					if(el!=flag)
 	 					{cout<<el->data<<" ";
             

 	 	 					if(el->lchild!=NULL)
 	 	 						{//cout<<"\n it has a left child!";
 	 	 						 q.add(el->lchild);
 	 	 						 // cout<<"\n pushing"; 
 	 	 						} 
 	 	 					if(el->rchild!=NULL)
 	 	 						{ //cout<<"\n it has a right child!";
 	 	 					     q.add(el->rchild);
 	 	 					     // cout<<"\n pushing";
 	 	 					    }
 	 					}
 	  				 else 
 	     				{cout<<"\n"; 
 	     			     //cout<<"next line";
 	     			      q.add(flag);
 	     			    }
 	      		
 	      			// el=q.rremove();


 	 				//}while(el!=NULL);

   }
  }


  int checkbalance(btnode *l)
  {if(l->lchild==NULL&&l->rchild==NULL)
  	 return 0;
  	 else
  	 	{int leftheight=0,rightheight=0;
  	 	 if(l->lchild!=NULL)
  	 	 	leftheight=checkheight(l->lchild);
  	 	 if(l->rchild!=NULL)
  	 		rightheight=checkheight(l->rchild);
  	     if(leftheight>(rightheight+1))
  	         return -1;
  	     else if(rightheight>(leftheight+1))
  	         return 1;
  	     else return 0;
  	    }

}

 int checkheight(btnode *l)
 {if(l->lchild==NULL&&l->rchild==NULL)
   return 1;
  else
    {if(l->rchild==NULL)
      return 1+checkheight(l->lchild);
     else if(l->lchild==NULL)
      return 1+checkheight(l->rchild);
     else
     	{return (1+max(checkheight(l->lchild),checkheight(l->rchild)));}
     }

 }



};














int main()
{tree t;
 int choice,cont,del;
 btnode *loc;
 do
 {
 	cout<<"\n enter 1 to add the data and 2 to convert to avl: ";
 	cin>>choice;
 	switch(choice)
 		{case 1: cout<<"\n enter the input sting: ";
 		 		 t.input="123456789"; //cin>>t.input;
 		 		 cout<<"\n input has been enterred! ";
 		 		 cout<<"\n enter 1 to continue: ";cin>>cont1;
 		 		 t.root->data=t.input[0]; t.index++;
 		 		 cout<<"\n enter 1 to continue: ";cin>>cont1;
 		 		 t.input_tree_bst();
 		 		 cout<<"\n tree has been inputted ";
 		 		 cout<<"\n\n Printing the tree row wise: ";
 		 		 t.all_layer(t.root);
 		 		 cout<<"\n rotating left singly: ";
 		 		 t.root=t.leftshift(t.root);
 		 		 cout<<"\n\n Printing the tree row wise: ";
 		 		 t.all_layer(t.root);

 		 		 break;

 		 /*case 2: cout<<"\n enter the number to be deleted: ";
 		 		 cin>>del;
 		 		 loc=t.nodesearch(del,t.root);
 		 		 //cout<<"\n node found points to: "<<loc->data;
 		 		 cout<<"\n enter 1 to continue: "; cin>>cont1;
 		 		 btnode *temp=loc->lchild;
 		 		 if(temp->lchild==NULL&&temp->rchild==NULL)
 		 		 	loc->lchild=NULL;
 		 		 loc->data=t.deletenode(temp);
 		 		 //cout<<"\n enter 1 to continue: "; cin>>cont1;
 		 		 cout<<"\n node has been deleted!";
 		 		 cout<<"\n enter 1 to continue to printing all layers: "; cin>>cont1;
 		 		 cout<<"\n\n Printing the tree row wise: \n\n";
 		 		 t.all_layer(t.root);
 		 		 break;
 		 */
 		 //case 2: cout<<"\n converting to avl: ";
 		         //t.convavl(t.root);

 		}
 		cout<<"\n enter 1 to continue or 0 to abort: ";
 		cin>>cont;
 } while (cont);

return 0;

}







