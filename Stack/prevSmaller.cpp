#include<bits/stdc++.h>
using namespace std;    

// Previous Smaller Element
// https://www.geeksforgeeks.org/previous-smaller-element/

// padho with pratyush
class Solution {
public:
    vector<int> prevSmaller(vector<int>& nums) {    
        int n = nums.size();
        vector<int> res(n);
        stack<int> st;
        res[0] = -1;
        st.push(nums[0]);

        for(int i = 1 ; i < n ; i++){
            while(!st.empty() && st.top() >= nums[i]){
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
class Solution {
public:
    vector<int> prevSmaller(vector<int>& nums) {    
        int n = nums.size();
        vector<int> res(n, -1);
        stack<int> st; 
        for(int i = 0 ; i < n ; i++){
            while(!st.empty() && st.top() >= nums[i]){
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
    vector<int> res = sol.prevSmaller(nums);

    for(int i : res){
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
