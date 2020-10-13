package main

import . "model"

// perf: 91, 90
func f0617(t1 *TreeNode, t2 *TreeNode) *TreeNode {
	if t1 == nil {
		return t2
	}
	if t2 == nil {
		return t1
	}
	t1.Left = f0617(t1.Left, t2.Left)
	t1.Right = f0617(t1.Right, t2.Right)
	t1.Val += t2.Val
	return t1
}

func mergeTrees(t1 *TreeNode, t2 *TreeNode) *TreeNode {
	return f0617(t1, t2)
}

func main() {

}
