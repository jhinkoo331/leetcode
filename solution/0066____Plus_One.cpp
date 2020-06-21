#include <vector>
using std::vector;

class Solution {
public:
	vector<int> plusOne(vector<int>& digits) { 
		return _1(digits);
	}
private:
	/**
	 * @perf: [4ms, 52]
	 * @time: O(n), n is length of trailing 9
	 * @space: constant
	 */
	vector<int> _1(vector<int>& digits){
		if(digits.empty())		//* make sure that ANCHOR 1 won't yield seg-err
			return vector<int>{1};
		int i = digits.size() - 1;
		while(i >= 0 && digits[i] == 9){
			digits[i] = 0;
			--i;
		}
		//* now digits[i] is the last number that doesn't equals w/ 9 or -1
		if(i == -1){	//* the digits are all 9s
			//* don't use vector.insert(), 'cuz it's time complexity is O(n)
			digits[0] = 1;		//ANCHOR 1
			digits.push_back(0);
		}else
			++digits[i];
		return digits;
	}
};
