package main

// perf: 100, 21
// time: n
// space: the width of the tree, n at worst
func _0559(root *Node) int {
	var cur_level []*Node
	var next_level []*Node
	height := 0
	if root != nil {
		cur_level = append(cur_level, root)
	}
	for len(cur_level) != 0 {
		height++
		next_level = nil
		for _, node := range cur_level {
			for _, child := range node.Children {
				next_level = append(next_level, child)
			}
		}
		cur_level = next_level
	}
	return height
}

func __0559_helper(root *Node, cur_height int, max_height *int) {
	if cur_height > *max_height {
		*max_height = cur_height
	}
	for _, child := range root.Children {
		__0559_helper(child, cur_height+1, max_height)
	}
}

// perf: 100, 98
// time: n
// space: depth of the tree, n at worst
func __0559(root *Node) int {
	if root == nil {
		return 0
	}
	max_height := 1
	__0559_helper(root, 1, &max_height)
	return max_height
}

func maxDepth(root *Node) int {
	//return _0559(root)
	return __0559(root)
}
