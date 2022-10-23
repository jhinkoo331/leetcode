package main

// be happy, be confident.

func getBucket(num, valueDiff int) int {
	r := num % valueDiff
	ans := num / valueDiff
	if r < 0 {
		ans -= 1
	}
	return ans
}

// perf: 64, 20
func containsNearbyAlmostDuplicate(nums []int, indexDiff int, valueDiff int) bool {
	if valueDiff == 0 {
		m := make(map[int]bool)
		left, right := 0, -1
		for right+1 <= indexDiff && right+1 < len(nums) {
			right += 1
			num := nums[right]
			if m[num] {
				return true
			} else {
				m[num] = true
			}
		}
		for right+1 < len(nums) {
			delete(m, nums[left])
			left += 1

			right += 1
			num := nums[right]
			if m[num] {
				return true
			} else {
				m[num] = true
			}
		}
		return false
	}
	// map[bucket]numInTheBucket
	// bucket(num) = num / valueDiff
	m := make(map[int]int)
	left, right := 0, -1
	for right+1 <= indexDiff && right+1 < len(nums) {
		right += 1
		num := nums[right]
		bucket := getBucket(num, valueDiff)
		if _, ok := m[bucket]; ok {
			return true
		}
		if v, ok := m[bucket+1]; ok && v-num <= valueDiff {
			return true
		}
		if v, ok := m[bucket-1]; ok && num-v <= valueDiff {
			return true
		}
		m[bucket] = num
	}
	for right+1 < len(nums) {
		bucket := getBucket(nums[left], valueDiff)
		delete(m, bucket)
		left += 1

		right += 1
		bucket = getBucket(nums[right], valueDiff)
		if _, ok := m[bucket]; ok {
			return true
		}
		if v, ok := m[bucket+1]; ok && v-nums[right] <= valueDiff {
			return true
		}
		if v, ok := m[bucket-1]; ok && nums[right]-v <= valueDiff {
			return true
		}
		m[bucket] = nums[right]
	}
	return false
}

func main() {
	containsNearbyAlmostDuplicate([]int{-3, 3}, 2, 4)
	containsNearbyAlmostDuplicate([]int{1, 5, 9, 1, 5, 9}, 2, 3)
}
