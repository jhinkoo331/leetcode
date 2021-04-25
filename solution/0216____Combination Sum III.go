package main

func combinationSum3(k int, n int) [][]int {
	return _1(k, n)
}

//var ans [][]int
//var trace []int

func _1(k, n int) [][]int {
	ans = [][]int{}
	trace = []int{}
	dfs(k, n, 1)
	return ans
}

// perf: 0ms, 13
func dfs(k, n, next int) {
	if k == 0 {
		if n == 0 {
			temp := make([]int, len(trace), len(trace))
			copy(temp, trace)
			ans = append(ans, temp)
			// fmt.Println("found: %v, %v", trace, temp)
		} else {

		}
	} else {
		for ; next <= n && next < 10; next++ {
			trace = append(trace, next)
			dfs(k-1, n-next, next+1)
			trace = trace[:len(trace)-1]
		}
	}
}
