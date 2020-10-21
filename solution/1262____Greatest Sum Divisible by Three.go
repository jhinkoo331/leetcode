package main

import "sort"

// perf: 25, 10
// time: O(n)
// space: O(n)          // could be enhanced.
func _1262(nums []int) int {
	var remain1, remain2 []int
	ans := 0
	for _, num := range nums {
		remainder := num % 3
		ans += num
		if remainder == 0 {
		} else if remainder == 1 {
			remain1 = append(remain1, num)
		} else {
			remain2 = append(remain2, num)
		}
	}
	// make remain1 longer than remain2
	if len(remain1) < len(remain2) {
		remain1, remain2 = remain2, remain1
	}
	sort.Ints(remain1)
	sort.Ints(remain2)
	diff := len(remain1) - len(remain2)
	remainder := diff % 3
	if remainder == 0 {
		return ans
	} else if remainder == 1 {
		if len(remain2) >= 2 && remain1[0] > remain2[0]+remain2[1] {
			ans -= remain2[0] + remain2[1]
		} else {
			ans -= remain1[0]
		}
	} else if remainder == 2 {
		if len(remain2) >= 1 && remain1[0]+remain1[1] > remain2[0] {
			ans -= remain2[0]
		} else {
			ans -= remain1[0] + remain1[1]
		}
	}
	return ans
}

// todo: reduce memory complexity to O(1) from method 1
func __1262(nums []int) int {

}

func maxSumDivThree(nums []int) int {
	return _1262(nums)
}

func main() {
	arr := []int{3, 6, 5, 1, 8}
	println(maxSumDivThree(arr))
}
