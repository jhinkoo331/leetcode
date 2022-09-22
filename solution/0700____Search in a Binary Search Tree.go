package main

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

import . "github.com/jhinkoo331/leetcode/src/model"

func searchBST(root *TreeNode, val int) *TreeNode {
	return s700(root, val)
}

// perf: 13, 8
func s700(root *TreeNode, val int) *TreeNode {
	for root != nil {
		if root.Val == val {
			return root
		} else if root.Val > val {
			root = root.Left
		} else {
			root = root.Right
		}
	}
	return nil
}

func main() {

}
