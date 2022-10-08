package main

import (
	"fmt"
)

// The worst of the journey is still to come

// 在s中找到最长的子序列: 序列必须是连续的pair组成, 例如 "aabb", "aaaabb", "aa"等
// AC
func maxSubString(s string) int {
	maxLen := 0
	for left := 0; left < len(s); {
		right := left
		for right+1 < len(s) {
			if s[right] == s[right+1] {
				right += 2
			} else {
				break
			}
		}
		if right-left > maxLen {
			maxLen = right - left
		}
		if left == right {
			left = left + 1
		} else {
			left = right - 1
		}
	}
	return maxLen
}

func main() {
	var s string
	fmt.Scan(&s)
	ans := maxSubString(s)
	fmt.Println(ans)
}
