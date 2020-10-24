package main

import . "model"

// perf: 4ms, 7.5
func _0508(root *TreeNode) []int {
	m := make(map[int]int)
	if root != nil {
		_0508_helper(root, &m)
	}
	maxOccurTime := 0
	for _, time := range m {
		if time > maxOccurTime {
			maxOccurTime = time
		}
	}
	var ans []int
	for val, time := range m {
		if time == maxOccurTime {
			ans = append(ans, val)
		}
	}
	return ans
}

// root should not be nil
func _0508_helper(root *TreeNode, m *map[int]int) int {
	sum := root.Val
	if root.Left != nil {
		sum += _0508_helper(root.Left, m)
	}
	if root.Right != nil {
		sum += _0508_helper(root.Right, m)
	}
	(*m)[sum]++
	return sum
}

func findFrequentTreeSum(root *TreeNode) []int {
	return _0508(root)
}

func main() {

}
