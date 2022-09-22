package main

import (
	"fmt"
)

// be happy, be confident.

const (
	Space   = '.'
	Invalid = 'X'
	Jump    = 'S'
)

var m, n int
var board [][]rune
var visited [][]bool

func sln2() (bool, int) {
	//visited[0][0] = true
	ok, step := search(0, 0)
	return ok, step
}

func search(i, j int) (bool, int) {
	if i < 0 || i >= m || j < 0 || j >= n {
		return false, 0
	}
	if i == m-1 && j == n-1 {
		return true, 0
	}
	if visited[i][j] == true {
		return false, 0
	} else {
		visited[i][j] = true
		defer func() {
			visited[i][j] = false
		}()
	}
	if board[i][j] == Space {
		ok1, step1 := search(i-1, j)
		ok2, step2 := search(i+1, j)
		ok3, step3 := search(i, j-1)
		ok4, step4 := search(i, j+1)
		ok, min := findBest([]struct {
			bool
			int
		}{
			{ok1, step1},
			{ok2, step2},
			{ok3, step3},
			{ok4, step4},
		})
		return ok, min + 1
	} else if board[i][j] == Invalid {
		return false, 0
	} else if board[i][j] == Jump {
		ok1, step1 := search(i-1, j)
		ok2, step2 := search(i+1, j)
		ok3, step3 := search(i, j-1)
		ok4, step4 := search(i, j+1)

		ok5, step5 := search(i-2, -1)
		step5 += 1
		ok6, step6 := search(i-1, j-2)
		step6 += 1
		ok7, step7 := search(i+2, j-1)
		step7 += 1
		ok8, step8 := search(i+1, j-2)
		step8 += 1
		ok9, step9 := search(i-2, j+1)
		step9 += 1
		oki, stepi := search(i-1, j+2)
		stepi += 1
		okii, stepii := search(i+2, j+1)
		stepii += 1
		okiii, stepiii := search(i+1, j+2)
		stepiii += 1
		ok, min := findBest([]struct {
			bool
			int
		}{
			{ok1, step1},
			{ok2, step2},
			{ok3, step3},
			{ok4, step4},

			{ok5, step5},
			{ok6, step6},
			{ok7, step7},
			{ok8, step8},
			{ok9, step9},
			{oki, stepi},
			{okii, stepii},
			{okiii, stepiii},
		})
		return ok, min + 1
	} else {
		panic("unreachable")
	}
}

func findBest(arr []struct {
	bool
	int
}) (bool, int) {
	var ok_arr []struct {
		bool
		int
	}
	for _, pair := range arr {
		if pair.bool {
			ok_arr = append(ok_arr, pair)
		}
	}
	if len(ok_arr) == 0 {
		return false, 0
	}
	min := ok_arr[0].int
	for _, pair := range ok_arr {
		if pair.int < min {
			min = pair.int
		}
	}
	return true, min
}

func main() {
	fmt.Scan(&m, &n)
	board = make([][]rune, m, m)
	for i := range board {
		board[i] = make([]rune, n, n)
	}
	visited = make([][]bool, m, m)
	for i := range visited {
		visited[i] = make([]bool, n, n)
	}
	for row := 0; row < m; row += 1 {
		var s string
		fmt.Scan(&s)
		for i, r := range s {
			board[row][i] = r
		}
	}
	_, step := sln2()
	fmt.Println(step)
}
