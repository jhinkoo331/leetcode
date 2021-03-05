package main

func balancedString(s string) int {
	return o1234(s)
}

// perf: 100, 100
// time: n
// space: constant
func o1234(s string) int {
	if len(s)%4 != 0 {
		// error, it can never be balanced
		return -1
	}
	var count [4]int
	for _, char := range s {
		switch char {
		case 'Q':
			count[0]++
		case 'W':
			count[1]++
		case 'E':
			count[2]++
		case 'R':
			count[3]++
		}
	}
	positive := 0
	for i := range count {
		if count[i] > len(s)/4 {
			count[i] -= len(s) / 4
			positive++
		} else {
			count[i] = 0
		}
	}
	if positive == 0 {
		// the string is already balanced
		return 0
	}
	left, right := 0, 0
	min_len := len(s)
	for right < len(s) {
		for positive != 0 && right < len(s) {
			switch s[right] {
			case 'Q':
				count[0]--
				if count[0] == 0 {
					positive--
				}
			case 'W':
				count[1]--
				if count[1] == 0 {
					positive--
				}
			case 'E':
				count[2]--
				if count[2] == 0 {
					positive--
				}
			case 'R':
				count[3]--
				if count[3] == 0 {
					positive--
				}
			}
			right++
		}
		for positive == 0 {
			switch s[left] {
			case 'Q':
				count[0]++
				if count[0] == 1 {
					positive++
				}
			case 'W':
				count[1]++
				if count[1] == 1 {
					positive++
				}
			case 'E':
				count[2]++
				if count[2] == 1 {
					positive++
				}
			case 'R':
				count[3]++
				if count[3] == 1 {
					positive++
				}
			}
			left++
		}
		if right-left+1 < min_len {
			min_len = right - left + 1
		}
	}
	return min_len
}

func main() {

}
