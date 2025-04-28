import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Deque;
import java.util.List;

class Task46 {

    public int fact(int x) {
        if (x == 1) {
            return 1;
        }
        return x * fact(x - 1);
    }

    public List<List<Integer>> permute(int[] nums) {
        Deque<Integer> current = new ArrayDeque<>();
        Arrays.stream(nums).forEach(current::add);

        List<List<Integer>> result = new ArrayList<>();
        int n = fact(nums.length);

        for (int i = 0; i < n; i++){
            result.add(current.stream().toList());
            Integer x = current.pollFirst();
            current.addLast(x);
        }
        return result;
    }

    public static void main(String[] args) {

    }
}