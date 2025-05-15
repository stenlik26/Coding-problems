import java.util.LinkedList;
import java.util.List;

class Task2900 {

    public List<String> getLongestSubsequence(String[] words, int[] groups) {
        int searchingFor = 1 - groups[0];
        List<String> res = new LinkedList<>();
        res.add(words[0]);

        for (int i = 1; i < groups.length; i++) {
            if (groups[i] == searchingFor) {
                searchingFor = 1 - searchingFor;
                res.add(words[i]);
            }
        }

        return res;
    }

    public static void main(String[] args) {

    }
}