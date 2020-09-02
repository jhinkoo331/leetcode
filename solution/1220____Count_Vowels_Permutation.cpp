#include <vector>
using namespace std;

enum vowel {a, e, i, o, u, x};

class Solution {
public:
	int countVowelPermutation(int n){
		return _2(n);
	}
public:
	/**
	 * @brief 
	 * @perf: 73, 59
	 * @param n 
	 * @return int 
	 */
	int _1(int n) {
		if(n <= 0)
			return 0;
		vector<vector<unsigned>> v(5);
		for(int ii = 0; ii < 5; ++ii){
			v[ii].resize(n);
			v[ii][0] = 1;
		}
		for(int ii = 1; ii < n; ++ii){
			int iii = ii - 1;
			v[a][ii] = v[e][iii];
			v[e][ii] = (v[a][iii] + v[i][iii]) % divisor;
			v[i][ii] = (v[a][iii] + v[e][iii] + v[o][iii] + v[u][iii]) % divisor;
			v[o][ii] = (v[i][iii] + v[u][iii]) % divisor;
			v[u][ii] = v[a][iii];
		}
		int sum = 0;
		for(int i = 0; i < 5; ++i){
			sum += v[i].back();
			sum %= divisor;
		}
		return sum;
	}

	/**
	 * @brief updated from _1
	 * @perf: 73, 79. Memory consumption reduced.
	 */
	int _2(int n){
		if(n <= 0)
			return 0;
		vector<unsigned> v(5, 1);
		vector<unsigned> v_temp(5);
		for(int ii = 1; ii < n; ++ii){
			v_temp[a] = v[e];
			v_temp[e] = (v[a] + v[i]) % divisor;
			v_temp[i] = (v[a] + v[e] + v[o] + v[u]) % divisor;
			v_temp[o] = (v[i] + v[u]) % divisor;
			v_temp[u] = v[a];
			v.swap(v_temp);
		}
		int sum = 0;
		for(const auto e: v){
			sum += e;
			sum %= divisor;
		}
		return sum;
	}
private:
	const int divisor = 1e9 + 7;
};

int main(){
	Solution sln;
	int ret = -1;
	ret = sln.countVowelPermutation(-1);
	ret = sln.countVowelPermutation(0);
	ret = sln.countVowelPermutation(1);
	ret = sln.countVowelPermutation(5);
	ret = sln.countVowelPermutation(144);
	ret = sln.countVowelPermutation(0x80000000);
	ret = sln.countVowelPermutation(0x7fffffff);
	return 0;
}