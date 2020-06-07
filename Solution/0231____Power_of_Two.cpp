
class Solution {
public:
	bool isPowerOfTwo(int n) {
		return isPowerOfTwo_1(n);
	}
private:
	bool isPowerOfTwo_1(int n){
		return n > 0 && !(n & (n - 1));
	}
	//* [100, 43]
	bool isPowerOfTwo_2(int n){
		return n > 0 && (0x40000000 % n == 0);
	}
};
