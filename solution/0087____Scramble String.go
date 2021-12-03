package main

func isScramble(s1 string, s2 string) bool {
	return e87(s1, s2)
}

func e87(s, ss string) bool {
	if len(s) != len(ss) {
		return false
	}
	var r, rr []rune
	to_check := [][]rune{[]rune(s), []rune(ss)}
	for len(to_check) > 0 {
		if len(r) == 0 {
			r = to_check[len(to_check)-1]
			to_check = to_check[:len(to_check)-1]
			rr = to_check[len(to_check)-1]
			to_check = to_check[:len(to_check)-1]
		}

		if string(r) == string(rr) {
			r = nil
			rr = nil
			continue
		}
		for len(r) > 0 && r[0] == rr[0] {
			r = r[1:]
			rr = rr[1:]
		}
		for len(r) > 0 && r[len(r)-1] == rr[len(rr)-1] {
			r = r[:len(r)-1]
			rr = rr[:len(rr)-1]
		}

		diff := 0
		var char_cnt [128]int
		for i := 0; ; i++ {
			if i == len(r)-1 {
				return false
			}
			var temp int

			temp = int(r[i])
			char_cnt[temp]++
			if char_cnt[temp] == 1 {
				diff++
			} else if char_cnt[temp] == 0 {
				diff--
			}

			temp = int(rr[len(rr)-i-1])
			char_cnt[temp]--
			if char_cnt[temp] == -1 {
				diff++
			} else if char_cnt[temp] == 0 {
				diff--
			}

			if diff == 0 {
				to_check = append(to_check, r[i+1:])
				to_check = append(to_check, rr[:len(rr)-i-1])
				r = r[:i+1]
				rr = rr[len(rr)-i-1:]
				break
			}
		}
	}
	return true
}

func main() {
	print(isScramble("abcde", "caebd"))
}
