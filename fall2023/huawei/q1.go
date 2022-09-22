package main

import (
	"fmt"
	"sort"
)

// be happy, be confident.

func sln(nums []int, max int) int {
	sum := 0
	for _, n := range nums {
		sum += n
	}
	if sum <= max {
		return -1
	}
	sort.Slice(nums, func(i, j int) bool {
		return nums[i] > nums[j]
	})
	curRemoved := 0
	toRemove := sum - max
	thresh := nums[0]
	curNotTruncatedIndex := 0
	for curRemoved < toRemove {
		for curNotTruncatedIndex < len(nums) && nums[curNotTruncatedIndex] > thresh-1 {
			curNotTruncatedIndex += 1
		}
		curRemoved += curNotTruncatedIndex
		thresh -= 1
	}
	return thresh
}

func main1() {
	var n int
	fmt.Scan(&n)
	nums := make([]int, n, n)
	for i := range nums {
		fmt.Scan(&nums[i])
	}
	var max int
	fmt.Scan(&max)
	ans := sln(nums, max)
	fmt.Println(ans)
}
