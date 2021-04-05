package main

import "sort"

func canPartitionKSubsets(nums []int, k int) bool {
        return s698(nums, k)
}

func s698(nums []int, k int) bool {
        sum := 0
        for _, num := range nums {
                sum += num
        }
        if sum % k != 0 {
                return false
        }
        sort.Sort(sort.Reverse(sort.IntSlice(nums)))

}

func s698_dfs()

func main() {

}
