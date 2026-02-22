#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/overlapping-intervals--174556/1

class Solution {
  public:
    bool isIntersect(vector<vector<int>> intervals) {
        // Code Here
         if(intervals.size() <= 1)
            return false;
            
        sort(intervals.begin(), intervals.end());
        int n = intervals.size();
        
        int start1 = intervals[0][0];
        int end1 = intervals[0][1];
        for(int i = 1; i< n ; i++){
            int start2 = intervals[i][0];
            int end2 = intervals[i][1];
            
            if(end1 >= start2){
                return true;
            }
            end1 = max(end1,end2);
        }
        return false;
    }
};

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<vector<int>> intervals(n, vector<int>(2));
        for (int i = 0; i < n; i++) {
            cin >> intervals[i][0] >> intervals[i][1];
        }
        Solution ob;
        if (ob.isIntersect(intervals)) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
    return 0;
}