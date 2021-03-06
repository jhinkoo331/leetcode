package main

import "strings"

func defangIPaddr(address string) string {
	return o1108(address)
}

// perf: 0ms, 35
func o1108(address string) string {
	var sb strings.Builder
	for _, r := range address {
		if r == '.' {
			sb.WriteString("[.]")
		} else {
			sb.WriteRune(r)
		}
	}
	return sb.String()
}

func main() {

}
