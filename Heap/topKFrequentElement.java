import java.util.*;

public class topKFrequentElement {
    public int[] findTopKFrequent(int[] nums, int k) {

        // Step 1: Count frequency
        HashMap<Integer, Integer> freq = new HashMap<>();

        for (int num : nums) {
            freq.put(num, freq.getOrDefault(num, 0) + 1);
        }

        // Step 2: Create buckets
        List<Integer>[] bucket = new ArrayList[nums.length + 1];

        for (int num : freq.keySet()) {
            int f = freq.get(num);

            if (bucket[f] == null) {
                bucket[f] = new ArrayList<>();
            }

            bucket[f].add(num);
        }

        // Step 3: Get top k elements
        int[] result = new int[k];
        int index = 0;

        for (int f = bucket.length - 1; f >= 0 && index < k; f--) {

            if (bucket[f] != null) {

                for (int num : bucket[f]) {
                    result[index] = num;
                    index++;

                    if (index == k) {
                        break;
                    }
                }
            }
        }

        return result;
    }

    public static void main(String[] args) {
        topKFrequentElement sol = new topKFrequentElement();
        int[] nums = { 1, 1, 1, 2, 2, 3 };
        int k = 2;
        int[] ans = sol.findTopKFrequent(nums, k);
        System.out.println(Arrays.toString(ans));
    }
}
