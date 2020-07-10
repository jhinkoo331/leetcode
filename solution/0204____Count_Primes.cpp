#include <vector>
#include <cmath>
using std::vector;

class Solution {
public:
	int countPrimes(int n) {
		return _2(n);
	}
private:
	/**
	 * @perf: 34, 57
	 * @time:
	 * @space: O(n)
	 */
	int _1(int n){
		vector<bool> v(n, true);
		int count = 0;
		for(int i = 2; i < n; ++i){
			if(v[i]){
				++count;
				int temp = i * 2;
				while(temp < n){
					v[temp] = false;
					temp += i;
				}
			}
		}
		return count;
	}
	/**
	 * @brief enhanced from _1
	 * TODO bug unfixed
	 */
	int _2(int n){
		vector<bool> v(n, true);
		int count = 0;
		int pivot = sqrt(n - 1);
		for(int i = 0; i <= pivot; ++i){
			if(v[i]){
				++count;
				int temp = i * 2;
				while(temp < n){
					v[temp] = false;
					temp += i;
				}
			}
		}
		return count;
	}
};
