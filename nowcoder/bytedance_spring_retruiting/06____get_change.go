package main

import "fmt"

// 4ms, 1000KB
func sln6(money int) (minCoin int) {
	// money is in range [0, 1023]

	coins := []int{64, 16, 4, 1}
	for _, coin := range coins {
		minCoin += money / coin
		money %= coin
	}
	return
}

func main() {
	var used int
	fmt.Scanf("%d", &used)
	remain := 1024 - used
	minCoin := sln6(remain)
	fmt.Printf("%d\n", minCoin)
}
