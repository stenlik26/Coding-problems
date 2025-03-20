import java.util.Arrays;

class Task6 {
    public String longestPalindrome(String s) {
        boolean[][] dp = new boolean[s.length()][s.length()];
        char[] sArr = s.toCharArray();
        String maxPal = "";
        for (boolean[] row : dp) {
            Arrays.fill(row, false);
        }

        //Initial dp
        for (int k = 0; k < s.length(); k++) {
            dp[k][k] = true;
            maxPal = s.substring(0, 1);
        }
        for (int k = 0; k < s.length() - 1; k++) {
            if (sArr[k] == sArr[k + 1]) {
                dp[k][k + 1] = true;
                maxPal = s.substring(k, k + 2);
            }
        }

        //Rec call
        for (int c = 2; c < s.length(); c++) {
            for (int r = 0; r < s.length() - c; r++) {
                int y = c + r;
                if (sArr[r] == sArr[y] && dp[r + 1][y - 1]) {
                    dp[r][y] = true;
                    maxPal = s.substring(r, y + 1);
                }
            }
        }
        return maxPal;
    }

    public static void main(String[] args) {
        Task6 r = new Task6();
        System.out.println(r.longestPalindrome("babad"));
        System.out.println(r.longestPalindrome("baab"));
    }
}
