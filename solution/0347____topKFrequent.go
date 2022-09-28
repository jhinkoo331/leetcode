package main

import (
	"fmt"
	"sort"
)

// be happy, be confident.

type foo0347 struct {
	val   int
	count int
}

// perf: 74, 21
func topKFrequent(nums []int, k int) (ans []int) {
	count := make(map[int]int)
	for _, num := range nums {
		count[num] += 1
	}
	arr := make([]foo0347, 0, len(nums))
	for num, count := range count {
		arr = append(arr, foo0347{num, count})
	}
	sort.Slice(arr, func(i, j int) bool {
		return arr[i].count > arr[j].count
	})
	for i := 0; i < k; i += 1 {
		ans = append(ans, arr[i].val)
	}
	return ans
}

func main() {
	ans := topKFrequent([]int{
		1, 1, 1, 2, 2, 3,
	}, 2)
	fmt.Printf("%v", ans)
}
