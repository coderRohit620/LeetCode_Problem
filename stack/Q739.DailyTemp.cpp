#include<bits/stdc++.h>
using namespace std;

// 739. Daily Temperatures
// https://leetcode.com/problems/daily-temperatures/description/

// 91% Accuracy in leetcode
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        
        int n = temp.size();
        vector<int> res(n, 0);   // initialize with 0
        stack<int> st;           // store indices
        
        for(int i = n - 1; i >= 0; i--) {
            
            while(!st.empty() && temp[st.top()] <= temp[i]) {
                st.pop();
            }
            
            if(!st.empty()) {
                res[i] = st.top() - i;
            }
            
            st.push(i);
        }
        
        return res;
    }
};


class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack <int> st;
        vector<int> res(n);

        res[n-1] = 0;
        st.push(n-1);
        
        for(int i = n-2 ; i >= 0; i--){
            while(!st.empty() &&  temperatures[st.top()] <= temperatures[i] ){
                st.pop();
            }
            if(st.empty())
                res[i] = 0;
            else
                res[i] = st.top() - i;
                
            st.push(i);
        }
        return res;
    }
};

// padho with pratyush 
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n = temp.size();
        stack <int> st;
        vector<int> res(n);

        res[n-1] = 0;
        st.push(n-1);
        
        for(int i = n-2 ; i >= 0; i--){
            while(!st.empty() &&  temp[st.top()] <= temp[i] ){
                st.pop();
            }
            if(st.empty())
                res[i] = 0;
            else
                res[i] = st.top() - i;
                
            st.push(i);
        }
        return res;
    }
};