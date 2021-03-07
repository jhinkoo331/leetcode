package main

func longestSubarray(nums []int) int {
	return o1493(nums)
}

// perf: 100, 91
func o1493(nums []int) int {
	var zero bool
	for _, num := range nums {
		if num == 0 {
			zero = true
			break
		}
	}
	if !zero {
		if len(nums) == 0 {
			return 0
		} else {
			return len(nums) - 1
		}
	}
	pre_len := 0
	max_len := 0
	nums = append(nums, 0)
	for i := 0; i < len(nums)-1; {
		count := 0
		if nums[i] == 0 {
			pre_len = 0
			i++
		} else {
			for nums[i] == 1 {
				count++
				i++
			}
			i++
			if pre_len+count > max_len {
				max_len = pre_len + count
			} else if count-1 > max_len {
				max_len = count - 1
			}
			pre_len = count
		}
	}
	if !zero {
		if len(nums) == 0 {
			return 0
		} else {
			return len(nums) - 1
		}
	} else {
		return max_len
	}
}

func main() {
	arr := []int{1, 1, 1}
	longestSubarray(arr)
}
