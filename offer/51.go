package main

// time out
func _51(nums []int) int {
	ans := 0
	for i := 1; i < len(nums); i++ {
		temp := i
		for temp > 0 && nums[temp-1] > nums[temp] {
			ans++
			nums[temp-1], nums[temp] = nums[temp], nums[temp-1]
			temp--
		}
	}
	return ans
}

type Tree struct {
	val   int
	left  *Tree
	right *Tree
}

func (root *Tree) insert(val uint) (ans int) {
	for mask := shift_value; mask != 0; mask >>= 1 {
		if mask&val == 0 {
			if root.left == nil {
				root.left = &Tree{0, nil, nil}
			}
			if root.right != nil {
				ans += root.right.val
			}
			root = root.left
		} else {
			if root.right == nil {
				root.right = &Tree{0, nil, nil}
			}
			root = root.right
		}
		root.val++
	}
	return
}

// 64bit, 0x8000,0000,0000,0000
const shift_value = (^uint(0) >> 1) + 1

// perf: 5, 5
func _51_2(nums []int) (ans int) {
	root := &Tree{0, nil, nil}
	for _, num := range nums {
		ans += root.insert(uint(num) + shift_value)
	}
	return ans
}

func reversePairs(nums []int) int {
	return _51_2(nums)
}
