package main

import "fmt"

// 0ms, 100
func hammingDistance(x int, y int) int {
	x = x ^ y
	y = 1 // take y as mask
	var ans int = 0
	for y != 0 {
		if (x & y) != 0 {
			ans++
		}
		y <<= 1
	}
	return ans
}

func main() {
	var i int = 1
	for true {
		i <<= 1
		fmt.Println("%d", i)
	}
	return
}
