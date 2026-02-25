#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/

class Solution {
public:
    bool hasAllCodes(string s, int k) {
        
        unordered_set<string> seen;
        
        for(int i = 0; i + k <= s.size(); i++) {
            seen.insert(s.substr(i, k));
        }
        
        return seen.size() == (1 << k);
    }
};

// By using Stack Approach
class Solution2 {
public:
    string removeDuplicates(string s) {
        string res;

        for(char c : s) {
            if(!res.empty() && res.back() == c)
                res.pop_back();
            else
                res.push_back(c);
        }

        return res;
    }
};

int main() {
    Solution s;
    string str = "00110110";
    int k = 2;
    cout << s.hasAllCodes(str, k) << endl; // Output: true
    return 0;
}       
