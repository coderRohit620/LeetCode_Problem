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

int main()
{
    Solution sol;
    string s = " ";

    if (sol.isPalindrome(s))
        cout << "Palindrome" << endl;
    else
        cout << "Not Palindrome" << endl;

    return 0;

}

// how to execute this file in terminal ?
// 1. Save the file with a .cpp extension (e.g., Q.125ValidPalindrome.cpp)
// 2. Open a terminal in the same directory
// 3. Compile the file using: g++ -std=c++17 Q.125ValidPalindrome.cpp -o Q.125ValidPalindrome
// 4. Run the compiled executable: ./Q.125ValidPalindrome