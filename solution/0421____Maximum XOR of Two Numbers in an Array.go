package main

import (
	"fmt"
	"math"
)

type Node0421 struct {
	zero *Node0421
	one  *Node0421
}

func (root *Node0421) insert(num int) {
	for mask := 0x80000000; mask != 0; mask >>= 1 {
		if num&mask == 0 {
			if root.zero == nil {
				root.zero = &Node0421{nil, nil}
			}
			root = root.zero
		} else {
			if root.one == nil {
				root.one = &Node0421{nil, nil}
			}
			root = root.one
		}
	}
}

// We assert that we can always find a non-negative xor result
// if there is no such result, return 0 instead
func (root *Node0421) maxXor(num int) int {
	maxXor := 0
	mask := 0x80000000
	if num&mask == 0 {
		if root.zero == nil {
			maxXor ^= mask
			root = root.one
		} else {
			root = root.zero
		}
	} else {
		if root.one == nil {
			maxXor ^= mask
			root = root.zero
		} else {
			root = root.one
		}
	}
	mask >>= 1
	for mask != 0 {
		if num&mask == 0 {
			if root.one != nil {
				maxXor ^= mask
				root = root.one
			} else {
				root = root.zero
			}
		} else {
			if root.zero != nil {
				maxXor ^= mask
				root = root.zero
			} else {
				root = root.one
			}
		}
		mask >>= 1
	}
	return maxXor
}

// there exists 1 number in nums at least
// perf: 95, 5
func f0421(nums []int) int {
	if len(nums) < 2 {
		return 0
	}
	root := &Node0421{nil, nil}
	root.insert(nums[0])
	maxXor := math.MinInt32
	for i := 1; i < len(nums); i++ {
		temp := root.maxXor(nums[i])
		if maxXor < temp {
			maxXor = temp
		}
		root.insert(nums[i])
	}
	return maxXor
}

func findMaximumXOR(nums []int) int {
	return f0421(nums)
}

func main() {
	nums := []int{1, 2}
	fmt.Println(findMaximumXOR(nums))
}
