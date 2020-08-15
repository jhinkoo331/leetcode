
/**
 * @brief bit operation
 * @perf: 4ms, 58
 */
int _1(int m, int n);

/**
 * @perf: 4ms, 65 
 */
int _2(int m, int n);

int rangeBitwiseAnd(int m, int n){
        return _2(m, n);
}


int _1(int m, int n){
        unsigned mask = 0x80000000;
        unsigned ans = 0;
        while(mask && (m & mask) == (n & mask)){
                ans |= (mask & m);
                mask >>= 1;
        }
        return ans;
}

int _2(int m, int n){
        unsigned mask = 0x80000000;
        unsigned ans = 0;
        while(mask){
                unsigned i = m & mask;
                unsigned ii = n & mask;
                if(i != ii)
                        break;
                else
                        ans += i;
                mask >>= 1;
        }
        return ans;
}