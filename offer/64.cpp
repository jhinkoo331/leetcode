class Solution {
public:
	int sumNums(int n) {
		return _1(n);
	}
private:
	/**
	 * @brief 
	 * @perf: [100, 100]
	 * @param n 
	 * @return int 
	 */
	int _1(int n){
		int sum = 0;
		_1_helper(n, sum);
		return sum;
	}
	bool _1_helper(int n, int& sum){
		sum += n;
		return (n && _1_helper(n - 1, sum));
	}
};
