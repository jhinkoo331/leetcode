package main

func _search(nums []int, target int) int {
	return s704(nums, target)
}

// perf: 67, 83
func s704(nums []int, target int) int {
	left, right := 0, len(nums)
	for left < right {
		mid := left + (right-left)/2
		if nums[mid] == target {
			return mid
		} else if nums[mid] > target {
			right = mid
		} else {
			left = mid + 1
		}
	}
	return -1
}

// perf: 95, 83
func ss704(nums []int, target int) int {
	left, right := 0, len(nums)
	for left+10 < right {
		mid := left + (right-left)/2
		if nums[mid] == target {
			return mid
		} else if nums[mid] > target {
			right = mid
		} else {
			left = mid + 1
		}
	}
	for left != right {
		if nums[left] == target {
			return left
		}
		left++
	}
	return -1
}

func main() {

}
