package main

import . "github.com/jhinkoo331/leetcode/src/model"

func sumEvenGrandparent(root *TreeNode) (ans int) {
	if root != nil {
		o1315(root, 1, 1, &ans)
	}
	return
}

// root must be non-nil
// perf: 10, 64
func o1315(root *TreeNode, gp, p int, ans *int) {
	if gp%2 == 0 {
		*ans += root.Val
	}
	if root.Left != nil {
		o1315(root.Left, p, root.Val, ans)
	}
	if root.Right != nil {
		o1315(root.Right, p, root.Val, ans)
	}
}

func main() {

}
