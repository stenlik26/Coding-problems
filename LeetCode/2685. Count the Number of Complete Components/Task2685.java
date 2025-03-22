import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Queue;
import java.util.Set;

class Task2685 {
    public int countCompleteComponents(int n, int[][] edges) {
        List<List<Integer>> matrix = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            matrix.add(new ArrayList<>());
        }
        for (int[] edge : edges) {
            matrix.get(edge[0]).add(edge[1]);
            matrix.get(edge[1]).add(edge[0]);
        }
        int result = 0;
        Set<Integer> visited = new HashSet<>();
        for (int i = 0; i < n; i++) {
            if (visited.contains(i)) {
                continue;
            }
            Queue<Integer> bfs = new ArrayDeque<>();
            Set<Integer> comp = new HashSet<>();
            int edgesCount = 0;
            comp.add(i);
            bfs.add(i);
            while (!bfs.isEmpty()) {
                int current = bfs.poll();
                if (visited.contains(current)) {
                    continue;
                }
                visited.add(current);
                for (Integer neighbor : matrix.get(current)) {
                    if (!visited.contains(neighbor)) {
                        bfs.add(neighbor);
                        comp.add(neighbor);
                        edgesCount++;
                    }
                }
            }
            if (edgesCount == (comp.size() * (comp.size() - 1)) / 2) {
                result++;
            }
        }

        return result;
    }

    public static void main(String[] args) {
        Task2685 x = new Task2685();
        System.out.println(x.countCompleteComponents(4, new int[][] {
            new int[] {1, 0},
            new int[] {2, 0},
            new int[] {2, 1},
            new int[] {3, 1},
            new int[] {3, 2}
        }));
    }
}