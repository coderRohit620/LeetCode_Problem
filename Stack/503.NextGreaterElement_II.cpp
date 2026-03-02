#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/next-greater-element-ii/description/

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> res(n, -1);
        stack<int> st;  // store indices

        for(int i = 2*n - 1; i >= 0; --i) {
            int idx = i % n;
            while(!st.empty() && nums[st.top()] <= nums[idx])
                st.pop();

            if(i < n && !st.empty())
                res[idx] = nums[st.top()];

            st.push(idx);
        }
        return res;
    }
};


int main() {
    Solution sol;
    vector<int> nums = {1, 2, 1};
    vector<int> result = sol.nextGreaterElements(nums);
    
    for(int num : result) {
        cout << num << " ";
    }
    cout << endl; // Output: 2 -1 2
    return 0;
}   