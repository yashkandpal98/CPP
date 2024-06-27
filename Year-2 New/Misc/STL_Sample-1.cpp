#include<bits/stdc++.h>
#include<vector>
#include "Tree-1.cpp"

using namespace std;

int construct_pre(bstptr &root, vector<int> inorder, vector<int> preorder, int position)
{
	int i = 0;
	
	insert(root, preorder[position++]);
	
	if(inorder.size() == 1) return position;
	
	vector<int> inorder_left, inorder_right;
	
	while(inorder[i] != preorder[position-1]) inorder_left.push_back(inorder[i++]);
	i++;
	while(i < inorder.size()) inorder_right.push_back(inorder[i++]);
	
	position = construct_pre(root->lchild, inorder_left, preorder, position);
	position = construct_pre(root->rchild, inorder_right, preorder, position);
	
	return position;
}

int construct_post(bstptr &root, vector<int>inorder, vector<int> postorder, int position)
{
	insert(root, postorder[position--]);
	
	if(inorder.size() == 1) return position;
	
	vector<int> inorder_left, inorder_right;
	
	int i = 0;
	
	while(inorder[i] != postorder[position+1]) inorder_left.push_back(inorder[i++]);
	i++;
	while(inorder[i]) inorder_right.push_back(inorder[i++]);
	
	position = construct_post(root->rchild, inorder_right, postorder, position);
	position = construct_post(root->lchild, inorder_left, postorder, position);
	
	return position;
}

int main()
{
	bstptr root = NULL;
	vector<int> inorder, preorder, postorder;
	int x;
	
	cout<<"Inorder array:\n";
	cin>>x;
	while(x != -1)
	{
		inorder.push_back(x);
		cin>>x;
	}
	
	/*/cout<<"\nPreorder array:\n";
	cin>>x;
	while(x != -1)
	{
		preorder.push_back(x);
		cin>>x;
	}*/
	
	cout<<"\nPostorder array:\n";
	cin>>x;
	while(x != -1)
	{
		postorder.push_back(x);
		cin>>x;
	}
	
	cout<<endl;
	int a = construct_post(root, inorder, postorder, postorder.size()-1);
	
	cout<<endl;
	levelorder(root);
	
	return 0;
}
