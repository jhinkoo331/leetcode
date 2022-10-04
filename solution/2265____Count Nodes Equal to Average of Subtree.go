package main

// The worst of the journey is still to come
type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

// 0ms, 78%, one pass
func averageOfSubtree(root *TreeNode) int {
	_, _, ans := fn(root)
	return ans
}

func fn(root *TreeNode) (sum int, nodeCount int, okCount int) {
	if root == nil {
		return 0, 0, 0
	}
	leftSum, leftNodeCount, leftOkCount := fn(root.Left)
	rightSum, rightNodeCount, rightOkCount := fn(root.Right)
	totalSum, totalNodeCount, totalOkCount := leftSum+rightSum+root.Val, leftNodeCount+rightNodeCount+1, leftOkCount+rightOkCount
	if totalSum/totalNodeCount == root.Val {
		totalOkCount += 1
	}
	return totalSum, totalNodeCount, totalOkCount
}
