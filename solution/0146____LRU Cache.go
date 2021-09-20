package main

// perf: 26, 7
type LRUCache struct {
	cap int
	len int
	// the latest accessed node is tail.prev
	head, tail *LRUCache_node
	m          map[int]*LRUCache_node
}

type LRUCache_node struct {
	key, value int
	prev, next *LRUCache_node
}

func Constructor(capacity int) LRUCache {

	temp := LRUCache{}
	temp.cap = capacity
	temp.len = 0
	temp.head = &LRUCache_node{}
	temp.tail = &LRUCache_node{}
	temp.head.next = temp.tail
	temp.tail.prev = temp.head
	temp.m = make(map[int]*LRUCache_node)
	return temp
}

func (this *LRUCache) Get(key int) int {
	v, ok := this.m[key]
	if !ok {
		return -1
	}
	// move the node
	v.prev.next = v.next
	v.next.prev = v.prev
	v.prev = this.tail.prev
	v.next = this.tail
	v.prev.next = v
	v.next.prev = v

	return v.value
}

func (this *LRUCache) Put(key int, value int) {

	v, ok := this.m[key]
	if ok {
		v.prev.next = v.next
		v.next.prev = v.prev
		this.len -= 1
	}

	temp := &LRUCache_node{key, value, this.tail.prev, this.tail}
	this.m[key] = temp
	this.tail.prev.next = temp
	this.tail.prev = temp
	this.len += 1
	if this.len > this.cap {
		this.len -= 1
		delete(this.m, this.head.next.key)
		this.head = this.head.next
	}
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * obj := Constructor(capacity);
 * param_1 := obj.Get(key);
 * obj.Put(key,value);
 */

func main() {
	t := __Constructor(2)
	t.Put(1, 1)
	t.Put(2, 2)
	t.Get(1)
	t.Put(3, 3)
	t.Get(2)
	t.Put(4, 4)
	t.Get(2)
	t.Get(3)
	t.Get(4)
}
