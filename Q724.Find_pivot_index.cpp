#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
         int left = 0, totalSum = 0;
        for (int num : nums) {
            totalSum += num;   // add each element
        }
        for(int i = 0 ; i < nums.size() ; i++ ){
            int right = totalSum - nums[i] - left;
            if(left == right){
                return i;
            }
            left += nums[i];
        }
        return -1;
    }
};

// Java code for the same problem
// class Solution {
//     public int pivotIndex(int[] nums) {
//         int left = 0, totalSum = 0;
//         for (int num : nums) {
//             totalSum += num;   // add each element
//         }
//         for(int i = 0 ; i < nums.length ; i++ ){
//             int right = totalSum - nums[i] - left;
//             if(left == right){
//                 return i;
//             }
//             left += nums[i];
//         }
//         return -1;
//     }
// }



int main(){
    Solution s;
    vector<int> nums = {1,7,3,6,5,6};
    cout << s.pivotIndex(nums) << endl;
    return 0;
}
