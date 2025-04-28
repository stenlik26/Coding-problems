import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

class Task39 {

    public List<List<Integer>> combRec(int[] candidates, int target, int startI) {
        int[] candDiff = new int[candidates.length];
        int maxPos = -1;
        for (int i = 0; i < candidates.length; i++) {
            candDiff[i] = target - candidates[i];
            if (candDiff[i] >= 0) {
                maxPos = i;
            }
        }

        List<List<Integer>> result = new ArrayList<>();

        if (maxPos == -1) {
            return result;
        }

        for (int i = startI; i <= maxPos; i++) {
            int diff = candDiff[i];
            if (diff > 0) {
                List<List<Integer>> rec = combRec(candidates, diff, i);
                for (List<Integer> l : rec) {
                    l.add(candidates[i]);
                }
                result.addAll(rec);
            } else if (diff == 0) {
                List<Integer> t = new ArrayList<>();
                t.add(candidates[i]);
                result.add(t);
            } else {
                break;
            }
        }
        return result;
    }

    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        Arrays.sort(candidates);
        return combRec(candidates, target, 0);
    }

    public static void main(String[] args) {
        Task39 x = new Task39();

        var res = x.combinationSum(new int[] {2,3,6,7}, 7);
        var res2 = x.combinationSum(
            new int[] {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26,
                27, 28, 29, 30}, 500);
        System.out.println(res);
        System.out.println(res2);
    }
}