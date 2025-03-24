import java.util.Arrays;
import java.util.Comparator;

class Task3169 {

    public int countDays(int days, int[][] meetings) {
        int result = days;

        Arrays.sort(meetings, Comparator.comparingInt((int[] a) -> a[0])
            .thenComparingInt(a -> a[1]));

        int i = 1;
        int start = meetings[0][0];
        int end = meetings[0][1];

        while (i < meetings.length) {
            if (end < meetings[i][0]) {
                result -= end - start + 1;
                start = meetings[i][0];
            }
            end = Math.max(meetings[i][1], end);
            i++;
        }
        result -= end - start + 1;

        return result;
    }

    public static void main(String[] args) {
        Task3169 x = new Task3169();

        System.out.println(x.countDays(8, new int[][] {
            new int[] {3, 4},
            new int[] {4, 8},
            new int[] {2, 5},
            new int[] {3, 8}
        }));
    }
}