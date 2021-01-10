
int _1(int* prices, int pricesSize);

int maxProfit(int* prices, int pricesSize){
        return _1(prices, pricesSize);
}


/**
 * @brief 75, 71
 */
int _1(int* prices, int pricesSize){
        if(pricesSize < 2)      // error condition
                return 0;
        int max_profit = 0;
        // price[0] is to store the lowest price that ever seen
        for(int i = 1; i < pricesSize; ++i){
                int profit = prices[i] - prices[0];
                if(profit > max_profit)
                        max_profit = profit;
                if(prices[i] < prices[0])
                        prices[0] = prices[i];
        }
        return max_profit;
}
