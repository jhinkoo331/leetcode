package main

func search(nums []int, target int) bool {
	return _81_unknown(nums, target)
}

// perf: 4ms, 30
func _81_unknown(nums []int, target int) bool {
	var stack = make([][]int, 0)
	stack = append(stack, nums)
	for len(stack) != 0 {
		// retrieve a slice and pop it out
		nums = stack[len(stack)-1]
		stack = stack[:len(stack)-1]
		// check nums
		for len(nums) > 10 {
			left := nums[0]
			mid_idx := len(nums) / 2
			mid := nums[mid_idx]
			right := nums[len(nums)-1]
			if mid == target {
				return true
			}
			// left > right: the slice consists of two parts
			// left == right: ... consists of two parts or all numbers are the same
			// left < right: the slice is in increasing order
			if left < right {
				if mid < target {
					nums = nums[mid_idx+1:]
				} else {
					nums = nums[:mid_idx]
				}
			} else if left == right {
				if mid > left {
					if target > mid {
						nums = nums[mid_idx+1:]
					} else if target <= right {
						nums = nums[mid_idx+1:]
					} else { // left < target < mid
						nums = nums[1:mid_idx]
					}
				} else if mid == left {
					// push right part to stack
					stack = append(stack, nums[mid_idx+1:len(nums)-1])
					nums = nums[1:mid_idx]
				} else { // mid < right
					if target < mid {
						nums = nums[:mid_idx]
					} else if target >= left {
						nums = nums[:mid_idx]
					} else { // target is in range (mid, left)
						nums = nums[mid_idx+1 : len(nums)-1]
					}
				}
			} else { // left > right: the slice consists of two parts
				if left <= mid { // mid is in left part
					if target > mid || target <= right {
						nums = nums[mid_idx+1:]
					} else if target < left {
						continue // target 404
					} else {
						nums = nums[:mid_idx]
					}
				} else { // ...right part
					if target < mid {
						nums = nums[1:mid_idx]
					} else if target >= left {
						nums = nums[:mid_idx]
					} else if target <= right {
						nums = nums[mid_idx+1:]
					} else {
						continue
					}
				}
			}
		}
		// when len(nums) reduce to less than 10, replace binary search with naive iteration
		for _, num := range nums {
			if num == target {
				return true
			}
		}
	}
	return false // target 404
}

func main() {
	var arr = []int{15, 16, 19, 20, 25, 1, 3, 4, 5, 7, 10, 14}
	search(arr, 25)
}
