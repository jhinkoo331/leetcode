package main

func solveSudoku(board [][]byte) {

}

var row [9][10]byte
var col [9][10]byte
var grid [3][3][10]byte

func _0037(board [][]byte) {
        for i := range board {
                for j := range board {
                        num := board[i][j]
                        row[i][num] = 1
                        col[j][num] = 1
                        grid[i / 3][j / 3][num] = 1
                }
        }
}

func main() {
	
}
