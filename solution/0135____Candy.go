package main

func candy(ratings []int) int {
	return o135(ratings)
}

// perf: 5, 72
func o135(ratings []int) (ret int) {
	if len(ratings) == 1 {
		return 1
	}
	ans := make([]int, len(ratings))
	index := make(map[int]bool)
	for i := range ratings {
		index[i] = true
	}
	for len(index) != 0 {
		for i := range index {
			if i == 0 {
				if ratings[i] <= ratings[i+1] {
					ans[i] = 1
					delete(index, i)
				} else if ans[1] != 0 {
					ans[0] = ans[1] + 1
					delete(index, i)
				}
			} else if i == len(ratings)-1 {
				if ratings[len(ratings)-2] >= ratings[len(ratings)-1] {
					ans[len(ratings)-1] = 1
					delete(index, i)
				} else if ans[len(ratings)-2] != 0 {
					ans[len(ratings)-1] = ans[len(ratings)-2] + 1
					delete(index, i)
				}
			} else {
				var left, right int
				if ratings[i-1] >= ratings[i] {
					left = 1
				} else if ans[i-1] != 0 {
					left = ans[i-1] + 1
				} else {
					continue
				}
				if ratings[i] <= ratings[i+1] {
					right = 1
				} else if ans[i+1] != 0 {
					right = ans[i+1] + 1
				} else {
					continue
				}
				if left > right {
					ans[i] = left
				} else {
					ans[i] = right
				}
				delete(index, i)
			}
		}
	}
	for _, num := range ans {
		ret += num
	}
	return ret
}

func main() {
	candy([]int{1, 0, 2})
}
