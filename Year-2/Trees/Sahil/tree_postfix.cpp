#include<iostream>
#include<cstring>
#include<string>
#include<stdio.h>

using namespace std;


int oper(int x,int y,char c)
 {switch(c)
 	{case '/': return x/y; break;
     case '*': return x*y; break;
     case '+': return x+y; break;
     case '-': return x-y; break;}
 }



int cont1=0;

union u
{ int data; char op;};



struct btnode
{u val; int tag;

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
	  {cout<<"\n the element whose pointer to be removed from the queue is: ";
	  if(s[front]->tag==0)
	  	 cout<<s[front]->val.data;
	  else cout<<s[front]->val.op;

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
      		{if(s[front]->tag==0)
	  	        cout<<s[i]->val.data<<" ";
	  		 else 
	  			cout<<s[i]->val.op<<" ";
	  	    }
     else 
     	{for(i=front;i<100;i++)
      		{if(s[front]->tag==0)
	  	        cout<<s[i]->val.data<<" ";
	  		 else 
	  			cout<<s[i]->val.op<<" ";
	  	    }

      	 for(i=0;i<=rear;i++)
      		{if(s[front]->tag==0)
	  	        cout<<s[i]->val.data<<" ";
	  		 else 
	  			cout<<s[i]->val.op<<" ";
	  	    }

        }
	}

	 };









class stack
{ public:
 btnode *s[100];
 int top;
 
  stack()
{top=-1;}

 void push(btnode *a)
 {top++;
  s[top]=a;
  cout<<"\n the value of pointer pushed is: ";
  if(a->tag==0)
  	cout<<a->val.data;
  else cout<<a->val.op;
  cout<<"\n the new top value is: "<<top;
}

 /*void push()
   {cout<<"\n enter the value to be pushed: ";
    top++;
    cin>>s[top];
   }
   */

 void pop()
  {cout<<"\n the value of pointer popped is: ";
  if(s[top]->tag==0)
  	cout<<s[top]->val.data;
  else cout<<s[top]->val.op;
    top--;
    cout<<"\n the new top value is: "<<top;
     }

  btnode* rpop()  // r is used to denote that it returns a value. can't overload directly
    {btnode *x=s[top];
     cout<<"\n the value of pointer popped is: ";
     if(x->tag==0)
  		cout<<x->val.data;
     else cout<<x->val.op;
     top--;
     cout<<"\n the new top value is: "<<top;
     return x;  }

