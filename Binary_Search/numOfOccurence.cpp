#include<bits/stdc++.h>
using namespace std;    


// https://www.geeksforgeeks.org/problems/number-of-occurrence2259/1


class Solution {
  public:
    int findBound(vector<int>& arr, int target, bool isFirst){
        
        int low =0, high= arr.size()-1;
        int res = -1;
        
        while(low <= high){
            int mid = low +(high - low)/2;
            
            if(arr[mid] == target){
                res = mid;
                if(isFirst){
                    high = mid - 1;
                }else{
                    low = mid +1;
                }
            }else if(arr[mid] < target){
                low = mid +1;
            }else{
                high = mid-1;
            }
            
        }
        return res;
    }
    int countFreq(vector<int>& arr, int target) {
        // code here
        int first = findBound(arr,target, true);
        int last = findBound(arr,target, false);
        
        if (first == -1) return 0;
        int ans = (last - first) + 1;
        
        return ans;
        
    }
};


class Solution {
  public:
    int countFreq(vector<int>& arr, int target) {
        // code here
        int count =0;
        for(int x : arr){
            if(x == target) count++;
            else if(x > target) break;
        }
        return count;
        
    }
};

int main(){
    Solution sol;
    vector<int> arr = {1, 2, 8, 10, 10, 12, 19};
    int x = 10;
    cout<<sol.countFreq(arr, x)<<endl;
    return 0;
}   