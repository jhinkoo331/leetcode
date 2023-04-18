package main

import "fmt"

// perf: 9ms, 1KB
func fixString(s string) string {
	ss := make([]rune, 0, len(s))
	for _, r := range s {
		if len(ss) >= 2 && ss[len(ss)-1] == ss[len(ss)-2] && ss[len(ss)-1] == r {
			continue
		}
		if len(ss) >= 3 && ss[len(ss)-1] == r && ss[len(ss)-2] == ss[len(ss)-3] {
			continue
		}
		ss = append(ss, r)
	}
	return string(ss)
}

func fixStringTest() {
	ss := [][]string{
		{"helllo", "hello"},
		{"helloo", "hello"},
	}
	for i, s := range ss {
		println(s[0], s[1], fixString(s[0]))
		if s[1] != fixString(s[0]) {
			println("error at", i)
		}
	}
}

func main() {
	// fixStringTest()
	var n int
	fmt.Scanf("%d", &n)
	for i := 0; i < n; i++ {
		var s string
		fmt.Scanf("%s", &s)
		fmt.Printf("%s\n", fixString(s))
	}
}
