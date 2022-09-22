package main

import (
	"fmt"
	. "github.com/jhinkoo331/leetcode/src/model"
	"strings"
)

var sb strings.Builder

// perf: 95, 7.9
func _0606(t *TreeNode) string {
	sb.Reset()
	if t != nil {
		fmt.Fprint(&sb, t.Val)
		if t.Left != nil {
			_0606_helper(t.Left)
		}
		if t.Left == nil && t.Right != nil {
			sb.WriteString("()")
		}
		if t.Right != nil {
			_0606_helper(t.Right)
		}
	}
	return sb.String()
}

// t most not be nil
func _0606_helper(t *TreeNode) {
	fmt.Fprintf(&sb, "(%d", t.Val)
	if t.Left != nil {
		_0606_helper(t.Left)
	}
	if t.Left == nil && t.Right != nil {
		sb.WriteString("()")
	}
	if t.Right != nil {
		_0606_helper(t.Right)
	}
	sb.WriteRune(')')
}

func tree2str(t *TreeNode) string {
	return _0606(t)
}
