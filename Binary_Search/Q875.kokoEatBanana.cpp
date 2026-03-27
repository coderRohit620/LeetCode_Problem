#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/koko-eating-bananas/

class Solution {
    public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = *max_element(piles.begin(), piles.end());
        int res = high;

        while(low < high){
            int mid = low + (high - low)/2;

            long long hours=0;
            for(int x : piles){
                hours = (long long)(x + mid -1)/mid;

                if(hours > h) break;
            }

            if(hours> h) 
                low = mid+1;
            else   
                high = mid;
        }
        return low;
    }
};


// class Solution {
//     public:
//     int findHr(vector<int>& piles, int speed,int h) {

//         long long hours=0;
//         for(int x : piles){
//             hours = (long long)(x + speed -1)/speed;

//             if(hours > h) break;
//         }
//     }
//     int minEatingSpeed(vector<int>& piles, int h) {
//         int low = 1, high = *max_element(piles.begin(), piles.end());
//         int res = high;

//         while(low < high){
//             int mid = low + (high - low)/2;

//             int hours = findHr(piles, mid,h);
//             if(hours> h) 
//                 low = mid+1;
//             else   
//                 high = mid;
//         }
//         return low;
//     }
// };




int main(){
    Solution sol;
    vector<int> piles = {3,6,7,11};
    int h = 8;
    cout<<sol.minEatingSpeed(piles, h)<<endl;
    return 0;
}   