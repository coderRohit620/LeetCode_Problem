#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;    


class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
       if(intervals.size() <= 1)
            return intervals;
        
        // Step 1: Sort intervals by start time
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
        
        // Push last interval
        res.push_back({start1, end1});
        
        return res;
    }
};

int main(){
    Solution s;
    vector<vector<int>> intervals = {{1,3},{2,6},{8,10},{15,18}};
    vector<vector<int>> res = s.merge(intervals);
    for(auto interval : res) {
        cout << "[" << interval[0] << "," << interval[1] << "] ";
    }
    cout << endl;
    return 0;
}