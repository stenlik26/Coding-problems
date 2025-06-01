import java.util.Arrays;
import java.util.Deque;
import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.Set;

class Task909 {

    public record Info(int b, int depth) {

    }

    public int toB(int r, int c, int n) {
        int base = (n - 1 - r) * n;
        if ((n - 1 - r) % 2 == 0) {
            return base + 1 + c;
        } else {
            return base + n - c;
        }
    }

    public void fromB(int b, int n, int[] rc) {
        int r = b / n;
        if (b % n == 0) {
            r--;
        }
        rc[0] = (n - 1) - r;

        int c = (b - 1) % n;
        if (r % 2 == 0) {
            rc[1] = c;
        } else {
            rc[1] = n - 1 - c;
        }
    }

    public int snakesAndLadders(int[][] board) {
        Deque<Info> toVisit = new LinkedList<>();
        final int n = board.length * board.length;

        toVisit.add(new Info(1, 0));
        int[] dp = new int[n + 1];
        Arrays.fill(dp, Integer.MAX_VALUE);

        while (!toVisit.isEmpty()) {
            Info current = toVisit.pollFirst();
            if (dp[current.b] < current.depth) {
                continue;
            }
            dp[current.b] = current.depth;

            for (int i = 1; i <= 6; i++) {
                int nextB = current.b + i;
                if (nextB > n) {
                    break;
                }
                int[] rc = new int[2];

                fromB(nextB, board.length, rc);

                if (board[rc[0]][rc[1]] != -1) {
                    nextB = board[rc[0]][rc[1]];
                }
                if (dp[nextB] > current.depth + 1) {
                    dp[nextB] = current.depth + 1;
                    toVisit.add(new Info(nextB, current.depth + 1));
                }
            }
        }
        return dp[n] == Integer.MAX_VALUE ? -1 : dp[n];
    }

    public static void main(String[] args) {
        Task909 x = new Task909();
//        System.out.println(x.snakesAndLadders(new int[][] {
//            new int[] {-1, -1, -1, -1, -1, -1},
//            new int[] {-1, -1, -1, -1, -1, -1},
//            new int[] {-1, -1, -1, -1, -1, -1},
//            new int[] {-1, 35, -1, -1, 13, -1},
//            new int[] {-1, -1, -1, -1, -1, -1},
//            new int[] {-1, 15, -1, -1, -1, -1}
//        }));

        System.out.println(x.snakesAndLadders(new int[][] {
            new int[] {-1, 231, -1, 173, -1, -1, 46, 39, 30, -1, -1, -1, -1, -1, -1, 172, -1},
            new int[] {287, -1, -1, -1, -1, -1, -1, -1, -1, 66, -1, 205, -1, 28, -1, -1, -1},
            new int[] {141, -1, -1, -1, 43, -1, -1, 200, -1, -1, -1, 147, -1, 224, -1, -1, -1},
            new int[] {215, 89, 231, 80, 12, 214, 25, -1, -1, -1, -1, -1, 281, -1, 133, 237, -1},
            new int[] {-1, -1, -1, -1, 55, -1, 177, 172, -1, -1, -1, -1, -1, 284, 229, -1, -1},
            new int[] {-1, 45, 112, -1, -1, 33, -1, -1, -1, -1, -1, -1, -1, -1, -1, 178, 266},
            new int[] {-1, 128, -1, -1, 191, 219, -1, 140, -1, -1, -1, -1, -1, -1, 141, -1, -1},
            new int[] {-1, 105, -1, -1, -1, -1, -1, 173, -1, -1, -1, -1, -1, -1, -1, 181, -1},
            new int[] {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
            new int[] {-1, -1, -1, 78, 219, -1, 56, -1, 117, -1, -1, 88, -1, 44, 103, -1, 243},
            new int[] {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
            new int[] {-1, -1, -1, -1, 233, -1, 218, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
            new int[] {201, 136, -1, -1, -1, -1, -1, -1, -1, -1, -1, 184, 68, -1, -1, 107, -1},
            new int[] {-1, -1, -1, -1, -1, 185, -1, -1, -1, -1, 52, -1, -1, -1, -1, -1, -1},
            new int[] {-1, -1, -1, -1, 52, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
            new int[] {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
            new int[] {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}
        }));
//
//        System.out.println(x.snakesAndLadders(new int[][] {
//            new int[] {-1, -1, -1, 30, -1, 144, 124, 135, -1, -1, -1, -1, -1},
//            new int[] {-1, -1, -1, -1, -1, -1, 167, 93, -1, -1, -1, -1, -1},
//            new int[] {-1, -1, -1, -1, -1, -1, -1, 77, -1, -1, 90, -1, -1},
//            new int[] {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
//            new int[] {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 122, -1},
//            new int[] {-1, -1, -1, 23, -1, -1, -1, -1, -1, 155, -1, -1, -1},
//            new int[] {-1, -1, 140, 29, -1, -1, -1, -1, -1, -1, -1, -1, -1},
//            new int[] {-1, -1, -1, -1, -1, 115, -1, -1, -1, 109, -1, -1, 5},
//            new int[] {-1, 57, -1, 99, 121, -1, -1, 132, -1, -1, -1, -1, -1},
//            new int[] {-1, 48, -1, -1, -1, 68, -1, -1, -1, -1, 31, -1, -1},
//            new int[] {-1, 163, 147, -1, 77, -1, -1, 114, -1, -1, 80, -1, -1},
//            new int[] {-1, -1, -1, -1, -1, 57, 28, -1, -1, 129, -1, -1, -1},
//            new int[] {-1, -1, -1, -1, -1, -1, -1, -1, -1, 87, -1, -1, -1}
//        }));

//        int[] rc = new int[2];
//        x.fromB(36, 6, rc);
//        System.out.println(rc[0]);
//        System.out.println(rc[1]);
    }
}