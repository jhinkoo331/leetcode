package main

// perf: 92, 34
func _03(nums []int) int {
	for index := 0; index < len(nums); index++ {
		for nums[index] != index {
			if nums[nums[index]] == nums[index] {
				return nums[index]
			} else {
				// swap the two numbers
				nums[index], nums[nums[index]] = nums[nums[index]], nums[index]
			}
		}
	}
	return -1 // make it compile, never executed
}

func findRepeatNumber(nums []int) int {
	return _03(nums)
}

func main() {
	arr := []int{2, 3, 1, 0, 5, 3}
	findRepeatNumber(arr)
}
