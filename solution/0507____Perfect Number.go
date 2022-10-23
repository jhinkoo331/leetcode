package main

import "math"

// The worst of the journey is still to come

// perf: 4ms, 40%
func checkPerfectNumber(num int) bool {
	divisors := make(map[int]struct{})
	for i, temp := 1, int(math.Sqrt(float64(num))); i <= temp; i += 1 {
		if num%i == 0 {
			divisors[i] = struct{}{}
			divisors[num/i] = struct{}{}
		}
	}

	sum := 0
	for i := range divisors {
		if i != num {
			sum += i
		}
	}
	return sum == num
}

func main() {
	checkPerfectNumber(1)
	checkPerfectNumber(28)
}
