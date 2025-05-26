import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

class Task322 {

    public int minCoinAmount(int[] coins, int[] dp, int amount) {
        if (amount < 0) {
            return -1;
        }
        if (amount == 0) {
            return 0;
        }
        if (dp[amount] != 0) {
            return dp[amount];
        }

        int curr = 0;
        int min = Integer.MAX_VALUE;

        for (int i = 0; i < coins.length; i++) {
            curr = minCoinAmount(coins, dp, amount - coins[i]) + 1;
            if (curr < min && curr != 0) {
                min = curr;
            }
        }
        dp[amount] = min;
        if (min == Integer.MAX_VALUE) {
            dp[amount] = -1;
        }
        return dp[amount] ;
    }

    public int coinChange(int[] coins, int amount) {
        int[] dp = new int[10001];

        return minCoinAmount(coins, dp, amount);
    }

    public static void main(String[] args) {
        Task322 x = new Task322();
        System.out.println(x.coinChange(new int[] {1, 2, 5}, 11));
    }
}