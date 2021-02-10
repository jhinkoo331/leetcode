package main

import (
	. "model"
)

// this method takes too much memory
func _widthOfBinaryTree(root *TreeNode) int {
	var level []*TreeNode
	if root != nil {
		level = append(level, root)
	}
	var max_width int = 0
	for len(level) != 0 {
		var width int = len(level)
		if width > max_width {
			max_width = width
		}
		for width != 0 {
			if level[0] == nil {
				level = append(level, nil)
				level = append(level, nil)
			} else {
				level = append(level, level[0].Left)
				level = append(level, level[0].Right)
			}
			level = level[1:]
			width--
		}
		// to drop nil pointers at tail
		for len(level) != 0 && level[len(level)-1] == nil {
			level = level[:len(level)-1]
		}
		// to drop leading nil pointers
		// note that this process differs from dropping tailing nil pointers
		if len(level) != 0 {
			for level[0] == nil {
				level = level[1:]
			}
		}
	}
	return max_width
}

// traverse the whole binary tree and record the left and right edge offsets
// perf: 4ms, 28
func widthOfBinaryTree(root *TreeNode) int {
	// global variables are reused in multiple test cases, reset them beforehand
	left = nil
	right = nil
	if root != nil {
		traverse(root, 0, 0)
	}
	var max_width int = -1
	for i := 0; i < len(left); i++ {
		if right[i]-left[i] > max_width {
			max_width = right[i] - left[i]
		}
	}
	return max_width + 1
}

var left []int
var right []int

// root can't be nil
func traverse(root *TreeNode, offset int, level int) {
	if len(left) == level {
		left = append(left, offset)
	} else if offset < left[level] {
		left[level] = offset
	}
	if len(right) == level {
		right = append(right, offset)
	} else if offset > right[level] {
		right[level] = offset
	}
	if root.Left != nil {
		traverse(root.Left, offset*2, level+1)
	}
	if root.Right != nil {
		traverse(root.Right, offset*2+1, level+1)
	}
}

func main() {
	root := &TreeNode{0, nil, nil}
	root.Left = &TreeNode{1, nil, nil}
	root.Left.Left = &TreeNode{1, nil, nil}
	root.Left.Right = &TreeNode{1, nil, nil}
	widthOfBinaryTree(root)
}
