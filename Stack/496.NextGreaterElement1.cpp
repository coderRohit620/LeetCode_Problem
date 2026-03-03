#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/next-greater-element-i/description/

// Optimized approach using stack and hash map
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        stack<int> st;
        unordered_map<int, int> mp;   // value -> next greater
        
        // Step 1: Find next greater for every element in nums2
        for(int num : nums2) {
            
            while(!st.empty() && st.top() < num) {
                mp[st.top()] = num;  // current num is next greater
                st.pop();
            }
            st.push(num);
        }
        // Step 2: Remaining elements have no next greater
        while(!st.empty()) {
            mp[st.top()] = -1;
            st.pop();
        }
        // Step 3: Build answer for nums1
        vector<int> ans;
        for(int num : nums1) {
            ans.push_back(mp[num]);
        }
        return ans;
    }
};


int main() {
    Solution sol;
    vector<int> nums1 = {4,1,2};
    vector<int> nums2 = {1,3,4,2};
    vector<int> result = sol.nextGreaterElement(nums1, nums2);
    
    for(int num : result) {
        cout << num << " "; // Output: -1 3 -1
    }
    cout << endl;
    
    return 0;
}   