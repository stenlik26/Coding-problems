/**
 * Definition for a binary tree node.
 * public class TreeNode {
 * int val;
 * TreeNode left;
 * TreeNode right;
 * TreeNode() {}
 * TreeNode(int val) { this.val = val; }
 * TreeNode(int val, TreeNode left, TreeNode right) {
 * this.val = val;
 * this.left = left;
 * this.right = right;
 * }
 * }
 */
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
        if (targetSum - root.val == 0) {
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
}