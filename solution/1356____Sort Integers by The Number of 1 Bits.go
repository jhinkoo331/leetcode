package main

import "sort"

func sortByBits(arr []int) []int {
	return o1356(arr)
}

type o1356_struct struct {
	nums []int
	bits []int
}

func (o *o1356_struct) Len() int {
	return len(o.nums)
}

func (o *o1356_struct) Less(i, j int) bool {
	if o.bits[i] < o.bits[j] {
		return true
	} else if o.bits[i] > o.bits[j] {
		return false
	} else {
		return o.nums[i] < o.nums[j]
	}
}

func (o *o1356_struct) Swap(i, j int) {
	o.nums[i], o.nums[j] = o.nums[j], o.nums[i]
	o.bits[i], o.bits[j] = o.bits[j], o.bits[i]
}

// perf: 72, 56
func o1356(arr []int) []int {
	bits := make([]int, len(arr), len(arr))
	o1356_count_bits(arr, bits)
	temp := o1356_struct{arr, bits}
	sort.Sort(&temp)
	return temp.nums
}

func o1356_count_bits(arr, bits []int) {
	for mask := 1; mask != 0; mask <<= 1 {
		for i, v := range arr {
			if v&mask != 0 {
				bits[i]++
			}
		}
	}
}

func main() {

}
