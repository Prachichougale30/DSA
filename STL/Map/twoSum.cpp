#include <iostream>
#include <vector>
#include <map>
using namespace std;


vector<int> TwoSum(vector<int> numbers, int target)
{
    map<int, int> m;
    vector<int> ans;
    for (int i = 0; i < numbers.size(); i++)
    {
        int rem = target - numbers[i];
        if (m.count(rem))
        {
            ans.push_back(m[rem]);
            ans.push_back(i);
            break;
        }
        m.insert({numbers[i],i});
    }
    return ans;
}

int main()
{
    int n, target;
    cout << "Enter number of elements in the vector: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    cout << "Enter target sum: ";
    cin >> target;

    vector<int> result = TwoSum(nums, target);

    if (result.size() == 2)
    {
        cout << "Indices of elements summing to target: ";
        cout << result[0] << " and " << result[1] << endl;
        cout << "Values are: " << nums[result[0]] << " + " << nums[result[1]] << " = " << target << endl;
    }
    else
    {
        cout << "No two elements found that sum to target.\n";
    }

    return 0;
}
