
#ifndef uint32_t
#define uint32_t unsigned
#endif

class Solution {
public:
	int hammingWeight(uint32_t n) {
		return hamminWeight_1(n);
	}
private:
	//* [4ms, 20]
	int hamminWeight_1(uint32_t n){
		int ans = 0;
		while(n){
			++ans;
			n &= (n - 1);
		}
		return ans;
	}
};