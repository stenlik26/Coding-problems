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
//                System.out.println(String.valueOf(r) + " - " + String.valueOf(c + r));
                int y = c + r;
                if (sArr[r] == sArr[y] && dp[r + 1][y - 1]) {
                    dp[r][y] = true;
                    maxPal = s.substring(r, y + 1);
                }
            }
        }
//        System.out.println();
//        for (int r = 0; r < s.length(); r++) {
//            for (int c = 0; c < s.length(); c++) {
//                System.out.print(dp[r][c] ? "1 " : "0 ");
//            }
//            System.out.println();
//        }

        return maxPal;
    }

    public static void main(String[] args) {
        Task6 r = new Task6();
        System.out.println(r.longestPalindrome("babad"));
        System.out.println(r.longestPalindrome("baab"));
//        System.out.println("0123456".substring(3,5));
    }
}

/*
babad
12345
  0 1 2 3 4
0 1 0 1 0 0
1   1 0 1 0
2     1 0 0
3       1 0
4         1
 */