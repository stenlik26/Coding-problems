import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.Set;
import java.util.TreeSet;

class Task1061 {

    class UnionFind {
        List<Integer> par, sz;

        UnionFind(int n) {
            par = new ArrayList<>(n + 2);
            par.add(0);
            sz = new ArrayList<>(n + 2);
            sz.add(0);
            for (int i = 1; i <= n; i++) {
                par.add(i, i);
                sz.add(i, 1);
            }
        }

        public int getParent(int x) {
            if (par.get(x) == x) {
                return x;
            } else {
                return getParent(par.get(x));
            }
        }

        public void merge(int x, int y) {
            x = getParent(x);
            y = getParent(y);

            if (x == y) {
                return;
            }

            if (par.get(x) > par.get(y)) {
                sz.set(y, sz.get(y) + sz.get(x));
                par.set(x, y);
            } else {
                sz.set(x, sz.get(y) + sz.get(x));
                par.set(y, x);
            }
        }

        public int getSize(int x) {
            return sz.get(x);
        }
    }

    public String smallestEquivalentString(String s1, String s2, String baseStr) {
        Map<Character, Set<Character>> equiv = new HashMap<>();
        for (char x = 'a'; x <= 'z'; x++) {
            Set<Character> h = new HashSet<>();
            h.add(x);
            equiv.put(x, h);
        }
        char[] c1 = s1.toCharArray();
        char[] c2 = s2.toCharArray();
        UnionFind uf = new UnionFind(26);

        for (int i = 0; i < c1.length; i++) {
            uf.merge(c1[i] - 'a', c2[i] - 'a');
        }
        StringBuilder res = new StringBuilder();

        for (char c : baseStr.toCharArray()) {
            res.append((char)(uf.getParent(c - 'a') + 'a'));
        }

        return res.toString();
    }

    public static void main(String[] args) {
        Task1061 x = new Task1061();
        System.out.println(x.smallestEquivalentString("leetcode",
            "programs",
            "sourcecode"));
//        System.out.println(x.smallestEquivalentString("opecenadojbodihfgmpijpfocomhcncicefpohkibjckijghii",
//            "ndlbhpaeppgekfhnjnmmplmdoifdhbglmedpjgleofgnahglbe",
//            "ttusuhhrabgsswpaapxoxdanchyccmpjitwwmfioedtbiggfru"));
    }

}