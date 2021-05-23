package main

func solveSudoku(board [][]byte) {
	_0037(board)
}

var row [9][10]byte
var col [9][10]byte
var grid [3][3][10]byte

// perf: 0ms, 84
func _0037(board [][]byte) {
	for i := range row {
		for j := range row[i] {
			row[i][j] = 0
			col[i][j] = 0
		}
	}
	for i := range grid {
		for j := range grid[i] {
			for k := range grid[i][j] {
				grid[i][j][k] = 0
			}
		}
	}

	for i := range board {
		for j := range board[i] {
			if board[i][j] == '.' {
				continue
			} else {
				num := byte(board[i][j] - '0')
				row[i][num] = 1
				col[j][num] = 1
				grid[i/3][j/3][num] = 1
			}
		}
	}
	_0037_helper(board, 0, 0)
}

func _0037_helper(board [][]byte, r, c int) bool {
	if c == 9 {
		r++
		c = 0
	}
	if r == 9 {
		return true
	}

	if board[r][c] == '.' {
		for i := 1; i < 10; i++ {
			if row[r][i] == 1 {
				continue
			} else if col[c][i] == 1 {
				continue
			} else if grid[r/3][c/3][i] == 1 {
				continue
			}

			row[r][i] = 1
			col[c][i] = 1
			grid[r/3][c/3][i] = 1
			board[r][c] = byte(i) + '0'

			// search deeper
			if _0037_helper(board, r, c+1) {
				return true
			} else {
				row[r][i] = 0
				col[c][i] = 0
				grid[r/3][c/3][i] = 0
				board[r][c] = '.'
				continue
			}
		}
		return false
	} else {
		return _0037_helper(board, r, c+1)
	}
}

func main() {
	board := [][]byte{
		{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
		{'6', '.', '.', '1', '9', '5', '.', '.', '.'},
		{'.', '9', '8', '.', '.', '.', '.', '6', '.'},
		{'8', '.', '.', '.', '6', '.', '.', '.', '3'},
		{'4', '.', '.', '8', '.', '3', '.', '.', '1'},
		{'7', '.', '.', '.', '2', '.', '.', '.', '6'},
		{'.', '6', '.', '.', '.', '.', '2', '8', '.'},
		{'.', '.', '.', '4', '1', '9', '.', '.', '5'},
		{'.', '.', '.', '.', '8', '.', '.', '7', '9'},
	}
	solveSudoku(board)
	return
}
