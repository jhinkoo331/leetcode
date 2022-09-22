package main

import (
	"fmt"
	. "github.com/jhinkoo331/leetcode/src/model"
)

// recursive
// perf: 77, 5
func f0701(root *TreeNode, val int) *TreeNode {
	if root == nil {
		return &TreeNode{val, nil, nil}
	}
	if root.Val < val {
		root.Right = f0701(root.Right, val)
	} else {
		root.Left = f0701(root.Left, val)
	}
	return root
}

// iterative
// perf: 45, 5
func ff0701(root *TreeNode, val int) *TreeNode {
	if root == nil {
		return &TreeNode{val, nil, nil}
	}
	curRoot := root
	for true {
		if val < curRoot.Val {
			if curRoot.Left == nil {
				curRoot.Left = &TreeNode{val, nil, nil}
				break
			} else {
				curRoot = curRoot.Left
			}
		} else {
			if curRoot.Right == nil {
				curRoot.Right = &TreeNode{val, nil, nil}
				break
			} else {
				curRoot = curRoot.Right
			}
		}
	}
	return root
}

func insertIntoBST(root *TreeNode, val int) *TreeNode {
	return f0701(root, val)
}

func main() {
	root := &TreeNode{1, nil, nil}
	fmt.Println(insertIntoBST(root, 2))
}
