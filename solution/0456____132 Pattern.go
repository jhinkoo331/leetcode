package main

func find132pattern(nums []int) bool {
	return f456(nums)
}

// perf: 100, 76
// time: O(n)
// space: O(n), it can be reduced to in-place by using the space from parameter.
func f456(nums []int) bool {
	var low, high []int
	low = append(low, 0x80000000)
	high = append(high, 0x80000000)
	i := 0
	for {
		temp_low := nums[i]
		temp_high := nums[i]
		for ii := len(low) - 1; ii >= 0; ii-- {
			if temp_low <= low[ii] {
				break
			} else if temp_low >= high[ii] {
				continue
			} else {
				return true
			}
		}
		for i+1 < len(nums) && nums[i] <= nums[i+1] {
			i++
			num := nums[i]
			for ii := len(low) - 1; ii >= 0; ii-- {
				if num <= low[ii] {
					break
				} else if num >= high[ii] {
					continue
				} else {
					return true
				}
			}
			temp_high = num
		}
		for high[len(high)-1] <= temp_high {
			low = low[:len(low)-1]
			high = high[:len(high)-1]
		}
		low = append(low, temp_low)
		high = append(high, temp_high)

		i++
		if i == len(nums) {
			break
		}
	}
	return false
}

func main() {

}
