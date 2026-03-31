#include <bits/stdc++.h>
using namespace std;


// https://leetcode.com/problems/squares-of-a-sorted-array/

// BruteForce Approch (TC - nlogn)
class Solution
{
public:
    vector<int> sortedArr(vector<int> &arr)
    {
        vector<int> result;
        for (int i = 0; i < arr.size(); i++)
        {
            result.push_back(arr[i] * arr[i]);
        }
        sort(result.begin(), result.end());
        return result;
    }
};

// 2nd approch ;- Split + merge  TC= O(n) SC = O(n)
class Solution1 {
    public:
        vector<int> sortedArr(vector<int>& arr){
            vector<int> pos, neg;

            for(int x : arr){
                if(x < 0) neg.push_back(x * x);
                else pos.push_back(x * x);
            }

            reverse(neg.begin(), neg.end());

            vector<int> res;
            res.reserve(pos.size() + neg.size());

            int i = 0, j = 0;

            while(i < neg.size() && j < pos.size()){
                if(neg[i] <= pos[j]) res.push_back(neg[i++]);
                else res.push_back(pos[j++]);
            }

            while(i < neg.size()) res.push_back(neg[i++]);
            while(j < pos.size()) res.push_back(pos[j++]);

            return res;
        }
};


// 3rd Apporoch ;- Two Pointer (100%) TC= O(n) SC = O(n)
class Solution3 {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);

        int left = 0, right=n-1;
        for(int i = n-1; i >= 0;i--){
            if(abs(nums[left]) > abs(nums[right])){
                res[i] = nums[left]*nums[left];
                left++;
            }else{
                res[i] = nums[right]*nums[right];
                right--;
            }
        }
        return res;
    }
};

// Two Pointer - by Using While Loop
class Solution4 {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);

        int left = 0, right = n-1;
        int pos = n-1;
        while (left <= right){
            if( abs(nums[left]) > abs(nums[right])){
                res[pos--] = nums[left]*nums[left];
                left++;
            }else{
                res[pos--] = nums[right]*nums[right];
                right--;
            }
        }
        return res;
    }
};


int main()
{
    Solution1 sol;
    vector<int> arr = {-4, -1, 0, 3, 10};
    vector<int> result = sol.sortedArr(arr);

    for (int x : result)
        cout << x << " ";
    cout << endl;

    return 0;
}