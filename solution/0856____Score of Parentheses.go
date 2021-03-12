package main

func scoreOfParentheses(S string) int {
	return e856(S)
}

// perf: 0ms, 36
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

func main() {

}
