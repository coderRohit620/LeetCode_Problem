// https://leetcode.com/problems/kth-largest-element-in-an-array/description/

import java.util.PriorityQueue;

public class kthLargestElement {

    public int findKthLargest(int[] nums, int k){
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
    public static void main(String[] args) {
        kthLargestElement sol = new kthLargestElement();
        int[] nums = {3,2,1,5,6,4};
        int k = 2;
        int ans = sol.findKthLargest(nums, k);
        System.err.println(ans);
    }
}
