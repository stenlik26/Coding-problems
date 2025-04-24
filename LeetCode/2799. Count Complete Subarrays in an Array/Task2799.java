import java.util.Arrays;

class Task2799 {

    public int countCompleteSubarrays(int[] nums) {
        int l = 0;
        int r = 0;
        int runningCount = 0;
        int target = (int) Arrays.stream(nums).distinct().count();

        int result = 0;

        int[] counts = new int[2001];
        Arrays.fill(counts, 0);

        while (l <= r && r < nums.length) {
            if (runningCount == target) {
                result += nums.length - r + 1;
                if (counts[nums[l]] == 1) {
                    runningCount--;
                }
                counts[nums[l]]--;
                l++;
            } else {
                if (counts[nums[r]] == 0) {
                    runningCount++;
                }
                counts[nums[r]]++;
                r++;
            }
        }

        while(runningCount == target){
            result++;
            if (counts[nums[l]] == 1) {
                runningCount--;
            }
            counts[nums[l]]--;
            l++;
        }

        return result;
    }

    public static void main(String[] args) {
        Task2799 x = new Task2799();

        System.out.println(x.countCompleteSubarrays(new int[] {1, 3, 1, 2, 2}));
        System.out.println(x.countCompleteSubarrays(new int[] {5,5,5,5}));
    }
}