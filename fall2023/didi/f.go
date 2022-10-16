package main

import (
	"sort"
)

// The worst of the journey is still to come

func fn(nums []int, k int) (ans int) {
	sort.Slice(nums, func(i, j int) bool {
		return nums[i] < nums[j]
	})
	right := 0
	for left := 0; left < len(nums); left += 1 {
		for right+1 < len(nums) && nums[right+1]-nums[left] <= k {
			right += 1
		}
		if temp := right - left + 1; temp > ans {
			ans = temp
		}
	}
	return ans
}

func test() {
	println(fn([]int{1, 3, 1, 5, 3, 1}, 3))
}
