
#include<iostream>
#include<string>
#include<cctype>
using namespace std;


struct btnode
{int data;
 btnode *lchild,*rchild;
 };

int cont1;
 



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
  int index;
  string input;



  tree()
  {index=0;
  root =new btnode;
  root->lchild=NULL;
  root->rchild=NULL;}
  


  void input_tree(btnode *t)
  {//cout<<"\n enter 1 to continue: ";
   		//	  	  cin>>cont1;
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

     //whatever existed at left pointer has been taken care of

    if(input[index]!='~')
   		{//cout<<"\n right child exists for "<<t->data;
   		 //cout<<"\n recursing to the node: ";
   		 t->rchild=new btnode;
   		 input_tree(t->rchild);

        }
    else {//cout<<"\n right child of "<<t->data<<" does not exist! ";
           index++;}

}

void print_ldr()
{stack s;
	btnode *l=root,*temp;
 s.push(l);
 do
  { cout<<"\n enter 1 to continue: ";
   		  	  cin>>cont1;
   if(l->lchild!=NULL)
      l=l->lchild;
   else if(l->rchild!=NULL)
   	  {cout<<l->data; l=l->rchild;}
  else
  	 {cout<<"\n"<<l->data<<" hi1 ";
  	   s.pop();   // we remove the l
  	   temp=s.rpop();
  	   if(l!=temp->rchild) cout<<"\n"<<temp->data<<" hi2 ";
  	   if(temp->rchild!=NULL)
  	   	 l=temp->rchild;
  	   	else
  	   		{l=s.rpop();
  	   		 cout<<"\n"<<l->data<<" hi3 ";
  	   		 l=l->rchild;}
  	  }
  	 s.push(l);

  	}while(s.top>=0);

  }


  void print_ldr1()
  {btnode *l=root;
   stack s;
   s.push(l);
   while(s.top!=-1)
    { cout<<"\n enter 1 to continue: "; cin>>cont1;
     if(l->lchild!=NULL)
       {s.push(l->lchild); l=l->lchild;}
     else //if(l->lchild==NULL)
       {cout<<l->data<<" hi "; s.pop();
         if(l->rchild!=NULL) 
         	{s.push(l->rchild);l=l->rchild;}
         else {l=s.rpop(); cout<<l->data<<" ";
                if(l->rchild!=NULL) 
         	     {s.push(l->rchild);l=l->rchild;}
         	    else l=s.rpop();
         	  }
        }
    }
     }



};



int main()
	{int choice,cont; tree t;
	 do
	 {cout<<"\n enter 1 to enter the tree and 2 to print the LDR: ";
	 cin>>choice;
	 switch(choice)
		{case 1: cout<<"\n enter the string: ";
	             //cin>>t.input;
	             t.input="461~~38~~~82~9~~7~~";
	             t.input_tree(t.root); 
	             cout<<"\n the details have been inputted: ";
	             break;

	     case 2: t.print_ldr1(); break;
	   }
	   cout<<"\n enter 1 to continue or 0 to abort: ";
	   cin>>cont;

	}while(cont);
	return 0;
	}




