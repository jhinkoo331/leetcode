package main

func maxProfit(prices []int) int {
	return o123(prices)
}

// time: n
// space: n
// perf: 65, 65
func o123(prices []int) int {
	// if we do two transactions, one is at left part and the other is at the
	// right part.
	// calculate left part max and right part max

	// left[i] = k, means that if we sold out at day i, we may get profit of k
	left := make([]int, len(prices), len(prices))
	left[0] = 0
	pre_min := prices[0]
	for i := 1; i < len(left); i++ {
		if prices[i] < pre_min {
			left[i] = 0
		} else {
			left[i] = prices[i] - pre_min
		}
		if prices[i] < pre_min {
			pre_min = prices[i]
		}
	}

	// right[i] = k, mean that if we brought in at day i, we may get profit of k
	right := make([]int, len(prices), len(prices))
	right[len(right)-1] = 0
	right_max := prices[len(prices)-1]
	for i := len(right) - 2; i >= 0; i-- {
		profit := right_max - prices[i]
		if profit > right[i+1] {
			right[i] = profit
		} else {
			right[i] = right[i+1]
		}
		if prices[i] > right_max {
			right_max = prices[i]
		}
	}

	max_profit := right[0]

	for i := 0; i < len(left)-1; i++ {
		profit := left[i] + right[i+1]
		if profit > max_profit {
			max_profit = profit
		}
	}
	// fmt.Println("%v", left)
	// fmt.Println("%v", right)
	return max_profit
}
