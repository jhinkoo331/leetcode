package main

import (
	. "github.com/jhinkoo331/leetcode/src/model"
)

func recoverTree(root *TreeNode) {
	n99(root)
}

// perf: 91, 91
// space: n, stack to mid-first traverse of the bi-tree, avg: lg(n)
// time: n, to traverse all nodes in the tree
func n99(root *TreeNode) {
	var stack []*TreeNode
	if root != nil {
		stack = append(stack, root)
		for stack[len(stack)-1].Left != nil {
			stack = append(stack, stack[len(stack)-1].Left)
		}
	} else { // err
		return
	}
	var swap_left *TreeNode = nil
	var swap_right *TreeNode = nil
	pre := stack[len(stack)-1]
	for len(stack) > 0 {
		cur := stack[len(stack)-1]
		stack = stack[:len(stack)-1]
		if cur.Right != nil {
			stack = append(stack, cur.Right)
			for stack[len(stack)-1].Left != nil {
				stack = append(stack, stack[len(stack)-1].Left)
			}
		}
		if cur.Val < pre.Val {
			if swap_left == nil {
				swap_left = pre
				swap_right = cur
			} else {
				swap_right = cur
				break
			}
		}
		pre = cur
	}
	if swap_left == nil {
		return
	}
	swap_left.Val, swap_right.Val = swap_right.Val, swap_left.Val
}

func main() {
	root := &TreeNode{1, nil, nil}
	root.Left = &TreeNode{3, nil, nil}
	root.Left.Right = &TreeNode{2, nil, nil}
	recoverTree(root)
}
