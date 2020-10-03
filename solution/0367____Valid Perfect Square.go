package main

// perf: 0ms, 85
func _0367_1(num int) bool {
	left, right := 0, num
	for left <= right {
		mid := left + (right-left)/2
		mid_square := mid * mid
		if mid_square == num {
			return true
		} else if mid_square > num {
			right = mid - 1
		} else {
			left = mid + 1
		}
	}
	return false
}

// num is given positive
func isPerfectSquare(num int) bool {
	return _0367_1(num)
}
