package main

// perf: 4ms, 100
func findNumbers(nums []int) int {
	var ans int = 0
	for _, num := range nums {
		if even_digits(num) {
			ans++
		}
	}
	return ans
}

// i is in range [1, 100000]
func even_digits(i int) bool {
	for i >= 100 {
		i /= 100
	}
	if i >= 10 {
		return true
	} else {
		return false
	}
}

func main() {
	var arr = []int{12, 345, 2, 6, 7896}
	findNumbers(arr)
}
