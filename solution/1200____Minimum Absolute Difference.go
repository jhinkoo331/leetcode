package main

import (
	"math"
	"sort"
)

// perf: 43,51
func _1_1477(arr []int) [][]int {
	sort.Ints(arr)
	var ans [][]int
	minDifference := math.MaxInt32
	for i := 1; i < len(arr); i++ {
		difference := arr[i] - arr[i-1]
		if difference == minDifference {
			ans = append(ans, []int{arr[i-1], arr[i]})
		} else if difference < minDifference {
			minDifference = difference
			ans = [][]int{{arr[i-1], arr[i]}}
		}
	}
	return ans
}

func minimumAbsDifference(arr []int) [][]int {
	return _1_1477(arr)
}
