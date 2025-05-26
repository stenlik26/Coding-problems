import java.util.ArrayList;
import java.util.List;

class Task131 {

    public boolean isPalindrome(String s) {
        int n = s.length();

        if (n == 1) {
            return true;
        }

        for (int i = 0; i < n / 2; i++) {
            if (s.charAt(i) != s.charAt(n - 1 - i)) {
                return false;
            }
        }
        return true;
    }

    public List<List<String>> partition(String s) {

        StringBuilder p = new StringBuilder();
        List<List<String>> out = new ArrayList<>();
        String sCopy = s;

        for (int i = 0; i < s.length(); i++) {
            p.append(s.charAt(i));
            sCopy = s.substring(i + 1);

            if (isPalindrome(p.toString())) {
                List<List<String>> res = partition(sCopy);
                for (List<String> innerList : res) {
                    innerList.addFirst(p.toString());
                }
                out.addAll(res);
            }
        }
        if (out.isEmpty()) {
            out.add(new ArrayList<>());
        }
        return out;
    }

    public static void main(String[] args) {
        Task131 x = new Task131();
        var res = x.partition("efe");

        for (var p : res) {
            for (String s : p) {
                System.out.print(s);
                System.out.print(" ");
            }
            System.out.println();
        }
    }
}