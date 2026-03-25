#include<bits/stdc++.h>
using namespace std;

// // 
// Given a sorted array arr[] and an integer x, find the index (0-based) of the smallest element in arr[] that is greater than or equal to x. This element is called the ceil of x. If such an element does not exist, return -1.

// Note: In case of multiple occurrences of ceil of x, return the index of the first occurrence.

// Examples

// Input: arr[] = [1, 2, 8, 10, 11, 12, 19], x = 5
// Output: 2
// Explanation: Smallest number greater than 5 is 8, whose index is 2.
// Input: arr[] = [1, 2, 8, 10, 11, 12, 19], x = 20
// Output: -1
// Explanation: No element greater than 20 is found. So output is -1.
// Input: arr[] = [1, 1, 2, 8, 10, 11, 12, 19], x = 0
// Output: 0
// Explanation: Smallest number greater than 0 is 1, whose indices are 0 and 1. The index of the first occurrence is 0.

// https://www.geeksforgeeks.org/problems/ceil-in-a-sorted-array/1?page=1&status=solved&sortBy=latest

// User function Template for C++
class Solution {
  public:
    int findCeil(vector<int>& arr, int x){
        // code here
        int low = 0;
        int high = arr.size()-1 ;
        int res = -1;
        
        while(low <= high){
            int mid = low + (high - low)/2;
            
            if(arr[mid] < x){
                low = mid+1; 
            }else{
                res = mid;
                high = mid-1; 
            }
        }
        return res;
    }
};

int main(){
    Solution sol;
    vector<int> arr = {1, 2, 8, 10, 10, 12, 19};
    int x = 5;
    cout<<sol.findCeil(arr, x)<<endl;
    return 0;
}   