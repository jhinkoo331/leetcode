package main

func maxProfit(k int, prices []int) int {
        return o188(k, prices)
}

func o188(k int, prices []int) int {

        // simplify prices array
        down := true
        tail := 0
        for i := 1; i < len(prices); i++ {
                if prices[i] == prices[tail] {
                        continue
                }
                if prices[i] < prices[tail] {
                        if down {
                                prices[tail] = prices[i]
                        } else {
                                tail++
                                prices[tail] = prices[i]
                                down = true
                        }
                }
                if prices[i] > prices[tail] {
                        if !down {
                                prices[tail] = prices[i]
                        } else {
                                tail++
                                prices[tail] = prices[i]
                                down = false
                        }
                }
        }
        prices = prices[:tail + 1]

        // record left transaction max profit
        info := make([][]int, len(prices), len(prices))
        for i := range info {
                info[i] = make([]int, k, k)
        }
        // left
        cur_min := prices[0]
        for i := 1; i < len(prices); i++ {
                for ii := range info[i] {
                        profit := prices[i] - cur_min
                        if profit > info[i][1] {
                                info[i][]
                        }
                }
        }

        return 0
}

func main() {
	
}
