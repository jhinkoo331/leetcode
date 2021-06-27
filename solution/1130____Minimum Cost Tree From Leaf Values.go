package main

func mctFromLeafValues(arr []int) int {
	return o1130(arr)
}

type o1130_node struct {
	val  int
	next *o1130_node
}

// perf: 0ms, 78
// todo: how to prove this alg's correctness?
func o1130(arr []int) (ans int) {

	head := &o1130_node{}
	tail := head
	for _, num := range arr {
		tail.next = &o1130_node{num, nil}
		tail = tail.next
	}
	for head.next.next != nil {
		min_prod_node := head.next
		min_prod := head.next.val * head.next.next.val
		cur := head.next
		for cur.next != nil {
			temp_prod := cur.val * cur.next.val
			if temp_prod < min_prod {
				min_prod = temp_prod
				min_prod_node = cur
			}
			cur = cur.next
		}
		ans += min_prod_node.val * min_prod_node.next.val
		if min_prod_node.val < min_prod_node.next.val {
			min_prod_node.val = min_prod_node.next.val
		}
		min_prod_node.next = min_prod_node.next.next
	}
	return ans
}

func main() {

}
