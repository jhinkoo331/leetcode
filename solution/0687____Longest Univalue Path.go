package main

import (
	. "github.com/jhinkoo331/leetcode/src/model"
)

func longestUnivaluePath(root *TreeNode) int {
	return s687(root)
}

// perf: 100, 85
func s687(root *TreeNode) (max int) {
	if root == nil {
		return
	}
	temp := s687_recur(root, root.Val, &max)
	if temp-1 > max {
		max = temp - 1
	}
	return
}

func s687_max(i, j int) int {
	if i > j {
		return i
	} else {
		return j
	}
}

func s687_recur(root *TreeNode, pre int, max *int) int {
	if root == nil {
		return 0
	}
	left := s687_recur(root.Left, root.Val, max)
	right := s687_recur(root.Right, root.Val, max)
	if left+right > *max {
		*max = left + right
	}
	if root.Val != pre {
		return 0
	}
	return 1 + s687_max(left, right)
}

func main() {
	root := &TreeNode{1, &TreeNode{4, nil, nil}, &TreeNode{5, nil, nil}}
	root.Left.Left = &TreeNode{4, nil, nil}
	root.Left.Right = &TreeNode{4, nil, nil}
	root.Right.Left = &TreeNode{5, nil, nil}
	longestUnivaluePath(root)
}
