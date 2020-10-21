package main

import "sort"

// perf: 56, 5
// time: len(coins) * amount
// space: linear(amount)
// todo: reduce the space complexity to O(max(coins))
func _0322(coins []int, amount int) int {
	sort.Ints(coins)
	arr := make([]int, amount+1)
	for i := 1; i <= amount; i++ {
		arr[i] = 0x7fffffff // 0x7fffffff stands for no solution
		for _, coin := range coins {
			temp := i - coin
			if temp < 0 {
				break
			}
			if arr[temp] != 0x7fffffff && arr[temp]+1 < arr[i] {
				arr[i] = arr[temp] + 1
			}
		}
	}
	if arr[amount] == 0x7fffffff {
		return -1
	} else {
		return arr[amount]
	}
}
func coinChange(coins []int, amount int) int {
	return _0322(coins, amount)
}

func main() {

}
