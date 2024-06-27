#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
vector<int> leftNode, rightNode;
int swapLevel;

void traverse(int node=1){
    if (node == -1) return;
    traverse(leftNode[node]);
    cout << node << " ";
    traverse(rightNode[node]);
    if (node == 1) cout << endl;
}

void swap(int level=1, int node=1) {
	if (node == -1) return;
	if (level % swapLevel == 0) {
		int tmp = leftNode[node];
		leftNode[node] = rightNode[node];
		rightNode[node] = tmp;
	}
	swap(level+1, leftNode[node]);
	swap(level+1, rightNode[node]);
}

int main() {
    int count;    
    cin>>count;
	leftNode.push_back(0);
    rightNode.push_back(0);
    while(count--){
        int L, R;
        cin>>L>>R;
        leftNode.push_back(L);
        rightNode.push_back(R);
    }
    cin>>count;
    while(count--){
		cin >> swapLevel;
		swap();
		traverse();
	}
    return 0;
}
