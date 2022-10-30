package main

import (
	"container/heap"
	"fmt"
)

// The worst of the journey is still to come

type PeekHeap interface {
	heap.Interface
	Peek() int
}

type MaxHeap []int

func (m *MaxHeap) Len() int {
	return len(*m)
}

func (m *MaxHeap) Less(i, j int) bool {
	return (*m)[i] > (*m)[j]
}

func (m *MaxHeap) Swap(i, j int) {
	(*m)[i], (*m)[j] = (*m)[j], (*m)[i]
}

func (m *MaxHeap) Push(x interface{}) {
	*m = append(*m, x.(int))
}

func (m *MaxHeap) Pop() interface{} {
	old := (*m)[m.Len()-1]
	*m = (*m)[:m.Len()-1]
	return old
}

func (m *MaxHeap) Peek() int {
	return (*m)[0]
}

type MinHeap []int

func (m *MinHeap) Len() int {
	return len(*m)
}

func (m *MinHeap) Less(i, j int) bool {
	return (*m)[i] < (*m)[j]
}

func (m *MinHeap) Swap(i, j int) {
	(*m)[i], (*m)[j] = (*m)[j], (*m)[i]
}

func (m *MinHeap) Push(x interface{}) {
	*m = append(*m, x.(int))
}

func (m *MinHeap) Pop() interface{} {
	old := (*m)[m.Len()-1]
	*m = (*m)[:m.Len()-1]
	return old
}

func (m *MinHeap) Peek() int {
	return (*m)[0]
}

type median480 struct {
	left         *MaxHeap
	leftCount    int
	leftRemoved  map[int]int
	right        *MinHeap
	rightCount   int
	rightRemoved map[int]int
}

func (m *median480) Add(x int) {
	defer m.fix()
	if m.leftCount == 0 {
		heap.Push(m.left, x)
		m.leftCount++
		return
	}
	if m.leftCount == 1 {
		if x > m.left.Peek() {
			heap.Push(m.right, x)
			m.rightCount++
		} else {
			heap.Push(m.left, x)
			m.leftCount++
		}
		return
	}
	if x < m.left.Peek() {
		heap.Push(m.left, x)
		m.leftCount++
		return
	}
	if x > m.right.Peek() {
		heap.Push(m.right, x)
		m.rightCount++
		return
	}
	if m.leftCount > m.rightCount {
		heap.Push(m.right, x)
		m.rightCount++
		return
	} else {
		heap.Push(m.left, x)
		m.leftCount++
		return
	}
}

func (m *median480) Remove(x int) {
	defer m.fix()
	if x <= m.left.Peek() {
		m.leftCount -= 1
		m.leftRemoved[x]++
	} else {
		m.rightCount -= 1
		m.rightRemoved[x]++
	}
}

func (m *median480) Median() float64 {
	m.fix()
	if m.leftCount > m.rightCount {
		return float64(m.left.Peek())
	} else {
		return float64(m.left.Peek()+m.right.Peek()) / 2
	}
}

func (m *median480) fix() {
	for m.leftCount < m.rightCount {
		fixHeap(m.left, m.leftRemoved)
		fixHeap(m.right, m.rightRemoved)
		temp := heap.Pop(m.right)
		m.rightCount--
		heap.Push(m.left, temp)
		m.leftCount++
	}
	for m.leftCount-m.rightCount >= 2 {
		fixHeap(m.left, m.leftRemoved)
		fixHeap(m.right, m.rightRemoved)
		temp := heap.Pop(m.left)
		m.leftCount--
		heap.Push(m.right, temp)
		m.rightCount++
	}
	fixHeap(m.left, m.leftRemoved)
	fixHeap(m.right, m.rightRemoved)
}

func fixHeap(h PeekHeap, removed map[int]int) {
	for h.Len() > 0 && removed[h.Peek()] > 0 {
		removed[h.Peek()] -= 1
		heap.Pop(h)
	}
}

// perf: 86%, 67%
func medianSlidingWindow(nums []int, k int) (medians []float64) {
	left, right := 0, 0
	m := &median480{
		left:         &MaxHeap{},
		leftCount:    0,
		leftRemoved:  map[int]int{},
		right:        &MinHeap{},
		rightCount:   0,
		rightRemoved: map[int]int{},
	}
	for ; right < k; right++ {
		m.Add(nums[right])
	}
	for true {
		medians = append(medians, m.Median())
		if right == len(nums) {
			break
		}
		m.Add(nums[right])
		m.Remove(nums[left])
		left, right = left+1, right+1
	}
	return medians
}

func main() {
	medians := medianSlidingWindow([]int{1, 3, -1, -3, 5, 3, 6, 7}, 3)
	fmt.Printf("%v\n", medians)
}