   void display()
    {cout<<"\n displaying pointed stack bottom to top: ";
     int i;
     for(i=0;i<=top;i++)
      {if(s[i]->tag==0)
      	cout<<s[i]->val.data<<" ";
      	else cout<<s[i]->val.op<<" ";
      }
  }


};








 class tree
 {public:
  btnode *root;
  string input;
  int index;
  int i;
  
  
  
  int x,y;

  btnode *store[100];
  int istore=0;
  


  tree()
  {index=0;
  root =new btnode;
  root->lchild=NULL;
  root->rchild=NULL;
  
   }

  

  void input_tree(btnode *t)
  { int sindex=0;
   stack x;
    btnode *l;


    btnode *flag=new btnode;
    flag->lchild=NULL;
    flag->rchild=flag->lchild;
    flag->val.data=100;
    flag->tag=0;



  	do
  	{  l=new btnode;
  		flag->lchild=NULL;
          flag->rchild=flag->lchild;
         flag->val.data=100;
           flag->tag=0;



  		if(!isdigit(input[sindex]))
  		{
  		 l->tag=1;
  		 l->val.op=input[sindex];
  		 l->lchild=new btnode;
  		 l->rchild=new btnode;
  		 l->rchild=x.rpop();
  		 l->lchild=x.rpop();
  		 cout<<"\n the node has value: ";
  		 cout<<l->val.op;
  		 cout<<"\n it left pushes to: ";
  		 if(l->lchild->tag==0)
  		 	{cout<<l->lchild->val.data;}
  		 else cout<<l->lchild->val.op;
  		 cout<<"\n it right pushes to: ";
  		 if(l->rchild->tag==0)
  		 	{cout<<l->rchild->val.data;}
  		 else cout<<l->rchild->val.op;
  		 x.push(l);

  		 
  		}
  		else
  		{l->tag=0;
  		 l->val.data=input[sindex]-48;
  		 x.push(l);
  		 }

  	   sindex++;
  	   l=flag;
  	}while(sindex!=input.length());

  	root=x.rpop();
  	cout<<"\n t has the value: "<<root->val.op;


  	
  	   

      }



  void all_layer(btnode *l)
 {	//creating dummy flag;
    btnode *flag=new btnode;
    flag->lchild=new btnode;
    flag->rchild=flag->lchild;
    flag->val.data=100;
    flag->tag=0;
    //cout<<"\n dummy flag created";
    cout<<"\n";
    											//cout<<"\n enter 1 to continue: ";
   			  	  								//cin>>cont1;
   	queue q; q.add(l);
   //	cout<<"\n function has been terminated and added the root to queue";
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
   		  //cout<<"\n removed from the queue pointing to: ";
   		   //if(el->tag==0) cout<<el->val.data<<" "; else cout<<el->val.op; 
   	                                            //cout<<"\n enter 1 to continue: ";
   			  	  								//cin>>cont1;

 	 			//do
 	 				//{
 	 					if(el!=flag)
 	 					{     if(el->tag==0)
 	 						     cout<<el->val.data<<" ";
 	 						  else
 	 						     cout<<el->val.op<<" ";
             

 	 	 					if(el->lchild!=NULL)
 	 	 						{//cout<<"\n it has a left child!";
 	 	 						 q.add(el->lchild);
 	 	 						  //cout<<"\n pushing: "; 
 	 	 						  //if(el->lchild->tag==0) cout<<el->lchild->val.data<<" "; else cout<<el->lchild->val.op; 
 	 	 						} 
 	 	 					if(el->rchild!=NULL)
 	 	 						{ //cout<<"\n it has a right child!";
 	 	 					     q.add(el->rchild);
 	 	 					      //cout<<"\n pushing: ";
 	 	 					      //if(el->rchild->tag==0) cout<<el->rchild->val.data<<" "; else cout<<el->rchild->val.op;
 	 	 					    }
 	 					}
 	  				 else 
 	     				{cout<<"\n"; 
 	     			     //cout<<"next line";
 	     			      q.add(flag);
 	     			    }
 	      		
 	      			 //el=q.rremove();


 	 				

   }
  }



  void calcexptree(btnode *t)
  {if(t->tag==0)
  	{cout<<"\n reached end of node";}

  else
  	{//if(t->lchild!=NULL)
  	calcexptree(t->lchild);
     //if(t->rchild!=NULL)
   	 calcexptree(t->rchild);
   	int sol=oper(t->lchild->val.data,t->rchild->val.data,t->val.op);
   	t->tag=0;
   	t->val.data=sol;
   	cout<<"\n solution is: "<<sol;
  }
}
};




int main()
{int choice,cont;
	tree t;
 do
 { cout<<"\n Enter 1 to enter the input in postfix format and 2 to print layer wise, ";
 cout<<"\n3 to evaluate the expression tree: ";
   cin>>choice;
   switch(choice)
   	{case 1: cout<<"\n enter the string: ";
   			 //cin>>t.input;
   	         t.input="1243/*+";
   			 cout<<"\n the ppostfix input enterred was: "<<t.input;
   			 cout<<"\n adding the details to the tree: ";
   			 t.input_tree(t.root);
   			 cout<<"\n root points to: "<<t.root->val.op; break;
   	 case 2: t.all_layer(t.root); break;
   	 case 3: t.calcexptree(t.root); cout<<"\n the value is: "<<t.root->val.data;

  }
 	cout<<"\n enter 1 to continue or 0 to abort: ";
 	cin>>cont;
 } while (cont);
return 0;
}



