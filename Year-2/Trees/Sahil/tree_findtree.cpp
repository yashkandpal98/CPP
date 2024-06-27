#include<iostream>
#include<string>
#include<cctype>
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




   class stack
{ public:
 btnode *s[100];
 int top;
 
  stack()
{top=-1;}

 void push(btnode *a)
 {top++;
  s[top]=a;
  cout<<"\n the value-pointer pushed is: "<<a->data;
}

 /*void push()
   {cout<<"\n enter the value to be pushed: ";
    top++;
    cin>>s[top];
   }
   */

 void pop()
  {cout<<"\n the value of pointer popped is: "<<s[top]->data;
    top--;
    cout<<"\n the new top value is: "<<top;
     }

  btnode* rpop()  // r is used to denote that it returns a value. can't overload directly
    {btnode *x=s[top];
     cout<<"\n the value of pointer popped is: "<<x->data;
     top--;
     cout<<"\n the new top value is: "<<top;
     return x;  }

   void display()
    {cout<<"\n displaying pointed stack bottom to top: ";
     int i;
     for(i=0;i<=top;i++)
      cout<<s[i]->data<<" ";
  }


};











 class tree
 {public:
  btnode *root;
  string ldr,lrd,dlr;



  btnode *input_tree(int lrdstart,int lrdend,int ldrstart,int ldrend)
  {int parent=-1,cont=-1,j;
  	
   cout<<"\n\n\n lrdstart: "<<lrdstart;
     cout<<"\n lrdend: "<<lrdend;
     cout<<"\n ldrstart: "<<ldrstart;
     cout<<"\n ldrend: "<<ldrend;
     cout<<"\n LRD: ";
     for(j=lrdstart;j<=lrdend;j++)  cout<<lrd[j];
     cout<<"\n LDR: ";
     for(j=ldrstart;j<=ldrend;j++)  cout<<ldr[j];
     cout<<"\n enter 1 to continue: "; cin>>cont;


   btnode *l,*r,*d; int i,lend=-1;
   
   d=new btnode;
   if(lrdend==lrdstart+2)
   	{d->data=lrd[lrdend]-48;
   	 d->lchild->data=lrd[lrdend-2]-48;
   	 d->rchild->data=lrd[lrdend-1]-48;
   	 d->lchild->lchild=NULL;
   	 d->lchild->rchild=NULL;
   	 d->rchild->lchild=NULL;
   	 d->rchild->rchild=NULL;
   	 return d;
   	}
   else if(lrdend==(lrdstart+1))
   	 {cout<<"\n calling the weird function";
   	  d->data=lrd[lrdend]-48;
   	  if(ldr[ldrend]-48==d->data)
   			{d->lchild=new btnode;
   				d->lchild->data=ldr[ldrend-1]-48;
   				cout<<"\n stored value:         "<<d->lchild->data;
   				d->lchild->lchild=NULL;
   	            d->lchild->rchild=NULL;
   	            d->rchild=NULL;
   			 }
   		else
   	     {d->rchild=new btnode;
   	     	d->rchild->data=ldr[ldrend]-48;
   				d->rchild->lchild=NULL;
   	            d->rchild->rchild=NULL;
   	            d->lchild=NULL;}
   	    return d;
   	   }
   	   else if(lrdend==lrdstart)
   	   	{d->data=lrd[lrdend]-48; d->rchild=NULL;
   	   	 d->lchild=NULL;
   	   	 return d;}
   	   	 else
   {
   d->data=lrd[lrdend]-48;
   cout<<"\n data value stored is: "<<d->data;
   
   int midpos=-1,rstart=-1,lend2=-1;
   		for(i=ldrstart;i<=ldrend;i++)
   				{if(d->data==(ldr[i]-48))
     				midpos=i;
     			}
     cout<<"\n middle position index of ldr: "<<midpos;
    rstart=midpos+1; // R starts 1 after D in LDR
    lend=midpos-1;   // L ends 1 before D 
    int lsize=midpos-ldrstart;
    cout<<"\n size of left part: "<<lsize;
    //cout<<"\n right of LRD starts with value: "<<rval;
    //for(i=lrdstart;i<=lrdend;i++)
    /// {if((lrd[i]-48)==rval)
        lend2=lrdstart+lsize-1;
     //}
     cout<<"\n left end index of lrd: "<<lend2;

      d->lchild=input_tree(lrdstart,lend2,ldrstart,lend);
      d->rchild=input_tree(lend2+1,lrdend-1,rstart,ldrend);
  }

  
   }




   btnode *input_tree1(int dlrstart,int dlrend,int ldrstart,int ldrend)
  {int parent=-1,cont=-1,j;
  	
   cout<<"\n\n\n dlrstart: "<<dlrstart;
     cout<<"\n dlrend: "<<dlrend;
     cout<<"\n ldrstart: "<<ldrstart;
     cout<<"\n ldrend: "<<ldrend;
     cout<<"\n DLR: ";
     for(j=dlrstart;j<=dlrend;j++)  cout<<dlr[j];
     cout<<"\n LDR: ";
     for(j=ldrstart;j<=ldrend;j++)  cout<<ldr[j];
     cout<<"\n enter 1 to continue: "; cin>>cont;


   btnode *l,*r,*d; int i,lend=-1;
   
   d=new btnode;
   if(dlrend==dlrstart+2)
   	{d->data=dlr[dlrstart]-48;
   	 d->lchild->data=dlr[dlrend-1]-48;
   	 d->rchild->data=dlr[dlrend]-48;
   	 d->lchild->lchild=NULL;
   	 d->lchild->rchild=NULL;
   	 d->rchild->lchild=NULL;
   	 d->rchild->rchild=NULL;
   	 return d;
   	}
   else if(dlrend==(dlrstart+1))
   	 {cout<<"\n calling the weird function";
   	  d->data=dlr[dlrstart]-48;
   	  if(ldr[ldrend]-48==d->data)
   			{d->lchild=new btnode;
   				d->lchild->data=ldr[ldrend-1]-48;
   				cout<<"\n stored value:         "<<d->lchild->data;
   				d->lchild->lchild=NULL;
   	            d->lchild->rchild=NULL;
   	            d->rchild=NULL;
   			 }
   		else
   	     {d->rchild=new btnode;
   	     	d->rchild->data=ldr[ldrend]-48;
   				d->rchild->lchild=NULL;
   	            d->rchild->rchild=NULL;
   	            d->lchild=NULL;}
   	    return d;
   	   }
   	   else if(dlrend==dlrstart)
   	   	{d->data=dlr[dlrstart]-48; d->rchild=NULL;
   	   	 d->lchild=NULL;
   	   	 return d;}
   else
   {
   d->data=dlr[dlrstart]-48;
   cout<<"\n data value stored is: "<<d->data;
   
   int midpos=-1,rstart=-1,lend2=-1;
   		for(i=ldrstart;i<=ldrend;i++)
   				{if(d->data==(ldr[i]-48))
     				midpos=i;
     			}
     cout<<"\n middle position index of ldr: "<<midpos;
    rstart=midpos+1; // R starts 1 after D in LDR
    lend=midpos-1;   // L ends 1 before D 
    int lsize=midpos-ldrstart;
    cout<<"\n size of left part: "<<lsize;
    //cout<<"\n right of LRD starts with value: "<<rval;
    //for(i=lrdstart;i<=lrdend;i++)
    /// {if((lrd[i]-48)==rval)
        lend2=dlrstart+lsize;
     //}
     cout<<"\n left end index of dlr: "<<lend2;

      d->lchild=input_tree1(dlrstart+1,lend2,ldrstart,lend);
      d->rchild=input_tree1(lend2+1,dlrend,rstart,ldrend);
  }

  
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

};


int main()
{int choice,cont;
 tree t;
 do
 {
 cout<<"\n enter 1 to add the elements in LDR and LRD: and 2 to display layers: and 3 to do the opposite: s";
 	cin>>choice;
 	switch(choice)
 	{case 1: cout<<"\n enter the ldr: ";
 	//cin>>t.ldr;
 	cout<<"\n enter the lrd: ";
 	//cin>>t.lrd;
 	t.ldr="168342987";
 	t.lrd="183692784";
 	t.root=t.input_tree(0,t.lrd.length()-1,0,t.ldr.length()-1);
 	cout<<"\n tree has been inputted";
 	break;

 	case 2:cout<<"\n printing all layers: \n"; t.all_layer(t.root);
    break;
    case 3: cout<<"\n enter the ldr: ";
 	//cin>>t.ldr;
 	cout<<"\n enter the dlr: ";
 	//cin>>t.dlr;
 	t.ldr="168342987";
 	t.dlr="461388297";
 	t.root=t.input_tree1(0,t.dlr.length()-1,0,t.ldr.length()-1);
 	cout<<"\n tree has been inputted";
 	break;
    }
    cout<<"\n enter 1 to continue and 0 to abort: ";
    cin>>cont;

 	 } while (cont);

 	 return 0;
 	}