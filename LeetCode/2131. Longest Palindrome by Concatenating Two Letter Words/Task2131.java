import java.util.HashMap;
import java.util.Map;

class Task2131 {

    public int longestPalindrome(String[] words) {
        Map<String, Integer> map = new HashMap<>();
        int result = 0;
        int singles = 0;
        for (String word : words) {
            map.put(word, map.getOrDefault(word, 0) + 1);
        }

        for (String word : words) {
            if (word.charAt(0) == word.charAt(1)) {
                int cnt = map.get(word);
                if (cnt == 0) {
                    continue;
                } else if (cnt % 2 == 0) {
                    result += map.get(word) * 2;
                    map.put(word, 0);
                } else {
                    result += (map.get(word) - 1) * 2;
                    singles++;
                    map.put(word, 0);
                }

            } else {
                String revW = word.charAt(1) + word.substring(0, 1);
                if (map.containsKey(revW)) {
                    int x = Math.min(map.get(revW), map.get(word));
                    result += 4 * x;
                    map.put(word, map.get(word) - x);
                    map.put(revW, map.get(revW) - x);
                }
            }
        }


        if (result == 2) {
            return 2;
        } else if (result == 0) {
            return (singles > 0 ? 2 : 0);
        } else if ((result / 2) % 2 == 0 && singles > 0) {
            return result + 2;
        } else {
            return result;
        }
    }

    public static void main(String[] args) {
        Task2131 x = new Task2131();
        System.out.println(x.longestPalindrome(new String[] {"lc", "cl", "gg", "ak", "kk"}));
    }
}