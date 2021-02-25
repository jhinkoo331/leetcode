package main

func singleNumber(nums []int) int {
	return _56_1(nums)
}

// perf: 89, 99
func _56_1(nums []int) (ans int) {
	for mask := 1; mask != 0; mask <<= 1 {
		cnt := 0
		for _, num := range nums {
			if num&mask != 0 {
				cnt++
			}
		}
		if cnt%3 == 1 {
			ans ^= mask
		}
	}
	return
}
