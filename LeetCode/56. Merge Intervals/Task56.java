import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.List;

class Task56 {

    public int[][] merge(int[][] intervals) {
        Arrays.sort(intervals, Comparator.comparingInt(a -> a[0]));
        List<List<Integer>> res = new ArrayList<>();
        int cur_s = intervals[0][0];
        int cur_e = intervals[0][1];

        for (int i = 1; i < intervals.length; i++) {
            if (intervals[i][0] <= cur_e) {
                cur_e = Math.max(intervals[i][1], cur_e);
            } else {
                res.add(List.of(cur_s, cur_e));
                cur_s = intervals[i][0];
                cur_e = intervals[i][1];
            }
        }
        res.add(List.of(cur_s, cur_e));
        int[][] resArr = new int[res.size()][2];
        int i = 0;
        for (List<Integer> x : res) {
            resArr[i][0] = x.get(0);
            resArr[i][1] = x.get(1);
            i++;
        }
        return resArr;
    }

    public static void main(String[] args) {

    }
}