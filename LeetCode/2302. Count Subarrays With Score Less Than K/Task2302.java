class Task2302 {

    public long countSubarrays(int[] nums, long k) {
        if (nums.length == 1) {
            return (nums[0] < k) ? 1 : 0;
        }
        int l = 0;
        int r = 0;
        long total = ((long) nums.length * (nums.length + 1)) / 2;

        long runningSum = 0;
        long result = 0;

        while (l <= r && r < nums.length) {
            if (runningSum * (r - l) < k) {
                runningSum += nums[r];
                r++;
            } else {
                result += (nums.length) - (r - 1);
                runningSum -= nums[l];
                l++;
            }
        }
        while (runningSum * (r - l) >= k) {
            result++;
            runningSum -= nums[l];
            l++;
        }
        return total - result;
    }

    public static void main(String[] args) {
        Task2302 x = new Task2302();
//        System.out.println(x.countSubarrays(new int[] {2, 1, 4, 3, 5}, 10));
//        System.out.println(x.countSubarrays(new int[] {1, 1, 1}, 5));
        System.out.println(
            x.countSubarrays(new int[] {9, 5, 3, 8, 4, 7, 2, 7, 4, 5, 4, 9, 1, 4, 8, 10, 8, 10, 4, 7}, 4));
    }
}