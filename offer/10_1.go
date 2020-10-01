package main

// perf: 100, 73
func _10_1(n int) int {
	const mod = 1e9 + 7 // why not const mod := 1e9 + 7
	i, ii := 1, 0
	for n != 0 {
		i, ii = ii, i+ii
		if ii > mod {
			ii %= mod
		}
		n--
	}
	return ii
}

func fib(n int) int {
	return _10_1(n)
}

func main() {
	fib(45)
}
