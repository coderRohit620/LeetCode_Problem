// 16. 3Sum Closest

// Given an integer array nums of length n and an integer target, find three integers at distinct indices in nums such that the sum is closest to target.
// Return the sum of the three integers.

// You may assume that each input would have exactly one solution.

// Example 1:

// Input: nums = [-1,2,1,-4], target = 1
// Output: 2
// Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
// Example 2:

// Input: nums = [0,0,0], target = 1
// Output: 0
// Explanation: The sum that is closest to the target is 0. (0 + 0 + 0 = 0).
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        int closestSum = nums[0] + nums[1] + nums[2];
        int closestDiff = abs(closestSum - target);

        for (int i = 0; i < n - 2; i++) {

            // Skip duplicate values for i
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int l = i + 1;
            int r = n - 1;

            while (l < r) {
                int currentSum = nums[i] + nums[l] + nums[r];
                int diff = abs(currentSum - target);

                if (diff < closestDiff) {
                    closestDiff = diff;
                    closestSum = currentSum;
                }
                else if (currentSum == target) {
                    return target;
                }
                else if (currentSum < target) {
                    l++;
                }
                else {
                    r--;
                }
            }
        }
        return closestSum;
    }
};


int main() {
    Solution sol;

    vector<pair<vector<int>, int>> testCases = {
        {{-1, 2, 1, -4}, 1},
        {{0, 0, 0}, 1},
        {{1, 1, 1, 0}, -100},
        {{1, 2, 5, 10, 11}, 12},
        {{-3, -2, -5, 3, -4}, -1}
    };

    for (const auto& testCase : testCases) {
        const auto& nums = testCase.first;
        int target = testCase.second;
        int result = sol.threeSumClosest(const_cast<vector<int>&>(nums), target);
        cout << "Input: nums = [";
        for (size_t i = 0; i < nums.size(); ++i) {
            cout << nums[i];
            if (i < nums.size() - 1) cout << ", ";
        }
        cout << "], target = " << target << "\n";
        cout << "Output: " << result << "\n\n";
    }

    return 0;
}