package main

// perf: 26, 24
func twoSum(nums []int, target int) []int {
	m := make(map[int]bool)
	for index := 0; index < len(nums); index++ {
		complement := target - nums[index]
		if m[complement] == true {
			return []int{nums[index], complement}
		}
		m[nums[index]] = true
	}
	return []int{0, 0} // error, target not found
}
