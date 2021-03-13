package main

import (
	. "model"
)

func isCousins(root *TreeNode, x int, y int) bool {
	return n993(root, x, y)
}

// perf: 0ms, 100
func n993(root *TreeNode, x, y int) bool {
	if root.Val == x || root.Val == y {
		return false
	}
	x_level, x_val := n993_dfs(root, 0, x)
	y_level, y_val := n993_dfs(root, 0, y)
	if x_level == y_level && x_val != y_val {
		return true
	} else {
		return false
	}
}

// when you call this function, make sure that root.Val != target
// if target is found, return the target's parent's level and value
func n993_dfs(root *TreeNode, root_depth int, target int) (parent_depth int, val int) {
	if root.Left != nil {
		if root.Left.Val == target {
			return root_depth, root.Val
		}
		i, ii := n993_dfs(root.Left, root_depth+1, target)
		if i != -1 {
			return i, ii
		}
	}
	if root.Right != nil {
		if root.Right.Val == target {
			return root_depth, root.Val
		}
		i, ii := n993_dfs(root.Right, root_depth+1, target)
		if i != -1 {
			return i, ii
		}
	}
	return -1, -1
}

func main() {

}
