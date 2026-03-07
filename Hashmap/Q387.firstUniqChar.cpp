#include<bits/stdc++.h>
using namespace std;

// 387. First Unique Character in a String
// Given a string s, return the first non-repeating character in it and return its index. If it does not exist, return -1.


class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int> f;

        for(char c : s){
            f[c]++;
        }

        for(int i = 0 ;i< s.size(); i++){
            if(f[s[i]] == 1) return i;
        }
        return -1;
    }
};

// 2nd approach using array instead of unordered_map..
class Solution2 {
public:
    int firstUniqChar(string s) {

        int freq[26] = {0};

        for(char c : s){
            freq[c - 'a']++;
        }

        for(int i = 0; i < s.size(); i++){
            if(freq[s[i] - 'a'] == 1)
                return i;
        }

        return -1;
    }
};


int main(){
    Solution sol;
    string s = "leetcode";
    cout << sol.firstUniqChar(s) << endl; // Output: 0

    s = "loveleetcode";
    cout << sol.firstUniqChar(s) << endl; // Output: 2          
    s = "aabb";
    cout << sol.firstUniqChar(s) << endl; // Output: -1
    return 0;
}