// 34. Find First and Last Position of Element in Sorted Array

// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/

#include <bits/stdc++.h>
using namespace std;


// Approach1: two binary search, one for first occurrence and another for last occurrence.
class Solution {
public:
    int findFirst(vector<int>& nums, int target){
        int low = 0;
        int high = nums.size() -1;
        int res = -1;
        while( low <= high){
            int mid = low + (high - low)/2;
            if(nums[mid] < target) low = mid+1;
            else if(nums[mid] > target) high = mid-1;
            else{
                res = mid;
                high = mid -1; //move left 
            }
        }
        return res;
    };
    
    int findLast(vector<int>& nums, int target){
        int low = 0;
        int high = nums.size() -1;
        int res = -1;
        while( low <= high){
            int mid = low + (high - low)/2;
            if(nums[mid] < target) low = mid+1;
            else if(nums[mid] > target) high = mid-1;
            else{
                res = mid;
                low = mid +1; //move right
            }
        }
        return res;
    };
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = findFirst(nums, target);
        int last = findLast(nums, target);

        return {first, last};
    }
};


// Approach2: One function with flag to find first and last occurrence.

class Solution {
public:
    int findBound(vector<int>& nums, int target, bool isFirst){
        int low = 0;
        int high = nums.size() -1;
        int res = -1;
        while( low <= high){
            int mid = low + (high - low)/2;
            if(nums[mid] == target){
                res = mid;
                if(isFirst) high = mid -1;
                else low = mid +1;
            }
            else if(nums[mid] < target){
                low = mid+1;
            }   
            else{
                high = mid -1; //move left 
            }
        }
        return res;
    };
    
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = findBound(nums, target, true);
        int last = findBound(nums, target ,false);

        return {first, last};
    }
};

// Approach3: Using STL functions lower_bound and upper_bound.

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto first = lower_bound(nums.begin(), nums.end(), target);
        auto last  = upper_bound(nums.begin(), nums.end(), target);

        if (first == nums.end() || *first != target)
            return {-1, -1};

        return {int(first - nums.begin()), int(last - nums.begin() - 1)};
    }
};

// Input: nums = [5,7,7,8,8,10], target = 8

int main(){
    vector<int> nums = {5,7,7,8,8,10};
    int target = 8;
    Solution ob;
    vector<int> res = ob.searchRange(nums, target);
    cout << res[0] << " " << res[1] << "\n";
    return 0;
}



