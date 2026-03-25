#include<bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/rotation4723/1

class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        // Code Here
        if(arr.size() == 1) return 0;
        int low =0, high = arr.size()-1;
        int res = 0;
        
        while(low < high){
            int mid = low+(high-low)/2;
            
            if(arr[mid] > arr[high]){
                low = mid+1;
            }else{
                high = mid;
            }
        }
        return low;
    }
};


int main(){
    Solution sol;
    vector<int> arr = {15, 18, 2, 3, 6, 12};
    vector<int> arr2 = {5, 1, 2, 3, 4};
    vector<int> arr3 = {1, 2, 3, 4, 5};
    cout<<sol.findKRotation(arr)<<endl;
    cout<<sol.findKRotation(arr2)<<endl;
    cout<<sol.findKRotation(arr3)<<endl;
    return 0;
}   