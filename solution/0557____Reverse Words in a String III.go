package main

func reverseWords(s string) string {
	return f557(s)
}

// perf: 4ms, 61
// time: n
// space: n
func f557(s string) string {
	var ss []uint8
	left := 0
	for right := range s {
		if s[right] == ' ' {
			// reverse
			for ll, rr := left, right-1; ll < rr; ll, rr = ll+1, rr-1 {
				ss[ll], ss[rr] = ss[rr], ss[ll]
			}
			left = right + 1
		}
		ss = append(ss, s[right])
	}
	for ll, rr := left, len(ss)-1; ll < rr; ll, rr = ll+1, rr-1 {
		ss[ll], ss[rr] = ss[rr], ss[ll]
	}
	return string(ss)
}
