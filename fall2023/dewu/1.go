package main

func Merge(pHead1 *ListNode, pHead2 *ListNode) *ListNode {
	head := &ListNode{}
	tail := head
	for true {
		if (pHead1 == nil) && (pHead2 == nil) {
			break
		}
		if pHead2 == nil {
			tail.Next = pHead1
			break
		}
		if pHead1 == nil {
			tail.Next = pHead2
			break
		}
		if pHead1.Val < pHead2.Val {
			tail.Next = pHead1
			pHead1 = pHead1.Next
		} else {
			tail.Next = pHead2
			pHead2 = pHead2.Next
		}
		tail = tail.Next
	}
	return head.Next
}

type ListNode struct {
	Val  int
	Next *ListNode
}

func main1() {
	Merge(&ListNode{
		Val: -1,
		Next: &ListNode{
			Val: 2,
			Next: &ListNode{
				Val:  4,
				Next: nil,
			},
		},
	}, &ListNode{
		Val: 1,
		Next: &ListNode{
			Val: 3,
			Next: &ListNode{
				Val:  4,
				Next: nil,
			},
		},
	})
}
