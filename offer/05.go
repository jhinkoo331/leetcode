package main

import "strings"

// perf: 100, 66
func _05(s string) string {
	var sb strings.Builder
	for _, char := range s {
		if char == ' ' {
			sb.WriteString("%20")
		} else {
			sb.WriteRune(char)
		}
	}
	return sb.String()
}

// TODO: this problem should be solved with c or cpp, for strings are modifiable in those languages
func replaceSpace(s string) string {
	return _05(s)
}
