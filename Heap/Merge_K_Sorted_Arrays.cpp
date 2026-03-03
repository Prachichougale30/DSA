#include <bits/stdc++.h>
using namespace std;

class node{
public:
    int data;
    int i;
    int j;

    node(int data, int row, int col){
        this->data = data;
        i = row;
        j = col;
    }
};

class compare{
public:
    bool operator()(node* a, node* b){
        return a->data > b->data;
    }
};

vector<int> mergeSortedArrays(vector<vector<int>> &kArrays, int k){

    priority_queue<node*, vector<node*>, compare> minHeap;

    // Step 1: Insert first element of every array
    for(int i = 0; i < k; i++){
        node* temp = new node(kArrays[i][0], i, 0);
        minHeap.push(temp);
    }

    vector<int> ans;

    // Step 2: Process heap
    while(!minHeap.empty()){

        node* temp = minHeap.top();
        minHeap.pop();

        ans.push_back(temp->data);

        int i = temp->i;
        int j = temp->j;

        // Insert next element of same array
        if(j + 1 < kArrays[i].size()){
            node* next = new node(kArrays[i][j+1], i, j+1);
            minHeap.push(next);
        }
    }

    return ans;
}

int main(){

    vector<vector<int>> arr = {
        {1,4,7},
        {2,5,8},
        {3,6,9}
    };

    int k = arr.size();

    vector<int> result = mergeSortedArrays(arr, k);

    for(int x : result){
        cout << x << " ";
    }

    return 0;
}