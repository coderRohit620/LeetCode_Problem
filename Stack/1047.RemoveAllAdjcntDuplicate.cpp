#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeDuplicates(string s) {
        stack <char> st;
        int n = s.size();
        string res;

        for(int i =0 ; i< n ; i++){
            if(st.empty()){
                st.push(s[i]);
                continue;
            }
            if(st.top() == s[i]){
                st.pop();
                continue;
            }
            st.push(s[i]);
        }

         while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

int main(){
    Solution s;
    string str = "abbaca";
    cout << s.removeDuplicates(str) << endl; // Output: "ca"
    return 0;
}