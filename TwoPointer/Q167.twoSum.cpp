#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/

class Solution
{
public:
    vector<int> twoSum(vector<int> &arr, int target)
    {
        int first = 0, last = arr.size() - 1;
        while (first < last)
        {
            int sum = arr[first] + arr[last];
            if (sum == target)
                return {first + 1, last + 1};
            else if (sum > target)
                last--;
            else
                first++;
        }
        return {};
    }
};

int main()
{
    vector<int> arr = {2, 7, 11, 15};
    int target = 9;
    Solution sol;
    vector<int> res = sol.twoSum(arr, target);
    for (int x : res)
        cout << x << " ";

    cout << endl;
    return 0;
}
