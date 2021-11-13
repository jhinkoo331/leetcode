package main

func maximumGap(nums []int) int {
	return o164_(nums)
}

// perf: 99.2, 43
// time: n
// space: 2n
func o164_(nums []int) int {
	if len(nums) <= 1 {
		return 0
	}
	// make all numbers starts from 0
	min := nums[0]
	for _, n := range nums {
		if n < min {
			min = n
		}
	}
	max := 0
	for i := range nums {
		nums[i] -= min
		if nums[i] > max {
			max = nums[i]
		}
	}
	if max == 0 {
		return 0
	}

	// calculate the gap
	gap := max / (len(nums) - 1)
	if max%(len(nums)-1) != 0 {
		gap += 1
	}

	var group_count int
	if max+1%gap == 0 {
		group_count = (max + 1) / gap
	} else {
		group_count = (max+1)/gap + 1
	}

	// there must be a a_i and a_{i + 1} with a_{i + 1} - a_i >= gap
	min_arr := make([]int, group_count, group_count)
	max_arr := make([]int, group_count, group_count)
	for i := range max_arr {
		min_arr[i] = max
		max_arr[i] = 0
	}

	for _, v := range nums {
		group := v / gap
		if v < min_arr[group] {
			min_arr[group] = v
		}
		if v > max_arr[group] {
			max_arr[group] = v
		}
	}

	max_gap := 0
	left, right := 0, 0
	for min_arr[left] > max_arr[left] {
		left += 1
	}
	for left < len(min_arr)-1 {
		right = left + 1
		for right < len(min_arr) && min_arr[right] > max_arr[right] {
			right += 1
		}
		if right == len(min_arr) {
			break
		}
		if temp := min_arr[right] - max_arr[left]; temp > max_gap {
			max_gap = temp
		}
		left = right
	}
	return max_gap
}
