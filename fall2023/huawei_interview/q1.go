package main

// be happy, be confident.

// n*n matrix, 每一个点的值0或者1, 0代表海洋, 1代表陆地, 可以走动, 计算步数
// 求: 距离陆地最远的海洋, 求距离

func q1(matrix [][]int) int {
	if len(matrix) == 0 || len(matrix[0]) == 0 {
		panic("invalid map")
	}
	updated := true
	for curStep := 2; updated == true; curStep += 1 {
		updated = false
		for row := 0; row < len(matrix); row += 1 {
			for col := 0; col < len(matrix[0]); col += 1 {
				// 处理所有当前到达的点
				if matrix[row][col] == curStep-1 { // 当前位置不是海洋
					if validLocation(matrix, row-1, col) {
						if matrix[row-1][col] == 0 {
							updated = true
							matrix[row-1][col] = curStep
						}
					}
					if validLocation(matrix, row+1, col) {
						if matrix[row+1][col] == 0 {
							updated = true
							matrix[row+1][col] = curStep
						}
					}
					if validLocation(matrix, row, col-1) {
						if matrix[row][col-1] == 0 {
							updated = true
							matrix[row][col-1] = curStep
						}
					}
					if validLocation(matrix, row, col+1) {
						if matrix[row][col+1] == 0 {
							updated = true
							matrix[row][col+1] = curStep
						}
					}
				}
			}
		}
	}
	max := -1
	for _, row := range matrix {
		for _, val := range row {
			if val > max {
				max = val
			}
		}
	}
	if max == 0 {
		panic("no island")
	}
	return max - 1
}

func validLocation(matrix [][]int, row, col int) bool {
	if len(matrix) == 0 {
		return false
	}
	if row < 0 || row >= len(matrix) {
		return false
	}
	if col < 0 || col >= len(matrix[0]) {
		return false
	}
	return true
}

func main() {
	matrix := [][]int{
		{1, 0, 0, 0, 0},
		{0, 0, 0, 0, 0},
		{0, 0, 1, 0, 0},
		{0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0},
	}
	ans := q1(matrix)
	println(ans)
}
