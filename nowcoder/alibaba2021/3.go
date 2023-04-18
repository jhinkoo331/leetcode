package main

import "fmt"

var tab3 [][]int

func test3() {

	println(sln3(0, 0))
	println(sln3(0, 1))
	println(sln3(0, 2))
	println("--------")

	println(sln3(1, 0))
	println(sln3(1, 1))
	println(sln3(1, 2))
	println(sln3(1, 3))
	println("--------")

	println(sln3(2, 0))
	println(sln3(2, 1))
	println(sln3(2, 2))
	println(sln3(2, 3))
	println(sln3(2, 4))
	println("--------")

	println(sln3(3, 0))
	println(sln3(3, 1))
	println(sln3(3, 2))
	println(sln3(3, 3))
	println(sln3(3, 4))
	println(sln3(3, 5))
	println(sln3(3, 6))

}

func sln3(n, h int) int {
	tab3 = make([][]int, n+1)
	for i := range tab3 {
		tab3[i] = make([]int, h+1)
	}
	ans := getnh(n, h)
	return ans
}

func invalidNh(n, h int) bool {
	if n >= 1<<h {
		return true
	}
	return false
}

// time out for input [50, 50]

// func getnh(n, h int) int {
// 	if invalidNh(n, h) {
// 		return 0
// 	}
// 	ans := 0
// 	if n == 0 {
// 		return 1
// 	}
// 	for left, right := 0, n-1; left < n; left, right = left+1, right-1 {
// 		ans += getnh(left, h-1) * getnh(right, h-1)
// 		ans %= 1e9 + 7
// 	}
// 	tab3[n][h] = ans
// 	return ans
// }

// run time: 4ms
func getnh(n, h int) int {
	if invalidNh(n, h) {
		return 0
	}
	ans := 0
	if n == 0 {
		return 1
	}
	if n == 1 {
		return 1
	}
	if tab3[n][h] > 0 { // this line get answer from cache
		return tab3[n][h]
	}

	// println(n, h)		// we find duplicate calculation from this line
	for left, right := 0, n-1; left < n; left, right = left+1, right-1 {
		ans += getnh(left, h-1) * getnh(right, h-1)
		ans %= 1e9 + 7
	}
	tab3[n][h] = ans
	return ans
}

func main() {
	// test3()
	var n, h int
	fmt.Scanf("%d %d", &n, &h)
	fmt.Printf("%d\n", sln3(n, h))
}
