import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

class Task2537 {

    public long countGood(int[] nums, int k) {
        long[] suffixGoodSubarays = new long[nums.length];
        long result = 0;
        long currentK = 0;

        Map<Integer, Integer> digitCount = new HashMap<>();
        if (nums.length <= 1) {
            return 0;
        }
        int l = 0, r = -1;
        boolean goodWindow = false;

        while (r < nums.length - 1) {
            if (goodWindow) {
                result += nums.length - r;

                int leftCount = digitCount.get(nums[l]);
                currentK -= leftCount - 1;

                digitCount.put(nums[l], digitCount.get(nums[l]) - 1);
                if(currentK < k){
                goodWindow = false;
                }
                l++;
            } else {
                r++;
                int rCount = digitCount.getOrDefault(nums[r], 0);
                currentK += rCount;
                digitCount.put(nums[r], rCount + 1);
                if (currentK >= k) {
                    goodWindow = true;
                }
            }
        }
        while(goodWindow && l < r){
            result++;

            int leftCount = digitCount.get(nums[l]);
            currentK -= leftCount - 1;

            digitCount.put(nums[l], digitCount.get(nums[l]) - 1);
            if(currentK < k) {
                goodWindow = false;
            }
            l++;
        }
        return result;
    }

    public static void main(String[] args) {
        Task2537 x = new Task2537();
        System.out.println(x.countGood(new int[] {3, 1, 4, 3, 2, 2, 4}, 2));
        //                                        0, 1, 2, 3, 4, 5, 6, } 7
    }
}