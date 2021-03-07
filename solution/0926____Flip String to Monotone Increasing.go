package main

func minFlipsMonoIncr(S string) int {
	return n926(S)
}

// perf: 0ms, 35
// time: n
// space: n
func n926(S string) int {
	right := make([]int, len(S)+1)
	for i := len(S) - 1; i >= 0; i-- {
		right[i] = right[i+1]
		if S[i] == '0' {
			right[i]++
		}
	}
	ans := len(S)
	one_count := 0
	for i, c := range S {
		if right[i]+one_count < ans {
			ans = right[i] + one_count
		}
		if c == '1' {
			one_count++
		}
	}
	if one_count < ans {
		return one_count // change all 1s to 0s
	} else {
		return ans
	}
}

func main() {
	n926("00011000")
}
