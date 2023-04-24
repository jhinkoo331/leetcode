package main

import (
	"fmt"

	"github.com/sirupsen/logrus"
)

// moving window
func sln3(loc []int, maxDistance int) (ans int) {
	mod := 99997867
	var left, right int
	for true {
		if left >= len(loc) {
			break
		}
		// keep moving `right`
		for right+1 < len(loc) && loc[right+1]-loc[left] <= maxDistance {
			right++
		}
		if tmp := right - left; tmp > 1 {
			logrus.Info("left, right: ", left, right)
			tmp = tmp * (tmp - 1) / 2
			ans += tmp
			if ans > mod {
				ans %= mod
			}
		}
		left++
	}
	return ans
}

func test3() {
	println(sln3([]int{1, 2, 3, 4}, 3))
	println(sln3([]int{1, 10, 20, 30}, 19))
	println(sln3([]int{1, 102}, 100))
}

func main() {
	test3()
	var locCount, maxDistance int
	fmt.Scanf("%d %d", &locCount, &maxDistance)
	loc := make([]int, locCount)
	for i := range loc {
		fmt.Scanf("%d", &loc[i])
	}
	ans := sln3(loc, maxDistance)
	fmt.Printf("%d\n", ans)
}
