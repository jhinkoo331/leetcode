
/**
 * @brief bit operation
 * @perf: 83, 36
 */
int _1(int m, int n);

int rangeBitwiseAnd(int m, int n){
        return _1(m, n);
}


int _1(int m, int n){
        //* make m >= n
        if(m < n){
                int temp = m;
                m = n;
                n = temp;
        }
        unsigned mask = 0x80000000;
        unsigned ans = 0;
        while(mask && (m & mask) == (n & mask)){
                ans |= (mask & m);
                mask >>= 1;
        }
        return ans;
}