package leetcode.solution;

// Definition for a QuadTree node.
class Node {
    public boolean val;
    public boolean isLeaf;
    public Node topLeft;
    public Node topRight;
    public Node bottomLeft;
    public Node bottomRight;

    public Node() {
        this.val = false;
        this.isLeaf = false;
        this.topLeft = null;
        this.topRight = null;
        this.bottomLeft = null;
        this.bottomRight = null;
    }

    public Node(boolean val, boolean isLeaf) {
        this.val = val;
        this.isLeaf = isLeaf;
        this.topLeft = null;
        this.topRight = null;
        this.bottomLeft = null;
        this.bottomRight = null;
    }

    public Node(boolean val, boolean isLeaf, Node topLeft, Node topRight, Node bottomLeft, Node bottomRight) {
        this.val = val;
        this.isLeaf = isLeaf;
        this.topLeft = topLeft;
        this.topRight = topRight;
        this.bottomLeft = bottomLeft;
        this.bottomRight = bottomRight;
    }
};

class Solution {

    // perf: [1ms, 5.26%]
    public Node construct(int[][] grid) {
        Node root = this.constructHelper(grid, 0, 0, grid.length);
        return root;
    }

    private Node constructHelper(int[][] grid, int x, int y, int len) {
        // only `construct` caller can trigger this condition
        if (len == 0) {
            return null;
        }
        // return a leaf node
        if (len == 1) {
            return new Node(grid[x][y] == 1, true, null, null, null, null);
        }
        // split the node into 4 sub nodes, and try to merge them.
        Node root = new Node(true/* set default value as `true` to make test results from leetcode consistant */,
                false);
        root.topLeft = this.constructHelper(grid, x, y, len / 2);
        root.topRight = this.constructHelper(grid, x, y + len / 2, len / 2);
        root.bottomLeft = this.constructHelper(grid, x + len / 2, y, len / 2);
        root.bottomRight = this.constructHelper(grid, x + len / 2, y + len / 2, len / 2);
        this.mergeNode(root);
        return root;
    }

    // if this node's 4 sub nodes can be merged, merge them and make the root node
    // as a leaf
    private void mergeNode(Node n) {
        if (n.topLeft.isLeaf
                && n.topRight.isLeaf
                && n.bottomLeft.isLeaf
                && n.bottomRight.isLeaf
                && n.topRight.val == n.topLeft.val
                && n.bottomLeft.val == n.topLeft.val
                && n.bottomRight.val == n.topLeft.val) {
            // merge the node, and make it a leaf node
            n.val = n.topLeft.val;
            n.isLeaf = true;
            n.topLeft = null;
            n.topRight = null;
            n.bottomLeft = null;
            n.bottomRight = null;
        }
    }
}