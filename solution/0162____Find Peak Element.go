package main

func findPeakElement(nums []int) int {
        return _0162(nums)
}

// perf: 100, 100
// time: log n
// space: in-space
// todo: what if nums[i] != nums[i + 1] constraint is removed?
func _0162(nums []int) int {
        // for if only one element in the array
        if len(nums) == 1 {
                return 0
        }
        // for if the result is the first or the last element
        if nums[0] > nums[1] {
                return 0
        }
        if nums[len(nums) - 2] < nums[len(nums) - 1] {
                return len(nums) - 1
        }
        // binary search
        left, right := 0, len(nums) - 1
        for left + 1 < right {
                mid := left + (right - left) / 2
                if nums[left] > nums[mid] {
                        right = mid
                } else if nums[mid] < nums[right] {
                        left = mid
                } else {
                        if nums[mid - 1] < nums[mid] && nums[mid] > nums[mid + 1] {
                                return mid
                        } else if nums[mid - 1] > nums[mid]{
                                right = mid - 1
                        } else {
                                left = mid + 1
                        }
                }
        }
        if nums[left] < nums[right] {
                return right
        } else {
                return left
        }
}

