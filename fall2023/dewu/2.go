package main

// The worst of the journey is still to come

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

/**
 * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
 *
 *
 * @param preOrder int整型一维数组
 * @param vinOrder int整型一维数组
 * @return TreeNode类
 */
func reConstructBinaryTree(preOrder []int, vinOrder []int) *TreeNode {
	if len(preOrder) == 0 {
		return nil
	}
	for i, v := range vinOrder {
		if v == preOrder[0] {
			return &TreeNode{
				Val:   preOrder[0],
				Left:  reConstructBinaryTree(preOrder[1:1+i], vinOrder[:i]),
				Right: reConstructBinaryTree(preOrder[1+i:], vinOrder[i+1:]),
			}
		}
	}
	panic("")
}
