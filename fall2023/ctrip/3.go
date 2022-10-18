package main

import (
	"fmt"
)

// The worst of the journey is still to come

func three(begin, target, left, right int) (less, more int) {
	target -= begin
	if target == 0 {
		return 0, 0
	}

	less = target / right
	if target%right != 0 {
		less += 1
		if temp := left * less; temp > target {
			return -1, -1
		}
	}

	more = target / left
	return less, more
}

func main() {
	var case_ int
	fmt.Scan(&case_)
	for i := 0; i < case_; i += 1 {
		var begin, target, left, right int
		fmt.Scan(&begin, &target, &left, &right)
		less, more := three(begin, target, left, right)
		if less == -1 {
			fmt.Printf("-1\n")
		} else {
			fmt.Printf("%d %d\n", less, more)
		}
	}
}
