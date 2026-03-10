#include<bits/stdc++.h>
using namespace std;

// 383. Ransom Note
// Given two strings ransomNote and magazine, return true if ransomNote can be constructed by using the letters from magazine and false otherwise.
// Each letter in magazine can only be used once in ransomNote.

// https://leetcode.com/problems/ransom-note/description/

// 1st approach using unordered_map to count the frequency of characters in both strings and then comparing them.
class Solution {
    bool fun(unordered_map<char, int> have, unordered_map<char, int> need){
        for(auto i: need){
            char c = i.first;
            int fneed = i.second;
            int fhave = have[c];
            if(fhave < fneed){
                return false;
            }
        }
        return true;
    }
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> have;
        unordered_map<char, int> need;

        for(char r : ransomNote){
            need[r]++;
        }
        for(char m : magazine){
            have[m]++;
        }

        return fun(have,need);
    }
};


// 2nd approach using a single unordered_map to count the frequency of characters in magazine and then decrementing the count for each character in ransomNote. If any character's count becomes negative, it means we don't have enough characters to construct the ransom note, and we return false.  

class Solution2 {
public:
    bool canConstruct(string ransomNote, string magazine) {

        unordered_map<char,int> mp;

        for(char c : magazine){
            mp[c]++;
        }

        for(char c : ransomNote){
            if(mp[c] == 0) return false;
            mp[c]--;
        }

        return true;
    }
};

// 3rd approach using an array of size 26 to count the frequency of lowercase letters in magazine and then decrementing the count for each character in ransomNote. This approach is more efficient in terms of space complexity compared to using an unordered_map.

class Solution3 {
public:
    bool canConstruct(string ransomNote, string magazine) {

        int freq[26] = {0};

        for(char c : magazine)
            freq[c - 'a']++;

        for(char c : ransomNote){
            if(--freq[c - 'a'] < 0)
                return false;
        }

        return true;
    }
};


int main(){
    Solution sol;
    string ransomNote = "a";
    string magazine = "b";
    cout << sol.canConstruct(ransomNote, magazine) << endl; // Output: false
    return 0;
}   