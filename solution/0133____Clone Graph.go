package main

import . "github.com/jhinkoo331/leetcode/src/model"

func cloneGraph(node *Node) *Node {
	return o133(node)
}

// 0ms, 22
func o133(node *Node) *Node {
	if node == nil {
		return nil
	}
	from := make([]*Node, 101, 101)
	to := make([]*Node, 101, 101)
	o133_place(node, from, to)
	o133_copy(from, to)
	return to[node.Val]
}

func o133_place(node *Node, from, to []*Node) {
	to_visit := []*Node{node}
	for len(to_visit) > 0 {
		temp := to_visit[len(to_visit)-1]
		to_visit = to_visit[:len(to_visit)-1]
		from[temp.Val] = temp
		to[temp.Val] = &Node{temp.Val, nil}
		for _, child := range temp.Neighbors {
			if from[child.Val] == nil {
				to_visit = append(to_visit, child)
			}
		}
	}
}

func o133_copy(from, to []*Node) {
	for _, node := range from {
		if node != nil {
			for _, child := range node.Neighbors {
				to[node.Val].Neighbors = append(to[node.Val].Neighbors, to[child.Val])
			}
		}
	}
}

func main() {
	n1 := &Node{1, nil}
	n2 := &Node{2, nil}
	n3 := &Node{3, nil}
	n1.Neighbors = []*Node{n2, n3}
	n2.Neighbors = []*Node{n1, n3}
	n3.Neighbors = []*Node{n1, n2}
	cloneGraph(n1)
}
