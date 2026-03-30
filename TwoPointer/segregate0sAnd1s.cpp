#include<bits/stdc++.h>
using namespace std;


// https://www.geeksforgeeks.org/problems/segregate-0s-and-1s5106/1

class Solution {
    public:
    void segregate0and1(vector<int> &arr){
        int i=0, j= arr.size()-1;

        while(i<j){

            if(arr[i] == 0) i++;
            else if(arr[j] == 1) j--;
            else swap(arr[i],arr[j]);
        }
    }
};


int main(){
    Solution sol;
    vector <int> arr = { 0, 0, 1, 1, 0 };
    sol.segregate0and1(arr);

    for(int x: arr) cout<<x<<" ";
    cout<<endl;
    return 0;
}
