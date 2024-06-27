#include<iostream>
#include<cstring>
#include<stdio.h>
#include<string>
using namespace std;

int cont1;









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



/*void print_onward(btnode *l)
{//cout<<"\n enter 1 to continue: ";
   			  	 // cin>>cont1;

 cout<<l->data<<" ";
 if(l->lchild!=NULL)
	print_onward(l->lchild);
 else cout<<" ~ ";

 if(l->rchild!=NULL)
    print_onward(l->rchild);
 else cout<<" ~ ";
 }





 void trav_allnode(btnode *l)
 {//cout<<"\n enter 1 to continue: ";
   			  	 // cin>>cont1;
  cout<<"\n printing the onward tree for the node: "<<l->data<<":  ";
  print_onward(l);
  if(l->lchild!=NULL)
    { trav_allnode(l->lchild);}

  if(l->rchild!=NULL)
  	trav_allnode(l->rchild);

 }


*/




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
 		{										cout<<"\n enter 1 to continue: ";
   			  	  								cin>>cont1;
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



/*

  void storexindex(btnode *l)
  { //cout<<"\n enter 1 to continue: ";
    //cin>>cont1;

  btnode *flag=new btnode;
    flag->lchild=new btnode;
    flag->rchild=flag->lchild;
    flag->data=100;


  if(l->lchild!=NULL)
      //if(l->lchild->lchild!=NULL&&l->lchild->rchild!=NULL)
        storexindex(l->lchild);
  else { //store[istore]=flag; istore++;
       }

 store[istore]=l; istore++;

 if(l->rchild!=NULL)
    storexindex(l->rchild);
 else { //store[istore]=flag; istore++;
      }
 
  }




  void printas(btnode *l)   // print with spaces
  {
  int g=0;
  int count=0;
  

     //creating dummy flag;
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
    {             //cout<<"\n enter 12 to continue: ";
                   //           cin>>cont1;
        el=q.rremove();
        //cout<<"\n removed from the queue pointing to: "<<el->data; 
                                                //cout<<"\n enter 1 to continue: ";
                              //cin>>cont1;

        //do
          //{
            if(el!=flag)
            {int h=count;
              for(int m=count;store[m]!=el&&m<istore;m++)
               {//if(m%2==1) 
                cout<<" "; count++;}

               cout<<el->data;count++;
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
                  count=0;
                }
            
              // el=q.rremove();


          //}while(el!=NULL);

   }
  }


  void recurse_left_print(btnode *l)
    {if(l->lchild!=NULL)
       recurse_left_print(l->lchild);
       cout<<l->data<<" ";
     }


  void recurse_right_print(btnode *l)
    {cout<<l->data<<" ";

    if(l->rchild!=NULL)
       recurse_right_print(l->rchild);
       
     }



  void top_view()
  {if(root->lchild!=NULL)
     recurse_left_print(root->lchild);
     cout<<root->data<<" ";
     if(root->rchild!=NULL)
     recurse_right_print(root->rchild);
  }

  void left_view(btnode *l)
      { //creating dummy flag;
    btnode *flag=new btnode;
    flag->lchild=new btnode;
    flag->rchild=flag->lchild;
    flag->data=100;
    //cout<<"\n dummy flag created";
                          //cout<<"\n enter 1 to continue: ";
                              //cin>>cont1;
    queue q; q.add(l);
    int flag1=0;
    //cout<<"\n function has been terminated and added the root to queue";
                          //cout<<"\n enter 1 to continue: ";
                              //cin>>cont1;
    q.add(flag);
    //cout<<"\n added the flag to the queue";
     btnode *el;
    //cout<<"\n qtotal is: "<<q.total;
  

  while(q.total>1)
    {                   //cout<<"\n enter 1 to continue: ";
                              //cin>>cont1;
        el=q.rremove();
        //cout<<"\n removed from the queue pointing to: "<<el->data; 
                                                //cout<<"\n enter 1 to continue: ";
                              //cin>>cont1;

        //do
          //{
            if(el!=flag)
            {if(!flag1) {cout<<el->data<<" "; flag1=1;}
             

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
                  q.add(flag); flag1=0;
                }
            
              // el=q.rremove();


          //}while(el!=NULL);

        }
  }



  void right_view(btnode *l)
      { //creating dummy flag;
    btnode *flag=new btnode;
    flag->lchild=new btnode;
    flag->rchild=flag->lchild;
    flag->data=100;
    //cout<<"\n dummy flag created";
                          //cout<<"\n enter 1 to continue: ";
                              //cin>>cont1;
    queue q; q.add(l);
    int flag1=0;
    //cout<<"\n function has been terminated and added the root to queue";
                          //cout<<"\n enter 1 to continue: ";
                              //cin>>cont1;
    q.add(flag);
    //cout<<"\n added the flag to the queue";
     btnode *el;
    //cout<<"\n qtotal is: "<<q.total;
  

  while(q.total>1)
    {                   //cout<<"\n enter 1 to continue: ";
                              //cin>>cont1;
        el=q.rremove();
        //cout<<"\n removed from the queue pointing to: "<<el->data; 
                                                //cout<<"\n enter 1 to continue: ";
                              //cin>>cont1;

        //do
          //{
            if(el!=flag)
            { flag1=el->data;
             

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
              {cout<<flag1<<"\n"; 
                 //cout<<"next line";
                  q.add(flag);
                }
            
              // el=q.rremove();


          //}while(el!=NULL);

        }

        cout<<flag1;
  }


  void store_rev(btnode *l)
  { int flag1=1; btnode *el;
    btnode *flag=new btnode;
    flag->lchild=new btnode;
    flag->rchild=flag->lchild;
    flag->data=100;
    queue q;

    revstore.add(l);
    revstore.add(flag);
    el=flag;

    while(flag1|el==flag)
    { flag1=0;
      el=revstore.rremove();
          while(el!=flag)
            {flag1=1;
              while(revstore.s[revstore.front]!=flag)
                revstore.add(revstore.rremove());

             if(el->lchild!=NULL)
                {revstore.add(el->lchild); }
             if(el->rchild!=NULL)
                {revstore.add(el->rchild); }
             q.add(el);
            }

      if(el==flag) revstore.add(flag);
      if(el==flag)
        while(q.total!=0)
          {revstore.add(q.rremove());}
      if(el==flag) revstore.add(flag);

  }
}








  void kr_topview1(btnode *l,int leftnow=0)
    { static int leftmax=0;


      if(leftnow>leftmax)
        {topv.add_start(l->data); leftmax++;}
      

      if(l->lchild!=NULL)
        {kr_topview1(l->lchild,leftnow+1);}
      if(l->rchild!=NULL)
        {kr_topview1(l->rchild,leftnow-1);}

    }



  void kr_topview2(btnode *l,int rightnow=0)
    { static int rightmax=0;


      
      if(rightnow>rightmax)
        {topv.add_end(l->data); rightmax++;}

      
      if(l->rchild!=NULL)
        {kr_topview2(l->rchild,rightnow+1);}
      if(l->lchild!=NULL)
        {kr_topview2(l->lchild,rightnow-1);}
      

    }



    void eval_exp(btnode *l)
      { if(l->lchild->data>=0&&l->rchild->data>=0)
         {l->data=oper(l->lchild->data,l->rchild->data,l->data);
          delete l->lchild;
          delete l->rchild;
          l->lchild=NULL;
          l->rchild=NULL;
         }

         else 
        {if(l->lchild!=NULL)
            eval_exp(l->lchild);
         if(l->rchild!=NULL)
            eval_exp(l->rchild);
          eval_exp(l);
          }


        }

        void oper(int x,int y,int z)
          { switch(z)
            {case -1: return x/y; break;
             case -2: return x*y; break;
             case -3: return x+y; break;
             case -4: return x-y; break;
            }

          }

*/

btnode *nodesearch(int k,btnode *l)
{ btnode *flag=new btnode;
    flag->lchild=new btnode;
    flag->rchild=flag->lchild;
    flag->data=100;



    if(l->data==k)
	{cout<<"\n node has been found!"; return l;}

    else 
   {if(l->lchild!=NULL)
      if(nodesearch(k,l->lchild)!=flag)
         return nodesearch(k,l->lchild);
    if(l->rchild!=NULL)
       if(nodesearch(k,l->rchild)!=flag)
         return nodesearch(k,l->rchild);
   }

   return flag;
}

int deletenode(btnode *l)
	{btnode *temp; int flag=0;
	 cout<<"\n current location in tree: "<<l->data;
	 cout<<"\n enter 1 to continue: "; cin>>cont1;
	 if(l->rchild!=NULL)
		{if(l->rchild->lchild==NULL&&l->rchild->rchild==NULL)
			{temp=l->rchild; l->rchild=NULL; cout<<"\n right shall be null";
			 return deletenode(temp);}
		 else return deletenode(l->rchild);
		}

	 else
		{if(l->lchild==NULL)
			{int x=l->data;
			 cout<<"\n deleting: "<<l->data;
				delete l;
			  return x;
			}

		 else
			{int x=l->data;
			 if(l->lchild->lchild==NULL&&l->lchild->rchild==NULL)
			 	{temp=l->lchild; l->lchild=NULL;cout<<"\n left shall be null";
			     l->data=deletenode(temp);}
			 else l->data=deletenode(l->lchild);
			 return x;
			}
		}
	}


};




int main()
{tree t;
 int choice,cont,del;
 btnode *loc;
 do
 {
 	cout<<"\n enter 1 to add the data and 2 to delete a particular element: ";
 	cin>>choice;
 	switch(choice)
 		{case 1: cout<<"\n enter the input sting: ";
 		 		 t.input="124~~5~~36~~7~~"; //cin>>t.input;
 		 		 cout<<"\n input has been enterred! ";
 		 		 t.input_tree(t.root);
 		 		 cout<<"\n tree has been inputted ";
 		 		 cout<<"\n\n Printing the tree row wise: ";
 		 		 t.all_layer(t.root);
 		 		 break;
 		 case 2: cout<<"\n enter the number to be deleted: ";
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

 		}
 		cout<<"\n enter 1 to continue or 0 to abort: ";
 		cin>>cont;
 } while (cont);

return 0;

}