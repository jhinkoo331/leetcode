package main

import (
        "go/ast"
        "net/http/httputil"
)

func _0123_findLowAndHigh(prices []int) ([]int, []int) {
        var low, high []int
        for index := 0; index < len(prices) - 1; {             // index is not pointing to the last element
                for index + 1 < len(prices) && prices[index] >= prices[index+1] {
                        index++
                }
                if index == len(prices) - 1 {
                        break
                }
                low = append(low, index)
                for index + 1 < len(prices) && prices[index] <= prices[index+1] {
                        index++
                }
                high = append(high, index)
        }
        return low, high
}

func _0123_process_low_and_high(low, high []int) {

}

func _0123(prices []int) int {
        low, high := _0123_findLowAndHigh(prices)
        sz := len(low)
        if len(low) == 0 {
                return 0
        }
        if len(low) == 1 {
                return high[0] - low[0]
        }
        if len(low) == 2 {
                return high[0] + high[1] - low[0] - low[0]
        }
        highestPriceTillNow := make([]int, sz)
        maxProfitIfPurchase := make([]int, sz)
        highestPriceTillNow[0] = high[0]
        for index := 1; index < sz; index++ {
                if high[index] < highestPriceTillNow[index - 1] {
                        highestPriceTillNow[index] = highestPriceTillNow[index - 1]
                } else {
                        highestPriceTillNow[index] = high[index]
                }
        }
        curHighest := high[sz - 1]
        for index := sz - 1; index >= 0; index-- {
                if curHighest < high[index] {
                        curHighest = high[index]
                }
                maxProfitIfPurchase[index] = curHighest - low[index]
        }
        for 
}

// you may complete two transactions at most, which means 0 or 1 transaction
// is acceptable as well.
func _maxProfit(prices []int) int {
        return _0128(prices)
}

func main() {
	
}
