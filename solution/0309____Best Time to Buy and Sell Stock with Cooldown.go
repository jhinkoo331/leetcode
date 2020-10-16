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

// Evolved from _0309, try to reduce calculation
// perf: no difference
func __0309(prices []int) int {
	maxProfit := make([]int, len(prices)+2) // @why there are two blank spaces at rear?
	for purchaseDate := len(prices) - 2; purchaseDate >= 0; purchaseDate-- {
		maxProfit[purchaseDate] = maxProfit[purchaseDate+1]
		sellPrice := prices[purchaseDate]
		for sellDate := purchaseDate + 1; sellDate < len(prices); sellDate++ {
			if sellPrice < prices[sellDate] {
				sellPrice = prices[sellDate]
				profit := sellPrice - prices[purchaseDate] + maxProfit[sellDate+2]
				if maxProfit[purchaseDate] < profit {
					maxProfit[purchaseDate] = profit
				}
			}
		}
	}
	return maxProfit[0]
}

// use a stack to reduce calculation
// perf: 0ms, 24

func ___0309(prices []int) int {
	maxProfit := make([]int, len(prices)+2) // @why there are two blank spaces at rear?
	var stack []int                         // the stack is decreasing in both price and data
	for purchaseDate := len(prices) - 1; purchaseDate >= 0; purchaseDate-- {
		// update the stack
		for len(stack) != 0 && prices[stack[len(stack)-1]] <= prices[purchaseDate] {
			stack = stack[:len(stack)-1] // pop out the last element
		}
		// update maxProfit[purchaseDate] if we don't start a transaction on this day
		maxProfit[purchaseDate] = maxProfit[purchaseDate+1]
		// update maxProfit if we start a transaction on this day
		for _, sellDate := range stack {
			profit := prices[sellDate] - prices[purchaseDate] + maxProfit[sellDate+2] // @this is why there are two blank spaces at the rear of maxProfit slice
			if maxProfit[purchaseDate] < profit {
				maxProfit[purchaseDate] = profit
			}
		}
		stack = append(stack, purchaseDate) // push today's price
	}
	return maxProfit[0]
}

// There should be at least one day between two complete transactions...
// ...which is the so-called COOL DOWN.
func maxProfit(prices []int) int {
	return ___0309(prices)
}

func main() {
	prices := []int{1, 2, 3, 0, 2}
	println(maxProfit(prices))
}
