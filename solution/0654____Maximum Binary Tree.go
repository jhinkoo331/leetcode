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

func constructMaximumBinaryTree(nums []int) *TreeNode {
	return s654(nums)
}

// perf: 35, 97
// time: n^2, in function get_max_index
// space: n
func s654(nums []int) *TreeNode {
	if nums == nil {
		return nil
	}
	root := &TreeNode{0, nil, nil}
	nodes := []*TreeNode{root}
	arrs := [][]int{nums}
	for len(nodes) > 0 {
		root := nodes[len(nodes)-1]
		nodes = nodes[:len(nodes)-1]
		arr := arrs[len(arrs)-1]
		arrs = arrs[:len(arrs)-1]
		arr_max_index := get_max_index(arr)
		root.Val = arr[arr_max_index]
		if arr_max_index > 0 {
			root.Left = &TreeNode{0, nil, nil}
			nodes = append(nodes, root.Left)
			arrs = append(arrs, arr[:arr_max_index])
		}
		if arr_max_index < len(arr)-1 {
			root.Right = &TreeNode{0, nil, nil}
			nodes = append(nodes, root.Right)
			arrs = append(arrs, arr[arr_max_index+1:])
		}
	}
	return root
}
func get_max_index(nums []int) int {
	max_index := 0
	for i, val := range nums {
		if val > nums[max_index] {
			max_index = i
		}
	}
	return max_index
}
func main() {
	nums := []int{3, 2, 1, 6, 0, 5}
	constructMaximumBinaryTree(nums)
}
