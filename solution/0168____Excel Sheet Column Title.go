package main

// The worst of the journey is still to come

// perf: 0ms 100%, 68%
func convertToTitle(columnNumber int) string {
	var s []byte
	for columnNumber != 0 {
		if columnNumber%26 == 0 {
			s = append(s, 'Z')
			columnNumber = columnNumber/26 - 1
		} else {
			s = append(s, uint8(columnNumber%26+'A'-1))
			columnNumber /= 26
		}
	}
	for left, right := 0, len(s)-1; left < right; left, right = left+1, right-1 {
		s[left], s[right] = s[right], s[left]
	}
	return string(s)
}

func main() {
	println(convertToTitle(1))
	println(convertToTitle(26))
}
