package main

import . "github.com/jhinkoo331/leetcode/src/model"

func pruneTree(root *TreeNode) *TreeNode {
	if !e814(root) {
		return nil
	}
	return root
}

// return: this tree consists at least one "1"
// perf: 0ms, 100
func e814(root *TreeNode) bool {
	if root == nil {
		return false
	}
	if !e814(root.Left) {
		root.Left = nil
	}
	if !e814(root.Right) {
		root.Right = nil
	}
	if root.Left == nil && root.Right == nil && root.Val == 0 {
		return false
	}
	return true
}

func main() {

}
