package main

import (
	"fmt"
)

func findNthDigit(n int) int {
	return _400(n)
}

// perf: 0ms, 100
func _400(n int) int {
	digit := 0
	// note that offset[-1] is assigned with a special value
	offset := []int{0, 9, 189, 2889, 38889, 488889, 5888889, 68888889, 788888889, 2147483647}
	for n > offset[digit] {
		digit++
	}
	n -= offset[digit-1]
	n--
	start := []int{0, 1, 10, 100, 1000, 1e4, 1e5, 1e6, 1e7, 1e8, 1e9}
	remainder := n % digit
	n /= digit
	n += start[digit]
	for temp := digit - remainder - 1; temp != 0; temp-- {
		n /= 10
	}
	return n % 10
}

func _400_code_generate() {
	arr := []int{0, 9}
	for i := 10; i != 0; i-- {
		arr = append(arr, arr[len(arr)-1]*10)
	}
	for i := range arr {
		arr[i] *= i
	}
	for i := 1; i < len(arr); i++ {
		arr[i] += arr[i-1]
	}
	fmt.Print(arr)
}

func main() {

}
