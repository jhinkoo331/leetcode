package main

func _0829(N int) int {
	// the consecutive numbers are range[left, right)
	left, right := 1, 1
	sum := 0
	ans := 0
	leftMax := (N + 1) / 2
	for left < leftMax {
		for sum < N {
			sum += right
			right++
		}
		if sum == N {
			ans++
		}
		for sum >= N {
			sum -= left
			left++
		}
	}
	return ans + 1
}

func consecutiveNumbersSum(N int) int {
	return _0829(N)
}

func main() {
	consecutiveNumbersSum(5)
}
