package main

// The worst of the journey is still to come

// perf: 80, 62
func constructArr(a []int) []int {
	var zeroCount, lastZeroIndex int
	totalProduct := 1
	for i, v := range a {
		if v == 0 {
			zeroCount += 1
			lastZeroIndex = i
		} else {
			totalProduct *= v
		}
	}
	b := make([]int, len(a), len(a))
	if zeroCount == 0 {
		for i := range b {
			b[i] = totalProduct / a[i]
		}
	} else if zeroCount == 1 {
		b[lastZeroIndex] = totalProduct
	}
	return b
}
