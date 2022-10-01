package main

var ans241 []int

// perf: 82%, 94%
func numSquares(n int) int {
	initAns241()
	return ans241[n]
}

func initAns241() {
	if len(ans241) > 0 {
		return
	}
	ans241 = make([]int, 1e4+1, 1e4+1)
	for i := 1; i <= 100; i += 1 {
		ans241[i*i] = 1
	}
	for i := 2; i <= 1e4; i += 1 {
		if ans241[i] == 1 {
			continue
		}
		curMin := i
		for left, right := 1, i-1; left <= right; left, right = left+1, right-1 {
			if temp := ans241[left] + ans241[right]; temp < curMin {
				curMin = temp
			}
		}
		ans241[i] = curMin
	}
}
