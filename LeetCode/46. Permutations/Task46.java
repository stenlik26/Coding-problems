import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Deque;
import java.util.List;

class Task46 {

    void recurPermute(int idx, List<Integer> arr, List<List<Integer>> res) {
        if (idx == arr.size()) {
            res.add(new ArrayList<>(arr));
        }

        for (int i = idx; i < arr.size(); i++) {
            Integer t = arr.get(idx);
            arr.set(idx, arr.get(i));
            arr.set(i, t);

            recurPermute(idx + 1, arr, res);

            t = arr.get(idx);
            arr.set(idx, arr.get(i));
            arr.set(i, t);
        }
    }

    public List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> res = new ArrayList<>();
        List<Integer> numsList = new ArrayList<>();
        Arrays.stream(nums).forEach(numsList::add);
        recurPermute(0, numsList, res);
        return res;
    }

    public static void main(String[] args) {
        Task46 h = new Task46();
        var res = h.permute(new int[]{1,2,3});

        System.out.println(res);
    }
}