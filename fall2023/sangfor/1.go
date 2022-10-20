package main

//import "fmt"

// The worst of the journey is still to come

// AC on nowcoder, tle on leetcode, one pass
func minDistance(s, ss string) int {
	v := []rune(s)
	vv := []rune(ss)
	return help1(v, vv)
}

func help1(s, ss []rune) int {
	if len(s) == 0 {
		return len(ss)
	}
	if len(ss) == 0 {
		return len(s)
	}
	if s[0] == ss[0] {
		return help1(s[1:], ss[1:])
	}
	curMin := len(s) + len(ss)
	if temp := help1(s[1:], ss[1:]); temp < curMin {
		curMin = temp
	}
	if temp := help1(s[1:], ss); temp < curMin {
		curMin = temp
	}
	if temp := help1(s, ss[1:]); temp < curMin {
		curMin = temp
	}
	return 1 + curMin
}
