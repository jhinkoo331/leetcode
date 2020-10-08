package main

// the max value of int32 is 2,147,483,647
var divisor = []int{1e9, 1e8, 1e7, 1e6, 1e5, 1e4, 1e3, 1e2, 1e1, 1}
var countOf1 = []int{9e8, 8e7, 7e6, 6e5, 5e4, 4e3, 3e2, 2e1, 1, 0}

// perf: 0ms, 57
func _0233(n int) int {
	if n < 0 {
		return 0
	}
	ans := 0
	for i := 0; i < len(divisor); i++ {
		quotient := n / divisor[i]
		n %= divisor[i]
		if quotient == 0 {
			continue
		} else if quotient == 1 {
			ans += countOf1[i]
			ans += n
			ans += 1
		} else {
			ans += (quotient) * countOf1[i]
			ans += divisor[i]
		}
	}
	return ans
}

func countDigitOne(n int) int {
	return _0233(n)
}

func main() {
	ans := 0
	ans = countDigitOne(0)
	ans = countDigitOne(1)
	ans = countDigitOne(2)
	ans = countDigitOne(11)
	ans = countDigitOne(23)
	ans = countDigitOne(456)
	println(ans)
}
