package main

var t279_ps map[int]bool
var t279_ans map[int]int

func numSquares(n int) int {
	return t279(n)
}

func t279(n int) int {
	if t279_ps == nil {
		t279_ps = make(map[int]bool)
		for i := 0; i <= 100; i++ {
			t279_ps[i*i] = true
		}
	}
	if t279_ans == nil {
		t279_ans = make(map[int]int)
	}
	return t279_helper(n)
}

func t279_helper(n int) (ans int) {
	ans = 10000000000
	if _, ok := t279_ps[n]; ok {
		t279_ans[n] = 1
		return 1
	}
	left, right := 1, n-1
	for ; left <= right; left, right = left+1, right-1 {
		temp := t279_helper(left) + t279_helper(right)
		if temp < ans {
			ans = temp
		}
	}
	t279_ans[n] = ans
	return ans
}

func main() {

}
