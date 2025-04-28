class Task3392 {

    public int countSubarrays(int[] nums) {
        int cnt = 0;

        for (int i = 1; i < nums.length - 1; i++) {
            int t = 2 * (nums[i - 1] + nums[i + 1]);
            if (t == nums[i]) {
                cnt++;
            }
        }

        return cnt;
    }

    public static void main(String[] args) {

    }
}