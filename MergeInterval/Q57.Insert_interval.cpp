#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// https://leetcode.com/problems/insert-interval/description/

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        // if(intervals.size() <= 1)
        //     return intervals;

        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end());
        
        vector<vector<int>> res;
        
        int start1 = intervals[0][0];
        int end1   = intervals[0][1];
        
        for(int i = 1; i < intervals.size(); i++) {
            
            int start2 = intervals[i][0];
            int end2   = intervals[i][1];
            
            // Overlapping case
            if(end1 >= start2) {
                end1 = max(end1, end2);
            } 
            else {
                res.push_back({start1, end1});
                start1 = start2;
                end1 = end2;
            }
        }

        // insted of using above code we can also use below code to merge intervals.
        // for(int i = 1; i < intervals.size(); i++){
        //     if(end >= intervals[i][0]){
        //         end = max(end, intervals[i][1]);
        //     }
        //     else{
        //         res.push_back({start, end});
        //         start = intervals[i][0];
        //         end = intervals[i][1];
        //     }
        // }

        // res.push_back({start, end});
        // Push last interval
        res.push_back({start1, end1});
        
        return res;
    }
};

int main(){
    Solution s;
    vector<vector<int>> intervals = {{1,3},{6,9}};
    vector<int> newInterval = {2,5};
    vector<vector<int>> res = s.insert(intervals, newInterval);
    for(auto interval : res) {
        cout << "[" << interval[0] << "," << interval[1] << "] ";
    }
    cout << endl;
    return 0;
}