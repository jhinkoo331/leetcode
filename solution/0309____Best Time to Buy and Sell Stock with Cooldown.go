package main

// time: n*n
// space: n
// perf: 22, 24
func _0309(prices []int) int {
	maxProfit := make([]int, len(prices)+2) // @why there are two blank spaces at rear?
	for purchaseDate := len(prices) - 2; purchaseDate >= 0; purchaseDate-- {
		maxProfit[purchaseDate] = maxProfit[purchaseDate+1]
		for sellDate := purchaseDate + 1; sellDate < len(prices); sellDate++ {
			profit := prices[sellDate] - prices[purchaseDate] + maxProfit[sellDate+2]
			if maxProfit[purchaseDate] < profit {
				maxProfit[purchaseDate] = profit
			}
		}
	}
	return maxProfit[0]
}

// There should be at least one day between two complete transactions...
// ...which is the so-called COOL DOWN.
func maxProfit(prices []int) int {
	return _0309(prices)
}

func main() {

}
