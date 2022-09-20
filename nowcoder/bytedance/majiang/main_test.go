package main

import (
	"fmt"
	"testing"
)

// be happy, be confident.

func Test1(t *testing.T) {
	ok := sln([]int{1, 1, 1, 2, 2, 2, 5, 5, 5, 6, 6, 6, 9})
	ok = sln([]int{1, 1, 1, 1, 2, 2, 3, 3, 5, 6, 7, 8, 9})
	ok = sln([]int{1, 1, 1, 2, 2, 2, 3, 3, 3, 5, 7, 7, 9})
	fmt.Printf("%v", ok)
}
