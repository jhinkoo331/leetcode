package main

// The worst of the journey is still to come

type ListNode struct {
	Val  int
	Next *ListNode
}

// perf: 4ms 97%, 19%
func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
	var n1, n2 []*ListNode
	for temp := l1; temp != nil; temp = temp.Next {
		n1 = append(n1, temp)
	}
	for temp := l2; temp != nil; temp = temp.Next {
		n2 = append(n2, temp)
	}

	ans := new(ListNode)
	flag := false
	for true {
		if len(n1) == 0 && len(n2) == 0 {
			break
		}
		temp := 0
		if flag {
			temp += 1
		}
		if len(n1) != 0 {
			temp += n1[len(n1)-1].Val
			n1 = n1[:len(n1)-1]
		}
		if len(n2) != 0 {
			temp += n2[len(n2)-1].Val
			n2 = n2[:len(n2)-1]
		}
		flag = temp >= 10
		tempNode := &ListNode{
			Val:  temp % 10,
			Next: ans.Next,
		}
		ans.Next = tempNode
	}

	if flag {
		tempNode := &ListNode{
			Val:  1,
			Next: ans.Next,
		}
		ans.Next = tempNode
	}
	return ans.Next
}
