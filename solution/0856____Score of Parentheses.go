package main

func scoreOfParentheses(S string) int {
	return ee856(S)
}

// perf: 0ms, 36
// time: n
// space: n
func e856(S string) int {
	total_score := 0
	var scores []int
	for _, r := range S {
		if r == '(' {
			scores = append(scores, 0)
		} else {
			temp := scores[len(scores)-1]
			scores = scores[:len(scores)-1]
			if len(scores) != 0 {
				if temp == 0 {
					scores[len(scores)-1] += 1
				} else {
					scores[len(scores)-1] += 2 * temp
				}
			} else {
				if temp == 0 {
					total_score += 1
				} else {
					total_score += 2 * temp
				}
			}
		}
	}
	return total_score
}

// perf: 0ms, 36
// time: n
// space: constant
func ee856(S string) int {
	ans := 0
	deepth := 0
	for i := 0; i < len(S); i++ {
		if S[i] == '(' {
			if S[i+1] == ')' {
				ans += 1 << deepth
			}
			deepth++
		} else {
			deepth--
		}
	}
	return ans
}

func main() {

}
