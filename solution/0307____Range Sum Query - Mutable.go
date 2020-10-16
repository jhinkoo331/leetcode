package main

// brief: segment-tree, I wrote it by myself ~, bangbangda ~
// space complexity: 2n
// insert time complexity: lg_n
// update time complexity: lg_n
// perf: 100, 13
type NumArray struct {
	tree   []int
	offset int
}

func Constructor(nums []int) NumArray {
	var numArray NumArray
	numArray.offset = 1
	for numArray.offset < len(nums) {
		numArray.offset <<= 1
	}
	numArray.tree = make([]int, numArray.offset, numArray.offset+len(nums))
	numArray.tree = append(numArray.tree, nums...)
	for index := len(numArray.tree) - 1; index != 0; index-- {
		numArray.tree[index/2] += numArray.tree[index]
	}
	return numArray
}

func (this *NumArray) Update(i int, val int) {
	i += this.offset
	diff := val - this.tree[i]
	for ; i != 0; i /= 2 {
		this.tree[i] += diff
	}
}

func (this *NumArray) SumRange(i int, j int) int {
	return this.getSum(j) - this.getSum(i-1)
}

func (this *NumArray) getSum(i int) int {
	i += 1
	// edge condition, all numbers all included
	if len(this.tree)-this.offset == i {
		return this.tree[1]
	}
	// move the curNode down a level
	curIndex := 2
	ans := 0
	for mask := this.offset >> 1; mask != 0; mask >>= 1 {
		if mask&i != 0 {
			ans += this.tree[curIndex]
			// move the curNode to it's sibling
			curIndex++
		}
		curIndex *= 2
		// move the curNode down a level
	}
	return ans
}

/**
 * Your NumArray object will be instantiated and called as such:
 * obj := Constructor(nums);
 * obj.Update(i,val);
 * param_2 := obj.SumRange(i,j);
 */
