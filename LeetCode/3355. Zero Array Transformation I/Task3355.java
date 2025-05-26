class Task3355 {

    public boolean isZeroArray(int[] nums, int[][] queries) {
        int[] runningC = new int[nums.length + 2];

        for (int[] q : queries) {
            runningC[q[0]]++;
            runningC[q[1] + 1]--;
        }

        long current = runningC[0];

        for (int i = 1; i < runningC.length - 1; i++) {
            nums[i - 1] -= current;
            current += runningC[i];
        }

        //System.out.println(nums);
        for(int x : nums){
            if(x > 0){
                return false;
            }
        }
        return true;
    }

    public static void main(String[] args) {
        Task3355 x = new Task3355();
        x.isZeroArray(new int[]{1,2,1,0,0,0}, new int[][]{
            new int[]{0,3},
            new int[]{2,4}
        });
    }
}