#include <bits/stdc++.h>
using namespace std;

string countAndSay(int n)
{
    // Base case
    string result = "1";

    // Generate sequence from 2 to n
    for (int i = 2; i <= n; i++)
    {
        string current = "";
        int count = 1;

        for (int j = 1; j < result.length(); j++)
        {
            if (result[j] == result[j - 1])
            {
                count++;
            }
            else
            {
                current += to_string(count);
                current += result[j - 1];
                count = 1;
            }
        }

        // Add the last group
        current += to_string(count);
        current += result.back();

        result = current;
    }

    return result;
}

int main()
{
    int n = 4;
    cout << countAndSay(n);
    return 0;
}
