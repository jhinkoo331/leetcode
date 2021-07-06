package main

import "math"

func maximalRectangle(matrix [][]byte) int {
	return e85(matrix)
}

// time: m*m*n when matrix.shape = (m, n)
// perf: 25, 93
func e85(matrix [][]byte) (max int) {

	if len(matrix) == 0 {
		return 0
	}
	top_row := make([]int, len(matrix[0]), len(matrix[0]))
	for _, row := range matrix {
		for i := range row {
			for ii := i; ii < len(row); ii++ {
				if row[ii] == '0' {
					break
				}
				top_row_min := math.MaxInt32
				for iii := i; iii <= ii; iii++ {
					if top_row[iii] < top_row_min {
						top_row_min = top_row[iii]
					}
				}
				if area := (top_row_min + 1) * (ii - i + 1); area > max {
					max = area
				}
			}
		}
		// update top_row
		for i, v := range row {
			if v == '0' {
				top_row[i] = 0
			} else {
				top_row[i]++
			}
		}
	}
	return max
}

func main() {

}
