class Task64 {

    public int minPathSum(int[][] grid) {
        int r = grid.length;
        int c = grid[0].length;
        int[][] dp = new int[r][c];

        dp[r - 1][c - 1] = grid[r - 1][c - 1];

        if (r - 2 >= 0) {
            dp[r - 2][c - 1] = grid[r - 2][c - 1] + dp[r - 1][c - 1];
        }
        if (c - 2 >= 0) {
            dp[r - 1][c - 2] = grid[r - 1][c - 2] + dp[r - 1][c - 1];
        }

        for (int ri = r - 1; ri >= 0; ri--) {
            for (int ci = c - 1; ci >= 0; ci--) {

                if (ci == c - 1 && ri == r - 1) {
                    continue;
                }

                int x = Integer.MAX_VALUE;
                int y = Integer.MAX_VALUE;

                if (ri + 1 < r) {
                    x = dp[ri + 1][ci];
                }
                if (ci + 1 < c) {
                    y = dp[ri][ci + 1];
                }
                dp[ri][ci] = Math.min(x, y) + grid[ri][ci];
            }
        }
        return dp[0][0];
    }

    public static void main(String[] args) {
        Task64 p = new Task64();
        System.out.println(p.minPathSum(new int[][] {
            new int[] {1, 3, 1},
            new int[] {1, 5, 1},
            new int[] {4, 2, 1}
        }));
    }

}