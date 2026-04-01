#include<bits/stdc++.h>
using namespace std;


// https://leetcode.com/problems/3sum-closest/description/

// two pointer approch with max_diff variable
class Solution {
    public:
    int threeSumClosest(vector<int>& nums, int target){
        sort(nums.begin(), nums.end());

        int n = nums.size();
        int max_diff = INT_MAX;
        int res;

        for (int i = 0; i < n-2; i++){
            int left = i+1, right = n-1;

            while(left < right){
                int sum = nums[i]+ nums[left]+nums[right];
                int diff = abs(sum - target);

                if(diff < max_diff){
                    max_diff = diff;
                    res = sum;
                }
                else if(sum < target) left++;
                else right--;
            }
        }
        return res;
    }
};

// alternative approach without using max_diff variable
class Solution1 {
    public:
    int threeSumClosest(vector<int>& nums, int target){
        sort(nums.begin(), nums.end());

        int n = nums.size();
        int res = nums[0] +nums[1]+nums[2];

        for (int i = 0; i < n-2; i++){
            int left = i+1, right = n-1;

            while(left < right){
                int sum = nums[i]+ nums[left]+nums[right];
                // int diff = abs(sum - target);

                if(sum == target) return sum;
                else if(abs(sum - target) < abs(res - target)){
                    res = sum;
                }
                else if(sum < target) left++;
                else right--;
            }
        }
        return res;
    }
};

int main(){
    Solution sol;
    Solution1 sol1;
    vector<int> nums ={-1,2,1,-4};
    vector<int> nums1 ={ 0,0,0 };
    int target = 1;

    int result = sol1.threeSumClosest(nums1,target);
    cout<< "Output :"<<result<<endl;
    return 0;
}


int main() {
    int n, target;
    cin >> n >> target;

    vector<int> nums(n);
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }

    sort(nums.begin(), nums.end());

    int res = nums[0] + nums[1] + nums[2];

    for(int i = 0; i < n - 2; i++){
        int left = i + 1;
        int right = n - 1;

        while(left < right){
            int sum = nums[i] + nums[left] + nums[right];

            // exact match → best case
            if(sum == target){
                cout << sum << endl;
                return 0;
            }

            // update closest
            if(abs(sum - target) < abs(res - target)){
                res = sum;
            }

            // move pointers
            if(sum < target){
                left++;
            } else {
                right--;
            }
        }
    }

    cout << res << endl;

    return 0;
}