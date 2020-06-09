#include <vector>
#include <algorithm>
#include <cmath>
using std::vector, std::find;

const vector<int> v = {0x1, 0x4, 0x10, 0x40, 0x100, 0x400, 0x1000, 0x4000, 0x10000, 0x40000, 0x100000, 0x400000, 0x1000000, 0x4000000, 0x10000000, 0x40000000};

class Solution {
public:
	bool isPowerOfFour(int num) {
		return isPowerOfFour_3(num);
	}

private:
	//* [100, 24]
	bool isPowerOfFour_1(int num){
		if(num <= 0)
			return false;
		while(true){
			if(num == 1)
				return true;
			else if((num & 3) == 0)
				num >>= 2;
			else
				return false;
		}
	}
	//* search table
	bool isPowerOfFour_2(int num){
		for(int i = 0; i < v.size(); ++i)
			if(v[i] == num)
				return true;
		return false;
	}
	/**
	 * without loop or recursion
	 * [100, 20]
	 */	
	bool isPowerOfFour_3(int num){
		return num > 0 && (int)pow(4, (int)(log(num) / log(4))) == num;
	}
	/**
	 * totally bit operation!
	 * power of 4 must satisfy 3 common feature:
	 * 1. positive: num > 0
	 * 2. contains only 1 bit of `1` in binary presentation: num & (num - 1) is to erase the last bit of `1`, and the result should be 32 0s
	 * 3. the only one `1` should locate at odd location, such as: 01, 0100, 010000..., num & 0x55555555 is to set all even bits to 0
	 * Another way to distinguish 4**n from 2**n: (num - 1) % 3 should be 0
	 */
	bool isPowerOfFour_4(int num){
		return num > 0 && (num & (num - 1)) == 0 && (num & 0x55555555) != 0;
	}
};

int main(){
	Solution sln;
	bool ret = true;
	for(auto e: v)
		if(!sln.isPowerOfFour(e))
			ret = false;
	return 0;
}