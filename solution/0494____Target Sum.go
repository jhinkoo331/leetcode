package main

// perf: 67, 5
func _0494(nums []int, S int) int {
	m := make(map[int]int)
	m[0] = 1
	for _, num := range nums {
		mm := make(map[int]int)
		for sum, ways := range m {
			mm[sum+num] += ways
			mm[sum-num] += ways
		}
		m = mm
	}
	return m[S]
}

// perf: 74, 5
func __0494(nums []int, S int) int {
	m_left := make(map[int]int)
	m_right := make(map[int]int)
	m_left[0] = 1
	m_right[0] = 1
	mid := len(nums) / 2
	for i := 0; i < mid; i++ {
		m := make(map[int]int)
		for sum, ways := range m_left {
			m[sum+nums[i]] += ways
			m[sum-nums[i]] += ways
		}
		m_left = m
	}
	for i := mid; i < len(nums); i++ {
		m := make(map[int]int)
		for sum, ways := range m_right {
			m[sum+nums[i]] += ways
			m[sum-nums[i]] += ways
		}
		m_right = m
	}
	ans := 0
	for sum, ways := range m_left {
		ans += m_right[S-sum] * ways
	}
	return ans
}

func findTargetSumWays(nums []int, S int) int {
	return __0494(nums, S)
}

func main() {
	arr := []int{1, 1, 1, 1, 1}
	findTargetSumWays(arr, 3)
}
