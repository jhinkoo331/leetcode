class Solution {
public:
	int fib(int N) {
		return _1(N);
	}
private:
	/**
	 * @brief if `n` is odd number, return `odd`, return `even` otherwise
	 * @perf: 100, 65
	 * @param n 
	 * @return int 
	 */
	int _1(int n){
		int even = 0, odd = 1;
		bool is_odd = n % 2;
		n /= 2;
		while(n--){
			even = even + odd;
			odd = even + odd;
		}
		return is_odd ? odd : even;
	}
};	
