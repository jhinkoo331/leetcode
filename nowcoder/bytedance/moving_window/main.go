package main

import (
	"fmt"
)

// https://www.nowcoder.com/question/next?pid=16516564&qid=362290&tid=61641104

// be happy, be confident.

func sln(buildings []int, maxDistance int) int {
	ans := 0
	mod := 99997867
	left, right := 0, 0
	for left < len(buildings) {
		// try moving right to the right-most location
		for right < len(buildings)-1 && buildings[right+1]-buildings[left] <= maxDistance {
			right += 1
		}
		if temp := right - left; temp >= 2 {
			temp = temp * (temp - 1) / 2
			ans = (ans + temp) % mod
		}
		left += 1
	}
	return ans
}

func main() {
	var building, maxDistance int
	fmt.Scan(&building, &maxDistance)
	buildingArray := make([]int, building, building)
	for i := range buildingArray {
		fmt.Scan(&buildingArray[i])
	}
	fmt.Println(sln(buildingArray, maxDistance))
}
