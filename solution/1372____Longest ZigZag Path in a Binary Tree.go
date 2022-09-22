package main

import (
	. "github.com/jhinkoo331/leetcode/src/model"
)

func _1372(root *TreeNode) int {
	maxLen := 0
	_1372_helper(root, &maxLen)
	if maxLen == 0 {
		return 0
	} else {
		return maxLen - 1
	}
}

func _1372_helper(root *TreeNode, maxLen *int) (int, int) {
	if root == nil {
		return 0, 0
	}
	_, left := _1372_helper(root.Left, maxLen)
	left++
	if left > *maxLen {
		*maxLen = left
	}
	right, _ := _1372_helper(root.Right, maxLen)
	right++
	if right > *maxLen {
		*maxLen = right
	}
	return left, right
}

func longestZigZag(root *TreeNode) int {
	return _1372(root)
}

func main() {

}
