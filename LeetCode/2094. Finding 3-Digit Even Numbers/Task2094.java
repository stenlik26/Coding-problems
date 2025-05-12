import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

class Task2094 {

    public int[] findEvenNumbers(int[] digits) {
        List<Integer> res = new ArrayList<>();
        Map<Integer, Integer> digitsCount = new HashMap<>();
        for (int x : digits) {
            digitsCount.put(x, digitsCount.getOrDefault(x, 0) + 1);
        }
        for (int i = 100; i <= 999; i += 2) {
            int[] hist = new int[10];
            int a = i / 100;
            int b = (i % 100) / 10;
            int c = i % 10;

            hist[a]++;
            hist[b]++;
            hist[c]++;

            if (hist[a] <= digitsCount.getOrDefault(a, 0) &&
                hist[b] <= digitsCount.getOrDefault(b, 0) &&
                hist[c] <= digitsCount.getOrDefault(c, 0)) {
                res.add(i);
            }
        }
        return res.stream().mapToInt(Integer::intValue).toArray();
    }

    public static void main(String[] args) {

    }
}