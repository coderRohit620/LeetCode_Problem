#include<bits/stdc++.h>
using namespace std;    


// 503. Next Greater Element II
// https://leetcode.com/problems/next-greater-element-ii/description/

// 100% Accuracy in leetcode
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> res(n, -1);
        stack<int> st; 

        for(int i = n-1 ; i >= 0 ; i--){
            st.push(nums[i]);
        }

        for(int i = n-1 ; i >= 0; i--){
            while(!st.empty() && st.top() <= nums[i]){
                st.pop();
            }
            if(!st.empty()) 
                res[i] = st.top();

            st.push(nums[i]);
        }
        return res;
    }
};

// 100% Accuracy in leetcode
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> res(n, -1);
        stack<int> st; 

        for(int i = n-1 ; i >= 0 ; i--){
            st.push(nums[i]);
        }

        for(int i = n-1 ; i >= 0; i--){
            while(!st.empty() && st.top() <= nums[i]){
                st.pop();
            }
            if(!st.empty()) 
                res[i] = st.top();

            st.push(nums[i]);
        }
        return res;
    }
};


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