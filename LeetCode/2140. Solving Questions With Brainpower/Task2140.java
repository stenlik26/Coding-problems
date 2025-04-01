class Task2140 {

    public long mostPoints(int[][] questions) {
        final int n = questions.length;
        long[] dp = new long[n];
        dp[n - 1] = questions[n - 1][0];

        for (int i = n - 2; i >= 0; i--) {
            long other = 0;
            if (i + 1 + questions[i][1] < n) {
                other = dp[i + 1 + questions[i][1]];
            }
            dp[i] = Math.max(dp[i + 1], questions[i][0] + other);
        }
        return dp[0];
    }

    public static void main(String[] args) {
        Task2140 x = new Task2140();
        System.out.println(x.mostPoints(new int[][] {
            new int[] {3, 2},
            new int[] {4, 3},
            new int[] {4, 4},
            new int[] {2, 5}
        }));
    }
}