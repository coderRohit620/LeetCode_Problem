#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkOnesSegment(string s) {
        return s.find("01") == string::npos;
    }
};

// class Solution {
// public:
//     bool checkOnesSegment(string s) {
//         for(int i = 1; i < s.size(); i++){
//             if(s[i] == '1' && s[i-1] == '0')
//                 return false;
//         }
//         return true;
//     }
// };

int main(){
    Solution sol;
    string s = "1001";
    cout << sol.checkOnesSegment(s) << endl;
    return 0;
}