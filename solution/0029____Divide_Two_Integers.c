
inline int abs(int i){
        return i < 0 ? -i : i;
}

/**
 * @brief the system is in a environment where only 32-bit signed integer
 *              availabe
 * 
 * @perf: 0ms, 12.9
 * @param dividend 
 * @param divisor 
 * @return int return 2**31 - 1 when the result overflows
 */
int _1(int dividend, int divisor){
        int dividend_is_negative = dividend < 0;
        int divisor_is_negative = divisor < 0;
        // overflow
        if(divisor == 0)
                return 0x7fffffff;
        if(dividend == 0x80000000 && divisor == -1)     // the answer is positive
                return 0x7fffffff;
        // make dividend positive
        if(dividend == 0x80000000){
                if(divisor == 0x80000000)
                        return 1;
                divisor = abs(divisor);
                if((divisor & (divisor - 1)) == 0){
                        if(divisor == 1)
                                return 0x80000000;
                        int ans = 1;
                        while(divisor != 0x40000000){
                                ans <<= 1;
                                divisor <<= 1;
                        }
                        ans <<= 1;
                        if(dividend_is_negative)
                                return -ans;
                        else
                                return ans;
                }
                ++dividend;
        }
        if(divisor == 0x80000000)
                return 0;
        dividend = abs(dividend);
        divisor = abs(divisor);
        int i = 1;
        while(divisor <= dividend && !(divisor & 0x40000000)){  // while divisor can be multipled with 2
                i <<= 1;
                divisor <<= 1;
        }
        int ans = 0;
        while(dividend && i){
                if(dividend >= divisor){
                        dividend -= divisor;
                        ans |= i;
                }
                i >>= 1;
                divisor >>= 1;
        }
        if(dividend_is_negative ^ divisor_is_negative)
                ans = -ans;
        return ans;
}

int divide(int dividend, int divisor){
        return _1(dividend, divisor);
}

int main(){
        int ans;
        // ans = divide(10, 3);
        // ans = divide(7, -3);
        // ans = divide(0x80000000, 2);
        ans = divide(1004958205, -2137325331);
        return 0;
}
