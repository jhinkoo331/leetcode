package main

import (
	"fmt"
)

// be happy, be confident.

func sln(nums []int) (ans []int) {
	for newCard := 1; newCard <= 9; newCard += 1 {
		temp := append(nums, newCard)
		if isAbcAbcAbcAbcDd(temp) || isAaaBbbCccDddEe(temp) {
			ans = append(ans, newCard)
		}
	}
	return ans
}

func isAbcAbcAbcAbcDd(nums []int) bool {
	var count [10]int
	for _, n := range nums {
		count[n] += 1
		if count[n] > 4 {
			return false
		}
	}
	for d := 1; d <= 9; d += 1 {
		temp := count
		temp[d] -= 2
		if temp[d] < 0 {
			return false
		}
		for left := 1; left <= 7; left += 1 {
			temp[left+1] -= temp[left]
			if temp[left+1] < 0 {
				return false
			}
			temp[left+2] -= temp[left]
			if temp[left+2] < 0 {
				return false
			}
			temp[left] = 0
		}
		allZero := true
		for _, n := range temp {
			if n != 0 {
				allZero = false
				break
			}
		}
		if allZero {
			return true
		}
	}
	return false
}

func isAaaBbbCccDddEe(nums []int) bool {
	var count [10]int
	for _, n := range nums {
		count[n] += 1
		if count[n] > 4 {
			return false
		}
	}
	var countCount [5]int
	for _, n := range count {
		countCount[n] += 1
	}
	if countCount[3] == 4 && countCount[2] == 1 {
		return true
	}
	return false
}

func main() {
	nums := make([]int, 13, 14)
	for i := range nums {
		fmt.Scan(&nums[i])
	}
	ans := sln(nums)
	if len(ans) == 0 {
		fmt.Println("0")
	} else {
		for i := 0; i < len(ans)-1; i += 1 {
			fmt.Printf("%d ", ans[i])
		}
		fmt.Printf("%d\n", ans[len(ans)-1])
	}
}
