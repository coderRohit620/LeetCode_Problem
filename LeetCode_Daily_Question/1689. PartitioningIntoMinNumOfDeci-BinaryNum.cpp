#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/partitioning-into-minimum-number-of-deci-binary-numbers/description/
class Solution {
public:
    int minPartitions(string n) {
        int maxDigit = 0;

        for(char c : n) {
            maxDigit = max(maxDigit, c - '0');
        }

        return maxDigit;
    }
};

int main() {
    Solution sol;
    string n = "82734";
    cout << sol.minPartitions(n) << endl; // Output: 8
    return 0;
}