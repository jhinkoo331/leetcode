package main

import "fmt"

type pair4 struct {
	x, y int
}

// 5ms, one pass
// handle I/O insde `sln` to reduce memory consumption
func sln4() int {
	var ans int
	var frameCount int
	fmt.Scanf("%d", &frameCount)
	var lastFrame, curFrame map[pair4]int
	lastFrame, curFrame = make(map[pair4]int), make(map[pair4]int)
	for i := 0; i < frameCount; i++ {
		var curFrameFeatureCount int
		fmt.Scanf("%d", &curFrameFeatureCount)
		for i := 0; i < curFrameFeatureCount; i++ {
			var f pair4
			fmt.Scanf("%d %d", &f.x, &f.y)
			t := lastFrame[f] + 1
			curFrame[f] = t
			if t > ans {
				ans = t
			}
		}
		lastFrame = curFrame
		curFrame = make(map[pair4]int)
	}
	return ans
}

func main() {
	var testCount int
	fmt.Scanf("%d", &testCount)
	for i := 0; i < testCount; i++ {
		ans := sln4()
		fmt.Printf("%d\n", ans)
	}
}
