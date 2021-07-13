package main

func gameOfLife(board [][]int) {
	t289(board)
}

// the least significant bit stands for original value, 0 or 1
// the bit left to the least significant bit stands for new value
// perf: 0ms, 16
// time: m*n
// space: in-place
func t289(board [][]int) {
	for i := range board {
		for j := range board[i] {
			live_neighbors := t289_get_live_neighbors(board, i, j)
			if board[i][j]&1 == 1 {
				if live_neighbors == 2 || live_neighbors == 3 {
					// live element with 2 or 3 live neighbors lives on to the next generation
					board[i][j] += 2
				}
			} else if live_neighbors == 3 {
				board[i][j] ^= 2
			}

		}
	}
	for i := range board {
		for j := range board[i] {
			board[i][j] >>= 1
		}
	}
}

func t289_get_live_neighbors(board [][]int, i, ii int) (count int) {
	if i > 0 {
		if ii > 0 && board[i-1][ii-1]&1 == 1 {
			count++
		}
		if board[i-1][ii]&1 == 1 {
			count++
		}
		if ii < len(board[0])-1 && board[i-1][ii+1]&1 == 1 {
			count++
		}
	}
	if i < len(board)-1 {
		if ii > 0 && board[i+1][ii-1]&1 == 1 {
			count++
		}
		if board[i+1][ii]&1 == 1 {
			count++
		}
		if ii < len(board[0])-1 && board[i+1][ii+1]&1 == 1 {
			count++
		}
	}
	if ii > 0 && board[i][ii-1]&1 == 1 {
		count++
	}
	if ii < len(board[0])-1 && board[i][ii+1]&1 == 1 {
		count++
	}
	return count
}

func main() {
	gameOfLife([][]int{{1, 1}, {1, 0}})
}
