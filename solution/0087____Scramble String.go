package main

func isScramble(s1 string, s2 string) bool {
	return e87([]rune(s1), []rune(s2))
}

func e87(s, ss []rune) bool {
	//if len(s) == 0 {
	//    return true
	//}
	if len(s) == 1 {
		return s[0] == ss[0]
	}
	left, right := make([]int, 128, 128), make([]int, 128, 128)
	for i, j := 0, len(s)-1; i < len(s)-1; i, j = i+1, j-1 {
		left[s[i]] += 1
		left[ss[i]] -= 1
		right[s[i]] += 1
		right[ss[j]] -= 1
		if e87allZero(left) && e87(s[:i+1], ss[:i+1]) && e87(s[i+1:], ss[i+1:]) {
			return true
		}
		if e87allZero(right) && e87(s[:i+1], ss[j:]) && e87(s[i+1:], ss[:j]) {
			return true
		}
	}
	return false
}

func e87allZero(m []int) bool {
	for _, v := range m {
		if v != 0 {
			return false
		}
	}
	return true
}

func main() {
	println(isScramble("abcde", "caebd"))
	println(isScramble("a", "a"))
	println(isScramble("ab", "ba"))
	println(isScramble("a", "b"))
	// this case takes 11 seconds...
	println(isScramble("eebaacbcbcadaaedceaaacadccd", "eadcaacabaddaceacbceaabeccd"))
}
