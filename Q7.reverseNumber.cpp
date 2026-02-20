#include <iostream>
#include <climits>
using namespace std;


class Solution
{
public:
    int reverseNumber(int nums){
        int ans = 0;

        while(nums != 0){
            int Digit = nums % 10;

            if( (ans > INT_MAX/10) || (ans < INT_MIN/10)){
                return 0;
            }

            ans = (ans * 10) + Digit;
            nums /= 10;
        }
        return ans;
    }
};



int main()
{
    Solution sol;
    int nums = 123;
    int result = sol.reverseNumber(nums);
    cout << "Reversed number: " << result << endl;
    return 0;
}