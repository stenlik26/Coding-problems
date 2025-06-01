class Task129 {

    public static class TreeNode {
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

    public int sumHelp(TreeNode root, int sumCurrent) {
        if (root == null) {
            return 0;
        }
        int newSum = (sumCurrent * 10) + root.val;
        if (root.left == null && root.right == null) {
            return newSum;
        }

        return sumHelp(root.left, newSum) + sumHelp(root.right, newSum);
    }

    public int sumNumbers(TreeNode root) {
        return sumHelp(root, 0);
    }

    public static void main(String[] args) {

    }
}