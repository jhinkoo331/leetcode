package main

// perf: 90, 99
// time: O(n), one pass
// space: O(128)
func _0387(s string) int {
	var appear [128]int   // how many times has a char appeared in the string till now
	var firstAppear []int // chars that appears for only one time
	for index := len(s) - 1; 0 <= index; index-- {
		appear[s[index]]++
		if appear[s[index]] == 1 {
			firstAppear = append(firstAppear, index)
		} else {
			// update firstAppear
			for len(firstAppear) != 0 && appear[s[firstAppear[len(firstAppear)-1]]] != 1 {
				firstAppear = firstAppear[:len(firstAppear)-1]
			}
		}
	}
	if len(firstAppear) == 0 {
		return -1
	} else {
		return firstAppear[len(firstAppear)-1]
	}
}

// perf: 99, 99
// time: O(n), two pass
// space: O(128)
func __0387(s string) int {
	var appear [128]int
	for _, c := range s {
		appear[c]++
	}
	for i, c := range s {
		if appear[c] == 1 {
			return i
		}
	}
	return -1
}

// s contains only lowercase characters
func firstUniqChar(s string) int {
	return __0387(s)
}

func main() {
	firstUniqChar("loveleetcode")
	firstUniqChar("fuckfuc")
}
