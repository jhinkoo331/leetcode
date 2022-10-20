package main

import "fmt"

// The worst of the journey is still to come

func sln2(nums []int, k int) int {
	ans := helper(nums, k)
	if ans == 0 { // len(nums) == 0
		return 0
	}
	return ans - 1
}

func helper(nums []int, k int) int {
	if len(nums) == 0 {
		return 0
	}
	curFloor, curCeil := nums[0]-k, nums[0]+k
	for i := 1; i < len(nums); i += 1 {
		nextFloor, nextCeil := nums[i]-k, nums[i]+k
		if curFloor > nextCeil || curCeil < nextFloor {
			return 1 + helper(nums[i:], k)
		} else {
			if curCeil > nextCeil {
				curCeil = nextCeil
			}
			if curFloor < nextFloor {
				curFloor = nextFloor
			}
		}
	}
	return 1
}

func main() {
	var n, k int
	fmt.Scan(&n, &k)
	nums := make([]int, n, n)
	for i := range nums {
		fmt.Scan(&nums[i])
	}
	ans := sln2(nums, k)
	fmt.Printf("%d\n", ans)
}
