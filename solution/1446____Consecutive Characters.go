package main

// perf: 0ms, 6.8
// todo: there comes the extra memory consumption? s += string(s[len(s) - 1) ^ 1 ?
func _1446(s string) int {
	if len(s) == 0 {
		return 0
	}
	s += string(s[len(s)-1] ^ 1)
	maxLen := 1
	for curIndex := 0; curIndex != len(s)-1; {
		nextIndex := curIndex + 1
		for s[curIndex] == s[nextIndex] {
			nextIndex++
		}
		if maxLen < nextIndex-curIndex {
			maxLen = nextIndex - curIndex
		}
		curIndex = nextIndex
	}
	return maxLen
}

// perf: 0ms, 6.7
// no difference with _1446
func __1446(s string) int {
	maxLen := 0
	for curIndex := 0; curIndex != len(s); {
		nextIndex := curIndex + 1
		for nextIndex < len(s) && s[curIndex] == s[nextIndex] {
			nextIndex++
		}
		if maxLen < nextIndex-curIndex {
			maxLen = nextIndex - curIndex
		}
		curIndex = nextIndex
	}
	return maxLen
}

func maxPower(s string) int {
	return __1446(s)
}

func main() {

}
