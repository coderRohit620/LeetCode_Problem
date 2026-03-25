#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int findMin(vector<int>& nums) {
        int low =0, high = nums.size()-1;
        while(low < high){
            int mid = low + (high-low)/2;

            if(nums[mid] > nums[high]){
                low = mid+1;
            }
            else{
                high = mid;
            }
        }
        return (nums[low]);
    }
};


class Solution {
public:
    int findMin(vector<int>& nums) {
        int low =0, n = nums.size();
        int high = n-1;
        int res = -1;
        while(low <= high){
            int mid = low + (high-low)/2;

            if(nums[mid] > nums[n-1]){
                low = mid+1;
            }
            else{
                res = mid;
                high = mid - 1;
            }
        }
        return (nums[res]);
    }
};