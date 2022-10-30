package main

// The worst of the journey is still to come

// 4ms, 20
func matrixReshape(mat [][]int, r int, c int) (ans [][]int) {
	// 1. make sure that input is valid, if not, return the original matrix
	// 2. make an underlying buff, which holds all the numbers
	// 3. cut the buff into r slices of length c, put them into the new matrix
	if len(mat)*len(mat[0]) != r*c {
		return mat
	}
	buf := make([]int, 0, len(mat)*len(mat[0]))
	for _, row := range mat {
		for _, num := range row {
			buf = append(buf, num)
		}
	}
	for i := 0; i < len(buf); i += c {
		ans = append(ans, buf[i:i+c])
	}
	return ans
}
