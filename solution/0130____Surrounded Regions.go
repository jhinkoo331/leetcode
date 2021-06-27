package main

func solve(board [][]byte) {
	o130(board)
}

// perf: 89, 55
func o130(board [][]byte) {

	// the top row
	for ii := range board[0] {
		if board[0][ii] == 'O' {
			o130_helper(board, 0, ii)
		}
	}
	// the bottom row
	for ii := range board[0] {
		if board[len(board)-1][ii] == 'O' {
			o130_helper(board, len(board)-1, ii)
		}
	}
	// left column
	for i := range board {
		if board[i][0] == 'O' {
			o130_helper(board, i, 0)
		}
	}
	// right column
	for i := range board {
		if board[i][len(board[0])-1] == 'O' {
			o130_helper(board, i, len(board[0])-1)
		}
	}

	o130_hh(board)
}

func o130_helper(board [][]byte, i, ii int) {

	board[i][ii] = 'o'
	if i-1 >= 0 && board[i-1][ii] == 'O' {
		o130_helper(board, i-1, ii)
	}
	if i+1 < len(board) && board[i+1][ii] == 'O' {
		o130_helper(board, i+1, ii)
	}
	if ii-1 >= 0 && board[i][ii-1] == 'O' {
		o130_helper(board, i, ii-1)
	}
	if ii+1 < len(board[0]) && board[i][ii+1] == 'O' {
		o130_helper(board, i, ii+1)
	}
}

func o130_hh(board [][]byte) {

	for i := range board {
		for ii := range board[i] {
			if board[i][ii] == 'o' {
				board[i][ii] = 'O'
			} else if board[i][ii] == 'O' {
				board[i][ii] = 'X'
			}
		}
	}
}

func main() {

}
