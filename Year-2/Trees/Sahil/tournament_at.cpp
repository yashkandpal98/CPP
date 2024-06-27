#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef struct btnode {
	int data;
	btnode *lchild, *rchild;
} *btptr;

void change_to_min(vector<int> &v, int k)   //searches fork and sets it to -1 in the vector
{
	for(int i = 0; i < v.size(); i++)
		if(v[i] == k)
		{
			v[i] = -1;
			break;
		}
}

void tournament_sort(queue<btptr> &q)  // takes queue of btptr type as argument call by reference
{
	if(q.size() < 2)
		return;

	btptr t = new btnode;
	btptr t1 = q.front();
	q.pop();
	btptr t2 = q.front();
	q.pop();

	t->lchild = t1;
	t->rchild = t2;
	t->data = max(t1->data, t2->data);
	q.push(t);

	tournament_sort(q);   // keeps doing until 2 nodes left
}

int main()
{
	int n;
	cout<<"\n Enter the size of the scores: ";
	cin>>n;

	vector<int> v(n), result;

	cout<<"\n Enter "<<n<<" numbers: ";
	for(int i = 0; i < n; i++)
		cin>>v[i];

	for(int i = 0; i < v.size(); i++)
	{
		queue <btptr> q;	

		for(int i: v)  // for all values left in the vector
		{
			btptr temp = new btnode;
			temp->data = i;
			q.push(temp);
		}                      // push the whole vector v to the queue as nodes.

		tournament_sort(q);    // sort the whole queue leaving only 1 element finally
		
		result.push_back(q.front()->data);  // maximum value pushed to result
		change_to_min(v, q.front()->data);  // it does not exist anymore in the vector and just occupies a space.
	}

	cout<<"\nSorted list is: ";
	for(int i: result)
		cout<<i<<" ";
	cout<<endl;

	return 0;
}