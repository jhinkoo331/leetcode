/**
 * @brief 0, 83
 * @time: log_n
 */
int _1(int n){
        int ans = 0;
        while(n){
                n /= 5;
                ans += n;
        }
        return ans;
}

int trailingZeroes(int n){
        return _1(n);
}
