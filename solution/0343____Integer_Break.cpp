class Solution {
public:
	/**
	 * @brief n is in range [2, 58]
	 */
	int integerBreak(int n) {
		return _1(n);
	}
private:
	/**
	 * @brief 
	 * @perf: 100, 97
	 * @param n 
	 * @return int 
	 */
	int _1(int n){
		//* n = 2 return 1 and n = 3 return 2;
		if(n < 4)
			return n - 1;
		int r = n % 3;
		int q = n / 3;
		int ans = 1;
		if(r == 2)
			ans *= 2;
		else if(r == 1){
			ans *= 4;
			--q;
		}
		while(q--)
			ans *= 3;
		return ans;
	}
};
