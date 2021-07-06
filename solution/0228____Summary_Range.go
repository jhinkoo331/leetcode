package main

import (
	"fmt"
	"strconv"
)

func summaryRanges(nums []int) []string {
	return t228(nums)
}

// perf: 0ms, 64
func t228(nums []int) (ans []string) {
	if len(nums) == 0 {
		return ans
	}
	pre_num := nums[0]
	for i := 1; i < len(nums); i++ {
		if nums[i] != nums[i-1]+1 {
			if nums[i-1] == pre_num {
				ans = append(ans, strconv.Itoa(pre_num))
			} else {
				ans = append(ans, fmt.Sprintf("%d->%d", pre_num, nums[i-1]))
			}
			pre_num = nums[i]
		}
	}
	if nums[len(nums)-1] == pre_num {
		ans = append(ans, strconv.Itoa(pre_num))
	} else {
		ans = append(ans, fmt.Sprintf("%d->%d", pre_num, nums[len(nums)-1]))
	}
	return ans
}

func main() {

}
