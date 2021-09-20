package main

// Below is the interface for Iterator, which is already defined for you.

type Iterator struct {
}

func (this *Iterator) hasNext() bool {
	// Returns true if the iteration has more elements.
}

func (this *Iterator) next() int {
	// Returns the next element in the iteration.
}

// perf: [3ms, 24, 9]
type PeekingIterator struct {
	has_next  bool
	pre_value int
	iter      *Iterator
}

func Constructor(iter *Iterator) *PeekingIterator {
	temp := &PeekingIterator{}
	temp.iter = iter

	if temp.iter.hasNext() {
		temp.has_next = true
		temp.pre_value = iter.next()
	}
	return temp
}

func (this *PeekingIterator) hasNext() bool {
	return this.has_next
}

func (this *PeekingIterator) next() int {
	temp := this.pre_value
	if this.iter.hasNext() {
		this.has_next = true
		this.pre_value = this.iter.next()
	} else {
		this.has_next = false
	}
	return temp
}

func (this *PeekingIterator) peek() int {
	return this.pre_value
}

func main() {

}
