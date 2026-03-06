#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/valid-parentheses/description/

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for(char c : s) {

            if(c == '(') st.push(')');
            else if(c == '{') st.push('}');
            else if(c == '[') st.push(']');
            else {
                if(st.empty() || st.top() != c)
                    return false;
                st.pop();
            }
        }
        return st.empty();
    }
};

// 2nd approch
class Solution2 {
public:
    bool isValid(string s) {
        stack<char> st;

        for(char c : s) {

            if(c == '(') st.push(')');
            else if(c == '{') st.push('}');
            else if(c == '[') st.push(']');
            else {
                if(st.empty() || st.top() != c)
                    return false;
                st.pop();
            }
        }
        return st.empty();
        return true;
    }
};

// 3rd approch
class Solution3 {
public:
    bool isValid(string s) {
        stack<char> st;

        for (char c : s) {
            if (c == '(' || c == '{' || c == '[') {
                st.push(c);
            } else {
                if (st.empty()) return false;

                char top = st.top();
                st.pop();

                if ((c == ')' && top != '(') ||
                    (c == '}' && top != '{') ||
                    (c == ']' && top != '[')) {
                    return false;
                }
            }
        }
        return st.empty();
    }
};



int main() {
    Solution sol;
    string s = "()[]{}";

    if (sol.isValid(s))
        cout << "Valid Parentheses" << endl;
    else
        cout << "Invalid Parentheses" << endl;

    return 0;
}