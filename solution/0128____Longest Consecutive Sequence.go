package main

import (
	"sort"
)

func max(i, ii int) int {
	if i > ii {
		return i
	} else {
		return ii
	}
}

// brief: sort the slice and iterating over all elements
// time: nlog n
// space: in-place
// perf: 98, 100
// todo: this is in hard-level list, try another way with better time complexity
func _0128(nums []int) int {
	if nums == nil || len(nums) == 0 {
		return 0
	}
	sort.Ints(nums)
	maxLen := 1
	curLen := 1
	for index := 1; index < len(nums); index++ {
		if nums[index-1]+1 == nums[index] {
			curLen++
		} else if nums[index-1] == nums[index] {
			// pass
		} else {
			maxLen = max(maxLen, curLen)
			curLen = 1
		}
	}
	maxLen = max(maxLen, curLen)
	return maxLen
}

func longestConsecutive(nums []int) int {
	return _0128(nums)
}
