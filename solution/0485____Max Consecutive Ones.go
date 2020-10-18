package main

// perf: 96, 10
func _0485(nums []int) int {
	maxLen := 0
	for curIndex := 0; curIndex < len(nums); {
		// skip all 0s
		for curIndex < len(nums) && nums[curIndex] == 0 {
			curIndex++
		}
		nextIndex := curIndex + 1
		for nextIndex < len(nums) && nums[nextIndex] == 1 {
			nextIndex++
		}
		if maxLen < nextIndex-curIndex {
			maxLen = nextIndex - curIndex
		}
		curIndex = nextIndex
	}
	return maxLen
}

func findMaxConsecutiveOnes(nums []int) int {
	return _0485(nums)
}

func main() {
	findMaxConsecutiveOnes([]int{1, 1, 0, 1, 1, 1})
}
