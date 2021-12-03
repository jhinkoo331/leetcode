package main

import (
	. "model"
)

var ans int = 0
var single_cnt int = 0
var info = [10]bool{false}

func pseudoPalindromicPaths(root *TreeNode) int {
	return _1457(root)
}

func _1457(root *TreeNode) int {
	for i := range info {
		info[i] = false
	}
	if root != nil {
		_1457_recursive_traverse(root)
	}
	return ans
}

func _1457_recursive_traverse(root *TreeNode) {
	info[root.Val] = info[root.Val] != true
	if info[root.Val] {
		single_cnt++
	} else {
		single_cnt--
	}
	if root.Left != nil {
		_1457_recursive_traverse(root.Left)
	}
	if root.Right != nil {
		_1457_recursive_traverse(root.Right)
	}
	if root.Left == nil && root.Right == nil && single_cnt <= 1 { // leaf node, check it
		ans++
	}
	info[root.Val] = info[root.Val] != true
	if info[root.Val] {
		single_cnt++
	} else {
		single_cnt--
	}
}

func main() {

}
