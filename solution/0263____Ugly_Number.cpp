#include <vector>
using std::vector;

class Solution {
public:
	bool isUgly(int num) {
		return _1(num);
	}
private:
	/**
	 * @perf: [100, 25]
	 * @time: log_n
	 * @space: in-place
	 */
	bool _1(int num){
		if(num <= 0)
			return false;
		while(num % 2 == 0)
			num /= 2;
		while(num % 3 == 0)
			num /= 3;
		while(num % 5 == 0)
			num /= 5;
		return num == 1;
	}
};
