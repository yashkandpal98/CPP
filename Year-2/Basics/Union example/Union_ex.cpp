#include<iostream>
using namespace std;

int main()
{
	union x
	{
		int a;
		char b[];
		float c;
	};
	
	struct s1
	{
		int tag;
		float f1;
		union x y;
	};
	
	struct s1 st;
	cout<<"Enter 1 to input int in union\n";
	cout<<"Enter 2 to input char in union\n";
	cout<<"Enter 3 to input float in union\n";
	cout<<"Enter tag: ";cin>>st.tag;cout<<endl;
	
	cin>>st.f1;
	if(st.tag==1)
	{
		cin>>st.y.a;
	}
	else if(st.tag==2)
	{
		cin>>st.y.b;
	}
	else if(st.tag==3)
	{
		cin>>st.y.c;
	}
	
	if(st.tag==1)
	{
	cout<<st.f1<<"  "<<st.y.a;
	}
	else if(st.tag==2)
	{
	cout<<st.f1<<"  "<<st.y.b;
	}
	else if(st.tag==3)
	{
	cout<<st.f1<<"  "<<st.y.c;
	}

	return 0;
}
