package main

func maxPoints(points [][]int) int {
	return o149(points)
}

// perf: 100, 97
func o149(points [][]int) (ans int) {
	if len(points) < 3 {
		return len(points)
	}

	checked := make([][]bool, len(points), len(points))
	for i := range checked {
		checked[i] = make([]bool, len(points), len(points))
	}
	for i := range points {
		for ii := i + 1; ii < len(points); ii++ {
			if checked[i][ii] {
				continue
			}
			checked[i][ii] = true
			temp_max := 2
			for iii := ii + 1; iii < len(points); iii++ {
				if o149_on_one_line(points[i], points[ii], points[iii]) {
					temp_max++
					checked[i][iii] = true
					checked[ii][iii] = true
				}
			}
			if temp_max > ans {
				ans = temp_max
			}
		}
	}
	return ans
}

func o149_on_one_line(a, b, c []int) bool {
	return (a[0]-b[0])*(b[1]-c[1]) == (b[0]-c[0])*(a[1]-b[1])
}

func main() {

}
