package main

import "unicode"

// s contains numbers, +, -, (, ) and spaces, it's guaranteed valid.
func calculate(s string) int {
	return t224(s)
}

// perf: 0ms, 97
// time: n
// space: n
func t224(s string) int {
	stack := []int{0}
	sign := []rune{'+'}
	for i := 0; i < len(s); {
		if s[i] == ' ' {
			i++
			continue
		}
		if s[i] == '(' {
			stack = append(stack, 0)
			sign = append(sign, '+')
			i++
		} else if s[i] == ')' {
			if sign[len(sign)-2] == '+' {
				stack[len(stack)-2] += stack[len(stack)-1]
			} else {
				stack[len(stack)-2] -= stack[len(stack)-1]
			}
			stack = stack[:len(stack)-1]
			sign = sign[:len(sign)-1]
			sign[len(sign)-1] = '+'
			i++
		} else if s[i] == '+' {
			sign[len(sign)-1] = '+'
			i++
		} else if s[i] == '-' {
			sign[len(sign)-1] = '-'
			i++
		} else { // encounter a number
			val := 0
			for i < len(s) && unicode.IsDigit(rune(s[i])) {
				val *= 10
				val += int(s[i] - '0')
				i++
			}
			if sign[len(sign)-1] == '-' {
				stack[len(stack)-1] -= val
				sign[len(sign)-1] = '+'
			} else {
				stack[len(stack)-1] += val
			}
		}
	}
	return stack[0]
}

func main() {

}
