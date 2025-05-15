import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;

class Task113 {

    static class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;

        TreeNode() {
        }

        TreeNode(int val) {
            this.val = val;
        }

        TreeNode(int val, TreeNode left, TreeNode right) {
            this.val = val;
            this.left = left;
            this.right = right;
        }
    }

    public void pathSumHelper(TreeNode current, int targetSum, List<Integer> currentPath, List<List<Integer>> all) {
        if (current == null || targetSum < 0) {
            return;
        }

        if (current.left == null && current.right == null && targetSum == current.val) {
            currentPath.add(current.val);
            all.add(new ArrayList<>(currentPath));
        }
        currentPath.add(current.val);
        List<Integer> c1 = new ArrayList<>(currentPath);
        List<Integer> c2 = new ArrayList<>(currentPath);
        pathSumHelper(current.left, targetSum - current.val, c1, all);
        pathSumHelper(current.right, targetSum - current.val, c2, all);
    }

    public List<List<Integer>> pathSum(TreeNode root, int targetSum) {
        List<Integer> currentPath = new ArrayList<>();
        List<List<Integer>> result = new ArrayList<>();
        pathSumHelper(root, targetSum, currentPath, result);
        return result;
    }

    public static void main(String[] args) {

    }
}