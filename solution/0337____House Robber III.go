package main

import . "github.com/jhinkoo331/leetcode/src/model"

// perf: 4ms, 33
func rob(root *TreeNode) int {
	rob, noRob := robHelper(root)
	if rob > noRob {
		return rob
	} else {
		return noRob
	}
}

func robHelper(root *TreeNode) (int, int) {
	if root == nil {
		return 0, 0
	}
	rob, noRob := root.Val, 0
	temp_rob, temp_noRob := robHelper(root.Left)
	if temp_rob > temp_noRob {
		noRob += temp_rob
	} else {
		noRob += temp_noRob
	}
	rob += temp_noRob
	temp_rob, temp_noRob = robHelper(root.Right)
	if temp_rob > temp_noRob {
		noRob += temp_rob
	} else {
		noRob += temp_noRob
	}
	rob += temp_noRob
	return rob, noRob
}

func main() {
	root := &TreeNode{3, &TreeNode{2, nil, &TreeNode{3, nil, nil}}, &TreeNode{3, nil, &TreeNode{1, nil, nil}}}
	rob(root)
}
