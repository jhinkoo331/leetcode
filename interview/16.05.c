
/**
 * @perf: 0ms, 6
 * @time: log_n
 * @space: 1
 */
int trailingZeroes(int n){
        int ans = 0;
        while(n){
                n /= 5;
                ans += n;
        }
        return n;
}
