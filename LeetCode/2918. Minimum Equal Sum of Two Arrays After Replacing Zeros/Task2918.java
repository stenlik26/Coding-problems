import java.lang.reflect.Array;
import java.util.Arrays;

class Task2918 {

    public long minSum(int[] nums1, int[] nums2) {
        long sum1 = 0, sum2 = 0;

        for (int x : nums1) {
            sum1 += x;
        }
        for (int x : nums2) {
            sum2 += x;
        }

        int zero1 = (int) Arrays.stream(nums1).filter(x -> x == 0).count();
        int zero2 = (int) Arrays.stream(nums2).filter(x -> x == 0).count();

        sum1 += zero1;
        sum2 += zero2;

        if (zero1 == 0 && zero2 == 0) {
            return (sum1 == sum2) ? sum1 : -1;
        } else if (zero1 == 0 && sum1 < sum2) {
            return -1;
        } else if (zero2 == 0 && sum2 < sum1) {
            return -1;
        }
        return Math.max(sum1, sum2);
    }

    public static void main(String[] args) {

    }
}