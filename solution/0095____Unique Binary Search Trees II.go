package main

import . "github.com/jhinkoo331/leetcode/src/model"

// 0ms, 100
func generateTrees(n int) []*TreeNode {
	mat := make([][][]*TreeNode, n+1, n+1)
	mat[0] = make([][]*TreeNode, n+2, n+2)
	for i := range mat[0] {
		mat[0][i] = append(mat[0][i], nil)
	}
	for i := 1; i <= n; i++ {
		mat[i] = make([][]*TreeNode, n+2-i)
	}
	for i := 1; i <= n; i++ {
		for ii := 1; i+ii <= n+1; ii++ {
			genTree_helper(i, ii, mat)
		}
	}
	return mat[n][1]
}
func genTree_helper(i, ii int, mat [][][]*TreeNode) {
	for mid := ii; mid < i+ii; mid++ {
		for _, left := range mat[mid-ii][ii] {
			for _, right := range mat[i+ii-1-mid][mid+1] {
				mat[i][ii] = append(mat[i][ii], &TreeNode{mid, left, right})
			}
		}
	}
}
