package baidu

// be happy, be confident.

// be happy, be confident.
type cell struct {
	left, up int
	total    int
}

func sln3(n, m int) int {
	mod := int(1e9 + 7)
	grid := make([][]cell, n, n)
	for i := range grid {
		grid[i] = make([]cell, m, m)
	}
	grid[0][0] = cell{
		left:  0,
		up:    0,
		total: 1,
	}
	for row := 0; row < n; row += 1 {
		for col := 0; col < m; col += 1 {
			// upside
			if row-1 >= 0 {
				grid[row][col].up = grid[row-1][col].total
			}
			if row-2 >= 0 {
				grid[row][col].up = (grid[row][col].up + grid[row-2][col].up) % mod
			}
			// left side
			if col-1 >= 0 {
				grid[row][col].left = grid[row][col-1].total
			}
			if col-2 >= 0 {
				grid[row][col].left = (grid[row][col].left + grid[row][col-2].left) % mod
			}
			grid[row][col].total = (grid[row][col].left + grid[row][col].up + grid[row][col].total) % mod
		}
	}
	return grid[n-1][m-1].total
}
