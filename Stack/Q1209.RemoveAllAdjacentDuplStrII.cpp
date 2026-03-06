#include<bits/stdc++.h>
using namespace std;    

// 1209. Remove All Adjacent Duplicates in String II
// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii/description/

// padho with pratyush
class Solution {
public:
    string removeDuplicates(string s, int k) {
        int n = s.size();
        stack <pair <char, int>> st;

        for(int i =0; i< n; i++){
            char c = s[i];
            if(st.empty())
            {
                st.push({c,1});
                continue;
            }
            if(st.top().first != c){
                st.push({c,1});
                continue;
            }
            if(st.top().second < k-1){
                pair<char, int> p = st.top();
                st.pop();
                st.push({p.first,p.second+1});
                continue;
            }
            st.pop();
        }

        string res ="";
        while(!st.empty()){
            pair<char,int> p = st.top();
            st.pop();

            while(p.second--){
                res.push_back(p.first);
            }
        }
        reverse(res.begin(),res.end());
        return res;
    }
};

// best solution
class Solution {
public:
    string removeDuplicates(string s, int k) {

        int n = s.size();
        vector<int> count(n);
        int i = 0;

        for(int j = 0; j < n; j++, i++) {

            s[i] = s[j];

            if(i > 0 && s[i] == s[i-1])
                count[i] = count[i-1] + 1;
            else
                count[i] = 1;

            if(count[i] == k)
                i -= k;
        }

        return s.substr(0, i);
    }
};


// 2nd approch

class Solution {
public:
    string removeDuplicates(string s, int k) {
        int n = s.size();
        stack <pair <char, int>> st;

        for(int i =0; i< n; i++){
            char c = s[i];
            if(st.empty())
            {
                st.push({c,1});
                continue;
            }
            if(st.top().first != c){
                st.push({c,1});
                continue;
            }
            if(st.top().second < k-1){
                pair<char, int> p = st.top();
                st.pop();
                st.push({p.first,p.second+1});
                continue;
            }
            st.pop();
        }

        string res ="";
        while(!st.empty()){
            pair<char,int> p = st.top();
            st.pop();

            while(p.second--){
                res.push_back(p.first);
            }
        }
        reverse(res.begin(),res.end());
        return res;
    }
};


class Solution {
public:
    string removeDuplicates(string s, int k) {

        stack<pair<char,int>> st;

        for(char c : s){

            if(st.empty() || st.top().first != c){
                st.push({c,1});
            }
            else{
                st.top().second++;

                if(st.top().second == k){
                    st.pop();
                }
            }
        }

        string res = "";

        while(!st.empty()){
            auto p = st.top();
            st.pop();

            res.append(p.second, p.first);   // faster
        }

        reverse(res.begin(), res.end());

        return res;
    }
};


int main(){
    Solution sol;
    string s = "deeedbbcccbdaa";
    int k = 3;
    cout << sol.removeDuplicates(s, k) << endl;
    return 0;
}   