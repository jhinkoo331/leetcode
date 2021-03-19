package main

func checkValidString(s string) bool {
	return s678(s)
}

// todo: cn-site solutions
// perf: 0ms, 29
// time: n
// space: n, stack used
func s678(s string) bool {
	var left, star []int
	for i, r := range s {
		if r == '(' {
			left = append(left, i)
		} else if r == '*' {
			star = append(star, i)
		} else { // r == ')'
			if len(left) > 0 {
				left = left[:len(left)-1]
			} else if len(star) > 0 {
				star = star[:len(star)-1]
			} else {
				return false
			}
		}
	}
	if len(left) > len(star) {
		return false
	}
	for len(left) > 0 {
		if left[len(left)-1] < star[len(star)-1] {
			left = left[:len(left)-1]
			star = star[:len(star)-1]
		} else {
			return false
		}
	}
	return true
}

func main() {

}
