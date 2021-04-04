package main

func superPow(a int, b []int) int {
	return t372(a, b)
}

// perf: 100, 100
// todo: reduce multiple and dividing
func t372(a int, b []int) int {
	pre := a % 1337
	ans := t372_mod_pow(a, b[len(b)-1])
	for i := len(b) - 2; i >= 0; i-- {
		pre = t372_mod_pow_10(pre)
		temp := t372_mod_pow(pre, b[i])
		ans = (ans * temp) % 1337
	}
	return ans
}

func t372_mod_pow_10(n int) int {
	nn := (n * n) % 1337
	n4 := (nn * nn) % 1337
	n8 := (n4 * n4) % 1337
	return (nn * n8) % 1337
}

func t372_mod_pow(base, pow int) int {
	ans := 1
	for i := 0; i < pow; i++ {
		ans = (ans * base) % 1337
	}
	return ans
}

func main() {
	println(superPow(2, []int{3, 3}))

}
