package main

import (
	"unicode"
)

type NestedInteger struct {
	isInteger bool
	val       int
	lists     []*NestedInteger
}

// Return true if this NestedInteger holds a single integer, rather than a nested list.
func (n NestedInteger) IsInteger() bool {
	return n.isInteger
}

// Return the single integer that this NestedInteger holds, if it holds a single integer
// The result is undefined if this NestedInteger holds a nested list
// So before calling this method, you should have a check
func (n NestedInteger) GetInteger() int {
	return n.val
}

// Set this NestedInteger to hold a single integer.
func (n *NestedInteger) SetInteger(value int) {
	n.isInteger = true
	n.val = value
}

// Set this NestedInteger to hold a nested list and adds a nested integer to it.
func (n *NestedInteger) Add(elem NestedInteger) {
	n.isInteger = false
	n.lists = append(n.lists, &elem)
}

// Return the nested list that this NestedInteger holds, if it holds a nested list
// The list length is zero if this NestedInteger holds a single integer
// You can access NestedInteger's List element directly if you want to modify it
func (n NestedInteger) GetList() []*NestedInteger {
	return n.lists
}

// perf: 0ms, 100
// todo: eliminate speculation for unknown interface's implementation
func deserialize(s string) *NestedInteger {
	var stack []*NestedInteger
	stack = append(stack, &NestedInteger{})
	cur := stack[0]
	i := 0
	for i < len(s) {
		if s[i] == '[' {
			cur.Add(NestedInteger{})
			// todo: no speculation
			temp := cur.GetList()[len(cur.GetList())-1]
			cur = temp
			stack = append(stack, temp)
			i++
		} else if s[i] == ']' {
			stack = stack[:len(stack)-1]
			cur = stack[len(stack)-1]
			i++
		} else if s[i] == ',' {
			i++
		} else {
			var negative bool
			if s[i] == '-' {
				negative = true
				i++
			}
			num := 0
			for i < len(s) && unicode.IsDigit(rune(s[i])) {
				num *= 10
				num += int(s[i]) - int('0')
				i++
			}
			if negative {
				num = -num
			}
			temp := NestedInteger{}
			temp.SetInteger(num)
			//cur.lists = append(cur.lists, temp)
			cur.Add(temp)
		}
	}
	return cur.GetList()[0]
}
