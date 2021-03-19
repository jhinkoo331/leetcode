package main

import . "model"

func flipMatchVoyage(root *TreeNode, voyage []int) []int {
	return n971(root, voyage)
}

// perf: 0ms, 66
// time: n
// space: n
func n971(root *TreeNode, voyage []int) (ans []int) {
	na := []int{-1}
	var unvisit []*TreeNode
	if root != nil {
		unvisit = append(unvisit, root)
	} else if voyage == nil {
		return ans
	} else {
		return na
	}

	voyage = append(voyage, -1) // sentinel
	voyage_i := 0
	for len(unvisit) > 0 {
		root := unvisit[len(unvisit)-1]
		unvisit = unvisit[:len(unvisit)-1]
		if root.Val != voyage[voyage_i] {
			return na
		} else {
			voyage_i++
			if root.Left != nil && root.Right != nil && voyage[voyage_i] == root.Right.Val {
				unvisit = append(unvisit, root.Left)
				unvisit = append(unvisit, root.Right)
				ans = append(ans, root.Val)
			} else {
				if root.Right != nil {
					unvisit = append(unvisit, root.Right)
				}
				if root.Left != nil {
					unvisit = append(unvisit, root.Left)
				}
			}
		}
	}
	return ans
}

func main() {

}
