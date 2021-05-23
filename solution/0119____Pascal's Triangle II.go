package main

func getRow(rowIndex int) []int {
	return o119(rowIndex)
}

// perf: 0ms, 100
// time: n
// space: 1
func o119(rowIndex int) (ans []int) {
	ans = make([]int, rowIndex+1, rowIndex+1)
	ans[0], ans[rowIndex] = 1, 1
	for i := 1; i < rowIndex; i++ {
		ans[i] = ans[i-1] * (rowIndex - i + 1) / i
	}
	return ans
}
