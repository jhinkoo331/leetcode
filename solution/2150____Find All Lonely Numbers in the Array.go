package main

import "sort"

// be happy, be confident.

// 97%, 74%
func findLonely(nums []int) (lonelyNums []int) {
	sort.Slice(nums, func(i, j int) bool {
		return nums[i] < nums[j]
	})
	for i := range nums {
		if i-1 >= 0 && (nums[i-1] == nums[i] || nums[i-1] == nums[i]-1) {
			continue
		}
		if i+1 < len(nums) && (nums[i] == nums[i+1] || nums[i]+1 == nums[i+1]) {
			continue
		}
		lonelyNums = append(lonelyNums, nums[i])
	}
	return lonelyNums
}
