import java.util.Arrays;
import java.util.List;

class Task120 {

    public int minimumTotal(List<List<Integer>> triangle) {
        int n = triangle.getLast().size();

        int[][] dp = new int[n][n];
        int i = 0;
        for (Integer x : triangle.getLast()) {
            dp[n - 1][i++] = x;
        }

        for (int r = n - 2; r >= 0; r--) {
            for (int c = 0; c < triangle.get(r).size(); c++) {
                dp[r][c] = Math.min(dp[r + 1][c], dp[r + 1][c + 1]) + triangle.get(r).get(c);
            }
        }
        return dp[0][0];
    }

    public static void main(String[] args) {
        Task120 k = new Task120();
        System.out.println(k.minimumTotal(List.of(
            List.of(2),
            List.of(3, 4),
            List.of(6, 5, 7),
            List.of(4, 1, 8, 3)
        )));
    }

}