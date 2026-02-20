#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        //  by using linear search
        int low = 0, high = nums.size() - 1;

        int postion = nums.size();
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target)
                return mid;
            if (nums[mid] > target)
            {
                postion = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        return postion;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 3, 5, 6};
    int target = 5;

    int result = sol.searchInsert(nums, target);
    cout << "The target should be inserted at index: " << result << endl;

    return 0;
}
