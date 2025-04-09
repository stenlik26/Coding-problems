import org.w3c.dom.Node;

class TreeNode {
    public int val;
    public TreeNode left;
    public TreeNode right;

    public TreeNode() {
    }

    public TreeNode(int val) {
        this.val = val;
    }

    public TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}

class Task1123 {

    public record NodeInfo(TreeNode node, int depth) {
    }

    public TreeNode lcaDeepestLeaves(TreeNode root) {
        return dfsRec(root).node;
    }

    public NodeInfo dfsRec(TreeNode root) {
        if (root == null) {
            return new NodeInfo(null, 0);
        }
        Task1123.NodeInfo left = dfsRec(root.left);
        Task1123.NodeInfo right = dfsRec(root.right);

        if (left.depth > right.depth) {
            return new NodeInfo(left.node,
                left.depth + 1);
        }
        if (right.depth > left.depth) {
            return new NodeInfo(right.node, right.depth + 1);
        }
        return new NodeInfo(root, left.depth + 1);
    }

    public static void main(String[] args) {

    }
}