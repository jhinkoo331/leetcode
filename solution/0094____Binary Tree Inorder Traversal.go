package main

import . "model"

// perf: 0ms, 33
func inorderTraversal(root *TreeNode) (ans []int) {
	return n94(root)
	var stack []*TreeNode
	if root == nil {
		return ans
	}

	stack = append(stack, root)
	for stack[len(stack)-1].Left != nil {
		stack = append(stack, stack[len(stack)-1].Left)
	}
	for len(stack) != 0 {
		ans = append(ans, stack[len(stack)-1].Val)
		if stack[len(stack)-1].Right == nil {
			stack = stack[:len(stack)-1]
		} else {
			stack[len(stack)-1] = stack[len(stack)-1].Right
			for stack[len(stack)-1].Left != nil {
				stack = append(stack, stack[len(stack)-1].Left)
			}
		}
	}
	return ans
}

// perf: 0ms, 30
// time: todo
// space: 1
// trade-off: the original tree is destroyed
func n94(root *TreeNode) (ans []int) {
	for root != nil {
		if root.Left != nil {
			temp := root.Left
			for temp.Right != nil {
				temp = temp.Right
			}
			temp.Right = root
			root = root.Left
			temp.Right.Left = nil
		} else {
			ans = append(ans, root.Val)
			root = root.Right
		}
	}
	return ans
}

func main() {

}
