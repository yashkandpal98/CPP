#include <iostream>
using namespace std;

struct stack{
    int top;
    int size;
    int elem[50];
};
void push(stack &s,int x){
    if(s.top==s.size-1)
        cout<<"stack is full";
    else
        s.elem[++s.top]=x;
}
int pop(stack &s){
    if(s.top==-1)
        cout<<"Stack is empty";
    else
        return s.elem[s.top--];
}
struct queue{
    int f;
    int r;
    int s;
    int elem[50];
};
void enq(queue &Q,int x){
    if(Q.f==((Q.r+1)%Q.s))
        cout<<"Queue is full";
    else{
        if(Q.r==-1)
            Q.f=0;
        Q.r=(Q.r+1)%Q.s;
        Q.elem[Q.r]=x;
    }
}
int dq(queue &q){
    if(q.f==-1)
        cout<<"Queue is empty.";
    else{
        int t=q.elem[q.f];
        if(q.f==q.r){
            q.f=-1;
            q.r=-1;
            return t;
        }else{
            q.f=(q.f+1)%q.s;
            return t;
        }
    }
}
int main(){
    //11 12 13 14 15 16 17 18 19 20 -1
    queue q1;
    q1.s=1;q1.f=-1;q1.r=-1;
    int n;
    cin>>n;
    while(n!=-1){
        enq(q1,n);
        q1.s++;
        cin>>n;
    }
    stack s1;
    s1.size=(q1.s/2);
    s1.top=-1;
    for(int i=0;i<(q1.s)/2;i++)
        push(s1,dq(q1));
    for(int i=0;i<(q1.s)/2;i++)
        enq(q1,pop(s1));
    for(int i=0;i<(q1.s)/2;i++)
        enq(q1,dq(q1));
    for(int i=0;i<(q1.s)/2;i++)
        push(s1,dq(q1));
    for(int i=0;i<(q1.s)/2;i++)
        cout<<pop(s1)<<" "<<dq(q1)<<" ";
    return 0;
}
