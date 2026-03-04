#include <bits/stdc++.h>
using namespace std;

// Node class to store value along with its row and column index
class node{
public:
    int data; // value of element
    int row;  // which list it belongs to
    int col;  // index inside that list

    node(int d,int r,int c){
        data = d;
        row = r;
        col = c;
    }
};

// Comparator for min heap
// We want the smallest element at the top
class compare{
public:
    bool operator()(node* a, node* b){
        return a->data > b->data; // min heap based on data
    }
};

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {

        int k = nums.size();   // number of lists

        int mini = INT_MAX;    // minimum element among heap elements
        int maxi = INT_MIN;    // maximum element among heap elements

        // Min heap to keep track of smallest element
        priority_queue<node*, vector<node*>, compare> minHeap;

        // Step 1: Insert first element of every list into heap
        for(int i = 0; i < k; i++){

            int element = nums[i][0];

            mini = min(mini, element);
            maxi = max(maxi, element);

            // store element with its row and column
            minHeap.push(new node(element, i, 0));
        }

        // Initial range
        int start = mini;
        int end = maxi;

        // Step 2: Process heap
        while(!minHeap.empty()){

            // Get the smallest element from heap
            node* temp = minHeap.top();
            minHeap.pop();

            mini = temp->data;

            // Update range if we found smaller range
            if(maxi - mini < end - start){
                start = mini;
                end = maxi;
            }

            // Move to next element in same list
            if(temp->col + 1 < nums[temp->row].size()){

                int nextVal = nums[temp->row][temp->col + 1];

                // Update maximum element
                maxi = max(maxi, nextVal);

                // Push next element into heap
                minHeap.push(new node(nextVal, temp->row, temp->col + 1));
            }
            else{
                // If any list ends, we cannot include all lists anymore
                break;
            }
        }

        // Return smallest range
        return {start, end};
    }
};