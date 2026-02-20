#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        string result = "";

        for (int i = 0; i < strs[0].size(); i++)
        {
            for (int j = 0; j < strs.size() - 1; j++)
            {
                if (strs[j][i] != strs[j + 1][i])
                {
                    return result;
                }
            }
            result += strs[0][i];
        }
        return result;
    }
};

int main()
{
    Solution sol;
    vector<string> strs;
    strs.push_back("flower");
    strs.push_back("flow");
    strs.push_back("flight");
    string ans = sol.longestCommonPrefix(strs);
    cout << "Longest Common Prefix: " << ans << endl;
    return 0;
}