// https://leetcode.com/problems/kth-largest-element-in-an-array/description/

import java.util.Arrays;
import java.util.PriorityQueue;

public class kthLargestElement {
// Brute Force Approch TC-  O(n log n) 
     public int findKthLargest(int[] nums, int k){
        Arrays.sort(nums);
        return nums[nums.length - k];
    }
// optimize Approch TC - O(log n)
    public int findKthLargest1(int[] nums, int k){
        PriorityQueue<Integer> pq = new PriorityQueue<>();

        int n = nums.length;
        for(int i =0; i< n ;i++){
            pq.add(nums[i]);
            if(pq.size() > k){
                pq.poll();
            }
        }
        return pq.peek();
    }

    public int findKthLargest2(int[] nums,int k){
        PriorityQueue<Integer> pq = new PriorityQueue<>();

            for (int i = 0; i < k; i++) {
                pq.add(nums[i]);
            }

            for(int i = k; i < nums.length;i++){
                if (nums[i] <= pq.peek()) continue;
                pq.poll();
                pq.add(nums[i]);
            }
            return pq.peek();
        }

    public static void main(String[] args) {
        kthLargestElement sol = new kthLargestElement();
        int[] nums = {3,2,1,5,6,4};
        int k = 2;
        int ans = sol.findKthLargest(nums, k);
        int ans1 = sol.findKthLargest1(nums, k);
        int ans2 = sol.findKthLargest(nums,k);
        System.err.println(ans);
        System.err.println(ans1);
        System.err.println(ans2);
    }
}