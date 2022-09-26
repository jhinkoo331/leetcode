package main

import "fmt"

// be happy, be confident.

type cell struct {
	index int
	val   int
}

func q2(nums []int) []int {
	var decrease []cell
	ans := make([]int, len(nums), len(nums))
	for index, val := range nums {
		for len(decrease) > 0 && val > decrease[len(decrease)-1].val {
			ans[decrease[len(decrease)-1].index] = index - decrease[len(decrease)-1].index
			decrease = decrease[:len(decrease)-1]
		}
		decrease = append(decrease, cell{
			index: index,
			val:   val,
		})
	}
	return ans
}

func main() {
	ans := q2([]int{
		4, 6, 6, 2, 3, 9, 13,
	})
	fmt.Printf("%v", ans)
}
