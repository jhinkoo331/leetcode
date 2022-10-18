package main

import (
	"fmt"
	"strconv"
)

// The worst of the journey is still to come

func flip(i, x int) int {
	s := strconv.Itoa(i)
	ss := []rune(s)
	for i, j := 0, x-1; i < j; i, j = i+1, j-1 {
		ss[i], ss[j] = ss[j], ss[i]
	}
	s = string(ss)
	ans, _ := strconv.ParseInt(s, 10, 32)
	return int(ans)
}

func main() {
	//println(flip(12345, 2))
	var n, k int
	fmt.Scan(&n, &k)
	fmt.Printf("%d", flip(n, k))
}
