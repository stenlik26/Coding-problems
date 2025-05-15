import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;

class Task437 {

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

    long canSumTo(TreeNode root, long targetSum) {
        long s = 0;
        if (root == null) {
            return 0;
        }
        if (targetSum - root.val == 0){
            s++;
        }
        return s + canSumTo(root.left, targetSum - root.val) + canSumTo(root.right, targetSum - root.val);
    }

    public int pathSum(TreeNode root, int targetSum) {
        if (root == null) {
            return 0;
        }
        long res = canSumTo(root, targetSum);
        return (int) res + pathSum(root.left, targetSum) + pathSum(root.right, targetSum);
    }

    public static void main(String[] args) {
        Task437 x = new Task437();
        System.out.println(x.pathSum(new TreeNode(1,
            new TreeNode(-2,
                new TreeNode(1, new TreeNode(-1), null),
                new TreeNode(3, null, null)),
            new TreeNode(-3,
                new TreeNode(-2), null)), -1));
    }
}