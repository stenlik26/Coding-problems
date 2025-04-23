class Task2176 {

    public int countPairs(int[] nums, int k) {
        int cnt = 0;
        for (int i = 0; i < nums.length; i++) {
            for (int j = i + 1; j < nums.length; j++) {
                if ((nums[i] * nums[j]) % k == 0) {
                    cnt++;
                }
            }
        }
        return cnt;
    }

    public static void main(String[] args) {

    }
}