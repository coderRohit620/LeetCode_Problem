#include<bits/stdc++.h>
using namespace std;    

// 1189. Maximum Number of Balloons
// https://leetcode.com/problems/maximum-number-of-balloons/

// 1st approach using unordered_map to count the frequency of characters in the input string and then calculating the maximum number of "balloon" that can be formed based on the frequency of characters.

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int> f;

        for(char c : text){
            f[c]++;
        }
        int b = f['b'];
        int a = f['a'];
        int l = f['l']/2;
        int o = f['o']/2;
        int n = f['n'];

        return min({b,a,l,o,n});
    }
};


// 2nd approach using an array of size 26 to count the frequency of characters in the input string and then calculating the maximum number of "balloon" that can be formed based on the frequency of characters.

class Solution2 {
public:
    int maxNumberOfBalloons(string text) {
        int freq[26] = {0};

        for(char c : text){
            freq[c - 'a']++;
        }

        int b = freq['b' - 'a'];
        int a = freq['a' - 'a'];
        int l = freq['l' - 'a'] / 2;
        int o = freq['o' - 'a'] / 2;
        int n = freq['n' - 'a'];

        return min({b,a,l,o,n});
    }
};


// 3rd approach 
// Padho with Pratyush

class Solution3 {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int> have;
        unordered_map<char,int> need;

        for(int i = 0; i < text.size(); i++){
            have[text[i]]++;
        }
        need['b'] = 1;
        need['a'] = 1;
        need['l'] = 2;
        need['o'] = 2;
        need['n'] = 1;

        int res = INT_MAX;

        for(auto i: need){
            char c = i.first;
            int fneed = i.second;
            int fhave = have[c];
            int times = fhave / fneed;
            res = min(res,times);
        }
        return res;
    }
};

#include <iostream>
using namespace std;

int main(){
    Solution sol;

    string text = "nlaebolko";
    cout << sol.maxNumberOfBalloons(text) << endl; // Output: 1

    text = "loonbalxballpoon";
    cout << sol.maxNumberOfBalloons(text) << endl; // Output: 2
}