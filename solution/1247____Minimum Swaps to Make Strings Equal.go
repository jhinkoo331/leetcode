package main

func minimumSwap(s1 string, s2 string) int {
	return o1247(s1, s2)
}

// perf: 0ms, 100
func o1247(s, ss string) (ans int) {
	if len(s) != len(ss) {
		return -1
	}
	var x, y int
	for i := range s {
		if s[i] != ss[i] {
			if s[i] == 'x' {
				x++
			} else {
				y++
			}
		}
	}
	ans += x / 2
	ans += y / 2
	if x%2 == 1 {
		if y%2 == 1 {
			ans += 2
		} else {
			ans = -1
		}
	} else if y%2 == 1 {
		ans = -1
	}
	return ans
}

func main() {
	minimumSwap("xxyyxyxyxx", "xyyxyxxxyx")
}
