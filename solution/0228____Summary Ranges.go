package main

import "fmt"

func summaryRanges(nums []int) []string {
	return _228(nums)
}

// perf: 100 100
func _228(nums []int) (ans []string) {
	if len(nums) == 0 {
		return ans
	}
	last_range_head := 0
	prev_num := nums[0] - 2
	for _, num := range nums {
		if prev_num+1 != num {
			if last_range_head == prev_num {
				ans = append(ans, fmt.Sprintf("%d", prev_num))
			} else {
				ans = append(ans, fmt.Sprintf("%d->%d", last_range_head, prev_num))
			}
			last_range_head = num
		}
		prev_num = num
	}
	if last_range_head == prev_num {
		return append(ans[1:], fmt.Sprintf("%d", prev_num))
	} else {
		return append(ans[1:], fmt.Sprintf("%d->%d", last_range_head, prev_num))
	}
}
