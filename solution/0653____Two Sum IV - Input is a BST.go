package main

import (
	. "model"
)

func findTarget(root *TreeNode, k int) bool {
	return _653(root, k)
}

// perf: 94, 97
// complexity: time: n; space: depth of the BST
func _653(root *TreeNode, k int) bool {
	var inc, dec []*TreeNode
	inc = append(inc, root)
	for inc[len(inc)-1].Left != nil {
		inc = append(inc, inc[len(inc)-1].Left)
	}
	dec = append(dec, root)
	for dec[len(dec)-1].Right != nil {
		dec = append(dec, dec[len(dec)-1].Right)
	}
	_, small := _653_next(&inc, true)
	_, big := _653_next(&dec, false)
	for small <= big {
		for small+big > k {
			var ok bool
			ok, big = _653_next(&dec, false)
			if !ok || small > big {
				return false
			}
		}
		for small+big < k {
			var ok bool
			ok, small = _653_next(&inc, true)
			if !ok || small > big {
				return false
			}
		}
		if small+big == k {
			break
		}
	}
	if small+big == k {
		if small != big {
			return true
		} else {
			ok, next := _653_next(&inc, true)
			if !ok || next != small {
				return false
			} else {
				return true
			}
		}
	} else {
		return false
	}
}

func _653_next(stack *[]*TreeNode, inc bool) (bool, int) {
	// todo: make to logic clear
	if len(*stack) == 0 {
		// no number to return
		return false, 0
	}
	var ret int
	if inc {
		ret = (*stack)[len(*stack)-1].Val
		if (*stack)[len(*stack)-1].Right != nil {
			(*stack)[len(*stack)-1] = (*stack)[len(*stack)-1].Right
			for (*stack)[len(*stack)-1].Left != nil {
				*stack = append(*stack, (*stack)[len(*stack)-1].Left)
			}
		} else {
			*stack = (*stack)[:len(*stack)-1]
		}
	} else {
		ret = (*stack)[len(*stack)-1].Val
		if (*stack)[len(*stack)-1].Left != nil {
			(*stack)[len(*stack)-1] = (*stack)[len(*stack)-1].Left
			for (*stack)[len(*stack)-1].Right != nil {
				*stack = append(*stack, (*stack)[len(*stack)-1].Right)
			}
		} else {
			// todo: it does affect the argument?
			*stack = (*stack)[:len(*stack)-1]
		}
	}
	return true, ret
}

func main() {
	root := &TreeNode{2, &TreeNode{1, nil, nil}, &TreeNode{3, nil, nil}}
	findTarget(root, 3)
}
