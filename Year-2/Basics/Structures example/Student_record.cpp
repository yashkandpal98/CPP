#include <iostream>
using namespace std;

struct stud
{
	int rno;
	char name[];
	float gpa;
};

int main()
{
	
	
	int n, i;
	
	cout<<"Enter number of students: ";cin>>n;cout<<endl;
	
	struct stud  s[n];
	
	cout<<"Entering student details:\n\n\n";
	for(i=0; i<n; i++)
	{
		cout<<"Entry "<<i+1<<endl;
		
		cout<<"Enter roll number: ";cin>>s[i].rno;
		cout<<"Enter name: ";cin>>s[i].name;
		cout<<"Enter CGPA: ";cin>>s[i].gpa;cout<<endl;
	}
	
	cout<<"\nDisplaying student details:\n\n\n";
	cout<<"Roll number\t\tName\t\tCGPA\n\n";

	for(i=0; i<n; i++)
	{
		cout<<s[i].rno<<"\t\t"<<s[i].name<<"\t\t"<<s[i].gpa<<endl;
	}
	
	int x=0, rn;
	cout<<endl<<endl<<"Enter roll number to search: ";cin>>rn;
	
	for(i=0; i<n; i++)
	{
		if(s[i].rno==rn)
		{
			x=1;
			cout<<"Roll number\t\tName\t\tCGPA\n\n";
			cout<<s[i].rno<<"\t\t\t"<<s[i].name<<"\t\t\t"<<s[i].gpa<<endl;
			break;
		}
	}
	
	if(x==0) cout<<"Student record not found";
	
	return 0;
}
