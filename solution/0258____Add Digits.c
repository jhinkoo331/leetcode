

/**
 * @brief int32 max is 21,4748,3647, the max digits sum number is
 *              19,9999,9999, sum of whose's digits is 82
 * 
 * @param num 
 * @perf: 4ms, 6.88
 * @return int 
 */
int _1(int num){
        if(num < 10)
                return num;
        int sum = 0;
        while(num){
                sum += num % 10;
                num /= 10;
        }
        return _1(sum);
}

// perf: 0ms, 59
int _2(int num) {
        if(num == 0)
                return 0;
        if (num % 9)
                return num % 9;
        else
                return 9;
}

/**
 * @brief 
 * 
 * @param num  non-negative
 * @return int steps to add digits till the result contains only 1 digit
 */
int addDigits(int num){
        return _2(num);
}
