//Infix to prefix with parenthesis
#include<iostream>
#include<string.h>
using namespace std;

struct Stack
{
	char sym[50];
	int top;
};
void push(Stack &s,char a);
char pop(Stack &s);
int getWeight(char ch)
{
	switch (ch) {
      case '/':return 3;
      			break;
      case '*': return 2;
      break;
      case '+':
      	return 1;
      	break;
      case '-': return 1;
      	break;
	  default : return 0;
  		break;
	  }
}
int j=0;
char e[50];
int main()
{
	struct Stack s;
	char exp[50];
	int i;
	s.top=-1;
	cout<<"Enter Infixed Expression\n";
	cin.getline(exp,50);
	i=strlen(exp)-1;
	while(i>=0)
	{
		if(isalnum(exp[i]))
		{
			e[j]=exp[i];
				j++;
		}
		else if(exp[i]==')')
		{
			push(s,exp[i]);
		}
		else if(exp[i]=='(')
		{
			while(s.sym[s.top]!=')')
			{
				e[j]=pop(s);
				j++;
			}
			s.sym[s.top]='\0';
			s.top-=1;
		}
		else if(exp[i]=='*'||exp[i]=='/'||exp[i]=='+'||exp[i]=='-')
		push(s,exp[i]);
		
		i--;
	}
	while(s.top!=-1)
	{
		e[j]=pop(s);
		j++;
	}
	cout<<"The prefix expression is "<<endl;
	i=strlen(e)-1;
	while(i>=0)//you must print rebverse of the stack
	{
		cout<<e[i];
		i--;
	}
	return(0);
}
void push(Stack &s,char a)
	{
		int w=getWeight(a);
		if(s.top==-1)
		{
			s.top+=1;
			s.sym[s.top]=a;
			cout<<"Push "<<a<<endl;
		}
		else
		{			
			while(s.top!=-1 && (getWeight(s.sym[s.top]))>=w&&s.sym[s.top]!=')'&&a!=')')
			{
				e[j]=pop(s);
				j+=1;
			}
			s.top+=1;
			s.sym[s.top]=a;
			cout<<"Push "<<a<<endl;
		}
}
	char pop(Stack &s)
	{
		char c;
		c=s.sym[s.top];
		s.sym[s.top]='\0';
		s.top-=1;
		cout<<"Pop "<<c<<endl;
		return(c);	
	}
