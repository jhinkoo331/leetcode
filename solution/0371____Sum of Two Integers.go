package main

func getSum(a int, b int) int {
	return t371(a, b)
}

// perf: 0ms, 100
func t371(a, b int) int {
	carry := false
	ans := 0
	for mask := 1; mask != 0; mask <<= 1 {
		if (a&mask) != 0 && (b&mask) != 0 {
			if carry {
				ans ^= mask
			}
			carry = true
		} else if (a&mask) == 0 && (b&mask) == 0 {
			if carry {
				ans ^= mask
				carry = false
			}
		} else {
			if carry {
				//carry = false
				//ans ^= mask
			} else {
				ans ^= mask
			}
		}
	}
	return ans
}

func main() {
	a, b := 123, 234
	println(getSum(a, b))
}
