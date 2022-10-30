package main

import (
	"fmt"
	"strconv"
)

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

// return the height of root, if root is nil, return 0
func treeHeight(root *TreeNode) int {
	height := 0
	var queue []*TreeNode
	if root != nil {
		queue = append(queue, root)
	}
	for len(queue) != 0 {
		height++
		sz := len(queue)
		for i := 0; i < sz; i++ {
			if queue[0].Left != nil {
				queue = append(queue, queue[0].Left)
			}
			if queue[0].Right != nil {
				queue = append(queue, queue[0].Right)
			}
			queue = queue[1:]
		}
	}
	return height
}

// arg t: the root node, not null
// arg offset: the offset of this subtree
// return: the width of the tree from root t
func f0655Helper(t *TreeNode, row int, col int) {
	if t.Left != nil {
		f0655Helper(t.Left, row+1, col)
	}
	// shifting made by left child
	col += 1<<(len(graph)-row-1) - 1
	graph[row][col] = strconv.Itoa(t.Val)
	if t.Right != nil {
		f0655Helper(t.Right, row+1, col+1)
	}
}

var graph [][]string

// perf: 4ms, 34
func printTree(root *TreeNode) [][]string {
	row := treeHeight(root)
	col := 1<<row - 1
	graph = graph[:0]
	for i := 0; i < row; i++ {
		graph = append(graph, make([]string, col))
	}
	if root != nil {
		f0655Helper(root, 0, 0)
	}
	return graph
}

func main() {
	temp := printTree(&TreeNode{1, &TreeNode{2, nil, &TreeNode{4, nil, nil}}, &TreeNode{3, nil, nil}})
	fmt.Printf("%v\n", temp)
}
