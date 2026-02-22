#include<iostream>
#include<vector>
using namespace std;

// https://leetcode.com/problems/interval-list-intersections/description/

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> res;
        if(firstList.empty() || secondList.empty())
            return {};

        int i = 0 , j = 0;
        int n = firstList.size();
        int m = secondList.size();
        while( i < n && j < m){
            int start1 = firstList[i][0];
            int end1 = firstList[i][1];
            int start2 = secondList[j][0];
            int end2 = secondList[j][1];

            if(start1 <= start2){
                if(end1 >= start2){
                    int s = max(start1,start2);
                    int e = min(end1,end2);
                    res.push_back({s,e});
                }
            }
            else{
                if(end2 >= start1){
                    int s = max(start1,start2);
                    int e = min(end1,end2);
                    res.push_back({s,e});
                }    
            }
            if(end1 <= end2) i++;
            else j++;
        }
        return res;  
    }
};


class Solution2 {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        
        vector<vector<int>> res;

        int i = 0, j = 0;
        int n = firstList.size();
        int m = secondList.size();

        while(i < n && j < m) {
            
            int start1 = firstList[i][0];
            int end1   = firstList[i][1];
            int start2 = secondList[j][0];
            int end2   = secondList[j][1];

            int start = max(start1, start2);
            int end   = min(end1, end2);

            if(start <= end) {
                res.push_back({start, end});
            }

            // Move pointer of smaller ending interval
            if(end1 < end2)
                i++;
            else
                j++;
        }

        return res;
    }
};

// Time Complexity: O(n + m) where n and m are the sizes of firstList and secondList respectively.
// Space Complexity: O(k) where k is the number of intersecting intervals.

// write a test case to test the above code.
int main() {
    Solution2 sol;
    vector<vector<int>> firstList = {{0,2},{5,10},{13,23},{24,25}};
    vector<vector<int>> secondList = {{1,5},{8,12},{15,24},{25,26}};
    
    vector<vector<int>> result = sol.intervalIntersection(firstList, secondList);
    
    cout << "Intersecting Intervals: " << endl;
    for(const auto& interval : result) {
        cout << "[" << interval[0] << ", " << interval[1] << "]" << endl;
    }
    
    return 0;
}  