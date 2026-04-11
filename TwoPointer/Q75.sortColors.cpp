#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/sort-colors/

// Brute Froce Approch
class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        vector<int> a, b, c;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
            {
                a.push_back(nums[i]);
            }
            else if (nums[i] == 1)
            {
                b.push_back(nums[i]);
            }
            else
            {
                c.push_back(nums[i]);
            }
        }
        int index = 0;

        // add all 0s
        for (int x : a){
            nums[index++] = x;
        }

        // add all 1s
        for (int x : b){
            nums[index++] = x;
        }

        // add all 2s
        for (int x : c){
            nums[index++] = x;
        }
    }
};

// 2nd Approch with no extra Space
class Solution
{
public:
    void sortColors(vector<int> &nums){
        int low = 0, mid=0, high = nums.size()-1;

        while( mid <= high){
            if(nums[mid] == 0){
                swap(nums[low],nums[mid]);
                low++,mid++;
            }
            else if(nums[mid] == 1){
                mid++;
            }
            else{
                swap(nums[mid],nums[high]);
                high--;
            }
        }
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {2, 0, 2, 1, 1, 0};
    sol.sortColors(nums);

    for (int x : nums)
    {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}