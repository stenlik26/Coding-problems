class Task {
    public static int minOperations(int[] nums) {
        int cnt = 0;
        for (int i = 0; i < nums.length - 2; i++) {
            if (nums[i] == 1) {
                continue;
            }
            cnt++;
            for (int j = 0; j < 3; j++) {
                nums[i + j] = 1 - nums[i + j];
            }
        }
        for (int i = nums.length - 3; i < nums.length; i++) {
            if (nums[i] == 0) {
                return -1;
            }
        }
        return cnt;
    }

    public static void main(String[] args) {
        System.out.println(minOperations(new int[]{0,1,1,1,0,0}));
        System.out.println(minOperations(new int[]{0,1,1,1}));
    }
}