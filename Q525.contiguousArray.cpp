#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int findMaxLength(vector<int> &nums)
    {
        unordered_map<int, int> mp;
        // mp[0] = -1;  // Important for handling prefix from index 0

        // int prefixSum = 0;
        // int maxLen = 0;

        // for (int i = 0; i < nums.size(); i++) {

        //     // Convert 0 → -1
        //     if (nums[i] == 0)
        //         prefixSum += -1;
        //     else
        //         prefixSum += 1;

        //     if (mp.find(prefixSum) != mp.end()) {
        //         maxLen = max(maxLen, i - mp[prefixSum]);
        //     } else {
        //         mp[prefixSum] = i;
        //     }
        // }
        // return maxLen;

        int zero = 0, one = 0;
        int maxLen = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
            {
                zero++;
            }
            else
            {
                one++;
            }

            int diff = zero - one;
            if (diff == 0)
            {
                maxLen = max(maxLen, i + 1);
                continue;
            }
            if (mp.find(diff) == mp.end())
            {
                mp[diff] = i;
            }
            else
            {
                maxLen = max(maxLen, i - mp[diff]);
            }
        }
        return maxLen;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {0, 0, 1, 0, 0, 0, 1, 1};
    cout << sol.findMaxLength(nums) << endl; // Output: 6
    return 0;
}