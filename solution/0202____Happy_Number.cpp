#include <unordered_set>
using std::unordered_set;


//TODO: use low and fast pointer, rather than hash map, to solve the loop problem.

class Solution {
public:
	bool isHappy(int n) {
		return _1(n);
	}
private:
	/**
	 * @perf: [4ms, 10]
	 * @space: not constant
	 * @time: not constant
	 */
	bool _1(int n){
		if(n == 0)
			return false;
		unordered_set<int> us;
		while(n != 1){
			if(us.find(n) != us.end())
				return false;
			us.insert(n);
			int temp = 0;
			while(n != 0){
				temp += (n % 10) * (n % 10);
				n /= 10;
			}
			n = temp;
		}
		return true;
	}
};

int main(int argc, char const *argv[]) {
	Solution sln;
	sln.isHappy(19);
	return 0;
}
