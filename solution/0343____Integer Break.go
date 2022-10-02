package main

import "math"

// be happy, be confident.

// 0ms, 95
func integerBreak(n int) int {
	// n: [2, 58]
	if n <= 3 {
		return n - 1
	}
	q, r := n/3, n%3
	ans := 1
	if r == 1 {
		ans = 4
		q -= 1
	} else if r == 2 {
		ans = 2
	}
	ans *= int(math.Pow(3, float64(q)))
	return ans
}
