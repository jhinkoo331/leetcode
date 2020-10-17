package main

// perf: 0ms, 100
// todo: what the hell?
func _0747(nums []int) int {
	if len(nums) == 0 {
		return -1
	}
	maxIndex := 0
	for i, val := range nums {
		if nums[maxIndex] < val {
			maxIndex = i
		}
	}
	if nums[maxIndex] <= 0 {
		return maxIndex
	} else {
		nums[maxIndex] >>= 1
	}
	for _, val := range nums {
		if val > nums[maxIndex] {
			return -1
		}
	}
	return maxIndex
}

func dominantIndex(nums []int) int {
	return _0747(nums)
}

func main() {

}
