package main

import (
	"sort"
)

func reorderedPowerOf2(N int) bool {
	return e869(N)
}

var nums []int

// perf: 0ms, 100
// time: constant
// space: constant
func e869(N int) bool {
	if nums == nil {
		e869_setup_nums()
	}
	var arr []int
	for N > 0 {
		arr = append(arr, N%10)
		N /= 10
	}
	sort.Ints(arr)
	for i := len(arr) - 1; i >= 0; i-- {
		N *= 10
		N += arr[i]
	}
	for _, num := range nums {
		if num == N {
			return true
		}
	}
	return false
}

func e869_setup_nums() {
	for i := 0; i < 31; i++ {
		num := 1 << i
		var arr []int
		for num != 0 {
			arr = append(arr, num%10)
			num /= 10
		}
		sort.Ints(arr)
		for i := len(arr) - 1; i >= 0; i-- {
			num *= 10
			num += arr[i]
		}
		nums = append(nums, num)
	}
}
