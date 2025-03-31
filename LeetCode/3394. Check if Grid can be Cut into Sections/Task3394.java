import java.lang.reflect.Array;
import java.util.Arrays;
import java.util.Comparator;

class Task3394 {
    private boolean checkInterval(int[][] intervals) {
        int nonOverlappingIntervals = 0;

        Arrays.sort(intervals, Comparator.comparingInt((int[] a) -> a[0])
            .thenComparingInt(a -> a[1]));

        int start = intervals[0][0];
        int end = intervals[0][1];
        for (int i = 1; i < intervals.length; i++) {
            if (intervals[i][0] < end) {
                end = Math.max(intervals[i][1], end);
            } else {
                start = intervals[i][0];
                end = intervals[i][1];
                nonOverlappingIntervals++;
            }
        }
        nonOverlappingIntervals++;

        return nonOverlappingIntervals >= 3;
    }

    public boolean checkValidCuts(int n, int[][] rectangles) {
        int[][] horizontal = new int[rectangles.length][2];
        int[][] vertical = new int[rectangles.length][2];
        int h = 0, v = 0;

        for (int[] rectangle : rectangles) {
            horizontal[h][0] = rectangle[0];
            horizontal[h++][1] = rectangle[2];

            vertical[v][0] = rectangle[1];
            vertical[v++][1] = rectangle[3];
        }

        return checkInterval(horizontal) || checkInterval(vertical);
    }

    public static void main(String[] args) {
        Task3394 x = new Task3394();
        
        System.out.println(x.checkValidCuts(5, new int[][] {
            new int[] {1, 0, 5, 2},
            new int[] {0, 2, 2, 4},
            new int[] {3, 2, 5, 3},
            new int[] {0, 4, 4, 5}
        }));
    }
}