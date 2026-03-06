#include<bits/stdc++.h>
using namespace std;

// Next Greater Element
// https://www.geeksforgeeks.org/next-greater-element/

// padho with pratyush
class Solution {
public:    
        vector<int> nextGreater(vector<int>& nums) {    
        int n = nums.size();
        vector<int> res(n);
        stack<int> st;
        res[n-1] = -1;
        st.push(nums[n-1]);     
        
        for(int i = n-2 ; i >= 0 ; i--){
            while(!st.empty() && st.top() <= nums[i]){
                st.pop();
            }

            if(st.empty()) 
                res[i] = -1;
            else
                res[i] = st.top();

            st.push(nums[i]);
        }
        return res;
    }
};

// 2nd approch
class Solution2 {
public:    
        vector<int> nextGreater(vector<int>& nums) {    
        int n = nums.size();
        vector<int> res(n, -1);
        stack<int> st;
        
        for(int i = n-1 ; i >= 0 ; i--){
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

int main(){
    Solution sol;
    vector<int> nums = {10, 20, 5, 15, 30};
    vector<int> res = sol.nextGreater(nums);

    for(int i : res){
        cout << i << " ";
    }
    cout << endl;
    return 0;
}   