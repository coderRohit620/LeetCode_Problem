#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/reverse-string/description/

class Solution {
public:     
    void reverseString(vector<char>& s) {
        int i = 0;
        int j = s.size() - 1;

        while(i < j){
            swap(s[i], s[j]);
            i++;
            j--;
        }
    }
};  

//  by Using Stack
class Solution2 {
public:
    void reverseString(vector<char>& s) {
        stack<char> st;
        for (char c : s){
            st.push(c);
        }
        for (int i = 0; i < s.size(); i++){
            s[i] = st.top();
            st.pop();
        }
    }
};


int main(){
    Solution s;
    vector<char> str = {'h', 'e', 'l', 'l', 'o'};
    s.reverseString(str);
    for (char c : str){
        cout << c << " ";
    }
    cout << endl;
    return 0;
}   