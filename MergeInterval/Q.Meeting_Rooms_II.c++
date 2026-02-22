#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int minMeetingRooms(vector<int> &start, vector<int> &end) {
        // code here
        sort(start.begin(),start.end());
        sort(end.begin(),end.end());
         int n = start.size();
         
         int room = 0, i=0,j=0, res =0;
         
         while(i < n && j< n){
             if(start[i] < end[j]){
                 room++;
                 res = max(res,room);
                 i++;
             }
             else{
                 room--;
                 j++;
             }
         }
         return res;
    }
};


int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<int> start(n), end(n);
        for (int i = 0; i < n; i++) {
            cin >> start[i] >> end[i];
        }
        Solution ob;
        cout << ob.minMeetingRooms(start, end) << "\n";
    }
    return 0;
}   