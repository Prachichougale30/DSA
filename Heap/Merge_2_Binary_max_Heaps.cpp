
class Solution {
public:
    
    void heapify(vector<int> &arr, int n, int i)
    {
        int largest = i;
        int left = 2 * i;
        int right = 2 * i + 1;

        if (left <= n && arr[largest] < arr[left])
            largest = left;

        if (right <= n && arr[largest] < arr[right])
            largest = right;

        if (largest != i)
        {
            swap(arr[largest], arr[i]);
            heapify(arr, n, largest);
        }
    }

    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        
        vector<int> ans;
        ans.push_back(-1);   // dummy for 1-based indexing

        for (auto i : a)
            ans.push_back(i);

        for (auto i : b)
            ans.push_back(i);

        int size = ans.size() - 1;  // actual heap size

        for (int i = size / 2; i > 0; i--)
            heapify(ans, size, i);
 ans.erase(ans.begin()); 
        return ans;
    }
};