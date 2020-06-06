#include <vector>
using std::vector;

class Solution {
public:
	int uniquePaths(int m, int n) {
		return uniquePaths_2(m, n);
	}
private:
	/** 
	 * @param m_n both in range [1, 100]
	 * [100, 63]
	 */
	int uniquePaths_1(int m, int n){
		//* make m >= n
		if(m < n)
			swap(m, n);
		//* when m == n == 1, return 1	<= from the website's return value
		if(n == 1)
			return 1;		//! must
		vector<int> vm, vn;
		helper(vm, vn, m, n);
		vm.push_back(0);		//! must
		int ret = 0;
		for(int i = 1; i < vn.size(); ++i){
			ret += vn[i] * vm[i - 1] + 2 * vn[i] * vm[i] + vn[i] * vm[i + 1];
		}
		return ret;
	}
	void helper(vector<int>& vm, vector<int>& vn, int m, int n){
		vm.resize(n + 1);
		vn.resize(n);
		int temp = 1;
		for(int i = 1; i <= n; ++i){
			vm[i] = temp;
			//* code below may render avoidable overflow
			// temp *= m - i - 1;
			// temp /= i;
			int _gcd = gcd(m - i - 1, i);
			int k = i / _gcd;
			temp /= k;
			k = (m - i - 1) / _gcd;
			temp *= k;
		}
		vm.push_back(0);
		temp = 1;
		for(int i = 1; i < n; ++i){
			vn[i] = temp;
			int _gcd = gcd(n - i - 1, i);
			int k = i / _gcd;
			temp /= k;
			k = (n - i - 1) / _gcd;
			temp *= k;
		}
	}
	/**
	 * @param i_ii both positive
	 * @return the greatest common divisor of i and ii
	 */
	int gcd(int i, int ii){
		//* assume that `i` is smaller one
		while(i != 0){
			int c = ii % i;
			ii = i;
			i = c;
		}
		return ii;
	}
	inline void swap(int& i, int& ii){
		int temp = i;
		i = ii;
		ii = temp;
	}
	//* [100, 43]
	//TODO: understand this...
	int uniquePaths_2(int m, int n){
		vector<vector<int>> v;
		v.resize(m);
		for(auto& elem: v)
			elem.resize(n, 1);
		for(int i = 1; i < v.size(); ++i)
			for(int ii = 1; ii < v.front().size(); ++ii)
				v[i][ii] = v[i - 1][ii] + v[i][ii - 1];
		return v.back().back();
	}
};

int main(){
	Solution sln;
	sln.uniquePaths(3, 2);
	sln.uniquePaths(51, 9);
	sln.uniquePaths(3, 2);
	sln.uniquePaths(7, 3);
	return 0;
}
