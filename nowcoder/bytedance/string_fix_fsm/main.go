package main

import (
	"fmt"
)

// be happy, be confident.

type State uint

const (
	Start State = iota
	X
	XX
	XXY
)

func fixString(s string) string {
	curState := Start
	var newString []rune
	var lastChar rune
	for _, c := range s {
		switch curState {
		case Start:
			newString = append(newString, c)
			curState = X
		case X:
			if c == lastChar {
				newString = append(newString, c)
				curState = XX
			} else {
				newString = append(newString, c)
			}
		case XX:
			if c == lastChar {
				continue
			} else {
				newString = append(newString, c)
				curState = XXY
			}
		case XXY:
			if c == lastChar {
				continue
			} else {
				newString = append(newString, c)
				curState = X
			}
		default:
			panic("invalid state")
		}
		lastChar = c
	}
	return string(newString)
}

func main() {
	var n int
	fmt.Scan(&n)
	for i := 0; i < n; i += 1 {
		var s string
		fmt.Scan(&s)
		ss := fixString(s)
		fmt.Println(ss)
	}
	return
}
