#include<bits/stdc++.h>
using namespace std;



class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty()) return 0;
        int count = 1;
        int n = nums.size();
        for(int i = 1; i < n ;i++){
            if( nums[i] != nums[i-1]){
                nums[count] = nums[i];
                count++;
            }
        }
        return count;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1,1,2,2,3,4,4,5};

    int newLength = sol.removeDuplicates(nums);

    cout<<newLength;
    // cout << "Length of unique elements: " << newLength << endl;
    // cout << "Array after removing duplicates: ";
    // for(int i = 0; i < newLength; i++) {
    //     cout << nums[i] << " ";
    // }
    // cout << endl;

    return 0;
}