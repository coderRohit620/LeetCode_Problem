#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/binary-gap/description/
class Solution {
public:
    int binaryGap(int n) {
        int curr =0;
        int prev = -1;
        int result = 0;

        while(n > 0){
            if ((n&1) > 0){
                result = (prev != -1) ? max(result, curr-prev) : result;
                prev = curr;
            }
            curr++;
            n>>=1;
        }
        return result;
    }
};

int main(){
    Solution s;
    int n = 22;
    cout << s.binaryGap(n) << endl;
    return 0;
}   