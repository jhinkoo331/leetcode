package main

import . "model"

func _06_reverse(slice []int) {
	for left, right := 0, len(slice)-1; left < right; left, right = left+1, right-1 {
		slice[left], slice[right] = slice[right], slice[left]
	}
}

// perf: 100, 69
func _06(head *ListNode) []int {
	var values []int
	for head != nil {
		values = append(values, head.Val)
		head = head.Next
	}
	_06_reverse(values)
	return values
}

func reversePrint(head *ListNode) []int {
	return _06(head)
}
