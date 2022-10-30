package main

// The worst of the journey is still to come

// perf: 8ms, 24%, 63%
func titleToNumber(columnTitle string) (ans int) {
	s := []byte(columnTitle)
	for _, c := range s {
		ans *= 26
		ans += int(c - 'A')
	}
	return ans
}
