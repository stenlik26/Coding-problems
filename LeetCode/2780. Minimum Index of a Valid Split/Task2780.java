import java.util.HashMap;
import java.util.List;
import java.util.Map;

class Task2780 {
    public int minimumIndex(List<Integer> nums) {
        Map<Integer, Integer> before = new HashMap<>();
        Map<Integer, Integer> after = new HashMap<>();

        for (Integer x : nums) {
            after.put(x, after.getOrDefault(x, 0) + 1);
        }

        for (int i = 0; i < nums.size(); i++) {
            int x = nums.get(i);
            before.put(x, before.getOrDefault(x, 0) + 1);

            if (after.containsKey(x)) {
                after.put(x, after.get(x) - 1);
            }

            if (before.getOrDefault(x, 0) * 2 > i + 1 &&
                after.getOrDefault(x, 0) * 2 > (nums.size() - 1 - i)){
                return i;
            }
        }
        return -1;
    }

    public static void main(String[] args) {

    }
}