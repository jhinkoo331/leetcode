package main

import "fmt"

// The worst of the journey is still to come

var ans int
var fullStringLen int
var curString []rune

func goodString(s string) int {
	ans, fullStringLen = 0, len(s)
	validChar := make([]int, 128, 128)
	for _, r := range s {
		validChar[r] += 1
	}
	help(0, '?', validChar)
	return ans
}

func help(curStringLen int, lastChar rune, validChar []int) {
	if curStringLen == fullStringLen {
		ans += 1
		return
	}
	for c := rune('a'); c <= 'z'; c += 1 {
		if c == lastChar {
			continue
		}
		if validChar[c] > 0 {
			validChar[c] -= 1
			help(curStringLen+1, c, validChar)
			validChar[c] += 1
		}
	}
}

func main() {
	var s string
	fmt.Scan(&s)
	fmt.Printf("%d", goodString(s))
}
