import java.util.ArrayList;
import java.util.List;

class Task2942 {

    public List<Integer> findWordsContaining(String[] words, char x) {

        List<Integer> res = new ArrayList<>();

        for (int i = 0; i < words.length; i++) {
            for (char c : words[i].toCharArray()) {
                if (c == x) {
                    res.add(i);
                    break;
                }
            }
        }

        return res;
    }

    public static void main(String[] args) {

    }
}