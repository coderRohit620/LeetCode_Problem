#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/3sum/description/

// Brute Force Approch 
class Solution {
    public:
    vector<vector<int>> threeSum(vector<int>& nums){
        int n = nums.size();
        vector<vector<int>> res;
        int sum;


        for(int i = 0; i < n - 2; i++){
            for(int j = i + 1; j < n - 1; j++){
                for(int k = j + 1; k < n; k++){
                    sum = nums[i] + nums[j] + nums[k];
                    if(sum == 0){
                        vector<int> triplet = {nums[i], nums[j], nums[k]};
                        sort(triplet.begin(), triplet.end());
                        res.push_back(triplet);
                    }
                }
            }
        }
        return res;
        
    }
};


// Optimal Approch - sorting + two pointer
class Solution1 {
    public:
    vector<vector<int>> threeSum(vector<int>& nums){
        int n = nums.size();
        vector<vector<int>> res;
        for(int i = 0 ; i < n-2 ; i++){
            if( i > 0 && nums[i] == nums[i-1]) continue;

            int left = i+1, right = n-1;
            int target  = -nums[i];

            while(left < right){
                int sum = nums[left]+nums[right];

                if(sum == target){
                    res.push_back({nums[i],nums[left],nums[right]});

                    while(left < right && nums[left]==nums[left-1])   left++;
                    while(left < right && nums[right]==nums[right+1])   right--;
                }
                else if(sum > 0) left++;
                else right--;

            }
        }
        return res;
    }
};


// Optimal Approch - sorting + two pointer
// NOTE: we can break the loop if nums[i] > 0 because in that case sum will always be greater than 0
class Solution1 {
    public:
    vector<vector<int>> threeSum(vector<int>& nums){
        int n = nums.size();
        vector<vector<int>> res;
        for(int i = 0 ; i < n-2 ; i++){
            if( i > 0 && nums[i] == nums[i-1]) continue;

            if(nums[i] > 0) break;

            int left = i+1, right = n-1;

            while(left < right){
                int sum = nums[i]+nums[left]+nums[right];

                if(sum == 0){
                    res.push_back({nums[i],nums[left],nums[right]});

                    while(left < right && nums[left]==nums[left-1])   left++;
                    while(left < right && nums[right]==nums[right+1])   right--;
                }
                else if(sum > 0) left++;
                else right--;
            }
        }
        return res;
    }
};



int main(){
    vector<int> nums = {-1,0,1,2,-1,-4};
    Solution1 sol;
    vector<vector<int>> res = sol.threeSum(nums);
    for(auto triplet : res){
        for(int x : triplet){
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}


int main() {
    vector<int> nums = {-1, 0, 1, 2, -1, -4}; // example input
    int n = nums.size();
    
    vector<vector<int>> res;

    sort(nums.begin(), nums.end()); // IMPORTANT for two-pointer approach

    for (int i = 0; i < n - 2; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) continue;

        if (nums[i] > 0) break;

        int left = i + 1, right = n - 1;
        int target = -nums[i];

        while (left < right) {
            int sum = nums[left] + nums[right];

            if (sum == target) {
                res.push_back({nums[i], nums[left], nums[right]});

                // skip duplicates
                while (left < right && nums[left] == nums[left + 1]) left++;
                while (left < right && nums[right] == nums[right - 1]) right--;

                left++;
                right--;
            }
            else if (sum < target) {
                left++;
            }
            else {
                right--;
            }
        }
    }

    // print result
    for (auto triplet : res) {
        for (int x : triplet) {
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}
