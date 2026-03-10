#include<bits/stdc++.h>
using namespace std;

// 409. Longest Palindrome
// https://leetcode.com/problems/longest-palindrome/

// 1st approach using unordered_map to count the frequency of characters in the input string and then calculating the length of the longest palindrome that can be formed based on the frequency of characters.
class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> freq;

        for(char c : s){
            freq[c]++;
        }

        int length = 0;
        bool oddFound = false;

        for(auto it : freq){
            if(it.second % 2 == 0){
                length += it.second;
            }
            else{
                length += it.second - 1;
                oddFound = true;
            }
        }

        if(oddFound) length += 1;

        return length;
    }
};

// 2nd approach using an array of size 128 to count the frequency of characters in the input string and then calculating the length of the longest palindrome that can be formed based on the frequency of characters.
class Solution2 {
public:
    int longestPalindrome(string s) {
        int freq[128] = {0};

        for(char c : s){
            freq[c]++;
        }

        int length = 0;

        for(int i = 0; i < 128; i++){
            length += (freq[i] / 2) * 2;
        }

        if(length < s.size()) length++;

        return length;
    }
};



int main(){
    string s = "abccccdd";
    Solution sol;
    cout << sol.longestPalindrome(s) << endl; // Output: 7
    return 0;
}   