#include <iostream>
#include <string>
#include <cctype>
using namespace std;


class Solution
{
public:
    // insted of using thid function we canuse c++ function 
    //isalnum() for check alphanumeric

    // bool isAlphaNum(char ch)
    // {
    //     if ((ch >= '0' && ch <= '9') ||
    //         (tolower(ch) >= 'a' && tolower(ch) <= 'z'))
    //     {
    //         return true;
    //     }
    //     return false;
    // }

    bool isPalindrome(string s)
    {

        int start = 0;
        int end = s.length() - 1;

        while (start < end)
        {
            if (!isalnum(s[start]))
            {
                start++;
                continue;
            }
            if (!isalnum(s[end]))
            {
                end--;
                continue;
            }
            if (tolower(s[start]) != tolower(s[end]))
            {
                return false;
            }

            start++;
            end--;
        }

        return true;
    }
};

main()
{
    Solution sol;
    string s = " ";

    if (sol.isPalindrome(s))
        cout << "Palindrome" << endl;
    else
        cout << "Not Palindrome" << endl;

    return 0;

}