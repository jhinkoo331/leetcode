package main

func numWays(steps int, arrLen int) int {
	return o1269(steps, arrLen)
}

// time: steps^2
// space: arrLen
// perf: 4ms, 87, 87
func o1269(steps int, arrLen int) int {
	if arrLen > steps/2+1 {
		arrLen = steps/2 + 1
	}
	var mod int = 1e9 + 7
	count := make([]int, arrLen+2, arrLen+2)
	count[1] = 1
	for i := 0; i < steps; i++ {
		// fmt.Println(count)
		temp := make([]int, arrLen+2, arrLen+2)
		for i := range count {
			temp[i] = count[i]
		}
		for i := 1; i <= arrLen; i++ {
			count[i] += temp[i-1]
			if count[i] > mod {
				count[i] -= mod
			}
			count[i] += temp[i+1]
			if count[i] > mod {
				count[i] -= mod
			}
		}
	}
	return count[1]
}
