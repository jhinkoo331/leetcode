package _341____Flatten_Nested_List_Iterator

// be happy, be confident.

// This is the interface that allows for creating nested lists.
// You should not implement it, or speculate about its implementation
type NestedInteger struct {
}

// Return true if this NestedInteger holds a single integer, rather than a nested list.
func (this NestedInteger) IsInteger() bool {
	return true
}

// Return the single integer that this NestedInteger holds, if it holds a single integer
// The result is undefined if this NestedInteger holds a nested list
// So before calling this method, you should have a check
func (this NestedInteger) GetInteger() int {
	return 0
}

// Set this NestedInteger to hold a single integer.
func (n *NestedInteger) SetInteger(value int) {}

// Set this NestedInteger to hold a nested list and adds a nested integer to it.
func (this *NestedInteger) Add(elem NestedInteger) {}

// Return the nested list that this NestedInteger holds, if it holds a nested list
// The list length is zero if this NestedInteger holds a single integer
// You can access NestedInteger's List element directly if you want to modify it
func (this NestedInteger) GetList() []*NestedInteger {
	return nil
}

// code ==============================================

// perf: 13.48, 88

type NestedIterator [][]*NestedInteger

func Constructor(nestedList []*NestedInteger) *NestedIterator {
	var iter NestedIterator
	iter = append(iter, nestedList)
	this := &iter
	// rearrange the list
	for {
		if len(*this) == 0 {
			break
		}
		if len((*this)[len(*this)-1]) == 0 {
			*this = (*this)[:len(*this)-1]
			continue
		}
		if (*this)[len(*this)-1][0].IsInteger() {
			break
		} else {
			temp := (*this)[len(*this)-1][0].GetList()
			(*this)[len(*this)-1] = (*this)[len(*this)-1][1:]
			*this = append(*this, temp)
		}
	}
	return this
}

func (this *NestedIterator) Next() int {
	// pop out the next
	temp := (*this)[len(*this)-1][0].GetInteger()
	(*this)[len(*this)-1] = (*this)[len(*this)-1][1:]
	// rearrange the list
	for {
		if len(*this) == 0 {
			break
		}
		if len((*this)[len(*this)-1]) == 0 {
			*this = (*this)[:len(*this)-1]
			continue
		}
		if (*this)[len(*this)-1][0].IsInteger() {
			break
		} else {
			temp := (*this)[len(*this)-1][0].GetList()
			(*this)[len(*this)-1] = (*this)[len(*this)-1][1:]
			*this = append(*this, temp)
		}
	}
	return temp
}

func (this *NestedIterator) HasNext() bool {
	return len(*this) > 0
}
