package main

func _0413(A []int) int {
	if len(A) < 2 {
		return 0
	}
	difference := (A[0] - A[1]) ^ 1
	count := 0
	total_count := 0
	for index := 1; index < len(A); index++ {
		if A[index-1]-A[index] == difference {
			count++
		} else {
			total_count += _0413_get_count(count)
			count = 1
			difference = A[index-1] - A[index]
		}
	}
	total_count += _0413_get_count(count)
	return total_count
}

// perf: 100, 96
func _0413_get_count(n int) int {
	if n < 2 {
		return 0
	}
	return n * (n - 1) / 2
}

func numberOfArithmeticSlices(A []int) int {
	return _0413(A)
}

func main() {
	arr := []int{1, 2, 3, 8, 9, 10}
	numberOfArithmeticSlices(arr)
}
