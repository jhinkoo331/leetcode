package main

import "fmt"

// perf: 99.28%, 82%
func findDuplicates(nums []int) (ans []int) {
	for i, v := range nums {
		for {
			if v == 0 {
				break
			}
			if i+1 == v {
				//nums[i] = 0
				break
			}
			targetIndex := v - 1
			if nums[i] == nums[targetIndex] {
				ans = append(ans, v)
				nums[i], nums[targetIndex] = 0, 0
				break
			}
			nums[i], nums[targetIndex] = nums[targetIndex], nums[i]
			v = nums[i]
		}
	}
	return ans
}

func main() {
	arr := []int{4, 3, 2, 7, 8, 2, 3, 1}
	fmt.Printf("%v\n", findDuplicates(arr))
	return
}
