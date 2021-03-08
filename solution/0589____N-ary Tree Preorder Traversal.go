package main

//type Node struct {
//    Val int
//    Children []*Node
//}

func preorder(root *Node) []int {
	return f589(root)
}

// perf: 0ms, 86
func f589(root *Node) (ans []int) {
	var stack []*Node
	if root != nil {
		stack = append(stack, root)
	}
	for len(stack) != 0 {
		temp := stack[len(stack)-1]
		stack = stack[:len(stack)-1]
		ans = append(ans, temp.Val)
		for i := len(temp.Children) - 1; i >= 0; i-- {
			stack = append(stack, temp.Children[i])
		}
	}
	return ans
}

func main() {

}
